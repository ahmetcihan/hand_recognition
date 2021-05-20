#include "mainwindow.h"
#include "ui_mainwindow.h"

double ann::_76800_1024_1024_6_ann_calculate_total_error(double *max_err){
    double total_error = 0;
    double aux;
    double max_error = 0;

    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        aux = net_76800_1024_1024_6.desired_output[i] - net_76800_1024_1024_6.calculated_output[i];
        if(fabs(aux) > max_error)  max_error = fabs(aux);
        //aux = aux * aux;
        total_error += fabs(aux);
    }
    *max_err = max_error;
    return total_error;
}
void ann::_76800_1024_1024_6_ann_test(   double input[INPUT_COUNT],
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
                                         double w_hidden_10_to_output[HIDDEN_COUNT_10][OUTPUT_COUNT]){
    double hidden_neuron_in_1[HIDDEN_COUNT_1];
    double hidden_neuron_out_1[HIDDEN_COUNT_1];
    double hidden_neuron_in_2[HIDDEN_COUNT_2];
    double hidden_neuron_out_2[HIDDEN_COUNT_2];
    double hidden_neuron_in_3[HIDDEN_COUNT_3];
    double hidden_neuron_out_3[HIDDEN_COUNT_3];
    double hidden_neuron_in_4[HIDDEN_COUNT_4];
    double hidden_neuron_out_4[HIDDEN_COUNT_4];
    double hidden_neuron_in_5[HIDDEN_COUNT_5];
    double hidden_neuron_out_5[HIDDEN_COUNT_5];
    double hidden_neuron_in_6[HIDDEN_COUNT_6];
    double hidden_neuron_out_6[HIDDEN_COUNT_6];
    double hidden_neuron_in_7[HIDDEN_COUNT_7];
    double hidden_neuron_out_7[HIDDEN_COUNT_7];
    double hidden_neuron_in_8[HIDDEN_COUNT_8];
    double hidden_neuron_out_8[HIDDEN_COUNT_8];
    double hidden_neuron_in_9[HIDDEN_COUNT_9];
    double hidden_neuron_out_9[HIDDEN_COUNT_9];
    double hidden_neuron_in_10[HIDDEN_COUNT_10];
    double hidden_neuron_out_10[HIDDEN_COUNT_10];

    double output_in[OUTPUT_COUNT];
    double calculated_output[OUTPUT_COUNT];

    /*****************FORWARD PROPAGATION********************/
    /*******************INPUT TO HIDDEN1*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        hidden_neuron_in_1[i] = hidden_neuron_bias_1[i];
        for(u32 j = 0; j < INPUT_COUNT; j++){
            hidden_neuron_in_1[i] += input[j]*w_input_to_hidden_1[j][i];
        }
        hidden_neuron_out_1[i] = sigmoid_func(hidden_neuron_in_1[i]);
    }

    /*******************HIDDEN1 TO HIDDEN2*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        hidden_neuron_in_2[i] = hidden_neuron_bias_2[i];
        for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
            hidden_neuron_in_2[i] += hidden_neuron_out_1[j]*w_hidden_1_to_hidden_2[j][i];
        }
        hidden_neuron_out_2[i] = sigmoid_func(hidden_neuron_in_2[i]);
    }

    /*******************HIDDEN2 TO HIDDEN3*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        hidden_neuron_in_3[i] = hidden_neuron_bias_3[i];
        for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
            hidden_neuron_in_3[i] += hidden_neuron_out_2[j]*w_hidden_2_to_hidden_3[j][i];
        }
        hidden_neuron_out_3[i] = sigmoid_func(hidden_neuron_in_3[i]);
    }

    /*******************HIDDEN3 TO HIDDEN4*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_4; i++){
        hidden_neuron_in_4[i] = hidden_neuron_bias_4[i];
        for(u32 j = 0; j < HIDDEN_COUNT_3; j++){
            hidden_neuron_in_4[i] += hidden_neuron_out_3[j]*w_hidden_3_to_hidden_4[j][i];
        }
        hidden_neuron_out_4[i] = sigmoid_func(hidden_neuron_in_4[i]);
    }

    /*******************HIDDEN4 TO HIDDEN5*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_5; i++){
        hidden_neuron_in_5[i] = hidden_neuron_bias_5[i];
        for(u32 j = 0; j < HIDDEN_COUNT_4; j++){
            hidden_neuron_in_5[i] += hidden_neuron_out_4[j]*w_hidden_4_to_hidden_5[j][i];
        }
        hidden_neuron_out_5[i] = sigmoid_func(hidden_neuron_in_5[i]);
    }

    /*******************HIDDEN5 TO HIDDEN6*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_6; i++){
        hidden_neuron_in_6[i] = hidden_neuron_bias_6[i];
        for(u32 j = 0; j < HIDDEN_COUNT_5; j++){
            hidden_neuron_in_6[i] += hidden_neuron_out_5[j]*w_hidden_5_to_hidden_6[j][i];
        }
        hidden_neuron_out_6[i] = sigmoid_func(hidden_neuron_in_6[i]);
    }

    /*******************HIDDEN6 TO HIDDEN7*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_7; i++){
        hidden_neuron_in_7[i] = hidden_neuron_bias_7[i];
        for(u32 j = 0; j < HIDDEN_COUNT_6; j++){
            hidden_neuron_in_7[i] += hidden_neuron_out_6[j]*w_hidden_6_to_hidden_7[j][i];
        }
        hidden_neuron_out_7[i] = sigmoid_func(hidden_neuron_in_7[i]);
    }

    /*******************HIDDEN7 TO HIDDEN8*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_8; i++){
        hidden_neuron_in_8[i] = hidden_neuron_bias_8[i];
        for(u32 j = 0; j < HIDDEN_COUNT_7; j++){
            hidden_neuron_in_8[i] += hidden_neuron_out_7[j]*w_hidden_7_to_hidden_8[j][i];
        }
        hidden_neuron_out_8[i] = sigmoid_func(hidden_neuron_in_8[i]);
    }

    /*******************HIDDEN8 TO HIDDEN9*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_9; i++){
        hidden_neuron_in_9[i] = hidden_neuron_bias_9[i];
        for(u32 j = 0; j < HIDDEN_COUNT_8; j++){
            hidden_neuron_in_9[i] += hidden_neuron_out_8[j]*w_hidden_8_to_hidden_9[j][i];
        }
        hidden_neuron_out_9[i] = sigmoid_func(hidden_neuron_in_9[i]);
    }

    /*******************HIDDEN9 TO HIDDEN10*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
        hidden_neuron_in_10[i] = hidden_neuron_bias_10[i];
        for(u32 j = 0; j < HIDDEN_COUNT_9; j++){
            hidden_neuron_in_10[i] += hidden_neuron_out_9[j]*w_hidden_9_to_hidden_10[j][i];
        }
        hidden_neuron_out_10[i] = sigmoid_func(hidden_neuron_in_10[i]);
    }

    /*******************HIDDEN10 TO OUTPUT*********************/
    for(u32 j = 0; j < OUTPUT_COUNT; j++){
        output_in[j] =  output_bias[j];
        for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
            output_in[j] += hidden_neuron_out_10[i]*w_hidden_10_to_output[i][j];
        }
        calculated_output[j]   = output_sigmoid_func(output_in[j]);
    }
    qDebug() << "desired-1" << net_76800_1024_1024_6.desired_output[0] << "calculated-1" << calculated_output[0];
    qDebug() << "desired-2" << net_76800_1024_1024_6.desired_output[1] << "calculated-2" << calculated_output[1];
    qDebug() << "desired-3" << net_76800_1024_1024_6.desired_output[2] << "calculated-3" << calculated_output[2];
}
void ann::_76800_1024_1024_6_ann_train(  double input[INPUT_COUNT],
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
                                         double w_hidden_10_to_output[HIDDEN_COUNT_10][OUTPUT_COUNT],
                                         u32 epoch, double learning_rate){

    double hidden_neuron_in_1[HIDDEN_COUNT_1];
    double hidden_neuron_out_1[HIDDEN_COUNT_1];
    double hidden_neuron_error_1[HIDDEN_COUNT_1];
    double hidden_neuron_in_2[HIDDEN_COUNT_2];
    double hidden_neuron_out_2[HIDDEN_COUNT_2];
    double hidden_neuron_error_2[HIDDEN_COUNT_2];
    double hidden_neuron_in_3[HIDDEN_COUNT_3];
    double hidden_neuron_out_3[HIDDEN_COUNT_3];
    double hidden_neuron_error_3[HIDDEN_COUNT_3];
    double hidden_neuron_in_4[HIDDEN_COUNT_4];
    double hidden_neuron_out_4[HIDDEN_COUNT_4];
    double hidden_neuron_error_4[HIDDEN_COUNT_4];
    double hidden_neuron_in_5[HIDDEN_COUNT_5];
    double hidden_neuron_out_5[HIDDEN_COUNT_5];
    double hidden_neuron_error_5[HIDDEN_COUNT_5];
    double hidden_neuron_in_6[HIDDEN_COUNT_6];
    double hidden_neuron_out_6[HIDDEN_COUNT_6];
    double hidden_neuron_error_6[HIDDEN_COUNT_6];
    double hidden_neuron_in_7[HIDDEN_COUNT_7];
    double hidden_neuron_out_7[HIDDEN_COUNT_7];
    double hidden_neuron_error_7[HIDDEN_COUNT_7];
    double hidden_neuron_in_8[HIDDEN_COUNT_8];
    double hidden_neuron_out_8[HIDDEN_COUNT_8];
    double hidden_neuron_error_8[HIDDEN_COUNT_8];
    double hidden_neuron_in_9[HIDDEN_COUNT_9];
    double hidden_neuron_out_9[HIDDEN_COUNT_9];
    double hidden_neuron_error_9[HIDDEN_COUNT_9];
    double hidden_neuron_in_10[HIDDEN_COUNT_10];
    double hidden_neuron_out_10[HIDDEN_COUNT_10];
    double hidden_neuron_error_10[HIDDEN_COUNT_10];

    double output_error[OUTPUT_COUNT];
    double global_error[OUTPUT_COUNT];
    double output_in[OUTPUT_COUNT];
    double output_out[OUTPUT_COUNT];

    double inset_sse[INPUT_SET];
    static double max_abs_err[INPUT_SET];

    for(u32 era = 0; era < epoch; era++){
        for(u32 inset = 0; inset < INPUT_SET; inset++){
            prepare_inputset(inset);
            learning_rate = mainwindow->ui->doubleSpinBox->value() * mainwindow->ui->doubleSpinBox_2->value();

            /*****************FORWARD PROPAGATION********************/
            /*******************INPUT TO HIDDEN1*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                hidden_neuron_in_1[i] = hidden_neuron_bias_1[i];
                for(u32 j = 0; j < INPUT_COUNT; j++){
                    hidden_neuron_in_1[i] += input[j]*w_input_to_hidden_1[j][i];
                }
                hidden_neuron_out_1[i] = sigmoid_func(hidden_neuron_in_1[i]);
            }

            /*******************HIDDEN1 TO HIDDEN2*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                hidden_neuron_in_2[i] = hidden_neuron_bias_2[i];
                for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
                    hidden_neuron_in_2[i] += hidden_neuron_out_1[j]*w_hidden_1_to_hidden_2[j][i];
                }
                hidden_neuron_out_2[i] = sigmoid_func(hidden_neuron_in_2[i]);
            }

            /*******************HIDDEN2 TO HIDDEN3*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
                hidden_neuron_in_3[i] = hidden_neuron_bias_3[i];
                for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
                    hidden_neuron_in_3[i] += hidden_neuron_out_2[j]*w_hidden_2_to_hidden_3[j][i];
                }
                hidden_neuron_out_3[i] = sigmoid_func(hidden_neuron_in_3[i]);
            }

            /*******************HIDDEN3 TO HIDDEN4*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_4; i++){
                hidden_neuron_in_4[i] = hidden_neuron_bias_4[i];
                for(u32 j = 0; j < HIDDEN_COUNT_3; j++){
                    hidden_neuron_in_4[i] += hidden_neuron_out_3[j]*w_hidden_3_to_hidden_4[j][i];
                }
                hidden_neuron_out_4[i] = sigmoid_func(hidden_neuron_in_4[i]);
            }

            /*******************HIDDEN4 TO HIDDEN5*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_5; i++){
                hidden_neuron_in_5[i] = hidden_neuron_bias_5[i];
                for(u32 j = 0; j < HIDDEN_COUNT_4; j++){
                    hidden_neuron_in_5[i] += hidden_neuron_out_4[j]*w_hidden_4_to_hidden_5[j][i];
                }
                hidden_neuron_out_5[i] = sigmoid_func(hidden_neuron_in_5[i]);
            }

            /*******************HIDDEN5 TO HIDDEN6*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_6; i++){
                hidden_neuron_in_6[i] = hidden_neuron_bias_6[i];
                for(u32 j = 0; j < HIDDEN_COUNT_5; j++){
                    hidden_neuron_in_6[i] += hidden_neuron_out_5[j]*w_hidden_5_to_hidden_6[j][i];
                }
                hidden_neuron_out_6[i] = sigmoid_func(hidden_neuron_in_6[i]);
            }

            /*******************HIDDEN6 TO HIDDEN7*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_7; i++){
                hidden_neuron_in_7[i] = hidden_neuron_bias_7[i];
                for(u32 j = 0; j < HIDDEN_COUNT_6; j++){
                    hidden_neuron_in_7[i] += hidden_neuron_out_6[j]*w_hidden_6_to_hidden_7[j][i];
                }
                hidden_neuron_out_7[i] = sigmoid_func(hidden_neuron_in_7[i]);
            }

            /*******************HIDDEN7 TO HIDDEN8*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_8; i++){
                hidden_neuron_in_8[i] = hidden_neuron_bias_8[i];
                for(u32 j = 0; j < HIDDEN_COUNT_7; j++){
                    hidden_neuron_in_8[i] += hidden_neuron_out_7[j]*w_hidden_7_to_hidden_8[j][i];
                }
                hidden_neuron_out_8[i] = sigmoid_func(hidden_neuron_in_8[i]);
            }

            /*******************HIDDEN8 TO HIDDEN9*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_9; i++){
                hidden_neuron_in_9[i] = hidden_neuron_bias_9[i];
                for(u32 j = 0; j < HIDDEN_COUNT_8; j++){
                    hidden_neuron_in_9[i] += hidden_neuron_out_8[j]*w_hidden_8_to_hidden_9[j][i];
                }
                hidden_neuron_out_9[i] = sigmoid_func(hidden_neuron_in_9[i]);
            }

            /*******************HIDDEN9 TO HIDDEN10*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
                hidden_neuron_in_10[i] = hidden_neuron_bias_10[i];
                for(u32 j = 0; j < HIDDEN_COUNT_9; j++){
                    hidden_neuron_in_10[i] += hidden_neuron_out_9[j]*w_hidden_9_to_hidden_10[j][i];
                }
                hidden_neuron_out_10[i] = sigmoid_func(hidden_neuron_in_10[i]);
            }


            /*******************HIDDEN10 TO OUTPUT*********************/
            for(u32 j = 0; j < OUTPUT_COUNT; j++){
                output_in[j] =  output_bias[j];
                for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
                    output_in[j] += hidden_neuron_out_10[i]*w_hidden_10_to_output[i][j];
                }
                output_out[j]   = output_sigmoid_func(output_in[j]);
                output_error[j] = desired_output[j] - output_out[j];
                calculated_output[j] = output_out[j];
                global_error[j] = output_derivative_of_sigmoid_func(output_in[j]) * output_error[j];
            }

            /********************BACKPROPAGATION**********************/
            /*******************OUTPUT TO HIDDEN10*********************/
            for(u32 j = 0; j < OUTPUT_COUNT; j++){
                for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
                    w_hidden_10_to_output[i][j] += global_error[j] * hidden_neuron_out_10[i] * learning_rate;
                }
                output_bias[j] += global_error[j] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
                hidden_neuron_error_10[i] = 0;
                for(u32 j = 0; j < OUTPUT_COUNT; j++){
                    hidden_neuron_error_10[i] += derivative_of_sigmoid_func(hidden_neuron_in_10[i]) * global_error[j] * w_hidden_10_to_output[i][j];
                }
            }

            /*******************HIDDEN10 TO HIDDEN9*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_9; j++){
                    w_hidden_9_to_hidden_10[j][i] += hidden_neuron_error_10[i] * hidden_neuron_out_9[j] * learning_rate;
                }
                hidden_neuron_bias_10[i] += hidden_neuron_error_10[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_9; i++){
                hidden_neuron_error_9[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_10; j++){
                    hidden_neuron_error_9[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_9[i]) * hidden_neuron_error_10[j] * w_hidden_9_to_hidden_10[i][j];
                }
            }

            /*******************HIDDEN9 TO HIDDEN8*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_9; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_8; j++){
                    w_hidden_8_to_hidden_9[j][i] += hidden_neuron_error_9[i] * hidden_neuron_out_8[j] * learning_rate;
                }
                hidden_neuron_bias_9[i] += hidden_neuron_error_9[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_8; i++){
                hidden_neuron_error_8[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_9; j++){
                    hidden_neuron_error_8[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_8[i]) * hidden_neuron_error_9[j] * w_hidden_8_to_hidden_9[i][j];
                }
            }

            /*******************HIDDEN8 TO HIDDEN7*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_8; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_7; j++){
                    w_hidden_7_to_hidden_8[j][i] += hidden_neuron_error_8[i] * hidden_neuron_out_7[j] * learning_rate;
                }
                hidden_neuron_bias_8[i] += hidden_neuron_error_8[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_7; i++){
                hidden_neuron_error_7[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_8; j++){
                    hidden_neuron_error_7[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_7[i]) * hidden_neuron_error_8[j] * w_hidden_7_to_hidden_8[i][j];
                }
            }

            /*******************HIDDEN7 TO HIDDEN6*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_7; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_6; j++){
                    w_hidden_6_to_hidden_7[j][i] += hidden_neuron_error_7[i] * hidden_neuron_out_6[j] * learning_rate;
                }
                hidden_neuron_bias_7[i] += hidden_neuron_error_7[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_6; i++){
                hidden_neuron_error_6[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_7; j++){
                    hidden_neuron_error_6[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_6[i]) * hidden_neuron_error_7[j] * w_hidden_6_to_hidden_7[i][j];
                }
            }

            /*******************HIDDEN6 TO HIDDEN5*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_6; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_5; j++){
                    w_hidden_5_to_hidden_6[j][i] += hidden_neuron_error_6[i] * hidden_neuron_out_5[j] * learning_rate;
                }
                hidden_neuron_bias_6[i] += hidden_neuron_error_6[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_5; i++){
                hidden_neuron_error_5[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_6; j++){
                    hidden_neuron_error_5[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_5[i]) * hidden_neuron_error_6[j] * w_hidden_5_to_hidden_6[i][j];
                }
            }

            /*******************HIDDEN5 TO HIDDEN4*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_5; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_4; j++){
                    w_hidden_4_to_hidden_5[j][i] += hidden_neuron_error_5[i] * hidden_neuron_out_4[j] * learning_rate;
                }
                hidden_neuron_bias_5[i] += hidden_neuron_error_5[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_4; i++){
                hidden_neuron_error_4[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_5; j++){
                    hidden_neuron_error_4[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_4[i]) * hidden_neuron_error_5[j] * w_hidden_4_to_hidden_5[i][j];
                }
            }

            /*******************HIDDEN4 TO HIDDEN3*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_4; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_3; j++){
                    w_hidden_3_to_hidden_4[j][i] += hidden_neuron_error_4[i] * hidden_neuron_out_3[j] * learning_rate;
                }
                hidden_neuron_bias_4[i] += hidden_neuron_error_4[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
                hidden_neuron_error_3[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_4; j++){
                    hidden_neuron_error_3[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_3[i]) * hidden_neuron_error_4[j] * w_hidden_3_to_hidden_4[i][j];
                }
            }

            /*******************HIDDEN3 TO HIDDEN2*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
                    w_hidden_2_to_hidden_3[j][i] += hidden_neuron_error_3[i] * hidden_neuron_out_2[j] * learning_rate;
                }
                hidden_neuron_bias_3[i] += hidden_neuron_error_3[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                hidden_neuron_error_2[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_3; j++){
                    hidden_neuron_error_2[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_2[i]) * hidden_neuron_error_3[j] * w_hidden_2_to_hidden_3[i][j];
                }
            }

            /*******************HIDDEN2 TO HIDDEN1*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
                    w_hidden_1_to_hidden_2[j][i] += hidden_neuron_error_2[i] * hidden_neuron_out_1[j] * learning_rate;
                }
                hidden_neuron_bias_2[i] += hidden_neuron_error_2[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                hidden_neuron_error_1[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
                    hidden_neuron_error_1[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_1[i]) * hidden_neuron_error_2[j] * w_hidden_1_to_hidden_2[i][j];
                }
            }

            /*******************HIDDEN1 TO INPUT*********************/
            for(u32 i = 0; i < INPUT_COUNT; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
                    w_input_to_hidden_1[i][j] += hidden_neuron_error_1[j] * input[i] * learning_rate;
                }
            }
            for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                hidden_neuron_bias_1[i] +=hidden_neuron_error_1[i] * learning_rate;
            }


            inset_sse[inset] = _76800_1024_1024_6_ann_calculate_total_error(&max_abs_err[inset]);
        }
        net_76800_1024_1024_6.total_err = 0;
        net_76800_1024_1024_6.max_error = 0;
        for(u32 i = 0; i < INPUT_SET; i++){
            net_76800_1024_1024_6.total_err += inset_sse[i];
            if(max_abs_err[i] > net_76800_1024_1024_6.max_error){
                net_76800_1024_1024_6.max_error = max_abs_err[i];
                net_76800_1024_1024_6.max_error_inset_no = i;
            }
        }
        epoch_no = era;
        epoch_status = (era*100)/epoch;
        if(stop_the_training == 1) break;
    }
}
void MainWindow::_76800_1024_1024_6_random_initilize_handler(void){
    qsrand(QDateTime::currentMSecsSinceEpoch());

    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_3[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_4; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_4[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_5; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_5[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_6; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_6[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_7; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_7[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_8; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_8[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_9; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_9[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_10[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }

    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        ann_class->net_76800_1024_1024_6.output_bias[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }

    for(u32 i = 0; i < INPUT_COUNT; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
            ann_class->net_76800_1024_1024_6.w_input_to_hidden_1[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_1_to_hidden_2[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_3; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_2_to_hidden_3[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_4; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_3_to_hidden_4[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_4; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_5; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_4_to_hidden_5[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_5; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_6; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_5_to_hidden_6[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_6; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_7; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_6_to_hidden_7[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_7; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_8; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_7_to_hidden_8[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_8; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_9; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_8_to_hidden_9[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_9; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_10; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_9_to_hidden_10[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_10_to_output[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }

    ui->label_76800_1024_1024_6_random_initilize->setText("Initilized randomly");
}
void MainWindow::_76800_1024_1024_6_train_handler(void){
    ann_class->train_status = 1;
    ann_class->stop_the_training = 0;
}
void MainWindow::_76800_1024_1024_6_test_handler(void){
    QFile file("/home/ahmet/Desktop/waveform_tester.csv");
    file.open(QIODevice::ReadOnly);

    u32 line_no = 0;
    double tester_index_no[200];
    double tester_waveform[200];

    file.readLine(); //this is dummy
    while (!file.atEnd()) {
        QString str = file.readLine();
        QString str1 = str.section(',',0,0);
        QString str2 = str.section(',',1,1);

        tester_index_no[line_no]      = str1.toInt();
        tester_waveform[line_no]      = str2.toDouble();

        line_no++;
    }

    for(u32 i = 0; i < WAVE_LENGTH; i++){
        ann_class->net_76800_1024_1024_6.test_input[WAVE_LENGTH*0 + i] = tester_index_no[i];
        ann_class->net_76800_1024_1024_6.test_input[WAVE_LENGTH*1 + i] = tester_waveform[i];

        qDebug()    << QString("Index_no : %1") .arg(tester_index_no[i])
                    << QString("waveform : %1") .arg(tester_waveform[i]);
    }

    ann_class->net_76800_1024_1024_6.desired_output[0] = OUTPUT_MULTIPLIER * tester_waveform[WAVE_LENGTH];
    ann_class->net_76800_1024_1024_6.desired_output[1] = OUTPUT_MULTIPLIER * tester_waveform[WAVE_LENGTH + 1];
    ann_class->net_76800_1024_1024_6.desired_output[2] = OUTPUT_MULTIPLIER * tester_waveform[WAVE_LENGTH + 2];

    ann_class->_76800_1024_1024_6_ann_test( ann_class->net_76800_1024_1024_6.test_input,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_3,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_4,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_5,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_6,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_7,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_8,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_9,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_10,
                                            ann_class->net_76800_1024_1024_6.output_bias,
                                            ann_class->net_76800_1024_1024_6.w_input_to_hidden_1,
                                            ann_class->net_76800_1024_1024_6.w_hidden_1_to_hidden_2,
                                            ann_class->net_76800_1024_1024_6.w_hidden_2_to_hidden_3,
                                            ann_class->net_76800_1024_1024_6.w_hidden_3_to_hidden_4,
                                            ann_class->net_76800_1024_1024_6.w_hidden_4_to_hidden_5,
                                            ann_class->net_76800_1024_1024_6.w_hidden_5_to_hidden_6,
                                            ann_class->net_76800_1024_1024_6.w_hidden_6_to_hidden_7,
                                            ann_class->net_76800_1024_1024_6.w_hidden_7_to_hidden_8,
                                            ann_class->net_76800_1024_1024_6.w_hidden_8_to_hidden_9,
                                            ann_class->net_76800_1024_1024_6.w_hidden_9_to_hidden_10,
                                            ann_class->net_76800_1024_1024_6.w_hidden_10_to_output);

}
void MainWindow::_76800_1024_1024_6_save_weights_handler(void){
    QSettings settings("weights_76800_1024_1024_6.ini",QSettings::IniFormat);

    settings.beginGroup("w");

    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        settings.setValue(QString("hb1-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        settings.setValue(QString("hb2-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        settings.setValue(QString("hb3-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_3[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_4; i++){
        settings.setValue(QString("hb4-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_4[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_5; i++){
        settings.setValue(QString("hb5-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_5[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_6; i++){
        settings.setValue(QString("hb6-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_6[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_7; i++){
        settings.setValue(QString("hb7-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_7[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_8; i++){
        settings.setValue(QString("hb8-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_8[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_9; i++){
        settings.setValue(QString("hb9-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_9[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
        settings.setValue(QString("hb10-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_10[i]);
    }

    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        settings.setValue(QString("ob-%1").arg(i),ann_class->net_76800_1024_1024_6.output_bias[i]);
    }

    for(u32 i = 0; i < INPUT_COUNT; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
            settings.setValue(QString("i2h1-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_input_to_hidden_1[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
            settings.setValue(QString("h12h2-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_1_to_hidden_2[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_3; j++){
            settings.setValue(QString("h22h3-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_2_to_hidden_3[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_4; j++){
            settings.setValue(QString("h32h4-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_3_to_hidden_4[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_4; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_5; j++){
            settings.setValue(QString("h42h5-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_4_to_hidden_5[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_5; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_6; j++){
            settings.setValue(QString("h52h6-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_5_to_hidden_6[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_6; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_7; j++){
            settings.setValue(QString("h62h7-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_6_to_hidden_7[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_7; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_8; j++){
            settings.setValue(QString("h72h8-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_7_to_hidden_8[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_8; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_9; j++){
            settings.setValue(QString("h82h9-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_8_to_hidden_9[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_9; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_10; j++){
            settings.setValue(QString("h92h10-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_9_to_hidden_10[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            settings.setValue(QString("h102o-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_10_to_output[i][j]);
        }
    }
    settings.endGroup();
    settings.sync();
    QProcess::execute("sync");

    ui->label_76800_1024_1024_6_save_weights->setText("Saved..");
}
void MainWindow::_76800_1024_1024_6_load_saved_weights_handler(void){
    QSettings settings("weights_76800_1024_1024_6.ini",QSettings::IniFormat);

    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1[i] = settings.value(QString("w/hb1-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[i] = settings.value(QString("w/hb2-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_3[i] = settings.value(QString("w/hb3-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_4; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_4[i] = settings.value(QString("w/hb4-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_5; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_5[i] = settings.value(QString("w/hb5-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_6; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_6[i] = settings.value(QString("w/hb6-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_7; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_7[i] = settings.value(QString("w/hb7-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_8; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_8[i] = settings.value(QString("w/hb8-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_9; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_9[i] = settings.value(QString("w/hb9-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_10[i] = settings.value(QString("w/hb10-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        ann_class->net_76800_1024_1024_6.output_bias[i] = settings.value(QString("w/ob-%1").arg(i)).toDouble();
    }

    for(u32 i = 0; i < INPUT_COUNT; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
            ann_class->net_76800_1024_1024_6.w_input_to_hidden_1[i][j] = settings.value(QString("w/i2h1-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_1_to_hidden_2[i][j] = settings.value(QString("w/h12h2-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_3; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_2_to_hidden_3[i][j] = settings.value(QString("w/h22h3-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_4; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_3_to_hidden_4[i][j] = settings.value(QString("w/h32h4-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_4; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_5; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_4_to_hidden_5[i][j] = settings.value(QString("w/h42h5-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_5; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_6; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_5_to_hidden_6[i][j] = settings.value(QString("w/h52h6-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_6; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_7; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_6_to_hidden_7[i][j] = settings.value(QString("w/h62h7-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_7; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_8; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_7_to_hidden_8[i][j] = settings.value(QString("w/h72h8-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_8; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_9; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_8_to_hidden_9[i][j] = settings.value(QString("w/h82h9-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_9; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_10; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_9_to_hidden_10[i][j] = settings.value(QString("w/h92h10-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_10_to_output[i][j] = settings.value(QString("w/h102o-%1-%2").arg(i).arg(j)).toDouble();
        }
    }

    ui->label_76800_1024_1024_6_load_saved_weights->setText("Loaded..");
}
void MainWindow::_76800_1024_1024_6_stop_train_handler(void){
    ann_class->stop_the_training = 1;
}
void ann::prepare_inputset(u32 input_s){
    for(u32 i = 0; i < WAVE_LENGTH; i++){
        net_76800_1024_1024_6.input[WAVE_LENGTH*0 + i] = waveform[i + input_s];
    }
    net_76800_1024_1024_6.desired_output[0] = OUTPUT_MULTIPLIER * waveform[WAVE_LENGTH + input_s];
    net_76800_1024_1024_6.desired_output[1] = OUTPUT_MULTIPLIER * waveform[WAVE_LENGTH + 1 + input_s];
    net_76800_1024_1024_6.desired_output[2] = OUTPUT_MULTIPLIER * waveform[WAVE_LENGTH + 2 + input_s];
}
