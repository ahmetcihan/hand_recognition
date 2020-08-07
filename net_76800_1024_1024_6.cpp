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
                                         double w_hidden_30_to_output[HIDDEN_COUNT_30][OUTPUT_COUNT]){
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
    double hidden_neuron_in_11[HIDDEN_COUNT_11];
    double hidden_neuron_out_11[HIDDEN_COUNT_11];
    double hidden_neuron_in_12[HIDDEN_COUNT_12];
    double hidden_neuron_out_12[HIDDEN_COUNT_12];
    double hidden_neuron_in_13[HIDDEN_COUNT_13];
    double hidden_neuron_out_13[HIDDEN_COUNT_13];
    double hidden_neuron_in_14[HIDDEN_COUNT_14];
    double hidden_neuron_out_14[HIDDEN_COUNT_14];
    double hidden_neuron_in_15[HIDDEN_COUNT_15];
    double hidden_neuron_out_15[HIDDEN_COUNT_15];
    double hidden_neuron_in_16[HIDDEN_COUNT_16];
    double hidden_neuron_out_16[HIDDEN_COUNT_16];
    double hidden_neuron_in_17[HIDDEN_COUNT_17];
    double hidden_neuron_out_17[HIDDEN_COUNT_17];
    double hidden_neuron_in_18[HIDDEN_COUNT_18];
    double hidden_neuron_out_18[HIDDEN_COUNT_18];
    double hidden_neuron_in_19[HIDDEN_COUNT_19];
    double hidden_neuron_out_19[HIDDEN_COUNT_19];
    double hidden_neuron_in_20[HIDDEN_COUNT_20];
    double hidden_neuron_out_20[HIDDEN_COUNT_20];
    double hidden_neuron_in_21[HIDDEN_COUNT_21];
    double hidden_neuron_out_21[HIDDEN_COUNT_21];
    double hidden_neuron_in_22[HIDDEN_COUNT_22];
    double hidden_neuron_out_22[HIDDEN_COUNT_22];
    double hidden_neuron_in_23[HIDDEN_COUNT_23];
    double hidden_neuron_out_23[HIDDEN_COUNT_23];
    double hidden_neuron_in_24[HIDDEN_COUNT_24];
    double hidden_neuron_out_24[HIDDEN_COUNT_24];
    double hidden_neuron_in_25[HIDDEN_COUNT_25];
    double hidden_neuron_out_25[HIDDEN_COUNT_25];
    double hidden_neuron_in_26[HIDDEN_COUNT_26];
    double hidden_neuron_out_26[HIDDEN_COUNT_26];
    double hidden_neuron_in_27[HIDDEN_COUNT_27];
    double hidden_neuron_out_27[HIDDEN_COUNT_27];
    double hidden_neuron_in_28[HIDDEN_COUNT_28];
    double hidden_neuron_out_28[HIDDEN_COUNT_28];
    double hidden_neuron_in_29[HIDDEN_COUNT_29];
    double hidden_neuron_out_29[HIDDEN_COUNT_29];
    double hidden_neuron_in_30[HIDDEN_COUNT_30];
    double hidden_neuron_out_30[HIDDEN_COUNT_30];

    double output_in[OUTPUT_COUNT];
    double calculated_output[OUTPUT_COUNT];

//    for(u32 i = 0; i < INPUT_COUNT; i++){
//        qDebug() << QString("input[%1] :").arg(i) << input[i];
//    }

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

    /*******************HIDDEN10 TO HIDDEN11*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_11; i++){
        hidden_neuron_in_11[i] = hidden_neuron_bias_11[i];
        for(u32 j = 0; j < HIDDEN_COUNT_10; j++){
            hidden_neuron_in_11[i] += hidden_neuron_out_10[j]*w_hidden_10_to_hidden_11[j][i];
        }
        hidden_neuron_out_11[i] = sigmoid_func(hidden_neuron_in_11[i]);
    }

    /*******************HIDDEN11 TO HIDDEN12*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_12; i++){
        hidden_neuron_in_12[i] = hidden_neuron_bias_12[i];
        for(u32 j = 0; j < HIDDEN_COUNT_11; j++){
            hidden_neuron_in_12[i] += hidden_neuron_out_11[j]*w_hidden_11_to_hidden_12[j][i];
        }
        hidden_neuron_out_12[i] = sigmoid_func(hidden_neuron_in_12[i]);
    }

    /*******************HIDDEN12 TO HIDDEN13*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_13; i++){
        hidden_neuron_in_13[i] = hidden_neuron_bias_13[i];
        for(u32 j = 0; j < HIDDEN_COUNT_12; j++){
            hidden_neuron_in_13[i] += hidden_neuron_out_12[j]*w_hidden_12_to_hidden_13[j][i];
        }
        hidden_neuron_out_13[i] = sigmoid_func(hidden_neuron_in_13[i]);
    }

    /*******************HIDDEN13 TO HIDDEN14*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_14; i++){
        hidden_neuron_in_14[i] = hidden_neuron_bias_14[i];
        for(u32 j = 0; j < HIDDEN_COUNT_13; j++){
            hidden_neuron_in_14[i] += hidden_neuron_out_13[j]*w_hidden_13_to_hidden_14[j][i];
        }
        hidden_neuron_out_14[i] = sigmoid_func(hidden_neuron_in_14[i]);
    }

    /*******************HIDDEN14 TO HIDDEN15*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_15; i++){
        hidden_neuron_in_15[i] = hidden_neuron_bias_15[i];
        for(u32 j = 0; j < HIDDEN_COUNT_14; j++){
            hidden_neuron_in_15[i] += hidden_neuron_out_14[j]*w_hidden_14_to_hidden_15[j][i];
        }
        hidden_neuron_out_15[i] = sigmoid_func(hidden_neuron_in_15[i]);
    }

    /*******************HIDDEN15 TO HIDDEN16*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_16; i++){
        hidden_neuron_in_16[i] = hidden_neuron_bias_16[i];
        for(u32 j = 0; j < HIDDEN_COUNT_15; j++){
            hidden_neuron_in_16[i] += hidden_neuron_out_15[j]*w_hidden_15_to_hidden_16[j][i];
        }
        hidden_neuron_out_16[i] = sigmoid_func(hidden_neuron_in_16[i]);
    }

    /*******************HIDDEN16 TO HIDDEN17*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_17; i++){
        hidden_neuron_in_17[i] = hidden_neuron_bias_17[i];
        for(u32 j = 0; j < HIDDEN_COUNT_16; j++){
            hidden_neuron_in_17[i] += hidden_neuron_out_16[j]*w_hidden_16_to_hidden_17[j][i];
        }
        hidden_neuron_out_17[i] = sigmoid_func(hidden_neuron_in_17[i]);
    }

    /*******************HIDDEN17 TO HIDDEN18*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_18; i++){
        hidden_neuron_in_18[i] = hidden_neuron_bias_18[i];
        for(u32 j = 0; j < HIDDEN_COUNT_17; j++){
            hidden_neuron_in_18[i] += hidden_neuron_out_17[j]*w_hidden_17_to_hidden_18[j][i];
        }
        hidden_neuron_out_18[i] = sigmoid_func(hidden_neuron_in_18[i]);
    }

    /*******************HIDDEN18 TO HIDDEN19*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_19; i++){
        hidden_neuron_in_19[i] = hidden_neuron_bias_19[i];
        for(u32 j = 0; j < HIDDEN_COUNT_18; j++){
            hidden_neuron_in_19[i] += hidden_neuron_out_18[j]*w_hidden_18_to_hidden_19[j][i];
        }
        hidden_neuron_out_19[i] = sigmoid_func(hidden_neuron_in_19[i]);
    }

    /*******************HIDDEN19 TO HIDDEN20*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_20; i++){
        hidden_neuron_in_20[i] = hidden_neuron_bias_20[i];
        for(u32 j = 0; j < HIDDEN_COUNT_19; j++){
            hidden_neuron_in_20[i] += hidden_neuron_out_19[j]*w_hidden_19_to_hidden_20[j][i];
        }
        hidden_neuron_out_20[i] = sigmoid_func(hidden_neuron_in_20[i]);
    }

    /*******************HIDDEN20 TO HIDDEN21*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_21; i++){
        hidden_neuron_in_21[i] = hidden_neuron_bias_21[i];
        for(u32 j = 0; j < HIDDEN_COUNT_20; j++){
            hidden_neuron_in_21[i] += hidden_neuron_out_20[j]*w_hidden_20_to_hidden_21[j][i];
        }
        hidden_neuron_out_21[i] = sigmoid_func(hidden_neuron_in_21[i]);
    }

    /*******************HIDDEN21 TO HIDDEN22*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_22; i++){
        hidden_neuron_in_22[i] = hidden_neuron_bias_22[i];
        for(u32 j = 0; j < HIDDEN_COUNT_21; j++){
            hidden_neuron_in_22[i] += hidden_neuron_out_21[j]*w_hidden_21_to_hidden_22[j][i];
        }
        hidden_neuron_out_22[i] = sigmoid_func(hidden_neuron_in_22[i]);
    }

    /*******************HIDDEN22 TO HIDDEN23*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_23; i++){
        hidden_neuron_in_23[i] = hidden_neuron_bias_23[i];
        for(u32 j = 0; j < HIDDEN_COUNT_22; j++){
            hidden_neuron_in_23[i] += hidden_neuron_out_22[j]*w_hidden_22_to_hidden_23[j][i];
        }
        hidden_neuron_out_23[i] = sigmoid_func(hidden_neuron_in_23[i]);
    }

    /*******************HIDDEN23 TO HIDDEN24*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_24; i++){
        hidden_neuron_in_24[i] = hidden_neuron_bias_24[i];
        for(u32 j = 0; j < HIDDEN_COUNT_23; j++){
            hidden_neuron_in_24[i] += hidden_neuron_out_23[j]*w_hidden_23_to_hidden_24[j][i];
        }
        hidden_neuron_out_24[i] = sigmoid_func(hidden_neuron_in_24[i]);
    }

    /*******************HIDDEN24 TO HIDDEN25*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_25; i++){
        hidden_neuron_in_25[i] = hidden_neuron_bias_25[i];
        for(u32 j = 0; j < HIDDEN_COUNT_24; j++){
            hidden_neuron_in_25[i] += hidden_neuron_out_24[j]*w_hidden_24_to_hidden_25[j][i];
        }
        hidden_neuron_out_25[i] = sigmoid_func(hidden_neuron_in_25[i]);
    }

    /*******************HIDDEN25 TO HIDDEN26*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_26; i++){
        hidden_neuron_in_26[i] = hidden_neuron_bias_26[i];
        for(u32 j = 0; j < HIDDEN_COUNT_25; j++){
            hidden_neuron_in_26[i] += hidden_neuron_out_25[j]*w_hidden_25_to_hidden_26[j][i];
        }
        hidden_neuron_out_26[i] = sigmoid_func(hidden_neuron_in_26[i]);
    }

    /*******************HIDDEN26 TO HIDDEN27*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_27; i++){
        hidden_neuron_in_27[i] = hidden_neuron_bias_27[i];
        for(u32 j = 0; j < HIDDEN_COUNT_26; j++){
            hidden_neuron_in_27[i] += hidden_neuron_out_26[j]*w_hidden_26_to_hidden_27[j][i];
        }
        hidden_neuron_out_27[i] = sigmoid_func(hidden_neuron_in_27[i]);
    }

    /*******************HIDDEN27 TO HIDDEN28*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_28; i++){
        hidden_neuron_in_28[i] = hidden_neuron_bias_28[i];
        for(u32 j = 0; j < HIDDEN_COUNT_27; j++){
            hidden_neuron_in_28[i] += hidden_neuron_out_27[j]*w_hidden_27_to_hidden_28[j][i];
        }
        hidden_neuron_out_28[i] = sigmoid_func(hidden_neuron_in_28[i]);
    }

    /*******************HIDDEN28 TO HIDDEN29*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_29; i++){
        hidden_neuron_in_29[i] = hidden_neuron_bias_29[i];
        for(u32 j = 0; j < HIDDEN_COUNT_28; j++){
            hidden_neuron_in_29[i] += hidden_neuron_out_28[j]*w_hidden_28_to_hidden_29[j][i];
        }
        hidden_neuron_out_29[i] = sigmoid_func(hidden_neuron_in_29[i]);
    }

    /*******************HIDDEN29 TO HIDDEN30*********************/
    for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
        hidden_neuron_in_30[i] = hidden_neuron_bias_30[i];
        for(u32 j = 0; j < HIDDEN_COUNT_29; j++){
            hidden_neuron_in_30[i] += hidden_neuron_out_29[j]*w_hidden_29_to_hidden_30[j][i];
        }
        hidden_neuron_out_30[i] = sigmoid_func(hidden_neuron_in_30[i]);
    }

    /*******************HIDDEN30 TO OUTPUT*********************/
    for(u32 j = 0; j < OUTPUT_COUNT; j++){
        output_in[j] =  output_bias[j];
        for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
            output_in[j] += hidden_neuron_out_30[i]*w_hidden_30_to_output[i][j];
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
    double hidden_neuron_in_11[HIDDEN_COUNT_11];
    double hidden_neuron_out_11[HIDDEN_COUNT_11];
    double hidden_neuron_error_11[HIDDEN_COUNT_11];
    double hidden_neuron_in_12[HIDDEN_COUNT_12];
    double hidden_neuron_out_12[HIDDEN_COUNT_12];
    double hidden_neuron_error_12[HIDDEN_COUNT_12];
    double hidden_neuron_in_13[HIDDEN_COUNT_13];
    double hidden_neuron_out_13[HIDDEN_COUNT_13];
    double hidden_neuron_error_13[HIDDEN_COUNT_13];
    double hidden_neuron_in_14[HIDDEN_COUNT_14];
    double hidden_neuron_out_14[HIDDEN_COUNT_14];
    double hidden_neuron_error_14[HIDDEN_COUNT_14];
    double hidden_neuron_in_15[HIDDEN_COUNT_15];
    double hidden_neuron_out_15[HIDDEN_COUNT_15];
    double hidden_neuron_error_15[HIDDEN_COUNT_15];
    double hidden_neuron_in_16[HIDDEN_COUNT_16];
    double hidden_neuron_out_16[HIDDEN_COUNT_16];
    double hidden_neuron_error_16[HIDDEN_COUNT_16];
    double hidden_neuron_in_17[HIDDEN_COUNT_17];
    double hidden_neuron_out_17[HIDDEN_COUNT_17];
    double hidden_neuron_error_17[HIDDEN_COUNT_17];
    double hidden_neuron_in_18[HIDDEN_COUNT_18];
    double hidden_neuron_out_18[HIDDEN_COUNT_18];
    double hidden_neuron_error_18[HIDDEN_COUNT_18];
    double hidden_neuron_in_19[HIDDEN_COUNT_19];
    double hidden_neuron_out_19[HIDDEN_COUNT_19];
    double hidden_neuron_error_19[HIDDEN_COUNT_19];
    double hidden_neuron_in_20[HIDDEN_COUNT_20];
    double hidden_neuron_out_20[HIDDEN_COUNT_20];
    double hidden_neuron_error_20[HIDDEN_COUNT_20];
    double hidden_neuron_in_21[HIDDEN_COUNT_21];
    double hidden_neuron_out_21[HIDDEN_COUNT_21];
    double hidden_neuron_error_21[HIDDEN_COUNT_21];
    double hidden_neuron_in_22[HIDDEN_COUNT_22];
    double hidden_neuron_out_22[HIDDEN_COUNT_22];
    double hidden_neuron_error_22[HIDDEN_COUNT_22];
    double hidden_neuron_in_23[HIDDEN_COUNT_23];
    double hidden_neuron_out_23[HIDDEN_COUNT_23];
    double hidden_neuron_error_23[HIDDEN_COUNT_23];
    double hidden_neuron_in_24[HIDDEN_COUNT_24];
    double hidden_neuron_out_24[HIDDEN_COUNT_24];
    double hidden_neuron_error_24[HIDDEN_COUNT_24];
    double hidden_neuron_in_25[HIDDEN_COUNT_25];
    double hidden_neuron_out_25[HIDDEN_COUNT_25];
    double hidden_neuron_error_25[HIDDEN_COUNT_25];
    double hidden_neuron_in_26[HIDDEN_COUNT_26];
    double hidden_neuron_out_26[HIDDEN_COUNT_26];
    double hidden_neuron_error_26[HIDDEN_COUNT_26];
    double hidden_neuron_in_27[HIDDEN_COUNT_27];
    double hidden_neuron_out_27[HIDDEN_COUNT_27];
    double hidden_neuron_error_27[HIDDEN_COUNT_27];
    double hidden_neuron_in_28[HIDDEN_COUNT_28];
    double hidden_neuron_out_28[HIDDEN_COUNT_28];
    double hidden_neuron_error_28[HIDDEN_COUNT_28];
    double hidden_neuron_in_29[HIDDEN_COUNT_29];
    double hidden_neuron_out_29[HIDDEN_COUNT_29];
    double hidden_neuron_error_29[HIDDEN_COUNT_29];
    double hidden_neuron_in_30[HIDDEN_COUNT_30];
    double hidden_neuron_out_30[HIDDEN_COUNT_30];
    double hidden_neuron_error_30[HIDDEN_COUNT_30];

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

            /*******************HIDDEN10 TO HIDDEN11*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_11; i++){
                hidden_neuron_in_11[i] = hidden_neuron_bias_11[i];
                for(u32 j = 0; j < HIDDEN_COUNT_10; j++){
                    hidden_neuron_in_11[i] += hidden_neuron_out_10[j]*w_hidden_10_to_hidden_11[j][i];
                }
                hidden_neuron_out_11[i] = sigmoid_func(hidden_neuron_in_11[i]);
            }

            /*******************HIDDEN11 TO HIDDEN12*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_12; i++){
                hidden_neuron_in_12[i] = hidden_neuron_bias_12[i];
                for(u32 j = 0; j < HIDDEN_COUNT_11; j++){
                    hidden_neuron_in_12[i] += hidden_neuron_out_11[j]*w_hidden_11_to_hidden_12[j][i];
                }
                hidden_neuron_out_12[i] = sigmoid_func(hidden_neuron_in_12[i]);
            }

            /*******************HIDDEN12 TO HIDDEN13*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_13; i++){
                hidden_neuron_in_13[i] = hidden_neuron_bias_13[i];
                for(u32 j = 0; j < HIDDEN_COUNT_12; j++){
                    hidden_neuron_in_13[i] += hidden_neuron_out_12[j]*w_hidden_12_to_hidden_13[j][i];
                }
                hidden_neuron_out_13[i] = sigmoid_func(hidden_neuron_in_13[i]);
            }

            /*******************HIDDEN13 TO HIDDEN14*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_14; i++){
                hidden_neuron_in_14[i] = hidden_neuron_bias_14[i];
                for(u32 j = 0; j < HIDDEN_COUNT_13; j++){
                    hidden_neuron_in_14[i] += hidden_neuron_out_13[j]*w_hidden_13_to_hidden_14[j][i];
                }
                hidden_neuron_out_14[i] = sigmoid_func(hidden_neuron_in_14[i]);
            }

            /*******************HIDDEN14 TO HIDDEN15*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_15; i++){
                hidden_neuron_in_15[i] = hidden_neuron_bias_15[i];
                for(u32 j = 0; j < HIDDEN_COUNT_14; j++){
                    hidden_neuron_in_15[i] += hidden_neuron_out_14[j]*w_hidden_14_to_hidden_15[j][i];
                }
                hidden_neuron_out_15[i] = sigmoid_func(hidden_neuron_in_15[i]);
            }

            /*******************HIDDEN15 TO HIDDEN16*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_16; i++){
                hidden_neuron_in_16[i] = hidden_neuron_bias_16[i];
                for(u32 j = 0; j < HIDDEN_COUNT_15; j++){
                    hidden_neuron_in_16[i] += hidden_neuron_out_15[j]*w_hidden_15_to_hidden_16[j][i];
                }
                hidden_neuron_out_16[i] = sigmoid_func(hidden_neuron_in_16[i]);
            }

            /*******************HIDDEN16 TO HIDDEN17*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_17; i++){
                hidden_neuron_in_17[i] = hidden_neuron_bias_17[i];
                for(u32 j = 0; j < HIDDEN_COUNT_16; j++){
                    hidden_neuron_in_17[i] += hidden_neuron_out_16[j]*w_hidden_16_to_hidden_17[j][i];
                }
                hidden_neuron_out_17[i] = sigmoid_func(hidden_neuron_in_17[i]);
            }

            /*******************HIDDEN17 TO HIDDEN18*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_18; i++){
                hidden_neuron_in_18[i] = hidden_neuron_bias_18[i];
                for(u32 j = 0; j < HIDDEN_COUNT_17; j++){
                    hidden_neuron_in_18[i] += hidden_neuron_out_17[j]*w_hidden_17_to_hidden_18[j][i];
                }
                hidden_neuron_out_18[i] = sigmoid_func(hidden_neuron_in_18[i]);
            }

            /*******************HIDDEN18 TO HIDDEN19*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_19; i++){
                hidden_neuron_in_19[i] = hidden_neuron_bias_19[i];
                for(u32 j = 0; j < HIDDEN_COUNT_18; j++){
                    hidden_neuron_in_19[i] += hidden_neuron_out_18[j]*w_hidden_18_to_hidden_19[j][i];
                }
                hidden_neuron_out_19[i] = sigmoid_func(hidden_neuron_in_19[i]);
            }

            /*******************HIDDEN19 TO HIDDEN20*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_20; i++){
                hidden_neuron_in_20[i] = hidden_neuron_bias_20[i];
                for(u32 j = 0; j < HIDDEN_COUNT_19; j++){
                    hidden_neuron_in_20[i] += hidden_neuron_out_19[j]*w_hidden_19_to_hidden_20[j][i];
                }
                hidden_neuron_out_20[i] = sigmoid_func(hidden_neuron_in_20[i]);
            }

            /*******************HIDDEN20 TO HIDDEN21*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_21; i++){
                hidden_neuron_in_21[i] = hidden_neuron_bias_21[i];
                for(u32 j = 0; j < HIDDEN_COUNT_20; j++){
                    hidden_neuron_in_21[i] += hidden_neuron_out_20[j]*w_hidden_20_to_hidden_21[j][i];
                }
                hidden_neuron_out_21[i] = sigmoid_func(hidden_neuron_in_21[i]);
            }

            /*******************HIDDEN21 TO HIDDEN22*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_22; i++){
                hidden_neuron_in_22[i] = hidden_neuron_bias_22[i];
                for(u32 j = 0; j < HIDDEN_COUNT_21; j++){
                    hidden_neuron_in_22[i] += hidden_neuron_out_21[j]*w_hidden_21_to_hidden_22[j][i];
                }
                hidden_neuron_out_22[i] = sigmoid_func(hidden_neuron_in_22[i]);
            }

            /*******************HIDDEN22 TO HIDDEN23*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_23; i++){
                hidden_neuron_in_23[i] = hidden_neuron_bias_23[i];
                for(u32 j = 0; j < HIDDEN_COUNT_22; j++){
                    hidden_neuron_in_23[i] += hidden_neuron_out_22[j]*w_hidden_22_to_hidden_23[j][i];
                }
                hidden_neuron_out_23[i] = sigmoid_func(hidden_neuron_in_23[i]);
            }

            /*******************HIDDEN23 TO HIDDEN24*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_24; i++){
                hidden_neuron_in_24[i] = hidden_neuron_bias_24[i];
                for(u32 j = 0; j < HIDDEN_COUNT_23; j++){
                    hidden_neuron_in_24[i] += hidden_neuron_out_23[j]*w_hidden_23_to_hidden_24[j][i];
                }
                hidden_neuron_out_24[i] = sigmoid_func(hidden_neuron_in_24[i]);
            }

            /*******************HIDDEN24 TO HIDDEN25*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_25; i++){
                hidden_neuron_in_25[i] = hidden_neuron_bias_25[i];
                for(u32 j = 0; j < HIDDEN_COUNT_24; j++){
                    hidden_neuron_in_25[i] += hidden_neuron_out_24[j]*w_hidden_24_to_hidden_25[j][i];
                }
                hidden_neuron_out_25[i] = sigmoid_func(hidden_neuron_in_25[i]);
            }

            /*******************HIDDEN25 TO HIDDEN26*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_26; i++){
                hidden_neuron_in_26[i] = hidden_neuron_bias_26[i];
                for(u32 j = 0; j < HIDDEN_COUNT_25; j++){
                    hidden_neuron_in_26[i] += hidden_neuron_out_25[j]*w_hidden_25_to_hidden_26[j][i];
                }
                hidden_neuron_out_26[i] = sigmoid_func(hidden_neuron_in_26[i]);
            }

            /*******************HIDDEN26 TO HIDDEN27*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_27; i++){
                hidden_neuron_in_27[i] = hidden_neuron_bias_27[i];
                for(u32 j = 0; j < HIDDEN_COUNT_26; j++){
                    hidden_neuron_in_27[i] += hidden_neuron_out_26[j]*w_hidden_26_to_hidden_27[j][i];
                }
                hidden_neuron_out_27[i] = sigmoid_func(hidden_neuron_in_27[i]);
            }

            /*******************HIDDEN27 TO HIDDEN28*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_28; i++){
                hidden_neuron_in_28[i] = hidden_neuron_bias_28[i];
                for(u32 j = 0; j < HIDDEN_COUNT_27; j++){
                    hidden_neuron_in_28[i] += hidden_neuron_out_27[j]*w_hidden_27_to_hidden_28[j][i];
                }
                hidden_neuron_out_28[i] = sigmoid_func(hidden_neuron_in_28[i]);
            }

            /*******************HIDDEN28 TO HIDDEN29*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_29; i++){
                hidden_neuron_in_29[i] = hidden_neuron_bias_29[i];
                for(u32 j = 0; j < HIDDEN_COUNT_28; j++){
                    hidden_neuron_in_29[i] += hidden_neuron_out_28[j]*w_hidden_28_to_hidden_29[j][i];
                }
                hidden_neuron_out_29[i] = sigmoid_func(hidden_neuron_in_29[i]);
            }

            /*******************HIDDEN29 TO HIDDEN30*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
                hidden_neuron_in_30[i] = hidden_neuron_bias_30[i];
                for(u32 j = 0; j < HIDDEN_COUNT_29; j++){
                    hidden_neuron_in_30[i] += hidden_neuron_out_29[j]*w_hidden_29_to_hidden_30[j][i];
                }
                hidden_neuron_out_30[i] = sigmoid_func(hidden_neuron_in_30[i]);
            }

            /*******************HIDDEN30 TO OUTPUT*********************/
            for(u32 j = 0; j < OUTPUT_COUNT; j++){
                output_in[j] =  output_bias[j];
                for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
                    output_in[j] += hidden_neuron_out_30[i]*w_hidden_30_to_output[i][j];
                }
                output_out[j]   = output_sigmoid_func(output_in[j]);
                output_error[j] = desired_output[j] - output_out[j];
                calculated_output[j] = output_out[j];
                global_error[j] = output_derivative_of_sigmoid_func(output_in[j]) * output_error[j];
            }

            /********************BACKPROPAGATION**********************/
            /*******************OUTPUT TO HIDDEN30*********************/
            for(u32 j = 0; j < OUTPUT_COUNT; j++){
                for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
                    w_hidden_30_to_output[i][j] += global_error[j] * hidden_neuron_out_30[i] * learning_rate;
                }
                output_bias[j] += global_error[j] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
                hidden_neuron_error_30[i] = 0;
                for(u32 j = 0; j < OUTPUT_COUNT; j++){
                    hidden_neuron_error_30[i] += derivative_of_sigmoid_func(hidden_neuron_in_30[i]) * global_error[j] * w_hidden_30_to_output[i][j];
                }
            }

            /*******************HIDDEN30 TO HIDDEN29*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_29; j++){
                    w_hidden_29_to_hidden_30[j][i] += hidden_neuron_error_30[i] * hidden_neuron_out_29[j] * learning_rate;
                }
                hidden_neuron_bias_30[i] += hidden_neuron_error_30[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_29; i++){
                hidden_neuron_error_29[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_30; j++){
                    hidden_neuron_error_29[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_29[i]) * hidden_neuron_error_30[j] * w_hidden_29_to_hidden_30[i][j];
                }
            }

            /*******************HIDDEN29 TO HIDDEN28*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_29; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_28; j++){
                    w_hidden_28_to_hidden_29[j][i] += hidden_neuron_error_29[i] * hidden_neuron_out_28[j] * learning_rate;
                }
                hidden_neuron_bias_29[i] += hidden_neuron_error_29[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_28; i++){
                hidden_neuron_error_28[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_29; j++){
                    hidden_neuron_error_28[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_28[i]) * hidden_neuron_error_29[j] * w_hidden_28_to_hidden_29[i][j];
                }
            }

            /*******************HIDDEN28 TO HIDDEN27*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_28; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_27; j++){
                    w_hidden_27_to_hidden_28[j][i] += hidden_neuron_error_28[i] * hidden_neuron_out_27[j] * learning_rate;
                }
                hidden_neuron_bias_28[i] += hidden_neuron_error_28[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_27; i++){
                hidden_neuron_error_27[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_28; j++){
                    hidden_neuron_error_27[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_27[i]) * hidden_neuron_error_28[j] * w_hidden_27_to_hidden_28[i][j];
                }
            }

            /*******************HIDDEN27 TO HIDDEN26*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_27; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_26; j++){
                    w_hidden_26_to_hidden_27[j][i] += hidden_neuron_error_27[i] * hidden_neuron_out_26[j] * learning_rate;
                }
                hidden_neuron_bias_27[i] += hidden_neuron_error_27[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_26; i++){
                hidden_neuron_error_26[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_27; j++){
                    hidden_neuron_error_26[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_26[i]) * hidden_neuron_error_27[j] * w_hidden_26_to_hidden_27[i][j];
                }
            }

            /*******************HIDDEN26 TO HIDDEN25*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_26; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_25; j++){
                    w_hidden_25_to_hidden_26[j][i] += hidden_neuron_error_26[i] * hidden_neuron_out_25[j] * learning_rate;
                }
                hidden_neuron_bias_26[i] += hidden_neuron_error_26[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_25; i++){
                hidden_neuron_error_25[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_26; j++){
                    hidden_neuron_error_25[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_25[i]) * hidden_neuron_error_26[j] * w_hidden_25_to_hidden_26[i][j];
                }
            }

            /*******************HIDDEN25 TO HIDDEN24*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_25; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_24; j++){
                    w_hidden_24_to_hidden_25[j][i] += hidden_neuron_error_25[i] * hidden_neuron_out_24[j] * learning_rate;
                }
                hidden_neuron_bias_25[i] += hidden_neuron_error_25[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_24; i++){
                hidden_neuron_error_24[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_25; j++){
                    hidden_neuron_error_24[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_24[i]) * hidden_neuron_error_25[j] * w_hidden_24_to_hidden_25[i][j];
                }
            }

            /*******************HIDDEN24 TO HIDDEN23*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_24; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_23; j++){
                    w_hidden_23_to_hidden_24[j][i] += hidden_neuron_error_24[i] * hidden_neuron_out_23[j] * learning_rate;
                }
                hidden_neuron_bias_24[i] += hidden_neuron_error_24[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_23; i++){
                hidden_neuron_error_23[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_24; j++){
                    hidden_neuron_error_23[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_23[i]) * hidden_neuron_error_24[j] * w_hidden_23_to_hidden_24[i][j];
                }
            }

            /*******************HIDDEN23 TO HIDDEN22*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_23; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_22; j++){
                    w_hidden_22_to_hidden_23[j][i] += hidden_neuron_error_23[i] * hidden_neuron_out_22[j] * learning_rate;
                }
                hidden_neuron_bias_23[i] += hidden_neuron_error_23[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_22; i++){
                hidden_neuron_error_22[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_23; j++){
                    hidden_neuron_error_22[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_22[i]) * hidden_neuron_error_23[j] * w_hidden_22_to_hidden_23[i][j];
                }
            }

            /*******************HIDDEN22 TO HIDDEN21*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_22; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_21; j++){
                    w_hidden_21_to_hidden_22[j][i] += hidden_neuron_error_22[i] * hidden_neuron_out_21[j] * learning_rate;
                }
                hidden_neuron_bias_22[i] += hidden_neuron_error_22[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_21; i++){
                hidden_neuron_error_21[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_22; j++){
                    hidden_neuron_error_21[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_21[i]) * hidden_neuron_error_22[j] * w_hidden_21_to_hidden_22[i][j];
                }
            }

            /*******************HIDDEN21 TO HIDDEN20*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_21; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_20; j++){
                    w_hidden_20_to_hidden_21[j][i] += hidden_neuron_error_21[i] * hidden_neuron_out_20[j] * learning_rate;
                }
                hidden_neuron_bias_21[i] += hidden_neuron_error_21[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_20; i++){
                hidden_neuron_error_20[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_21; j++){
                    hidden_neuron_error_20[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_20[i]) * hidden_neuron_error_21[j] * w_hidden_20_to_hidden_21[i][j];
                }
            }

            /*******************HIDDEN20 TO HIDDEN19*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_20; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_19; j++){
                    w_hidden_19_to_hidden_20[j][i] += hidden_neuron_error_20[i] * hidden_neuron_out_19[j] * learning_rate;
                }
                hidden_neuron_bias_20[i] += hidden_neuron_error_20[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_19; i++){
                hidden_neuron_error_19[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_20; j++){
                    hidden_neuron_error_19[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_19[i]) * hidden_neuron_error_20[j] * w_hidden_19_to_hidden_20[i][j];
                }
            }

            /*******************HIDDEN19 TO HIDDEN18*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_19; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_18; j++){
                    w_hidden_18_to_hidden_19[j][i] += hidden_neuron_error_19[i] * hidden_neuron_out_18[j] * learning_rate;
                }
                hidden_neuron_bias_19[i] += hidden_neuron_error_19[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_18; i++){
                hidden_neuron_error_18[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_19; j++){
                    hidden_neuron_error_18[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_18[i]) * hidden_neuron_error_19[j] * w_hidden_18_to_hidden_19[i][j];
                }
            }

            /*******************HIDDEN18 TO HIDDEN17*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_18; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_17; j++){
                    w_hidden_17_to_hidden_18[j][i] += hidden_neuron_error_18[i] * hidden_neuron_out_17[j] * learning_rate;
                }
                hidden_neuron_bias_18[i] += hidden_neuron_error_18[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_17; i++){
                hidden_neuron_error_17[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_18; j++){
                    hidden_neuron_error_17[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_17[i]) * hidden_neuron_error_18[j] * w_hidden_17_to_hidden_18[i][j];
                }
            }

            /*******************HIDDEN17 TO HIDDEN16*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_17; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_16; j++){
                    w_hidden_16_to_hidden_17[j][i] += hidden_neuron_error_17[i] * hidden_neuron_out_16[j] * learning_rate;
                }
                hidden_neuron_bias_17[i] += hidden_neuron_error_17[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_16; i++){
                hidden_neuron_error_16[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_17; j++){
                    hidden_neuron_error_16[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_16[i]) * hidden_neuron_error_17[j] * w_hidden_16_to_hidden_17[i][j];
                }
            }

            /*******************HIDDEN16 TO HIDDEN15*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_16; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_15; j++){
                    w_hidden_15_to_hidden_16[j][i] += hidden_neuron_error_16[i] * hidden_neuron_out_15[j] * learning_rate;
                }
                hidden_neuron_bias_16[i] += hidden_neuron_error_16[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_15; i++){
                hidden_neuron_error_15[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_16; j++){
                    hidden_neuron_error_15[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_15[i]) * hidden_neuron_error_16[j] * w_hidden_15_to_hidden_16[i][j];
                }
            }

            /*******************HIDDEN15 TO HIDDEN14*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_15; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_14; j++){
                    w_hidden_14_to_hidden_15[j][i] += hidden_neuron_error_15[i] * hidden_neuron_out_14[j] * learning_rate;
                }
                hidden_neuron_bias_15[i] += hidden_neuron_error_15[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_14; i++){
                hidden_neuron_error_14[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_15; j++){
                    hidden_neuron_error_14[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_14[i]) * hidden_neuron_error_15[j] * w_hidden_14_to_hidden_15[i][j];
                }
            }

            /*******************HIDDEN14 TO HIDDEN13*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_14; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_13; j++){
                    w_hidden_13_to_hidden_14[j][i] += hidden_neuron_error_14[i] * hidden_neuron_out_13[j] * learning_rate;
                }
                hidden_neuron_bias_14[i] += hidden_neuron_error_14[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_13; i++){
                hidden_neuron_error_13[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_14; j++){
                    hidden_neuron_error_13[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_13[i]) * hidden_neuron_error_14[j] * w_hidden_13_to_hidden_14[i][j];
                }
            }

            /*******************HIDDEN13 TO HIDDEN12*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_13; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_12; j++){
                    w_hidden_12_to_hidden_13[j][i] += hidden_neuron_error_13[i] * hidden_neuron_out_12[j] * learning_rate;
                }
                hidden_neuron_bias_13[i] += hidden_neuron_error_13[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_12; i++){
                hidden_neuron_error_12[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_13; j++){
                    hidden_neuron_error_12[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_12[i]) * hidden_neuron_error_13[j] * w_hidden_12_to_hidden_13[i][j];
                }
            }

            /*******************HIDDEN12 TO HIDDEN11*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_12; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_11; j++){
                    w_hidden_11_to_hidden_12[j][i] += hidden_neuron_error_12[i] * hidden_neuron_out_11[j] * learning_rate;
                }
                hidden_neuron_bias_12[i] += hidden_neuron_error_12[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_11; i++){
                hidden_neuron_error_11[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_12; j++){
                    hidden_neuron_error_11[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_11[i]) * hidden_neuron_error_12[j] * w_hidden_11_to_hidden_12[i][j];
                }
            }

            /*******************HIDDEN11 TO HIDDEN10*********************/
            for(u32 i = 0; i < HIDDEN_COUNT_11; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_10; j++){
                    w_hidden_10_to_hidden_11[j][i] += hidden_neuron_error_11[i] * hidden_neuron_out_10[j] * learning_rate;
                }
                hidden_neuron_bias_11[i] += hidden_neuron_error_11[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_10; i++){
                hidden_neuron_error_10[i] = 0;
                for(u32 j = 0; j < HIDDEN_COUNT_11; j++){
                    hidden_neuron_error_10[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_10[i]) * hidden_neuron_error_11[j] * w_hidden_10_to_hidden_11[i][j];
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
    for(u32 i = 0; i < HIDDEN_COUNT_11; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_11[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_12; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_12[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_13; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_13[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_14; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_14[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_15; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_15[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_16; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_16[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_17; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_17[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_18; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_18[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_19; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_19[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_20; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_20[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_21; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_21[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_22; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_22[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_23; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_23[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_24; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_24[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_25; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_25[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_26; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_26[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_27; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_27[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_28; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_28[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_29; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_29[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_30[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
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
        for(u32 j = 0; j < HIDDEN_COUNT_11; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_10_to_hidden_11[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_11; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_12; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_11_to_hidden_12[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_12; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_13; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_12_to_hidden_13[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_13; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_14; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_13_to_hidden_14[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_14; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_15; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_14_to_hidden_15[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_15; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_16; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_15_to_hidden_16[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_16; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_17; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_16_to_hidden_17[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_17; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_18; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_17_to_hidden_18[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_18; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_19; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_18_to_hidden_19[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_19; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_20; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_19_to_hidden_20[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_20; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_21; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_20_to_hidden_21[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_21; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_22; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_21_to_hidden_22[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_22; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_23; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_22_to_hidden_23[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_23; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_24; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_23_to_hidden_24[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_24; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_25; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_24_to_hidden_25[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_25; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_26; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_25_to_hidden_26[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_26; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_27; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_26_to_hidden_27[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_27; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_28; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_27_to_hidden_28[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_28; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_29; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_28_to_hidden_29[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_29; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_30; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_29_to_hidden_30[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_30_to_output[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
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
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_11,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_12,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_13,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_14,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_15,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_16,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_17,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_18,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_19,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_20,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_21,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_22,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_23,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_24,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_25,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_26,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_27,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_28,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_29,
                                            ann_class->net_76800_1024_1024_6.hidden_neuron_bias_30,
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
                                            ann_class->net_76800_1024_1024_6.w_hidden_10_to_hidden_11,
                                            ann_class->net_76800_1024_1024_6.w_hidden_11_to_hidden_12,
                                            ann_class->net_76800_1024_1024_6.w_hidden_12_to_hidden_13,
                                            ann_class->net_76800_1024_1024_6.w_hidden_13_to_hidden_14,
                                            ann_class->net_76800_1024_1024_6.w_hidden_14_to_hidden_15,
                                            ann_class->net_76800_1024_1024_6.w_hidden_15_to_hidden_16,
                                            ann_class->net_76800_1024_1024_6.w_hidden_16_to_hidden_17,
                                            ann_class->net_76800_1024_1024_6.w_hidden_17_to_hidden_18,
                                            ann_class->net_76800_1024_1024_6.w_hidden_18_to_hidden_19,
                                            ann_class->net_76800_1024_1024_6.w_hidden_19_to_hidden_20,
                                            ann_class->net_76800_1024_1024_6.w_hidden_20_to_hidden_21,
                                            ann_class->net_76800_1024_1024_6.w_hidden_21_to_hidden_22,
                                            ann_class->net_76800_1024_1024_6.w_hidden_22_to_hidden_23,
                                            ann_class->net_76800_1024_1024_6.w_hidden_23_to_hidden_24,
                                            ann_class->net_76800_1024_1024_6.w_hidden_24_to_hidden_25,
                                            ann_class->net_76800_1024_1024_6.w_hidden_25_to_hidden_26,
                                            ann_class->net_76800_1024_1024_6.w_hidden_26_to_hidden_27,
                                            ann_class->net_76800_1024_1024_6.w_hidden_27_to_hidden_28,
                                            ann_class->net_76800_1024_1024_6.w_hidden_28_to_hidden_29,
                                            ann_class->net_76800_1024_1024_6.w_hidden_29_to_hidden_30,
                                            ann_class->net_76800_1024_1024_6.w_hidden_30_to_output);

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
    for(u32 i = 0; i < HIDDEN_COUNT_11; i++){
        settings.setValue(QString("hb11-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_11[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_12; i++){
        settings.setValue(QString("hb12-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_12[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_13; i++){
        settings.setValue(QString("hb13-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_13[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_14; i++){
        settings.setValue(QString("hb14-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_14[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_15; i++){
        settings.setValue(QString("hb15-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_15[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_16; i++){
        settings.setValue(QString("hb16-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_16[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_17; i++){
        settings.setValue(QString("hb17-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_17[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_18; i++){
        settings.setValue(QString("hb18-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_18[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_19; i++){
        settings.setValue(QString("hb19-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_19[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_20; i++){
        settings.setValue(QString("hb20-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_20[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_21; i++){
        settings.setValue(QString("hb21-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_21[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_22; i++){
        settings.setValue(QString("hb22-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_22[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_23; i++){
        settings.setValue(QString("hb23-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_23[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_24; i++){
        settings.setValue(QString("hb24-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_24[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_25; i++){
        settings.setValue(QString("hb25-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_25[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_26; i++){
        settings.setValue(QString("hb26-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_26[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_27; i++){
        settings.setValue(QString("hb27-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_27[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_28; i++){
        settings.setValue(QString("hb28-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_28[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_29; i++){
        settings.setValue(QString("hb29-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_29[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
        settings.setValue(QString("hb30-%1").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_30[i]);
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
        for(u32 j = 0; j < HIDDEN_COUNT_11; j++){
            settings.setValue(QString("h102h11-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_10_to_hidden_11[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_11; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_12; j++){
            settings.setValue(QString("h112h12-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_11_to_hidden_12[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_12; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_13; j++){
            settings.setValue(QString("h122h13-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_12_to_hidden_13[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_13; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_14; j++){
            settings.setValue(QString("h132h14-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_13_to_hidden_14[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_14; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_15; j++){
            settings.setValue(QString("h142h15-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_14_to_hidden_15[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_15; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_16; j++){
            settings.setValue(QString("h152h16-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_15_to_hidden_16[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_16; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_17; j++){
            settings.setValue(QString("h162h17-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_16_to_hidden_17[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_17; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_18; j++){
            settings.setValue(QString("h172h18-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_17_to_hidden_18[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_18; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_19; j++){
            settings.setValue(QString("h182h19-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_18_to_hidden_19[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_19; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_20; j++){
            settings.setValue(QString("h192h20-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_19_to_hidden_20[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_20; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_21; j++){
            settings.setValue(QString("h202h21-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_20_to_hidden_21[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_21; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_22; j++){
            settings.setValue(QString("h212h22-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_21_to_hidden_22[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_22; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_23; j++){
            settings.setValue(QString("h222h23-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_22_to_hidden_23[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_23; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_24; j++){
            settings.setValue(QString("h232h24-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_23_to_hidden_24[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_24; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_25; j++){
            settings.setValue(QString("h242h25-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_24_to_hidden_25[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_25; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_26; j++){
            settings.setValue(QString("h252h26-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_25_to_hidden_26[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_26; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_27; j++){
            settings.setValue(QString("h262h27-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_26_to_hidden_27[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_27; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_28; j++){
            settings.setValue(QString("h272h28-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_27_to_hidden_28[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_28; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_29; j++){
            settings.setValue(QString("h282h29-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_28_to_hidden_29[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_29; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_30; j++){
            settings.setValue(QString("h292h30-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_29_to_hidden_30[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            settings.setValue(QString("h302o-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_30_to_output[i][j]);
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
    for(u32 i = 0; i < HIDDEN_COUNT_11; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_11[i] = settings.value(QString("w/hb11-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_12; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_12[i] = settings.value(QString("w/hb12-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_13; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_13[i] = settings.value(QString("w/hb13-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_14; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_14[i] = settings.value(QString("w/hb14-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_15; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_15[i] = settings.value(QString("w/hb15-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_16; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_16[i] = settings.value(QString("w/hb16-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_17; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_17[i] = settings.value(QString("w/hb17-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_18; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_18[i] = settings.value(QString("w/hb18-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_19; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_19[i] = settings.value(QString("w/hb19-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_20; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_20[i] = settings.value(QString("w/hb20-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_21; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_21[i] = settings.value(QString("w/hb21-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_22; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_22[i] = settings.value(QString("w/hb22-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_23; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_23[i] = settings.value(QString("w/hb23-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_24; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_24[i] = settings.value(QString("w/hb24-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_25; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_25[i] = settings.value(QString("w/hb25-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_26; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_26[i] = settings.value(QString("w/hb26-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_27; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_27[i] = settings.value(QString("w/hb27-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_28; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_28[i] = settings.value(QString("w/hb28-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_29; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_29[i] = settings.value(QString("w/hb29-%1").arg(i)).toDouble();
    }
    for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_30[i] = settings.value(QString("w/hb30-%1").arg(i)).toDouble();
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
        for(u32 j = 0; j < HIDDEN_COUNT_11; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_10_to_hidden_11[i][j] = settings.value(QString("w/h102h11-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_11; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_12; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_11_to_hidden_12[i][j] = settings.value(QString("w/h112h12-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_12; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_13; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_12_to_hidden_13[i][j] = settings.value(QString("w/h122h13-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_13; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_14; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_13_to_hidden_14[i][j] = settings.value(QString("w/h132h14-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_14; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_15; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_14_to_hidden_15[i][j] = settings.value(QString("w/h142h15-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_15; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_16; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_15_to_hidden_16[i][j] = settings.value(QString("w/h152h16-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_16; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_17; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_16_to_hidden_17[i][j] = settings.value(QString("w/h162h17-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_17; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_18; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_17_to_hidden_18[i][j] = settings.value(QString("w/h172h18-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_18; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_19; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_18_to_hidden_19[i][j] = settings.value(QString("w/h182h19-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_19; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_20; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_19_to_hidden_20[i][j] = settings.value(QString("w/h192h20-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_20; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_21; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_20_to_hidden_21[i][j] = settings.value(QString("w/h202h21-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_21; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_22; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_21_to_hidden_22[i][j] = settings.value(QString("w/h212h22-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_22; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_23; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_22_to_hidden_23[i][j] = settings.value(QString("w/h222h23-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_23; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_24; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_23_to_hidden_24[i][j] = settings.value(QString("w/h232h24-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_24; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_25; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_24_to_hidden_25[i][j] = settings.value(QString("w/h242h25-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_25; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_26; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_25_to_hidden_26[i][j] = settings.value(QString("w/h252h26-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_26; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_27; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_26_to_hidden_27[i][j] = settings.value(QString("w/h262h27-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_27; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_28; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_27_to_hidden_28[i][j] = settings.value(QString("w/h272h28-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_28; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_29; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_28_to_hidden_29[i][j] = settings.value(QString("w/h282h29-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_29; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_30; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_29_to_hidden_30[i][j] = settings.value(QString("w/h292h30-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_30; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_30_to_output[i][j] = settings.value(QString("w/h302o-%1-%2").arg(i).arg(j)).toDouble();
        }
    }

    ui->label_76800_1024_1024_6_load_saved_weights->setText("Loaded..");
}
void MainWindow::_76800_1024_1024_6_stop_train_handler(void){
    ann_class->stop_the_training = 1;
}
void ann::prepare_inputset(u32 input_s){
    for(u32 i = 0; i < WAVE_LENGTH; i++){
        net_76800_1024_1024_6.input[WAVE_LENGTH*0 + i] = index_no[i + input_s];
        net_76800_1024_1024_6.input[WAVE_LENGTH*1 + i] = waveform[i + input_s];
    }
    net_76800_1024_1024_6.desired_output[0] = OUTPUT_MULTIPLIER * waveform[WAVE_LENGTH + input_s];
    net_76800_1024_1024_6.desired_output[1] = OUTPUT_MULTIPLIER * waveform[WAVE_LENGTH + 1 + input_s];
    net_76800_1024_1024_6.desired_output[2] = OUTPUT_MULTIPLIER * waveform[WAVE_LENGTH + 2 + input_s];
}
