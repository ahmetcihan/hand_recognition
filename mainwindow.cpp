#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_ann.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ann_class = new ann(this);

    connect(ui->pushButton_snapshot_object_automatic,SIGNAL(clicked(bool)), this,SLOT(get_object_picture_automatic()));

    _100_msec_timer = new QTimer(this);
    _100_msec_timer->setInterval(1000);
    _100_msec_timer->start();
    connect(this->_100_msec_timer,SIGNAL(timeout()),this,SLOT(_100_msec_timer_handle()));

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

    image_manipulation();

    //setMouseTracking(true);

}
void MainWindow::mousePressEvent(QMouseEvent *event){
    qDebug() << "x-pos" << event->pos().x() << "y-pos" << event->pos().y();
}

void MainWindow::image_manipulation(void){
    /*
    QImage read_image;
    read_image.load("/home/ahmet/Desktop/gloves/fist/fist_1.jpg");

    QPainter my_painter(&read_image);

    my_painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    my_painter.setRenderHints(QPainter::HighQualityAntialiasing);
    my_painter.setBrush(Qt::red);
    my_painter.setPen(QPen(Qt::yellow,3.0));
    my_painter.drawEllipse(QPoint(20,20),10,10);
    my_painter.end();


    QPixmap my_pix = QPixmap::fromImage(read_image);

    ui->label_small_image->setPixmap(my_pix);
    */

    /*
     * ///////monochrome save////////////////////////
    QImage read_image;
    QImage manipulated_image(80,60,QImage::Format_Mono);

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
    QImage manipulated_image(80,60,QImage::Format_RGB888);
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
    QImage manipulated_image(80,60,QImage::Format_RGB888);
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
    QPixmap original_pix = QPixmap::fromImage(my_image);

    ui->label_video->setPixmap(original_pix);
    ui->label_video_original_2->setPixmap(original_pix);
    ui->label_video_greyscale_2->setPixmap(original_pix);

    //change to small_scale
    QImage small_scale;
    small_scale = my_image.scaled(QSize(80,60),Qt::KeepAspectRatio,Qt::SmoothTransformation);

    QPixmap small_picture;
    small_picture = QPixmap::fromImage(small_scale);

    ui->label_video_small_monochrome_2->setPixmap(small_picture);
    ui->label_video_small_monochrome_3->setPixmap(small_picture);

    original_frame.release();

    // push into ANN
    if(1){
        u8 tester[80][60][3];

        for(u8 i = 0; i < small_scale.width();i++){
            for(u8 j = 0; j < small_scale.height();j++){
                tester[i][j][0] = QColor(small_scale.pixel(i,j)).red();
                tester[i][j][1] = QColor(small_scale.pixel(i,j)).green();
                tester[i][j][2] = QColor(small_scale.pixel(i,j)).blue();
            }
        }

        for(u32 j = 0; j < 60; j++){
            for(u32 i = 0; i < 80; i++){
                ann_class->net_76800_1024_1024_6.test_input[3*(i + 80*j) + 0] = (double)tester[i][j][0]/255;
                ann_class->net_76800_1024_1024_6.test_input[3*(i + 80*j) + 1] = (double)tester[i][j][1]/255;
                ann_class->net_76800_1024_1024_6.test_input[3*(i + 80*j) + 2] = (double)tester[i][j][2]/255;
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
    //ann_class->start_animation = 1;
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
MainWindow::~MainWindow()
{
    delete ui;
}
