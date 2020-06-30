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
    QFile file("/home/ahmet/Desktop/inputs.csv");
    file.open(QIODevice::ReadOnly);

    QByteArray line;
    u32 line_no = 0;
    u32 number[140];
    double dollar[140];
    double euro[140];
    double sterlin[140];
    double yen[140];
    double bist[140];
    double altin[140];
    double petrol[140];
    double faiz[140];

    file.readLine(); //this is dummy
    while (!file.atEnd()) {
        QString str = file.readLine();
        QString str1 = str.section(',',0,0);
        QString str2 = str.section(',',2,2);
        QString str3 = str.section(',',3,3);
        QString str4 = str.section(',',4,4);
        QString str5 = str.section(',',5,5);
        QString str6 = str.section(',',6,6);
        QString str7 = str.section(',',7,7);
        QString str8 = str.section(',',8,8);
        QString str9 = str.section(',',9,9);

        number[line_no] = str1.toInt();
        dollar[line_no] = str2.toDouble();
        euro[line_no] = str3.toDouble();
        sterlin[line_no] = str4.toDouble();
        yen[line_no] = str5.toDouble();
        bist[line_no] = str6.toDouble();
        altin[line_no] = str7.toDouble();
        petrol[line_no] = str8.toDouble();
        faiz[line_no] = str9.toDouble();
        line_no++;
    }

    for(u32 i = 0; i < line_no; i++){
        qDebug() << QString("no : %1").arg(number[i]) << QString("dollar : %1").arg(dollar[i])
                 << QString("euro : %1").arg(euro[i]) << QString("sterlin : %1").arg(sterlin[i])
                 << QString("yen : %1").arg(yen[i]) << QString("bist : %1").arg(bist[i])
                 << QString("altin : %1").arg(altin[i]) << QString("petrol : %1").arg(petrol[i]) << QString("faiz : %1").arg(faiz[i]);
    }

}
void MainWindow::mousePressEvent(QMouseEvent *event){
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
