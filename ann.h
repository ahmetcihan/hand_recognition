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

    QTimer *periodic_timer;

    u8 train_status;
    u8 epoch_status;
    u32 epoch_no;
    u8 stop_the_training;

    double  dollar  [3000];
    double  euro    [3000];
    double  yen     [3000];
    double  sterlin [3000];
    double  altin   [3000];
    double  petrol  [3000];
    double  bist_100[3000];
    double  faiz    [3000];
    double  dollar_index    [3000];
    double  ay      [3000];
    double  yil     [3000];
    double  tatil   [3000];


    struct _76800_1024_1024_6_str{
        double input[INPUT_COUNT];
        double desired_output[OUTPUT_COUNT];
        double calculated_output[OUTPUT_COUNT];
        double hidden_neuron_bias_1[HIDDEN_COUNT_1];
        double hidden_neuron_bias_2[HIDDEN_COUNT_2];
        double hidden_neuron_bias_3[HIDDEN_COUNT_3];
        double hidden_neuron_bias_4[HIDDEN_COUNT_4];
        double hidden_neuron_bias_5[HIDDEN_COUNT_5];
        double hidden_neuron_bias_6[HIDDEN_COUNT_6];
        double hidden_neuron_bias_7[HIDDEN_COUNT_7];
        double hidden_neuron_bias_8[HIDDEN_COUNT_8];
        double hidden_neuron_bias_9[HIDDEN_COUNT_9];
        double hidden_neuron_bias_10[HIDDEN_COUNT_10];
        double hidden_neuron_bias_11[HIDDEN_COUNT_11];
        double hidden_neuron_bias_12[HIDDEN_COUNT_12];
        double hidden_neuron_bias_13[HIDDEN_COUNT_13];
        double hidden_neuron_bias_14[HIDDEN_COUNT_14];
        double hidden_neuron_bias_15[HIDDEN_COUNT_15];
        double hidden_neuron_bias_16[HIDDEN_COUNT_16];
        double hidden_neuron_bias_17[HIDDEN_COUNT_17];
        double hidden_neuron_bias_18[HIDDEN_COUNT_18];
        double hidden_neuron_bias_19[HIDDEN_COUNT_19];
        double hidden_neuron_bias_20[HIDDEN_COUNT_20];
        double hidden_neuron_bias_21[HIDDEN_COUNT_21];
        double hidden_neuron_bias_22[HIDDEN_COUNT_22];
        double hidden_neuron_bias_23[HIDDEN_COUNT_23];
        double hidden_neuron_bias_24[HIDDEN_COUNT_24];
        double hidden_neuron_bias_25[HIDDEN_COUNT_25];
        double hidden_neuron_bias_26[HIDDEN_COUNT_26];
        double hidden_neuron_bias_27[HIDDEN_COUNT_27];
        double hidden_neuron_bias_28[HIDDEN_COUNT_28];
        double hidden_neuron_bias_29[HIDDEN_COUNT_29];
        double hidden_neuron_bias_30[HIDDEN_COUNT_30];
        double output_bias[OUTPUT_COUNT];
        double w_input_to_hidden_1[INPUT_COUNT][HIDDEN_COUNT_1];
        double w_hidden_1_to_hidden_2[HIDDEN_COUNT_1][HIDDEN_COUNT_2];
        double w_hidden_2_to_hidden_3[HIDDEN_COUNT_2][HIDDEN_COUNT_3];
        double w_hidden_3_to_hidden_4[HIDDEN_COUNT_3][HIDDEN_COUNT_4];
        double w_hidden_4_to_hidden_5[HIDDEN_COUNT_4][HIDDEN_COUNT_5];
        double w_hidden_5_to_hidden_6[HIDDEN_COUNT_5][HIDDEN_COUNT_6];
        double w_hidden_6_to_hidden_7[HIDDEN_COUNT_6][HIDDEN_COUNT_7];
        double w_hidden_7_to_hidden_8[HIDDEN_COUNT_7][HIDDEN_COUNT_8];
        double w_hidden_8_to_hidden_9[HIDDEN_COUNT_8][HIDDEN_COUNT_9];
        double w_hidden_9_to_hidden_10[HIDDEN_COUNT_9][HIDDEN_COUNT_10];
        double w_hidden_10_to_hidden_11[HIDDEN_COUNT_10][HIDDEN_COUNT_11];
        double w_hidden_11_to_hidden_12[HIDDEN_COUNT_11][HIDDEN_COUNT_12];
        double w_hidden_12_to_hidden_13[HIDDEN_COUNT_12][HIDDEN_COUNT_13];
        double w_hidden_13_to_hidden_14[HIDDEN_COUNT_13][HIDDEN_COUNT_14];
        double w_hidden_14_to_hidden_15[HIDDEN_COUNT_14][HIDDEN_COUNT_15];
        double w_hidden_15_to_hidden_16[HIDDEN_COUNT_15][HIDDEN_COUNT_16];
        double w_hidden_16_to_hidden_17[HIDDEN_COUNT_16][HIDDEN_COUNT_17];
        double w_hidden_17_to_hidden_18[HIDDEN_COUNT_17][HIDDEN_COUNT_18];
        double w_hidden_18_to_hidden_19[HIDDEN_COUNT_18][HIDDEN_COUNT_19];
        double w_hidden_19_to_hidden_20[HIDDEN_COUNT_19][HIDDEN_COUNT_20];
        double w_hidden_20_to_hidden_21[HIDDEN_COUNT_20][HIDDEN_COUNT_21];
        double w_hidden_21_to_hidden_22[HIDDEN_COUNT_21][HIDDEN_COUNT_22];
        double w_hidden_22_to_hidden_23[HIDDEN_COUNT_22][HIDDEN_COUNT_23];
        double w_hidden_23_to_hidden_24[HIDDEN_COUNT_23][HIDDEN_COUNT_24];
        double w_hidden_24_to_hidden_25[HIDDEN_COUNT_24][HIDDEN_COUNT_25];
        double w_hidden_25_to_hidden_26[HIDDEN_COUNT_25][HIDDEN_COUNT_26];
        double w_hidden_26_to_hidden_27[HIDDEN_COUNT_26][HIDDEN_COUNT_27];
        double w_hidden_27_to_hidden_28[HIDDEN_COUNT_27][HIDDEN_COUNT_28];
        double w_hidden_28_to_hidden_29[HIDDEN_COUNT_28][HIDDEN_COUNT_29];
        double w_hidden_29_to_hidden_30[HIDDEN_COUNT_29][HIDDEN_COUNT_30];
        double w_hidden_30_to_output[HIDDEN_COUNT_30][OUTPUT_COUNT];
        double test_input[INPUT_COUNT];
        double total_err;
        double max_error;
        u32 max_error_inset_no;
    };
    struct _76800_1024_1024_6_str net_76800_1024_1024_6;

    void _76800_1024_1024_6_ann_train(  double input[INPUT_COUNT],
                                        double desired_output[OUTPUT_COUNT], double calculated_output[OUTPUT_COUNT],
                                        double hidden_neuron_bias_1[HIDDEN_COUNT_1],
                                        double hidden_neuron_bias_2[HIDDEN_COUNT_2],
                                        double hidden_neuron_bias_3[HIDDEN_COUNT_3],
                                        double hidden_neuron_bias_4[HIDDEN_COUNT_4],
                                        double hidden_neuron_bias_5[HIDDEN_COUNT_5],
                                        double hidden_neuron_bias_6[HIDDEN_COUNT_6],
                                        double hidden_neuron_bias_7[HIDDEN_COUNT_7],
                                        double hidden_neuron_bias_8[HIDDEN_COUNT_8],
                                        double hidden_neuron_bias_9[HIDDEN_COUNT_9],
                                        double hidden_neuron_bias_10[HIDDEN_COUNT_10],
                                        double hidden_neuron_bias_11[HIDDEN_COUNT_11],
                                        double hidden_neuron_bias_12[HIDDEN_COUNT_12],
                                        double hidden_neuron_bias_13[HIDDEN_COUNT_13],
                                        double hidden_neuron_bias_14[HIDDEN_COUNT_14],
                                        double hidden_neuron_bias_15[HIDDEN_COUNT_15],
                                        double hidden_neuron_bias_16[HIDDEN_COUNT_16],
                                        double hidden_neuron_bias_17[HIDDEN_COUNT_17],
                                        double hidden_neuron_bias_18[HIDDEN_COUNT_18],
                                        double hidden_neuron_bias_19[HIDDEN_COUNT_19],
                                        double hidden_neuron_bias_20[HIDDEN_COUNT_20],
                                        double hidden_neuron_bias_21[HIDDEN_COUNT_21],
                                        double hidden_neuron_bias_22[HIDDEN_COUNT_22],
                                        double hidden_neuron_bias_23[HIDDEN_COUNT_23],
                                        double hidden_neuron_bias_24[HIDDEN_COUNT_24],
                                        double hidden_neuron_bias_25[HIDDEN_COUNT_25],
                                        double hidden_neuron_bias_26[HIDDEN_COUNT_26],
                                        double hidden_neuron_bias_27[HIDDEN_COUNT_27],
                                        double hidden_neuron_bias_28[HIDDEN_COUNT_28],
                                        double hidden_neuron_bias_29[HIDDEN_COUNT_29],
                                        double hidden_neuron_bias_30[HIDDEN_COUNT_30],
                                        double output_bias[OUTPUT_COUNT],
                                        double w_input_to_hidden_1[INPUT_COUNT][HIDDEN_COUNT_1],
                                        double w_hidden_1_to_hidden_2[HIDDEN_COUNT_1][HIDDEN_COUNT_2],
                                        double w_hidden_2_to_hidden_3[HIDDEN_COUNT_2][HIDDEN_COUNT_3],
                                        double w_hidden_3_to_hidden_4[HIDDEN_COUNT_3][HIDDEN_COUNT_4],
                                        double w_hidden_4_to_hidden_5[HIDDEN_COUNT_4][HIDDEN_COUNT_5],
                                        double w_hidden_5_to_hidden_6[HIDDEN_COUNT_5][HIDDEN_COUNT_6],
                                        double w_hidden_6_to_hidden_7[HIDDEN_COUNT_6][HIDDEN_COUNT_7],
                                        double w_hidden_7_to_hidden_8[HIDDEN_COUNT_7][HIDDEN_COUNT_8],
                                        double w_hidden_8_to_hidden_9[HIDDEN_COUNT_8][HIDDEN_COUNT_9],
                                        double w_hidden_9_to_hidden_10[HIDDEN_COUNT_9][HIDDEN_COUNT_10],
                                        double w_hidden_10_to_hidden_11[HIDDEN_COUNT_10][HIDDEN_COUNT_11],
                                        double w_hidden_11_to_hidden_12[HIDDEN_COUNT_11][HIDDEN_COUNT_12],
                                        double w_hidden_12_to_hidden_13[HIDDEN_COUNT_12][HIDDEN_COUNT_13],
                                        double w_hidden_13_to_hidden_14[HIDDEN_COUNT_13][HIDDEN_COUNT_14],
                                        double w_hidden_14_to_hidden_15[HIDDEN_COUNT_14][HIDDEN_COUNT_15],
                                        double w_hidden_15_to_hidden_16[HIDDEN_COUNT_15][HIDDEN_COUNT_16],
                                        double w_hidden_16_to_hidden_17[HIDDEN_COUNT_16][HIDDEN_COUNT_17],
                                        double w_hidden_17_to_hidden_18[HIDDEN_COUNT_17][HIDDEN_COUNT_18],
                                        double w_hidden_18_to_hidden_19[HIDDEN_COUNT_18][HIDDEN_COUNT_19],
                                        double w_hidden_19_to_hidden_20[HIDDEN_COUNT_19][HIDDEN_COUNT_20],
                                        double w_hidden_20_to_hidden_21[HIDDEN_COUNT_20][HIDDEN_COUNT_21],
                                        double w_hidden_21_to_hidden_22[HIDDEN_COUNT_21][HIDDEN_COUNT_22],
                                        double w_hidden_22_to_hidden_23[HIDDEN_COUNT_22][HIDDEN_COUNT_23],
                                        double w_hidden_23_to_hidden_24[HIDDEN_COUNT_23][HIDDEN_COUNT_24],
                                        double w_hidden_24_to_hidden_25[HIDDEN_COUNT_24][HIDDEN_COUNT_25],
                                        double w_hidden_25_to_hidden_26[HIDDEN_COUNT_25][HIDDEN_COUNT_26],
                                        double w_hidden_26_to_hidden_27[HIDDEN_COUNT_26][HIDDEN_COUNT_27],
                                        double w_hidden_27_to_hidden_28[HIDDEN_COUNT_27][HIDDEN_COUNT_28],
                                        double w_hidden_28_to_hidden_29[HIDDEN_COUNT_28][HIDDEN_COUNT_29],
                                        double w_hidden_29_to_hidden_30[HIDDEN_COUNT_29][HIDDEN_COUNT_30],
                                        double w_hidden_30_to_output[HIDDEN_COUNT_30][OUTPUT_COUNT],
                                        u32 epoch, double learning_rate);
    void _76800_1024_1024_6_ann_test(   double input[INPUT_COUNT],
                                        double hidden_neuron_bias_1[HIDDEN_COUNT_1],
                                        double hidden_neuron_bias_2[HIDDEN_COUNT_2],
                                        double hidden_neuron_bias_3[HIDDEN_COUNT_3],
                                        double hidden_neuron_bias_4[HIDDEN_COUNT_4],
                                        double hidden_neuron_bias_5[HIDDEN_COUNT_5],
                                        double hidden_neuron_bias_6[HIDDEN_COUNT_6],
                                        double hidden_neuron_bias_7[HIDDEN_COUNT_7],
                                        double hidden_neuron_bias_8[HIDDEN_COUNT_8],
                                        double hidden_neuron_bias_9[HIDDEN_COUNT_9],
                                        double hidden_neuron_bias_10[HIDDEN_COUNT_10],
                                        double hidden_neuron_bias_11[HIDDEN_COUNT_11],
                                        double hidden_neuron_bias_12[HIDDEN_COUNT_12],
                                        double hidden_neuron_bias_13[HIDDEN_COUNT_13],
                                        double hidden_neuron_bias_14[HIDDEN_COUNT_14],
                                        double hidden_neuron_bias_15[HIDDEN_COUNT_15],
                                        double hidden_neuron_bias_16[HIDDEN_COUNT_16],
                                        double hidden_neuron_bias_17[HIDDEN_COUNT_17],
                                        double hidden_neuron_bias_18[HIDDEN_COUNT_18],
                                        double hidden_neuron_bias_19[HIDDEN_COUNT_19],
                                        double hidden_neuron_bias_20[HIDDEN_COUNT_20],
                                        double hidden_neuron_bias_21[HIDDEN_COUNT_21],
                                        double hidden_neuron_bias_22[HIDDEN_COUNT_22],
                                        double hidden_neuron_bias_23[HIDDEN_COUNT_23],
                                        double hidden_neuron_bias_24[HIDDEN_COUNT_24],
                                        double hidden_neuron_bias_25[HIDDEN_COUNT_25],
                                        double hidden_neuron_bias_26[HIDDEN_COUNT_26],
                                        double hidden_neuron_bias_27[HIDDEN_COUNT_27],
                                        double hidden_neuron_bias_28[HIDDEN_COUNT_28],
                                        double hidden_neuron_bias_29[HIDDEN_COUNT_29],
                                        double hidden_neuron_bias_30[HIDDEN_COUNT_30],
                                        double output_bias[OUTPUT_COUNT],
                                        double w_input_to_hidden_1[INPUT_COUNT][HIDDEN_COUNT_1],
                                        double w_hidden_1_to_hidden_2[HIDDEN_COUNT_1][HIDDEN_COUNT_2],
                                        double w_hidden_2_to_hidden_3[HIDDEN_COUNT_2][HIDDEN_COUNT_3],
                                        double w_hidden_3_to_hidden_4[HIDDEN_COUNT_3][HIDDEN_COUNT_4],
                                        double w_hidden_4_to_hidden_5[HIDDEN_COUNT_4][HIDDEN_COUNT_5],
                                        double w_hidden_5_to_hidden_6[HIDDEN_COUNT_5][HIDDEN_COUNT_6],
                                        double w_hidden_6_to_hidden_7[HIDDEN_COUNT_6][HIDDEN_COUNT_7],
                                        double w_hidden_7_to_hidden_8[HIDDEN_COUNT_7][HIDDEN_COUNT_8],
                                        double w_hidden_8_to_hidden_9[HIDDEN_COUNT_8][HIDDEN_COUNT_9],
                                        double w_hidden_9_to_hidden_10[HIDDEN_COUNT_9][HIDDEN_COUNT_10],
                                        double w_hidden_10_to_hidden_11[HIDDEN_COUNT_10][HIDDEN_COUNT_11],
                                        double w_hidden_11_to_hidden_12[HIDDEN_COUNT_11][HIDDEN_COUNT_12],
                                        double w_hidden_12_to_hidden_13[HIDDEN_COUNT_12][HIDDEN_COUNT_13],
                                        double w_hidden_13_to_hidden_14[HIDDEN_COUNT_13][HIDDEN_COUNT_14],
                                        double w_hidden_14_to_hidden_15[HIDDEN_COUNT_14][HIDDEN_COUNT_15],
                                        double w_hidden_15_to_hidden_16[HIDDEN_COUNT_15][HIDDEN_COUNT_16],
                                        double w_hidden_16_to_hidden_17[HIDDEN_COUNT_16][HIDDEN_COUNT_17],
                                        double w_hidden_17_to_hidden_18[HIDDEN_COUNT_17][HIDDEN_COUNT_18],
                                        double w_hidden_18_to_hidden_19[HIDDEN_COUNT_18][HIDDEN_COUNT_19],
                                        double w_hidden_19_to_hidden_20[HIDDEN_COUNT_19][HIDDEN_COUNT_20],
                                        double w_hidden_20_to_hidden_21[HIDDEN_COUNT_20][HIDDEN_COUNT_21],
                                        double w_hidden_21_to_hidden_22[HIDDEN_COUNT_21][HIDDEN_COUNT_22],
                                        double w_hidden_22_to_hidden_23[HIDDEN_COUNT_22][HIDDEN_COUNT_23],
                                        double w_hidden_23_to_hidden_24[HIDDEN_COUNT_23][HIDDEN_COUNT_24],
                                        double w_hidden_24_to_hidden_25[HIDDEN_COUNT_24][HIDDEN_COUNT_25],
                                        double w_hidden_25_to_hidden_26[HIDDEN_COUNT_25][HIDDEN_COUNT_26],
                                        double w_hidden_26_to_hidden_27[HIDDEN_COUNT_26][HIDDEN_COUNT_27],
                                        double w_hidden_27_to_hidden_28[HIDDEN_COUNT_27][HIDDEN_COUNT_28],
                                        double w_hidden_28_to_hidden_29[HIDDEN_COUNT_28][HIDDEN_COUNT_29],
                                        double w_hidden_29_to_hidden_30[HIDDEN_COUNT_29][HIDDEN_COUNT_30],
                                        double w_hidden_30_to_output[HIDDEN_COUNT_30][OUTPUT_COUNT]);
    double _76800_1024_1024_6_ann_calculate_total_error(double *max_err);
    void prepare_inputset(u32 input_s);

private:
    Ui::ann *ui;
    MainWindow *mainwindow;
    QTimer* thread_timer;

    double sigmoid_func(double val);
    double derivative_of_sigmoid_func(double val);
    double output_sigmoid_func(double val);
    double output_derivative_of_sigmoid_func(double val);
    double classic_MA_1(double raw_signal);
    double classic_MA_2(double raw_signal);

private slots:
    void thread_handler(void);

};

#endif // ANN_H
