#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ann_class = new ann(this);

    _100_msec_timer = new QTimer(this);
    _100_msec_timer->setInterval(1000);
    _100_msec_timer->start();
    connect(this->_100_msec_timer,SIGNAL(timeout()),this,SLOT(_100_msec_timer_handle()));

    QPixmap my_pixmap;
    my_pixmap.load("/home/ahmet/Desktop/my_hand/32x42_full_contrast/two.jpg");
    ui->label_hand_two->setPixmap(my_pixmap);

    connect(ui->pushButton_76800_1024_1024_6_random_initilize,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_random_initilize_handler()));
    connect(ui->pushButton_76800_1024_1024_6_train,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_train_handler()));
    connect(ui->pushButton_76800_1024_1024_6_test,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_test_handler()));
    connect(ui->pushButton_76800_1024_1024_6_show_weights,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_show_weights_handler()));
    connect(ui->pushButton_76800_1024_1024_6_save_weights,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_save_weights_handler()));
    connect(ui->pushButton_76800_1024_1024_6_load_saved_weights,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_load_saved_weights_handler()));
    connect(ui->pushButton_76800_1024_1024_6_stop_train,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_stop_train_handler()));

    periodic_timer = new QTimer(this);
    periodic_timer->setInterval(200);
    connect(periodic_timer,SIGNAL(timeout()),this,SLOT(capture_video()));
    periodic_timer->start();

    //my_vid.open("/dev/video0");
    my_vid.open(0);

}
void MainWindow::capture_video(void){
    cv::Mat my_frame;
    my_vid >> my_frame;

    //find fps of the vid
    qDebug() << "fps" << my_vid.get(CV_CAP_PROP_FPS);

    cv::resize(my_frame,my_frame, cv::Size(480,270),0,0,CV_INTER_LINEAR);

    /////////////////////////////////////////
    double angle = 0;

    cv::Point2f center((my_frame.cols-1)/2.0, (my_frame.rows-1)/2.0);
    cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
    cv::Rect bbox = cv::RotatedRect(cv::Point2f(), my_frame.size(), angle).boundingRect();
    rot.at<double>(0,2) += bbox.width/2.0 - my_frame.cols/2.0;
    rot.at<double>(1,2) += bbox.height/2.0 - my_frame.rows/2.0;
    cv::Mat dst;
    cv::warpAffine(my_frame, dst, rot, bbox.size());
    QImage show_my_image((uchar*)dst.data, dst.cols, dst.rows, dst.step, QImage::Format_RGB888);
    ui->label_video->setPixmap(QPixmap::fromImage(show_my_image));
    /////////////////////////////////////////

//    QImage show_my_vid((uchar*)my_frame.data, my_frame.cols, my_frame.rows, my_frame.step, QImage::Format_RGB888);
//    ui->label_video->setPixmap(QPixmap::fromImage(show_my_vid));

    my_frame.release();
}

void MainWindow::_100_msec_timer_handle(void){
    if(ann_class->train_status == 1){
        ui->label_76800_1024_1024_6_train->setText(QString("training status %  %1").arg(ann_class->epoch_status));
        ui->label_76800_1024_1024_6_train_status->setText(QString("Epoch : %1 , Error : %2 , ob-0 : %3").
                                                        arg(ann_class->epoch_no).arg(ann_class->net_76800_1024_1024_6.total_err).
                                                        arg(ann_class->net_76800_1024_1024_6.output_bias[0]));
        ui->label_76800_1024_1024_6_train_status_2->setText(QString("hb1-0 : %1 , hb2-0 : %2 , wh2h-0 : %3").
                                                        arg(ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1[0]).
                                                        arg(ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[0]).
                                                        arg(ann_class->net_76800_1024_1024_6.w_hidden_1_to_hidden_2[0][0]));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
