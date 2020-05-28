#include "mainwindow.h"
#include "ui_mainwindow.h"

#define INPUT_COUNT     1344
#define HIDDEN_COUNT_1  128
#define HIDDEN_COUNT_2  128
#define HIDDEN_COUNT_3  128
#define OUTPUT_COUNT    6
#define IO_ARRAY_LENGTH 6
#define INPUT_SET       3

double ann::_76800_1024_1024_6_ann_calculate_total_error(void){
    double total_error = 0;
    double aux;

    for(u8 i = 0; i < OUTPUT_COUNT; i++){
        for(u8 j = 0; j < OUTPUT_COUNT; j++){
            aux = net_76800_1024_1024_6.desired_output[i][j] - net_76800_1024_1024_6.calculated_output[i][j];
            aux = aux * aux;
            total_error += aux;
        }
    }
    return total_error;
}
void ann::_76800_1024_1024_6_ann_test(  double input[1344],
                                        double hidden_neuron_bias_1[1024], double hidden_neuron_bias_2[1024], double hidden_neuron_bias_3[1024],
                                        double output_bias[6],
                                        double w_input_to_hidden_1[1344][1024],
                                        double w_hidden_1_to_hidden_2[1024][1024],
                                        double w_hidden_2_to_hidden_3[1024][1024],
                                        double w_hidden_3_to_output[1024][6]){
    double hidden_neuron_in_1[HIDDEN_COUNT_1];
    double hidden_neuron_out_1[HIDDEN_COUNT_1];

    double hidden_neuron_in_2[HIDDEN_COUNT_2];
    double hidden_neuron_out_2[HIDDEN_COUNT_2];

    double hidden_neuron_in_3[HIDDEN_COUNT_3];
    double hidden_neuron_out_3[HIDDEN_COUNT_3];

    double output_in[OUTPUT_COUNT];
    double calculated_output[OUTPUT_COUNT];

    for(u32 i = 0; i < INPUT_COUNT; i++){
        qDebug() << QString("input[%1] :").arg(i) << input[i];
    }

    /*****************FORWARD PROPAGATION********************/
    /*******************INPUT TO HIDDEN1*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        hidden_neuron_in_1[i] = hidden_neuron_bias_1[i];
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        for(u32 j = 0; j < INPUT_COUNT; j++){
            hidden_neuron_in_1[i] += input[j]*w_input_to_hidden_1[j][i];
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        hidden_neuron_out_1[i] = sigmoid_func(hidden_neuron_in_1[i]);
    }

    /*******************HIDDEN1 TO HIDDEN2*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        hidden_neuron_in_2[i] = hidden_neuron_bias_2[i];
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
            hidden_neuron_in_2[i] += hidden_neuron_out_1[j]*w_hidden_1_to_hidden_2[j][i];
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        hidden_neuron_out_2[i] = sigmoid_func(hidden_neuron_in_2[i]);
    }

    /*******************HIDDEN2 TO HIDDEN3*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        hidden_neuron_in_3[i] = hidden_neuron_bias_3[i];
    }
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
            hidden_neuron_in_3[i] += hidden_neuron_out_2[j]*w_hidden_2_to_hidden_3[j][i];
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        hidden_neuron_out_3[i] = sigmoid_func(hidden_neuron_in_3[i]);
    }

    /*******************HIDDEN3 TO OUTPUT*********************/
    for(u32 j = 0; j < OUTPUT_COUNT; j++){
        output_in[j] =  output_bias[j];
        for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
            output_in[j] += hidden_neuron_out_3[i]*w_hidden_3_to_output[i][j];
        }
        calculated_output[j]   = output_sigmoid_func(output_in[j]);
    }

    qDebug() << "**********testing***************";
    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        qDebug() << QString("output[%1] :").arg(i) << calculated_output[i];
    }

    qDebug() << "% " << 100*calculated_output[0] << "\t" << "ihtimal fist";
    qDebug() << "% " << 100*calculated_output[1] << "\t" << "ihtimal one";
    qDebug() << "% " << 100*calculated_output[2] << "\t" << "ihtimal two";
    qDebug() << "% " << 100*calculated_output[3] << "\t" << "ihtimal three";
    qDebug() << "% " << 100*calculated_output[4] << "\t" << "ihtimal four";
    qDebug() << "% " << 100*calculated_output[5] << "\t" << "ihtimal five";

    u32 max_value_index = 0;
    double max_value = 0;
    QString str = "";

    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        if(calculated_output[i] > max_value){
            max_value = calculated_output[i];
            max_value_index = i;
        }
    }
    double out_strict[OUTPUT_COUNT] = {0};

    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        if(calculated_output[i] > 1.0){
            out_strict[i] = calculated_output[i] - 1.0;
            calculated_output[i] = calculated_output[i] - 2*out_strict[i];
        }
    }

    if(max_value_index == 0)    str = QString("% %1 ihtimal fist").arg((u32)(100*calculated_output[0]));
    if(max_value_index == 1)    str = QString("% %1 ihtimal one").arg((u32)(100*calculated_output[1]));
    if(max_value_index == 2)    str = QString("% %1 ihtimal two").arg((u32)(100*calculated_output[2]));
    if(max_value_index == 3)    str = QString("% %1 ihtimal three").arg((u32)(100*calculated_output[3]));
    if(max_value_index == 4)    str = QString("% %1 ihtimal four").arg((u32)(100*calculated_output[4]));
    if(max_value_index == 5)    str = QString("% %1 ihtimal five").arg((u32)(100*calculated_output[5]));

    mainwindow->ui->label_76800_1024_1024_6_test->setText(str);

}

