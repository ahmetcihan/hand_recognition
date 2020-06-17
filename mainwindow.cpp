#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_ann.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ann_class = new ann(this);

    load_filter_parameters();

    connect(ui->pushButton_snapshot_fist,SIGNAL(clicked(bool)), this,SLOT(get_fist_picture()));
    connect(ui->pushButton_snapshot_stop,SIGNAL(clicked(bool)), this,SLOT(get_stop_picture()));
    connect(ui->pushButton_snapshot_up,SIGNAL(clicked(bool)),   this,SLOT(get_up_picture()));
    connect(ui->pushButton_snapshot_left,SIGNAL(clicked(bool)), this,SLOT(get_left_picture()));
    connect(ui->pushButton_snapshot_right,SIGNAL(clicked(bool)),this,SLOT(get_right_picture()));
    connect(ui->pushButton_snapshot_five,SIGNAL(clicked(bool)), this,SLOT(get_five_picture()));

    connect(ui->pushButton_snapshot_fist_automatic,SIGNAL(clicked(bool)), this,SLOT(get_fist_picture_automatic()));
    connect(ui->pushButton_snapshot_stop_automatic,SIGNAL(clicked(bool)), this,SLOT(get_stop_picture_automatic()));
    connect(ui->pushButton_snapshot_up_automatic,SIGNAL(clicked(bool)),   this,SLOT(get_up_picture_automatic()));
    connect(ui->pushButton_snapshot_left_automatic,SIGNAL(clicked(bool)), this,SLOT(get_left_picture_automatic()));
    connect(ui->pushButton_snapshot_right_automatic,SIGNAL(clicked(bool)),this,SLOT(get_right_picture_automatic()));
    connect(ui->pushButton_snapshot_five_automatic,SIGNAL(clicked(bool)), this,SLOT(get_five_picture_automatic()));

    _100_msec_timer = new QTimer(this);
    _100_msec_timer->setInterval(1000);
    _100_msec_timer->start();
    connect(this->_100_msec_timer,SIGNAL(timeout()),this,SLOT(_100_msec_timer_handle()));

    connect(ui->pushButton_76800_1024_1024_6_prepare_io,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_prepare_io_pairs_handler()));
    connect(ui->pushButton_76800_1024_1024_6_random_initilize,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_random_initilize_handler()));
    connect(ui->pushButton_76800_1024_1024_6_train,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_train_handler()));
    connect(ui->pushButton_76800_1024_1024_6_test,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_test_handler()));
    connect(ui->pushButton_76800_1024_1024_6_save_weights,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_save_weights_handler()));
    connect(ui->pushButton_76800_1024_1024_6_load_saved_weights,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_load_saved_weights_handler()));
    connect(ui->pushButton_76800_1024_1024_6_stop_train,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_stop_train_handler()));

    periodic_timer = new QTimer(this);
    periodic_timer->setInterval(200);
    connect(periodic_timer,SIGNAL(timeout()),this,SLOT(capture_video()));
    //periodic_timer->start();
    connect(ui->pushButton_start_stream,SIGNAL(clicked(bool)),this,SLOT(start_stream()));

    connect(ui->pushButton_shot,SIGNAL(clicked(bool)),this,SLOT(capture_video()));
    connect(ui->pushButton_select_tester,SIGNAL(clicked(bool)), this,SLOT(select_tester_file()));

    //my_vid.open("/dev/video0");
    my_vid.open(0);

    //image_manipulation();

}
void MainWindow::image_manipulation(void){
    /*
     * ///////monochrome save////////////////////////
    QImage read_image;
    QImage manipulated_image(40,30,QImage::Format_Mono);

    for(u8 k = 1; k < 121 ; k++){
        read_image.load(QString("/home/ahmet/Desktop/gloves/up/up_%1.jpg").arg(k));

        for(u8 i = 0; i < read_image.width();i++){
            for(u8 j = 0; j < read_image.height();j++){
                if((read_image.pixel(i,j) & 0xFF) < 128){
                    manipulated_image.setPixel(i,j,0);
                }
                else{
                    manipulated_image.setPixel(i,j,1);

                }
            }
        }

        manipulated_image.save(QString("/home/ahmet/Desktop/gloves/up/up_%1.jpg").arg(k),0,100);
    }
    */
    /*
    ////////////Align left////////////
    QImage read_image;
    QImage manipulated_image(40,30,QImage::Format_RGB888);
    u32 first_row;
    u8 point_detected = 0;

    for(u8 k = 1; k < 121 ; k++){
        first_row = 0;
        point_detected = 0;
        read_image.load(QString("/home/ahmet/Desktop/gloves/up/up_%1.jpg").arg(k));

        for(u8 i = 0; i < read_image.width();i++){
            for(u8 j = 0; j < read_image.height();j++){
                manipulated_image.setPixel(i,j,qRgb(255,255,255));
                if((read_image.pixel(i,j) & 0xFF) < 128){
                    if(point_detected == 0){
                        point_detected = 1;
                        first_row = i;
                    }
                }
            }
        }
        for(u8 i = (first_row-1); i < read_image.width();i++){
            for(u8 j = 0; j < read_image.height();j++){
                manipulated_image.setPixel(i-(first_row-1),j,read_image.pixel(i,j));
            }
        }
        manipulated_image.save(QString("/home/ahmet/Desktop/gloves/up/up_%1.jpg").arg(k),0,100);
    }
    */

    /*
    QImage read_image;
    QImage manipulated_image(40,30,QImage::Format_RGB888);
    u32 first_row;
    u8 point_detected = 0;

    read_image.load("/home/ahmet/Desktop/gloves/five/five_63.jpg");

    QPixmap my_pix = QPixmap::fromImage(read_image);
    ui->label_small_image->setPixmap(my_pix);

    for(u8 i = 0; i < read_image.width();i++){
        for(u8 j = 0; j < read_image.height();j++){
            manipulated_image.setPixel(i,j,qRgb(255,255,255));
            if((read_image.pixel(i,j) & 0xFF) < 128){
                if(point_detected == 0){
                    point_detected = 1;
                    first_row = i;
                }
            }
        }
    }

    for(u8 i = (first_row-1); i < read_image.width();i++){
        for(u8 j = 0; j < read_image.height();j++){
            manipulated_image.setPixel(i-(first_row-1),j,read_image.pixel(i,j));
        }
    }


    QPixmap manipulated_pix = QPixmap::fromImage(manipulated_image);
    ui->label_small_image_manipulated->setPixmap(manipulated_pix);

    manipulated_image.save(QString("/home/ahmet/Desktop/denemci.jpg"),0,100);
    */
}
void MainWindow::select_tester_file(void){
    tester_file_name = QFileDialog::getOpenFileName(this,"Open Test File","/home/ahmet/Desktop/gloves/",("Images (*.jpg)"));
    qDebug() << "file name" << tester_file_name;
}

