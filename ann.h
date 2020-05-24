#ifndef ANN_H
#define ANN_H

#include <QWidget>
#include <QThread>
#include <QtConcurrentRun>
#include <QTimer>

namespace Ui {
class ann;
}
class MainWindow;

typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;

class ann : public QWidget
{
    Q_OBJECT

public:
    explicit ann(MainWindow *master, QWidget *parent = 0);
    ~ann();
    QThread *thread_1;

    u8 train_status;
    u8 epoch_status;
    u32 epoch_no;
    u8 stop_the_training;


    struct _76800_1024_1024_6_str{
        double input[76800][6];
        double desired_output[6][6];
        double calculated_output[6][6];
        double hidden_neuron_bias_1[1024];
        double hidden_neuron_bias_2[1024];
        double output_bias[6];
        double w_input_to_hidden[76800][1024];
        double w_hidden_to_hidden[1024][1024];
        double w_hidden_to_output[1024][6];
        double test_input[76800];
        double total_err;
    };
    struct _76800_1024_1024_6_str net_76800_1024_1024_6;

    void _76800_1024_1024_6_ann_train(double input[76800][6], double desired_output[6][6], double calculated_output[6][6],
                                double hidden_neuron_bias_1[1024], double hidden_neuron_bias_2[1024], double output_bias[6],
                                double w_input_to_hidden[76800][1024], double w_hidden_to_hidden[1024][1024], double w_hidden_to_output[1024][6],
                                u32 epoch, double learning_rate);
    void _76800_1024_1024_6_ann_test(  double input[76800],
                                    double hidden_neuron_bias_1[1024], double hidden_neuron_bias_2[1024], double output_bias[6],
                                    double w_input_to_hidden[76800][1024], double w_hidden_to_hidden[1024][1024], double w_hidden_to_output[1024][6]);
    double _76800_1024_1024_6_ann_calculate_total_error(void);

private:
    Ui::ann *ui;
    MainWindow *mainwindow;
    QTimer* thread_timer;

    double sigmoid_func(double val);
    double derivative_of_sigmoid_func(double val);


private slots:
    void thread_handler(void);

};

#endif // ANN_H
