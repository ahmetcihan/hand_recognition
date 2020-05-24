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

}
void MainWindow::_100_msec_timer_handle(void){
    if(ann_class->train_status == 1){
        ui->label_76800_1024_1024_6_train->setText(QString("training status %  %1").arg(ann_class->epoch_status));
        ui->label_76800_1024_1024_6_train_status->setText(QString("Epoch : %1 , Error : %2 , ob-0 : %3").
                                                        arg(ann_class->epoch_no).arg(ann_class->_76800_1024_1024_6_ann_calculate_total_error()).
                                                        arg(ann_class->net_76800_1024_1024_6.output_bias[0]));
        ui->label_76800_1024_1024_6_train_status_2->setText(QString("hb1-0 : %1 , hb2-0 : %2 , wh2h-0 : %3").
                                                        arg(ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1[0]).
                                                        arg(ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[0]).
                                                        arg(ann_class->net_76800_1024_1024_6.w_hidden_to_hidden[0][0]));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