void ann::_76800_1024_1024_6_ann_train( double input[1344][6*3], double desired_output[6][6], double calculated_output[6][6],
                                        double hidden_neuron_bias_1[1024], double hidden_neuron_bias_2[1024],double hidden_neuron_bias_3[1024],
                                        double output_bias[6],
                                        double w_input_to_hidden_1[1344][1024],
                                        double w_hidden_1_to_hidden_2[1024][1024],
                                        double w_hidden_2_to_hidden_3[1024][1024],
                                        double w_hidden_3_to_output[1024][6],
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

    double output_error[OUTPUT_COUNT];
    double global_error[OUTPUT_COUNT];
    double output_in[OUTPUT_COUNT];
    double output_out[OUTPUT_COUNT];

    double inset_error[INPUT_SET];

    for(u32 era = 0; era < epoch; era++){
        for(u16 inset = 0; inset < INPUT_SET; inset++){
            for(u32 k = 0; k < IO_ARRAY_LENGTH; k++){
                learning_rate = mainwindow->ui->doubleSpinBox->value() * mainwindow->ui->doubleSpinBox_2->value();

                /*****************FORWARD PROPAGATION********************/
                /*******************INPUT TO HIDDEN1*********************/
                for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                    hidden_neuron_in_1[i] = hidden_neuron_bias_1[i];
                }
                for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                    for(u32 j = 0; j < INPUT_COUNT; j++){
                        hidden_neuron_in_1[i] += input[j][k + 6*inset]*w_input_to_hidden_1[j][i];
                    }
                }
                for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                    hidden_neuron_out_1[i] = sigmoid_func(hidden_neuron_in_1[i]);
                }

                /*******************HIDDEN1 TO HIDDEN2*********************/
                for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                    hidden_neuron_in_2[i] = hidden_neuron_bias_2[i];
                }
                for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                    for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
                        hidden_neuron_in_2[i] += hidden_neuron_out_1[j]*w_hidden_1_to_hidden_2[j][i];
                    }
                }
                for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                    hidden_neuron_out_2[i] = sigmoid_func(hidden_neuron_in_2[i]);
                }

                /*******************HIDDEN2 TO HIDDEN3*********************/
                for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
                    hidden_neuron_in_3[i] = hidden_neuron_bias_3[i];
                }
                for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
                    for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
                        hidden_neuron_in_3[i] += hidden_neuron_out_2[j]*w_hidden_2_to_hidden_3[j][i];
                    }
                }
                for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
                    hidden_neuron_out_3[i] = sigmoid_func(hidden_neuron_in_3[i]);
                }

                /*******************HIDDEN3 TO OUTPUT*********************/
                for(u32 j = 0; j < OUTPUT_COUNT; j++){
                    output_in[j] =  output_bias[j];
                    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
                        output_in[j] += hidden_neuron_out_3[i]*w_hidden_3_to_output[i][j];
                    }
                    output_out[j]   = output_sigmoid_func(output_in[j]);
                    output_error[j] = desired_output[j][k] - output_out[j];
                    calculated_output[j][k] = output_out[j];
                    global_error[j] = output_derivative_of_sigmoid_func(output_in[j]) * output_error[j];
                }

                /********************BACKPROPAGATION**********************/
                /*******************OUTPUT TO HIDDEN3*********************/
                for(u32 j = 0; j < OUTPUT_COUNT; j++){
                    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
                        w_hidden_3_to_output[i][j] += global_error[j] * hidden_neuron_out_3[i] * learning_rate;
                    }
                }
                for(u32 i = 0; i < OUTPUT_COUNT; i++){
                    output_bias[i] += global_error[i] * learning_rate;
                }
                for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
                    hidden_neuron_error_3[i] = 0;
                }
                for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
                    for(u32 j = 0; j < OUTPUT_COUNT; j++){
                        hidden_neuron_error_3[i] += derivative_of_sigmoid_func(hidden_neuron_in_3[i]) * global_error[j] * w_hidden_3_to_output[i][j];
                    }
                }

                /*******************HIDDEN3 TO HIDDEN2*********************/
                for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
                    for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
                        w_hidden_2_to_hidden_3[j][i] += hidden_neuron_error_3[i] * hidden_neuron_out_2[j] * learning_rate;
                    }
                }
                for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
                    hidden_neuron_bias_3[i] += hidden_neuron_error_3[i] * learning_rate;
                }
                for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                    hidden_neuron_error_2[i] = 0;
                }
                for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                    for(u32 j = 0; j < HIDDEN_COUNT_3; j++){
                        hidden_neuron_error_2[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_2[i]) * hidden_neuron_error_3[j] * w_hidden_2_to_hidden_3[i][j];
                    }
                }

                /*******************HIDDEN2 TO HIDDEN1*********************/
                for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                    for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
                        w_hidden_1_to_hidden_2[j][i] += hidden_neuron_error_2[i] * hidden_neuron_out_1[j] * learning_rate;
                    }
                }
                for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                    hidden_neuron_bias_2[i] += hidden_neuron_error_2[i] * learning_rate;
                }
                for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                    hidden_neuron_error_1[i] = 0;
                }
                for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                    for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
                        hidden_neuron_error_1[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_1[i]) * hidden_neuron_error_2[j] * w_hidden_1_to_hidden_2[i][j];
                    }
                }

                /*******************HIDDEN1 TO INPUT*********************/
                for(u32 i = 0; i < INPUT_COUNT; i++){
                    for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
                        w_input_to_hidden_1[i][j] += hidden_neuron_error_1[j] * input[i][k + 6*inset] * learning_rate;
                    }
                }
                for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                    hidden_neuron_bias_1[i] +=hidden_neuron_error_1[i] * learning_rate;
                }
            }
            inset_error[inset] = _76800_1024_1024_6_ann_calculate_total_error();
        }
        net_76800_1024_1024_6.total_err =  (inset_error[0]*inset_error[0] + inset_error[1]*inset_error[1] + inset_error[2]*inset_error[2])/3;
        epoch_no = era;
        epoch_status = (era*100)/epoch;
        if(stop_the_training == 1) break;
    }
}
void MainWindow::_76800_1024_1024_6_random_initilize_handler(void){
    _76800_1024_1024_6_picture_to_arrays();

    /********************************SET 1***********************************/
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][0] = fist_image_1[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][1] = one_image_1[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][2] = two_image_1[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][3] = three_image_1[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][4] = four_image_1[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][5] = five_image_1[i][j];
        }
    }

    /********************************SET 2***********************************/
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][6] = fist_image_2[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][7] = one_image_2[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][8] = two_image_2[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][9] = three_image_2[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][10] = four_image_2[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][11] = five_image_2[i][j];
        }
    }

    /********************************SET 3***********************************/
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][12] = fist_image_3[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][13] = one_image_3[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][14] = two_image_3[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][15] = three_image_3[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][16] = four_image_3[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][17] = five_image_3[i][j];
        }
    }


    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            ann_class->net_76800_1024_1024_6.desired_output[i][j] = 0;
            if(i == j){
                ann_class->net_76800_1024_1024_6.desired_output[i][j] = 1;
            }
        }
    }

    qsrand(QDateTime::currentMSecsSinceEpoch());

    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        //ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1[i] = 0.01 + 0.001*i;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        //ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[i] = 0.02 + 0.001*i;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_3[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        //ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[i] = 0.02 + 0.001*i;
    }
    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        ann_class->net_76800_1024_1024_6.output_bias[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        //ann_class->net_76800_1024_1024_6.output_bias[i] = 0.03 + 0.001*i;
    }

    for(u32 i = 0; i < INPUT_COUNT; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
            ann_class->net_76800_1024_1024_6.w_input_to_hidden_1[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
            //ann_class->net_76800_1024_1024_6.w_input_to_hidden[i][j] = -0.3 + 0.001*i;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_1_to_hidden_2[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
            //ann_class->net_76800_1024_1024_6.w_hidden_to_hidden[i][j] = -0.2 + 0.001*i;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_3; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_2_to_hidden_3[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
            //ann_class->net_76800_1024_1024_6.w_hidden_to_hidden[i][j] = -0.2 + 0.001*i;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_3_to_output[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
            //ann_class->net_76800_1024_1024_6.w_hidden_to_output[i][j] = -0.1 + 0.001*i;
        }
    }

    ui->label_76800_1024_1024_6_random_initilize->setText("Initilized randomly");
}
void MainWindow::_76800_1024_1024_6_train_handler(void){
    ann_class->train_status = 1;
    ann_class->stop_the_training = 0;
}
void MainWindow::_76800_1024_1024_6_test_handler(void){

    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.test_input[i + 32*j] = five_image_2[i][j];
        }
    }

    ann_class->_76800_1024_1024_6_ann_test( ann_class->net_76800_1024_1024_6.test_input,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_3,
                                            ann_class->net_76800_1024_1024_6.output_bias,
                                            ann_class->net_76800_1024_1024_6.w_input_to_hidden_1,
                                            ann_class->net_76800_1024_1024_6.w_hidden_1_to_hidden_2,
                                            ann_class->net_76800_1024_1024_6.w_hidden_2_to_hidden_3,
                                            ann_class->net_76800_1024_1024_6.w_hidden_3_to_output);

}
void MainWindow::_76800_1024_1024_6_show_weights_handler(void){
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        qDebug() << QString("hidden_bias_1[%1] : ").arg(i) << ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1[i];
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        qDebug() << QString("hidden_bias_2[%1] : ").arg(i) << ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[i];
    }
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        qDebug() << QString("hidden_bias_3[%1] : ").arg(i) << ann_class->net_76800_1024_1024_6.hidden_neuron_bias_3[i];
    }
    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        qDebug() << QString("output_bias[%1] : ").arg(i) << ann_class->net_76800_1024_1024_6.output_bias[i];
    }

    for(u32 i = 0; i < INPUT_COUNT; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
            qDebug() << QString("w_input_to_hidden_1[%1][%2] : ").arg(i).arg(j) << ann_class->net_76800_1024_1024_6.w_input_to_hidden_1[i][j];
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
            qDebug() << QString("w_hidden_1_to_hidden_2[%1][%2] : ").arg(i).arg(j) << ann_class->net_76800_1024_1024_6.w_hidden_1_to_hidden_2[i][j];
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_3; j++){
            qDebug() << QString("w_hidden_2_to_hidden_3[%1][%2] : ").arg(i).arg(j) << ann_class->net_76800_1024_1024_6.w_hidden_2_to_hidden_3[i][j];
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_3; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            qDebug() << QString("w_hidden_3_to_output[%1][%2] : ").arg(i).arg(j) << ann_class->net_76800_1024_1024_6.w_hidden_3_to_output[i][j];
        }
    }
    ui->label_76800_1024_1024_6_show_weights->setText("Showed..");
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
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            settings.setValue(QString("h32o-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_3_to_output[i][j]);
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
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_3_to_output[i][j] = settings.value(QString("w/h32o-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    ui->label_76800_1024_1024_6_load_saved_weights->setText("Loaded..");
}
void MainWindow::_76800_1024_1024_6_stop_train_handler(void){
    ann_class->stop_the_training = 1;
}
void MainWindow::_76800_1024_1024_6_picture_to_arrays(void){
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast/fist.jpg",fist_image_1);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast/one.jpg",one_image_1);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast/two.jpg",two_image_1);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast/three.jpg",three_image_1);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast/four.jpg",four_image_1);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast/five.jpg",five_image_1);

    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast_2/fist.jpg",fist_image_2);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast_2/one.jpg",one_image_2);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast_2/two.jpg",two_image_2);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast_2/three.jpg",three_image_2);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast_2/four.jpg",four_image_2);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast_2/five.jpg",five_image_2);
}
void MainWindow::image_to_array_240x320(QString location, u8 image_array[32][42]){
    QImage read_image;

    read_image.load(location);

    for(u8 i = 0; i < read_image.width();i++){
        for(u8 j = 0; j < read_image.height();j++){
            image_array[i][j] = 0;
            if((read_image.pixel(i,j) & 0xFF) == 0xFF){
                image_array[i][j] = 1;
            }
            //qDebug() << QString("array[%1][%2] :").arg(i).arg(j) << QString("%1").arg(image_array[i][j],0,16);
        }
    }
}