void MainWindow::start_stream(void){
    periodic_timer->start();
}
void MainWindow::capture_video(void){
    static QElapsedTimer my_elapsed_timer;

    my_elapsed_timer.restart();

    //get original frame
    cv::Mat original_frame;
    my_vid >> original_frame;
    cv::cvtColor(original_frame,original_frame,CV_BGR2RGB);
    //qDebug() << "fps" << my_vid.get(CV_CAP_PROP_FPS) << "width" << my_vid.get(CV_CAP_PROP_FRAME_WIDTH) << "height" << my_vid.get(CV_CAP_PROP_FRAME_HEIGHT);

    //resize original frame
    cv::resize(original_frame,original_frame, cv::Size(320,240),0,0,CV_INTER_LINEAR);

    QImage my_image((uchar*)original_frame.data, original_frame.cols, original_frame.rows, original_frame.step, QImage::Format_RGB888);
    QImage momochrome((uchar*)original_frame.data, original_frame.cols, original_frame.rows, original_frame.step, QImage::Format_RGB888);
    QPixmap original_pix = QPixmap::fromImage(my_image);

    ui->label_video->setPixmap(original_pix);
    ui->label_video_original_2->setPixmap(original_pix);
    //qDebug() << "color" << QColor(my_image.pixel(160,120)).red() << QColor(my_image.pixel(160,120)).green() << QColor(my_image.pixel(160,120)).blue();

    //change to monocrome
    for(u16 i = 0; i < my_image.width(); i++){
        for(u16 j = 0; j < my_image.height(); j++){
            if((QColor(my_image.pixel(i,j)).red() >= ui->spinBox_red_min->value()) && (QColor(my_image.pixel(i,j)).red() <= ui->spinBox_red_max->value()) &&
               (QColor(my_image.pixel(i,j)).green() >= ui->spinBox_green_min->value()) && (QColor(my_image.pixel(i,j)).green() <= ui->spinBox_green_max->value()) &&
               (QColor(my_image.pixel(i,j)).blue() >= ui->spinBox_blue_min->value()) && (QColor(my_image.pixel(i,j)).blue() <= ui->spinBox_blue_max->value())){
                momochrome.setPixel(i,j,qRgb(0,0,0));
            }
            else{
                momochrome.setPixel(i,j,qRgb(255,255,255));
            }
        }
    }

    ui->label_video_monocrome->setPixmap(QPixmap::fromImage(momochrome));
    ui->label_video_monocrome_2->setPixmap(QPixmap::fromImage(momochrome));

    //change to small_scale
    QImage small_scale;
    small_scale = momochrome.scaled(QSize(40,30),Qt::KeepAspectRatio,Qt::FastTransformation);

    //Align left
    QImage align_left_image(40,30,QImage::Format_RGB888);
    u32 first_row = 0;
    u8 point_detected = 0;

    first_row = 0;
    point_detected = 0;

    for(u8 i = 0; i < small_scale.width();i++){
        for(u8 j = 0; j < small_scale.height();j++){
            align_left_image.setPixel(i,j,qRgb(255,255,255));
            if((small_scale.pixel(i,j) & 0xFF) < 128){
                if(point_detected == 0){
                    point_detected = 1;
                    first_row = i;
                }
            }
        }
    }
    QImage test_image;
    QPixmap small_picture;

    if(first_row > 0){
        for(u8 i = (first_row-1); i < small_scale.width();i++){
            for(u8 j = 0; j < small_scale.height();j++){
                align_left_image.setPixel(i-(first_row-1),j,small_scale.pixel(i,j));
            }
        }
        small_picture = QPixmap::fromImage(align_left_image);
        test_image = align_left_image;
    }
    else{
        small_picture = QPixmap::fromImage(small_scale);
        test_image = small_scale;
    }


    ui->label_video_small_monochrome->setPixmap(small_picture);
    ui->label_video_small_monochrome_2->setPixmap(small_picture);
    ui->label_video_small_monochrome_3->setPixmap(small_picture);
    ui->label_hand_two->setPixmap(small_picture);

    original_frame.release();

    // push into ANN
    if(1){
        u8 tester[40][30];


        for(u8 i = 0; i < test_image.width();i++){
            for(u8 j = 0; j < test_image.height();j++){
                if((test_image.pixel(i,j) & 0xFF) < 128){
                    tester[i][j] = 0;
                }
                else{
                    tester[i][j] = 1;
                }
            }
        }


        for(u32 j = 0; j < 30; j++){
            for(u32 i = 0; i < 40; i++){
                ann_class->net_76800_1024_1024_6.test_input[i + 40*j] = tester[i][j];
            }
        }

        ann_class->_76800_1024_1024_6_ann_test( ann_class->net_76800_1024_1024_6.test_input,
                                                ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1,
                                                ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2,
                                                ann_class->net_76800_1024_1024_6.hidden_neuron_bias_3,
                                                ann_class->net_76800_1024_1024_6.hidden_neuron_bias_4,
                                                ann_class->net_76800_1024_1024_6.hidden_neuron_bias_5,
                                                ann_class->net_76800_1024_1024_6.output_bias,
                                                ann_class->net_76800_1024_1024_6.w_input_to_hidden_1,
                                                ann_class->net_76800_1024_1024_6.w_hidden_1_to_hidden_2,
                                                ann_class->net_76800_1024_1024_6.w_hidden_2_to_hidden_3,
                                                ann_class->net_76800_1024_1024_6.w_hidden_3_to_hidden_4,
                                                ann_class->net_76800_1024_1024_6.w_hidden_4_to_hidden_5,
                                                ann_class->net_76800_1024_1024_6.w_hidden_5_to_output);
    }


    qDebug() << "elapsed time" << my_elapsed_timer.elapsed();
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
        ui->label_76800_1024_1024_6_train_status_3->setText(QString("wh122-0 : %1 , wh223-0 : %2 , wh52o-0 : %3").
                                                            arg(ann_class->net_76800_1024_1024_6.w_hidden_1_to_hidden_2[0][0]).
                                                            arg(ann_class->net_76800_1024_1024_6.w_hidden_2_to_hidden_3[0][0]).
                                                            arg(ann_class->net_76800_1024_1024_6.w_hidden_5_to_output[0][0]));
        ui->label_76800_1024_1024_6_train_status_4->setText(QString("max_err : %1 , inset : %2").
                                                            arg(ann_class->net_76800_1024_1024_6.max_error).
                                                            arg(ann_class->net_76800_1024_1024_6.max_error_inset_no));
    }
}
void MainWindow::save_filter_parameters(void){
    QSettings settings("filter_parameters.ini",QSettings::IniFormat);

    settings.beginGroup("f");

    settings.setValue("red_min",ui->spinBox_red_min->value());
    settings.setValue("red_max",ui->spinBox_red_max->value());
    settings.setValue("green_min",ui->spinBox_green_min->value());
    settings.setValue("green_max",ui->spinBox_green_max->value());
    settings.setValue("blue_min",ui->spinBox_blue_min->value());
    settings.setValue("blue_max",ui->spinBox_blue_max->value());
    settings.endGroup();
    settings.sync();

}
void MainWindow::load_filter_parameters(void){
    QSettings settings("filter_parameters.ini",QSettings::IniFormat);

    ui->spinBox_red_min->setValue(settings.value("f/red_min").toInt());
    ui->spinBox_red_max->setValue(settings.value("f/red_max").toInt());
    ui->spinBox_green_min->setValue(settings.value("f/green_min").toInt());
    ui->spinBox_green_max->setValue(settings.value("f/green_max").toInt());
    ui->spinBox_blue_min->setValue(settings.value("f/blue_min").toInt());
    ui->spinBox_blue_max->setValue(settings.value("f/blue_max").toInt());

}
MainWindow::~MainWindow()
{
    save_filter_parameters();
    delete ui;
}
