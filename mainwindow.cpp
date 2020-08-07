#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_ann.h"

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

    connect(ui->pushButton_76800_1024_1024_6_random_initilize,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_random_initilize_handler()));
    connect(ui->pushButton_76800_1024_1024_6_train,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_train_handler()));
    connect(ui->pushButton_76800_1024_1024_6_test,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_test_handler()));
    connect(ui->pushButton_76800_1024_1024_6_save_weights,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_save_weights_handler()));
    connect(ui->pushButton_76800_1024_1024_6_load_saved_weights,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_load_saved_weights_handler()));
    connect(ui->pushButton_76800_1024_1024_6_stop_train,SIGNAL(clicked(bool)),this,SLOT(_76800_1024_1024_6_stop_train_handler()));

    periodic_timer = new QTimer(this);
    periodic_timer->setInterval(200);
    //periodic_timer->start();

    read_money_values();

}
void MainWindow::read_money_values(void){
    QFile file("/home/ahmet/Desktop/waveform.csv");
    file.open(QIODevice::ReadOnly);

    u32 line_no = 0;

    file.readLine(); //this is dummy
    while (!file.atEnd()) {
        QString str = file.readLine();
        QString str1 = str.section(',',0,0);
        QString str2 = str.section(',',1,1);

        ann_class->index_no[line_no]     = str1.toInt();
        ann_class->waveform[line_no]     = str2.toDouble();

        line_no++;
    }

    for(u32 i = 0; i < line_no; i++){
        qDebug()    << QString("index_no : %1") .arg(ann_class->index_no[i])
                    << QString("waveform : %1") .arg(ann_class->waveform[i]);
    }

    for(u32 i = 0; i < WAVE_LENGTH; i++){
        ann_class->net_76800_1024_1024_6.input[WAVE_LENGTH*0 + i] = ann_class->index_no[i];
        ann_class->net_76800_1024_1024_6.input[WAVE_LENGTH*1 + i] = ann_class->waveform[i];
    }

    ann_class->net_76800_1024_1024_6.desired_output[0] = OUTPUT_MULTIPLIER * ann_class->waveform[WAVE_LENGTH];
    ann_class->net_76800_1024_1024_6.desired_output[1] = OUTPUT_MULTIPLIER * ann_class->waveform[WAVE_LENGTH + 1];
    ann_class->net_76800_1024_1024_6.desired_output[2] = OUTPUT_MULTIPLIER * ann_class->waveform[WAVE_LENGTH + 2];

    qDebug()    << QString("index_no : %1") .arg(ann_class->net_76800_1024_1024_6.input[WAVE_LENGTH*0])
                << QString("waveform : %1") .arg(ann_class->net_76800_1024_1024_6.input[WAVE_LENGTH*1]);
}
void MainWindow::mousePressEvent(QMouseEvent *event){
}

void MainWindow::_100_msec_timer_handle(void){
    static u32 old_epoch = 0;
    static double old_err = 0;

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
                                                            arg(ann_class->net_76800_1024_1024_6.w_hidden_30_to_output[0][0]));
        ui->label_76800_1024_1024_6_train_status_4->setText(QString("max_err : %1 , inset : %2").
                                                            arg(ann_class->net_76800_1024_1024_6.max_error).
                                                            arg(ann_class->net_76800_1024_1024_6.max_error_inset_no));

        if(ann_class->epoch_no != old_epoch){
            qDebug() << QString("total err-%1 :").arg(ann_class->epoch_no) << ann_class->net_76800_1024_1024_6.total_err
                     << "\t\t" << "diff :" << old_err - ann_class->net_76800_1024_1024_6.total_err;
            old_err = ann_class->net_76800_1024_1024_6.total_err;
        }

        old_epoch = ann_class->epoch_no;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
