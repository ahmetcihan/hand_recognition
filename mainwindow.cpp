#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ann_class = new ann(this);

    connect(ui->pushButton_snapshot_fist_1,SIGNAL(clicked(bool)),this,SLOT(get_fist_1_picture()));
    connect(ui->pushButton_snapshot_fist_2,SIGNAL(clicked(bool)),this,SLOT(get_fist_2_picture()));
    connect(ui->pushButton_snapshot_fist_3,SIGNAL(clicked(bool)),this,SLOT(get_fist_3_picture()));
    connect(ui->pushButton_snapshot_fist_4,SIGNAL(clicked(bool)),this,SLOT(get_fist_4_picture()));
    connect(ui->pushButton_snapshot_fist_5,SIGNAL(clicked(bool)),this,SLOT(get_fist_5_picture()));
    connect(ui->pushButton_snapshot_fist_6,SIGNAL(clicked(bool)),this,SLOT(get_fist_6_picture()));
    connect(ui->pushButton_snapshot_fist_7,SIGNAL(clicked(bool)),this,SLOT(get_fist_7_picture()));
    connect(ui->pushButton_snapshot_fist_8,SIGNAL(clicked(bool)),this,SLOT(get_fist_8_picture()));
    connect(ui->pushButton_snapshot_fist_9,SIGNAL(clicked(bool)),this,SLOT(get_fist_9_picture()));
    connect(ui->pushButton_snapshot_fist_10,SIGNAL(clicked(bool)),this,SLOT(get_fist_10_picture()));
    connect(ui->pushButton_snapshot_fist_11,SIGNAL(clicked(bool)),this,SLOT(get_fist_11_picture()));
    connect(ui->pushButton_snapshot_fist_12,SIGNAL(clicked(bool)),this,SLOT(get_fist_12_picture()));
    connect(ui->pushButton_snapshot_fist_13,SIGNAL(clicked(bool)),this,SLOT(get_fist_13_picture()));
    connect(ui->pushButton_snapshot_fist_14,SIGNAL(clicked(bool)),this,SLOT(get_fist_14_picture()));
    connect(ui->pushButton_snapshot_fist_15,SIGNAL(clicked(bool)),this,SLOT(get_fist_15_picture()));
    connect(ui->pushButton_snapshot_fist_16,SIGNAL(clicked(bool)),this,SLOT(get_fist_16_picture()));
    connect(ui->pushButton_snapshot_fist_17,SIGNAL(clicked(bool)),this,SLOT(get_fist_17_picture()));
    connect(ui->pushButton_snapshot_fist_18,SIGNAL(clicked(bool)),this,SLOT(get_fist_18_picture()));
    connect(ui->pushButton_snapshot_fist_19,SIGNAL(clicked(bool)),this,SLOT(get_fist_19_picture()));
    connect(ui->pushButton_snapshot_fist_20,SIGNAL(clicked(bool)),this,SLOT(get_fist_20_picture()));
    connect(ui->pushButton_snapshot_fist_21,SIGNAL(clicked(bool)),this,SLOT(get_fist_21_picture()));
    connect(ui->pushButton_snapshot_fist_22,SIGNAL(clicked(bool)),this,SLOT(get_fist_22_picture()));
    connect(ui->pushButton_snapshot_fist_23,SIGNAL(clicked(bool)),this,SLOT(get_fist_23_picture()));
    connect(ui->pushButton_snapshot_fist_24,SIGNAL(clicked(bool)),this,SLOT(get_fist_24_picture()));
    connect(ui->pushButton_snapshot_one_1,SIGNAL(clicked(bool)),this,SLOT(get_one_1_picture()));
    connect(ui->pushButton_snapshot_one_2,SIGNAL(clicked(bool)),this,SLOT(get_one_2_picture()));
    connect(ui->pushButton_snapshot_one_3,SIGNAL(clicked(bool)),this,SLOT(get_one_3_picture()));
    connect(ui->pushButton_snapshot_one_4,SIGNAL(clicked(bool)),this,SLOT(get_one_4_picture()));
    connect(ui->pushButton_snapshot_one_5,SIGNAL(clicked(bool)),this,SLOT(get_one_5_picture()));
    connect(ui->pushButton_snapshot_one_6,SIGNAL(clicked(bool)),this,SLOT(get_one_6_picture()));
    connect(ui->pushButton_snapshot_one_7,SIGNAL(clicked(bool)),this,SLOT(get_one_7_picture()));
    connect(ui->pushButton_snapshot_one_8,SIGNAL(clicked(bool)),this,SLOT(get_one_8_picture()));
    connect(ui->pushButton_snapshot_one_9,SIGNAL(clicked(bool)),this,SLOT(get_one_9_picture()));
    connect(ui->pushButton_snapshot_one_10,SIGNAL(clicked(bool)),this,SLOT(get_one_10_picture()));
    connect(ui->pushButton_snapshot_one_11,SIGNAL(clicked(bool)),this,SLOT(get_one_11_picture()));
    connect(ui->pushButton_snapshot_one_12,SIGNAL(clicked(bool)),this,SLOT(get_one_12_picture()));
    connect(ui->pushButton_snapshot_one_13,SIGNAL(clicked(bool)),this,SLOT(get_one_13_picture()));
    connect(ui->pushButton_snapshot_one_14,SIGNAL(clicked(bool)),this,SLOT(get_one_14_picture()));
    connect(ui->pushButton_snapshot_one_15,SIGNAL(clicked(bool)),this,SLOT(get_one_15_picture()));
    connect(ui->pushButton_snapshot_one_16,SIGNAL(clicked(bool)),this,SLOT(get_one_16_picture()));
    connect(ui->pushButton_snapshot_one_17,SIGNAL(clicked(bool)),this,SLOT(get_one_17_picture()));
    connect(ui->pushButton_snapshot_one_18,SIGNAL(clicked(bool)),this,SLOT(get_one_18_picture()));
    connect(ui->pushButton_snapshot_one_19,SIGNAL(clicked(bool)),this,SLOT(get_one_19_picture()));
    connect(ui->pushButton_snapshot_one_20,SIGNAL(clicked(bool)),this,SLOT(get_one_20_picture()));
    connect(ui->pushButton_snapshot_one_21,SIGNAL(clicked(bool)),this,SLOT(get_one_21_picture()));
    connect(ui->pushButton_snapshot_one_22,SIGNAL(clicked(bool)),this,SLOT(get_one_22_picture()));
    connect(ui->pushButton_snapshot_one_23,SIGNAL(clicked(bool)),this,SLOT(get_one_23_picture()));
    connect(ui->pushButton_snapshot_one_24,SIGNAL(clicked(bool)),this,SLOT(get_one_24_picture()));
    connect(ui->pushButton_snapshot_two_1,SIGNAL(clicked(bool)),this,SLOT(get_two_1_picture()));
    connect(ui->pushButton_snapshot_two_2,SIGNAL(clicked(bool)),this,SLOT(get_two_2_picture()));
    connect(ui->pushButton_snapshot_two_3,SIGNAL(clicked(bool)),this,SLOT(get_two_3_picture()));
    connect(ui->pushButton_snapshot_two_4,SIGNAL(clicked(bool)),this,SLOT(get_two_4_picture()));
    connect(ui->pushButton_snapshot_two_5,SIGNAL(clicked(bool)),this,SLOT(get_two_5_picture()));
    connect(ui->pushButton_snapshot_two_6,SIGNAL(clicked(bool)),this,SLOT(get_two_6_picture()));
    connect(ui->pushButton_snapshot_two_7,SIGNAL(clicked(bool)),this,SLOT(get_two_7_picture()));
    connect(ui->pushButton_snapshot_two_8,SIGNAL(clicked(bool)),this,SLOT(get_two_8_picture()));
    connect(ui->pushButton_snapshot_two_9,SIGNAL(clicked(bool)),this,SLOT(get_two_9_picture()));
    connect(ui->pushButton_snapshot_two_10,SIGNAL(clicked(bool)),this,SLOT(get_two_10_picture()));
    connect(ui->pushButton_snapshot_two_11,SIGNAL(clicked(bool)),this,SLOT(get_two_11_picture()));
    connect(ui->pushButton_snapshot_two_12,SIGNAL(clicked(bool)),this,SLOT(get_two_12_picture()));
    connect(ui->pushButton_snapshot_two_13,SIGNAL(clicked(bool)),this,SLOT(get_two_13_picture()));
    connect(ui->pushButton_snapshot_two_14,SIGNAL(clicked(bool)),this,SLOT(get_two_14_picture()));
    connect(ui->pushButton_snapshot_two_15,SIGNAL(clicked(bool)),this,SLOT(get_two_15_picture()));
    connect(ui->pushButton_snapshot_two_16,SIGNAL(clicked(bool)),this,SLOT(get_two_16_picture()));
    connect(ui->pushButton_snapshot_two_17,SIGNAL(clicked(bool)),this,SLOT(get_two_17_picture()));
    connect(ui->pushButton_snapshot_two_18,SIGNAL(clicked(bool)),this,SLOT(get_two_18_picture()));
    connect(ui->pushButton_snapshot_two_19,SIGNAL(clicked(bool)),this,SLOT(get_two_19_picture()));
    connect(ui->pushButton_snapshot_two_20,SIGNAL(clicked(bool)),this,SLOT(get_two_20_picture()));
    connect(ui->pushButton_snapshot_two_21,SIGNAL(clicked(bool)),this,SLOT(get_two_21_picture()));
    connect(ui->pushButton_snapshot_two_22,SIGNAL(clicked(bool)),this,SLOT(get_two_22_picture()));
    connect(ui->pushButton_snapshot_two_23,SIGNAL(clicked(bool)),this,SLOT(get_two_23_picture()));
    connect(ui->pushButton_snapshot_two_24,SIGNAL(clicked(bool)),this,SLOT(get_two_24_picture()));
    connect(ui->pushButton_snapshot_three_1,SIGNAL(clicked(bool)),this,SLOT(get_three_1_picture()));
    connect(ui->pushButton_snapshot_three_2,SIGNAL(clicked(bool)),this,SLOT(get_three_2_picture()));
    connect(ui->pushButton_snapshot_three_3,SIGNAL(clicked(bool)),this,SLOT(get_three_3_picture()));
    connect(ui->pushButton_snapshot_three_4,SIGNAL(clicked(bool)),this,SLOT(get_three_4_picture()));
    connect(ui->pushButton_snapshot_three_5,SIGNAL(clicked(bool)),this,SLOT(get_three_5_picture()));
    connect(ui->pushButton_snapshot_three_6,SIGNAL(clicked(bool)),this,SLOT(get_three_6_picture()));
    connect(ui->pushButton_snapshot_three_7,SIGNAL(clicked(bool)),this,SLOT(get_three_7_picture()));
    connect(ui->pushButton_snapshot_three_8,SIGNAL(clicked(bool)),this,SLOT(get_three_8_picture()));
    connect(ui->pushButton_snapshot_three_9,SIGNAL(clicked(bool)),this,SLOT(get_three_9_picture()));
    connect(ui->pushButton_snapshot_three_10,SIGNAL(clicked(bool)),this,SLOT(get_three_10_picture()));
    connect(ui->pushButton_snapshot_three_11,SIGNAL(clicked(bool)),this,SLOT(get_three_11_picture()));
    connect(ui->pushButton_snapshot_three_12,SIGNAL(clicked(bool)),this,SLOT(get_three_12_picture()));
    connect(ui->pushButton_snapshot_three_13,SIGNAL(clicked(bool)),this,SLOT(get_three_13_picture()));
    connect(ui->pushButton_snapshot_three_14,SIGNAL(clicked(bool)),this,SLOT(get_three_14_picture()));
    connect(ui->pushButton_snapshot_three_15,SIGNAL(clicked(bool)),this,SLOT(get_three_15_picture()));
    connect(ui->pushButton_snapshot_three_16,SIGNAL(clicked(bool)),this,SLOT(get_three_16_picture()));
    connect(ui->pushButton_snapshot_three_17,SIGNAL(clicked(bool)),this,SLOT(get_three_17_picture()));
    connect(ui->pushButton_snapshot_three_18,SIGNAL(clicked(bool)),this,SLOT(get_three_18_picture()));
    connect(ui->pushButton_snapshot_three_19,SIGNAL(clicked(bool)),this,SLOT(get_three_19_picture()));
    connect(ui->pushButton_snapshot_three_20,SIGNAL(clicked(bool)),this,SLOT(get_three_20_picture()));
    connect(ui->pushButton_snapshot_three_21,SIGNAL(clicked(bool)),this,SLOT(get_three_21_picture()));
    connect(ui->pushButton_snapshot_three_22,SIGNAL(clicked(bool)),this,SLOT(get_three_22_picture()));
    connect(ui->pushButton_snapshot_three_23,SIGNAL(clicked(bool)),this,SLOT(get_three_23_picture()));
    connect(ui->pushButton_snapshot_three_24,SIGNAL(clicked(bool)),this,SLOT(get_three_24_picture()));
    connect(ui->pushButton_snapshot_four_1,SIGNAL(clicked(bool)),this,SLOT(get_four_1_picture()));
    connect(ui->pushButton_snapshot_four_2,SIGNAL(clicked(bool)),this,SLOT(get_four_2_picture()));
    connect(ui->pushButton_snapshot_four_3,SIGNAL(clicked(bool)),this,SLOT(get_four_3_picture()));
    connect(ui->pushButton_snapshot_four_4,SIGNAL(clicked(bool)),this,SLOT(get_four_4_picture()));
    connect(ui->pushButton_snapshot_four_5,SIGNAL(clicked(bool)),this,SLOT(get_four_5_picture()));
    connect(ui->pushButton_snapshot_four_6,SIGNAL(clicked(bool)),this,SLOT(get_four_6_picture()));
    connect(ui->pushButton_snapshot_four_7,SIGNAL(clicked(bool)),this,SLOT(get_four_7_picture()));
    connect(ui->pushButton_snapshot_four_8,SIGNAL(clicked(bool)),this,SLOT(get_four_8_picture()));
    connect(ui->pushButton_snapshot_four_9,SIGNAL(clicked(bool)),this,SLOT(get_four_9_picture()));
    connect(ui->pushButton_snapshot_four_10,SIGNAL(clicked(bool)),this,SLOT(get_four_10_picture()));
    connect(ui->pushButton_snapshot_four_11,SIGNAL(clicked(bool)),this,SLOT(get_four_11_picture()));
    connect(ui->pushButton_snapshot_four_12,SIGNAL(clicked(bool)),this,SLOT(get_four_12_picture()));
    connect(ui->pushButton_snapshot_four_13,SIGNAL(clicked(bool)),this,SLOT(get_four_13_picture()));
    connect(ui->pushButton_snapshot_four_14,SIGNAL(clicked(bool)),this,SLOT(get_four_14_picture()));
    connect(ui->pushButton_snapshot_four_15,SIGNAL(clicked(bool)),this,SLOT(get_four_15_picture()));
    connect(ui->pushButton_snapshot_four_16,SIGNAL(clicked(bool)),this,SLOT(get_four_16_picture()));
    connect(ui->pushButton_snapshot_four_17,SIGNAL(clicked(bool)),this,SLOT(get_four_17_picture()));
    connect(ui->pushButton_snapshot_four_18,SIGNAL(clicked(bool)),this,SLOT(get_four_18_picture()));
    connect(ui->pushButton_snapshot_four_19,SIGNAL(clicked(bool)),this,SLOT(get_four_19_picture()));
    connect(ui->pushButton_snapshot_four_20,SIGNAL(clicked(bool)),this,SLOT(get_four_20_picture()));
    connect(ui->pushButton_snapshot_four_21,SIGNAL(clicked(bool)),this,SLOT(get_four_21_picture()));
    connect(ui->pushButton_snapshot_four_22,SIGNAL(clicked(bool)),this,SLOT(get_four_22_picture()));
    connect(ui->pushButton_snapshot_four_23,SIGNAL(clicked(bool)),this,SLOT(get_four_23_picture()));
    connect(ui->pushButton_snapshot_four_24,SIGNAL(clicked(bool)),this,SLOT(get_four_24_picture()));
    connect(ui->pushButton_snapshot_five_1,SIGNAL(clicked(bool)),this,SLOT(get_five_1_picture()));
    connect(ui->pushButton_snapshot_five_2,SIGNAL(clicked(bool)),this,SLOT(get_five_2_picture()));
    connect(ui->pushButton_snapshot_five_3,SIGNAL(clicked(bool)),this,SLOT(get_five_3_picture()));
    connect(ui->pushButton_snapshot_five_4,SIGNAL(clicked(bool)),this,SLOT(get_five_4_picture()));
    connect(ui->pushButton_snapshot_five_5,SIGNAL(clicked(bool)),this,SLOT(get_five_5_picture()));
    connect(ui->pushButton_snapshot_five_6,SIGNAL(clicked(bool)),this,SLOT(get_five_6_picture()));
    connect(ui->pushButton_snapshot_five_7,SIGNAL(clicked(bool)),this,SLOT(get_five_7_picture()));
    connect(ui->pushButton_snapshot_five_8,SIGNAL(clicked(bool)),this,SLOT(get_five_8_picture()));
    connect(ui->pushButton_snapshot_five_9,SIGNAL(clicked(bool)),this,SLOT(get_five_9_picture()));
    connect(ui->pushButton_snapshot_five_10,SIGNAL(clicked(bool)),this,SLOT(get_five_10_picture()));
    connect(ui->pushButton_snapshot_five_11,SIGNAL(clicked(bool)),this,SLOT(get_five_11_picture()));
    connect(ui->pushButton_snapshot_five_12,SIGNAL(clicked(bool)),this,SLOT(get_five_12_picture()));
    connect(ui->pushButton_snapshot_five_13,SIGNAL(clicked(bool)),this,SLOT(get_five_13_picture()));
    connect(ui->pushButton_snapshot_five_14,SIGNAL(clicked(bool)),this,SLOT(get_five_14_picture()));
    connect(ui->pushButton_snapshot_five_15,SIGNAL(clicked(bool)),this,SLOT(get_five_15_picture()));
    connect(ui->pushButton_snapshot_five_16,SIGNAL(clicked(bool)),this,SLOT(get_five_16_picture()));
    connect(ui->pushButton_snapshot_five_17,SIGNAL(clicked(bool)),this,SLOT(get_five_17_picture()));
    connect(ui->pushButton_snapshot_five_18,SIGNAL(clicked(bool)),this,SLOT(get_five_18_picture()));
    connect(ui->pushButton_snapshot_five_19,SIGNAL(clicked(bool)),this,SLOT(get_five_19_picture()));
    connect(ui->pushButton_snapshot_five_20,SIGNAL(clicked(bool)),this,SLOT(get_five_20_picture()));
    connect(ui->pushButton_snapshot_five_21,SIGNAL(clicked(bool)),this,SLOT(get_five_21_picture()));
    connect(ui->pushButton_snapshot_five_22,SIGNAL(clicked(bool)),this,SLOT(get_five_22_picture()));
    connect(ui->pushButton_snapshot_five_23,SIGNAL(clicked(bool)),this,SLOT(get_five_23_picture()));
    connect(ui->pushButton_snapshot_five_24,SIGNAL(clicked(bool)),this,SLOT(get_five_24_picture()));

    load_snapshot_pictures();

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
    periodic_timer->setInterval(500);
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

    if(0){
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
