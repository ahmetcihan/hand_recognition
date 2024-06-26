#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ann_class = new ann(this);

    connect(ui->pushButton_snapshot_fist,SIGNAL(clicked(bool)),this,SLOT(get_fist_picture()));
    connect(ui->pushButton_snapshot_two,SIGNAL(clicked(bool)),this,SLOT(get_two_picture()));
    connect(ui->pushButton_snapshot_five,SIGNAL(clicked(bool)),this,SLOT(get_five_picture()));

    _100_msec_timer = new QTimer(this);
    _100_msec_timer->setInterval(1000);
    _100_msec_timer->start();
    connect(this->_100_msec_timer,SIGNAL(timeout()),this,SLOT(_100_msec_timer_handle()));

    connect(ui->pushButton_76800_1024_1024_6_prepare_io,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_prepare_io_pairs_handler()));
    connect(ui->pushButton_76800_1024_1024_6_random_initilize,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_random_initilize_handler()));
    connect(ui->pushButton_76800_1024_1024_6_train,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_train_handler()));
    connect(ui->pushButton_76800_1024_1024_6_test,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_test_handler()));
    connect(ui->pushButton_76800_1024_1024_6_show_weights,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_show_weights_handler()));
    connect(ui->pushButton_76800_1024_1024_6_save_weights,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_save_weights_handler()));
    connect(ui->pushButton_76800_1024_1024_6_load_saved_weights,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_load_saved_weights_handler()));
    connect(ui->pushButton_76800_1024_1024_6_stop_train,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_stop_train_handler()));

    periodic_timer = new QTimer(this);
    periodic_timer->setInterval(50);
    connect(periodic_timer,SIGNAL(timeout()),this,SLOT(capture_video()));
    //periodic_timer->start();
    connect(ui->pushButton_start_stream,SIGNAL(clicked(bool)),this,SLOT(start_stream()));

    //connect(ui->pushButton_shot,SIGNAL(clicked(bool)),this,SLOT(capture_video()));

    //my_vid.open("/dev/video0");
    my_vid.open(0);

}
void MainWindow::start_stream(void){
    periodic_timer->start();
}
void MainWindow::capture_video(void){
    static QElapsedTimer my_timer;

    my_timer.restart();

    cv::Mat original_frame;
    cv::Mat rotated_frame;

    my_vid >> original_frame;

    qDebug() << "fps" << my_vid.get(CV_CAP_PROP_FPS) << "width" << my_vid.get(CV_CAP_PROP_FRAME_WIDTH) << "height" << my_vid.get(CV_CAP_PROP_FRAME_HEIGHT);

    cv::resize(original_frame,original_frame, cv::Size(320,240),0,0,CV_INTER_LINEAR);
    cv::rotate(original_frame,rotated_frame,cv::ROTATE_90_COUNTERCLOCKWISE);

    QImage show_my_image((uchar*)original_frame.data, original_frame.cols, original_frame.rows, original_frame.step, QImage::Format_RGB888);
    ui->label_video->setPixmap(QPixmap::fromImage(show_my_image));


    QImage rotated_image((uchar*)rotated_frame.data, rotated_frame.cols, rotated_frame.rows, rotated_frame.step, QImage::Format_RGB888);

    QPixmap rotated_original = QPixmap::fromImage(rotated_image);
    ui->label_video_original_rotated->setPixmap(rotated_original);

    for(u16 i = 0; i < rotated_image.width(); i++){
        for(u16 j = 0; j < rotated_image.height(); j++){
            if(QColor(rotated_image.pixel(i,j)).black() < 64){
                rotated_image.setPixel(i,j,qRgb(255,255,255));
            }
            else{
                rotated_image.setPixel(i,j,qRgb(0,0,0));
            }
        }
    }
    QPixmap rotated_monochrome = QPixmap::fromImage(rotated_image);
    ui->label_video_rotated->setPixmap(rotated_monochrome);

    QImage small_scale;
    small_scale = rotated_image.scaled(QSize(30,40),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    QPixmap small_picture = QPixmap::fromImage(small_scale);
    ui->label_video_small_monochrome->setPixmap(small_picture);
    ui->label_video_small_monochrome_2->setPixmap(small_picture);
    ui->label_hand_two->setPixmap(small_picture);

    original_frame.release();
    rotated_frame.release();

    if(1){
        u8 tester[30][40];

        for(u8 i = 0; i < small_scale.width();i++){
            for(u8 j = 0; j < small_scale.height();j++){
                tester[i][j] = 0;
                if((small_scale.pixel(i,j) & 0xFF) == 0xFF){
                    tester[i][j] = 1;
                }
            }
        }


        for(u32 j = 0; j < 40; j++){
            for(u32 i = 0; i < 30; i++){
                ann_class->net_76800_1024_1024_6.test_input[i + 30*j] = tester[i][j];
            }
        }

        ann_class->_76800_1024_1024_6_ann_test( ann_class->net_76800_1024_1024_6.test_input,
                                                ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1,
                                                ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2,
                                                ann_class->net_76800_1024_1024_6.hidden_neuron_bias_3,
                                                ann_class->net_76800_1024_1024_6.output_bias,
                                                ann_class->net_76800_1024_1024_6.w_input_to_hidden_1,
                                                ann_class->net_76800_1024_1024_6.w_hidden_1_to_hidden_2,
                                                ann_class->net_76800_1024_1024_6.w_hidden_2_to_hidden_3,
                                                ann_class->net_76800_1024_1024_6.w_hidden_3_to_output);
    }


    qDebug() << "elapsed time" << my_timer.elapsed();
}

void MainWindow::_100_msec_timer_handle(void){
    if(ann_class->train_status == 1){
        ui->label_76800_1024_1024_6_train->setText(QString("training status %  %1").arg(ann_class->epoch_status));
        ui->label_76800_1024_1024_6_train_status->setText(QString("Epoch : %1 , Error : %2 , ob-0 : %3 , hb1-0 : %4").
                                                            arg(ann_class->epoch_no).
                                                            arg(ann_class->net_76800_1024_1024_6.total_err).
                                                            arg(ann_class->net_76800_1024_1024_6.output_bias[0]).
                                                            arg(ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1[0]));
        ui->label_76800_1024_1024_6_train_status_2->setText(QString("hb2-0 : %1 , hb3-0 : %2 , whi21-0 : %3").
                                                            arg(ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[0]).
                                                            arg(ann_class->net_76800_1024_1024_6.hidden_neuron_bias_3[0]).
                                                            arg(ann_class->net_76800_1024_1024_6.w_input_to_hidden_1[0][0]));
        ui->label_76800_1024_1024_6_train_status_3->setText(QString("wh122-0 : %1 , wh223-0 : %2 , wh32o-0 : %3").
                                                            arg(ann_class->net_76800_1024_1024_6.w_hidden_1_to_hidden_2[0][0]).
                                                            arg(ann_class->net_76800_1024_1024_6.w_hidden_2_to_hidden_3[0][0]).
                                                            arg(ann_class->net_76800_1024_1024_6.w_hidden_3_to_output[0][0]));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
