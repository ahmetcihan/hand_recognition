#ifndef ANN_H
#define ANN_H

#include <QWidget>
#include <QThread>
#include <QtConcurrentRun>
#include <QTimer>
#include "my_macros.h"

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
        double input[INPUT_COUNT][IO_ARRAY_LENGTH*INPUT_SET];
        double desired_output[OUTPUT_COUNT][IO_ARRAY_LENGTH];
        double calculated_output[OUTPUT_COUNT][IO_ARRAY_LENGTH];
        double hidden_neuron_bias_1[HIDDEN_COUNT_1];
        double hidden_neuron_bias_2[HIDDEN_COUNT_2];
        double hidden_neuron_bias_3[HIDDEN_COUNT_3];
        double output_bias[OUTPUT_COUNT];
        double w_input_to_hidden_1[INPUT_COUNT][HIDDEN_COUNT_1];
        double w_hidden_1_to_hidden_2[HIDDEN_COUNT_1][HIDDEN_COUNT_2];
        double w_hidden_2_to_hidden_3[HIDDEN_COUNT_2][HIDDEN_COUNT_3];
        double w_hidden_3_to_output[HIDDEN_COUNT_3][OUTPUT_COUNT];
        double test_input[INPUT_COUNT];
        double total_err;
    };
    struct _76800_1024_1024_6_str net_76800_1024_1024_6;

    void _76800_1024_1024_6_ann_train(  double input[INPUT_COUNT][IO_ARRAY_LENGTH*INPUT_SET],
                                        double desired_output[OUTPUT_COUNT][IO_ARRAY_LENGTH], double calculated_output[OUTPUT_COUNT][IO_ARRAY_LENGTH],
                                        double hidden_neuron_bias_1[HIDDEN_COUNT_1],
                                        double hidden_neuron_bias_2[HIDDEN_COUNT_2],
                                        double hidden_neuron_bias_3[HIDDEN_COUNT_3],
                                        double output_bias[OUTPUT_COUNT],
                                        double w_input_to_hidden_1[INPUT_COUNT][HIDDEN_COUNT_1],
                                        double w_hidden_1_to_hidden_2[HIDDEN_COUNT_1][HIDDEN_COUNT_2],
                                        double w_hidden_2_to_hidden_3[HIDDEN_COUNT_2][HIDDEN_COUNT_3],
                                        double w_hidden_3_to_output[HIDDEN_COUNT_3][OUTPUT_COUNT],
                                        u32 epoch, double learning_rate);
    void _76800_1024_1024_6_ann_test(   double input[INPUT_COUNT],
                                        double hidden_neuron_bias_1[HIDDEN_COUNT_1],
                                        double hidden_neuron_bias_2[HIDDEN_COUNT_2],
                                        double hidden_neuron_bias_3[HIDDEN_COUNT_3],
                                        double output_bias[OUTPUT_COUNT],
                                        double w_input_to_hidden_1[INPUT_COUNT][HIDDEN_COUNT_1],
                                        double w_hidden_1_to_hidden_2[HIDDEN_COUNT_1][HIDDEN_COUNT_2],
                                        double w_hidden_2_to_hidden_3[HIDDEN_COUNT_2][HIDDEN_COUNT_3],
                                        double w_hidden_3_to_output[HIDDEN_COUNT_3][OUTPUT_COUNT]);
    double _76800_1024_1024_6_ann_calculate_total_error(void);

private:
    Ui::ann *ui;
    MainWindow *mainwindow;
    QTimer* thread_timer;

    double sigmoid_func(double val);
    double derivative_of_sigmoid_func(double val);
    double output_sigmoid_func(double val);
    double output_derivative_of_sigmoid_func(double val);


private slots:
    void thread_handler(void);

};

#endif // ANN_H
