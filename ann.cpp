#include "ann.h"
#include "mainwindow.h"
#include "ui_ann.h"
#include "ui_mainwindow.h"

ann::ann(MainWindow *master, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ann)
{
    ui->setupUi(this);
    mainwindow = master;

    thread_1 = new QThread(this);
    thread_timer = new QTimer(0); //parent must be null
    thread_timer->setInterval(100);
    thread_timer->moveToThread(thread_1);
    connect(thread_timer, SIGNAL(timeout()), SLOT(thread_handler()), Qt::DirectConnection);
    QObject::connect(thread_1, SIGNAL(started()), thread_timer, SLOT(start()));
    thread_1->start();

    stop_the_training = 0;

    periodic_timer = new QTimer(this);
    periodic_timer->setInterval(100);
    //periodic_timer->start();

    //this->show();

}
void ann::thread_handler(void){
    if(train_status == 1){
        _76800_1024_1024_6_ann_train(   net_76800_1024_1024_6.input,
                                        net_76800_1024_1024_6.desired_output,
                                        net_76800_1024_1024_6.calculated_output,
                                        net_76800_1024_1024_6.hidden_neuron_bias_1,
                                        net_76800_1024_1024_6.hidden_neuron_bias_2,
                                        net_76800_1024_1024_6.hidden_neuron_bias_3,
                                        net_76800_1024_1024_6.hidden_neuron_bias_4,
                                        net_76800_1024_1024_6.hidden_neuron_bias_5,
                                        net_76800_1024_1024_6.output_bias,
                                        net_76800_1024_1024_6.w_input_to_hidden_1,
                                        net_76800_1024_1024_6.w_hidden_1_to_hidden_2,
                                        net_76800_1024_1024_6.w_hidden_2_to_hidden_3,
                                        net_76800_1024_1024_6.w_hidden_3_to_hidden_4,
                                        net_76800_1024_1024_6.w_hidden_4_to_hidden_5,
                                        net_76800_1024_1024_6.w_hidden_5_to_output,
                                        100000, 0.001);

        for(u32 i = 0; i < OUTPUT_COUNT; i++){
            qDebug() << QString("desired output[%1] : ").arg(i) << net_76800_1024_1024_6.desired_output[i] <<
                        QString("calculated output[%1] : ").arg(i) << net_76800_1024_1024_6.calculated_output[i];
        }

        double total_error = 0;
        double aux;

        for(u32 i = 0; i < OUTPUT_COUNT; i++){
            aux = net_76800_1024_1024_6.desired_output[i] - net_76800_1024_1024_6.calculated_output[i];
            //aux = aux * aux;
            total_error += fabs(aux);
        }

        mainwindow->ui->label_76800_1024_1024_6_train->setText(QString("Trained. Total err %1").arg(total_error));
        train_status = 0;
    }
}

ann::~ann()
{
    delete ui;
}
