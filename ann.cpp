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
                                        net_76800_1024_1024_6.hidden_neuron_bias_6,
                                        net_76800_1024_1024_6.hidden_neuron_bias_7,
                                        net_76800_1024_1024_6.hidden_neuron_bias_8,
                                        net_76800_1024_1024_6.hidden_neuron_bias_9,
                                        net_76800_1024_1024_6.hidden_neuron_bias_10,
                                        net_76800_1024_1024_6.hidden_neuron_bias_11,
                                        net_76800_1024_1024_6.hidden_neuron_bias_12,
                                        net_76800_1024_1024_6.hidden_neuron_bias_13,
                                        net_76800_1024_1024_6.hidden_neuron_bias_14,
                                        net_76800_1024_1024_6.hidden_neuron_bias_15,
                                        net_76800_1024_1024_6.hidden_neuron_bias_16,
                                        net_76800_1024_1024_6.hidden_neuron_bias_17,
                                        net_76800_1024_1024_6.hidden_neuron_bias_18,
                                        net_76800_1024_1024_6.hidden_neuron_bias_19,
                                        net_76800_1024_1024_6.hidden_neuron_bias_20,
                                        net_76800_1024_1024_6.hidden_neuron_bias_21,
                                        net_76800_1024_1024_6.hidden_neuron_bias_22,
                                        net_76800_1024_1024_6.hidden_neuron_bias_23,
                                        net_76800_1024_1024_6.hidden_neuron_bias_24,
                                        net_76800_1024_1024_6.hidden_neuron_bias_25,
                                        net_76800_1024_1024_6.hidden_neuron_bias_26,
                                        net_76800_1024_1024_6.hidden_neuron_bias_27,
                                        net_76800_1024_1024_6.hidden_neuron_bias_28,
                                        net_76800_1024_1024_6.hidden_neuron_bias_29,
                                        net_76800_1024_1024_6.hidden_neuron_bias_30,
                                        net_76800_1024_1024_6.output_bias,
                                        net_76800_1024_1024_6.w_input_to_hidden_1,
                                        net_76800_1024_1024_6.w_hidden_1_to_hidden_2,
                                        net_76800_1024_1024_6.w_hidden_2_to_hidden_3,
                                        net_76800_1024_1024_6.w_hidden_3_to_hidden_4,
                                        net_76800_1024_1024_6.w_hidden_4_to_hidden_5,
                                        net_76800_1024_1024_6.w_hidden_5_to_hidden_6,
                                        net_76800_1024_1024_6.w_hidden_6_to_hidden_7,
                                        net_76800_1024_1024_6.w_hidden_7_to_hidden_8,
                                        net_76800_1024_1024_6.w_hidden_8_to_hidden_9,
                                        net_76800_1024_1024_6.w_hidden_9_to_hidden_10,
                                        net_76800_1024_1024_6.w_hidden_10_to_hidden_11,
                                        net_76800_1024_1024_6.w_hidden_11_to_hidden_12,
                                        net_76800_1024_1024_6.w_hidden_12_to_hidden_13,
                                        net_76800_1024_1024_6.w_hidden_13_to_hidden_14,
                                        net_76800_1024_1024_6.w_hidden_14_to_hidden_15,
                                        net_76800_1024_1024_6.w_hidden_15_to_hidden_16,
                                        net_76800_1024_1024_6.w_hidden_16_to_hidden_17,
                                        net_76800_1024_1024_6.w_hidden_17_to_hidden_18,
                                        net_76800_1024_1024_6.w_hidden_18_to_hidden_19,
                                        net_76800_1024_1024_6.w_hidden_19_to_hidden_20,
                                        net_76800_1024_1024_6.w_hidden_20_to_hidden_21,
                                        net_76800_1024_1024_6.w_hidden_21_to_hidden_22,
                                        net_76800_1024_1024_6.w_hidden_22_to_hidden_23,
                                        net_76800_1024_1024_6.w_hidden_23_to_hidden_24,
                                        net_76800_1024_1024_6.w_hidden_24_to_hidden_25,
                                        net_76800_1024_1024_6.w_hidden_25_to_hidden_26,
                                        net_76800_1024_1024_6.w_hidden_26_to_hidden_27,
                                        net_76800_1024_1024_6.w_hidden_27_to_hidden_28,
                                        net_76800_1024_1024_6.w_hidden_28_to_hidden_29,
                                        net_76800_1024_1024_6.w_hidden_29_to_hidden_30,
                                        net_76800_1024_1024_6.w_hidden_30_to_output,
                                        1000000, 0.001);

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
