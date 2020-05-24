#include "mainwindow.h"
#include "ui_mainwindow.h"

#define INPUT_COUNT     1344
#define HIDDEN_COUNT_1  512
#define HIDDEN_COUNT_2  512
#define OUTPUT_COUNT    6
#define IO_ARRAY_LENGTH 6

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
                                        double hidden_neuron_bias_1[512], double hidden_neuron_bias_2[512], double output_bias[6],
                                        double w_input_to_hidden[1344][512], double w_hidden_to_hidden[512][512], double w_hidden_to_output[512][6]){
    double hidden_neuron_in_1[HIDDEN_COUNT_1];
    double hidden_neuron_out_1[HIDDEN_COUNT_1];

    double hidden_neuron_in_2[HIDDEN_COUNT_2];
    double hidden_neuron_out_2[HIDDEN_COUNT_2];

    double output_in[OUTPUT_COUNT];
    double calculated_output[OUTPUT_COUNT];

    for(u32 i = 0; i < INPUT_COUNT; i++){
        qDebug() << QString("input[%1] :").arg(i) << input[i];
    }

    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        hidden_neuron_in_1[i] = hidden_neuron_bias_1[i];
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        for(u32 j = 0; j < INPUT_COUNT; j++){
            hidden_neuron_in_1[i] += input[j]*w_input_to_hidden[j][i];
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        hidden_neuron_out_1[i] = sigmoid_func(hidden_neuron_in_1[i]);
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        hidden_neuron_in_2[i] = hidden_neuron_bias_2[i];
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
            hidden_neuron_in_2[i] += hidden_neuron_out_1[j]*w_hidden_to_hidden[j][i];
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        hidden_neuron_out_2[i] = sigmoid_func(hidden_neuron_in_2[i]);
    }

    for(u32 j = 0; j < OUTPUT_COUNT; j++){
        output_in[j] =  output_bias[j];
        for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
            output_in[j] += hidden_neuron_out_2[i]*w_hidden_to_output[i][j];
        }
        calculated_output[j]   = sigmoid_func(output_in[j]);
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

void ann::_76800_1024_1024_6_ann_train(double input[1344][6], double desired_output[6][6], double calculated_output[6][6],
                                        double hidden_neuron_bias_1[512], double hidden_neuron_bias_2[512], double output_bias[6],
                                        double w_input_to_hidden[512][512], double w_hidden_to_hidden[512][512], double w_hidden_to_output[512][6],
                                        u32 epoch, double learning_rate){

    double hidden_neuron_in_1[HIDDEN_COUNT_1];
    double hidden_neuron_out_1[HIDDEN_COUNT_1];
    double hidden_neuron_error_1[HIDDEN_COUNT_1];

    double hidden_neuron_in_2[HIDDEN_COUNT_2];
    double hidden_neuron_out_2[HIDDEN_COUNT_2];
    double hidden_neuron_error_2[HIDDEN_COUNT_2];

    double output_error[OUTPUT_COUNT];
    double global_error[OUTPUT_COUNT];
    double output_in[OUTPUT_COUNT];
    double output_out[OUTPUT_COUNT];

    for(u32 era = 0; era < epoch; era++){
        for(u32 k = 0; k < IO_ARRAY_LENGTH; k++){

            for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                hidden_neuron_in_1[i] = hidden_neuron_bias_1[i];
            }
            for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                for(u32 j = 0; j < INPUT_COUNT; j++){
                    hidden_neuron_in_1[i] += input[j][k]*w_input_to_hidden[j][i];
                }
            }
            for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                hidden_neuron_out_1[i] = sigmoid_func(hidden_neuron_in_1[i]);
            }
            for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                hidden_neuron_in_2[i] = hidden_neuron_bias_2[i];
            }
            for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
                    hidden_neuron_in_2[i] += hidden_neuron_out_1[j]*w_hidden_to_hidden[j][i];
                }
            }
            for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                hidden_neuron_out_2[i] = sigmoid_func(hidden_neuron_in_2[i]);
            }

            for(u32 j = 0; j < OUTPUT_COUNT; j++){
                output_in[j] =  output_bias[j];
                for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                    output_in[j] += hidden_neuron_out_2[i]*w_hidden_to_output[i][j];
                }
                output_out[j]   = sigmoid_func(output_in[j]);
                output_error[j] = desired_output[j][k] - output_out[j];
                calculated_output[j][k] = output_out[j];
                global_error[j] = derivative_of_sigmoid_func(output_in[j]) * output_error[j];
            }

            for(u32 j = 0; j < OUTPUT_COUNT; j++){
                for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                    w_hidden_to_output[i][j] += global_error[j] * hidden_neuron_out_2[i] * learning_rate;
                }
            }

            for(u32 i = 0; i < OUTPUT_COUNT; i++){
                output_bias[i] += global_error[i] * learning_rate;
            }
            for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                hidden_neuron_error_2[i] = 0;
            }

            for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                for(u32 j = 0; j < OUTPUT_COUNT; j++){
                    hidden_neuron_error_2[i] += derivative_of_sigmoid_func(hidden_neuron_in_2[i]) * global_error[j] * w_hidden_to_output[i][j];
                }
            }
            for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
                    w_hidden_to_hidden[j][i] += hidden_neuron_error_2[i] * hidden_neuron_out_1[j] * learning_rate;
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
                    hidden_neuron_error_1[i] +=  derivative_of_sigmoid_func(hidden_neuron_in_1[i]) * hidden_neuron_error_2[j] * w_hidden_to_hidden[i][j];
                }
            }
            for(u32 i = 0; i < INPUT_COUNT; i++){
                for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
                    w_input_to_hidden[i][j] += hidden_neuron_error_1[j] * input[i][k] * learning_rate;
                }
            }

            for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
                hidden_neuron_bias_1[i] +=hidden_neuron_error_1[i] * learning_rate;
            }
        }
        net_76800_1024_1024_6.total_err = output_error[0];
        epoch_no = era;
        epoch_status = (era*100)/epoch;
        if(stop_the_training == 1) break;
    }
}
void MainWindow::_76800_1024_1024_6_random_initilize_handler(void){
    _76800_1024_1024_6_picture_to_arrays();

    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][0] = fist_image[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][1] = one_image[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][2] = two_image[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][3] = three_image[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][4] = four_image[i][j];
        }
    }
    for(u32 j = 0; j < 42; j++){
        for(u32 i = 0; i < 32; i++){
            ann_class->net_76800_1024_1024_6.input[i + 32*j][5] = five_image[i][j];
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
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }
    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        ann_class->net_76800_1024_1024_6.output_bias[i] = ((double) qrand()/RAND_MAX) * (-2) + 1;
    }

    for(u32 i = 0; i < INPUT_COUNT; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
            ann_class->net_76800_1024_1024_6.w_input_to_hidden[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_to_hidden[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_to_output[i][j] = ((double) qrand()/RAND_MAX) * (-2) + 1;
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
            ann_class->net_76800_1024_1024_6.test_input[i + 32*j] = two_image[i][j];
        }
    }

    ann_class->_76800_1024_1024_6_ann_test(ann_class->net_76800_1024_1024_6.test_input,
                                        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1,
                                        ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2,
                                        ann_class->net_76800_1024_1024_6.output_bias,
                                        ann_class->net_76800_1024_1024_6.w_input_to_hidden,
                                        ann_class->net_76800_1024_1024_6.w_hidden_to_hidden,
                                        ann_class->net_76800_1024_1024_6.w_hidden_to_output);

}
void MainWindow::_76800_1024_1024_6_show_weights_handler(void){
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        qDebug() << QString("hidden_bias_1[%1] : ").arg(i) << ann_class->net_76800_1024_1024_6.hidden_neuron_bias_1[i];
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        qDebug() << QString("hidden_bias_2[%1] : ").arg(i) << ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[i];
    }
    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        qDebug() << QString("output_bias[%1] : ").arg(i) << ann_class->net_76800_1024_1024_6.output_bias[i];
    }

    for(u32 i = 0; i < INPUT_COUNT; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
            qDebug() << QString("w_input_to_hidden[%1][%2] : ").arg(i).arg(j) << ann_class->net_76800_1024_1024_6.w_input_to_hidden[i][j];
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
            qDebug() << QString("w_hidden_to_hidden[%1][%2] : ").arg(i).arg(j) << ann_class->net_76800_1024_1024_6.w_hidden_to_hidden[i][j];
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            qDebug() << QString("w_hidden_to_output[%1][%2] : ").arg(i).arg(j) << ann_class->net_76800_1024_1024_6.w_hidden_to_output[i][j];
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
        settings.setValue(QString("hb2-%2").arg(i),ann_class->net_76800_1024_1024_6.hidden_neuron_bias_2[i]);
    }
    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        settings.setValue(QString("ob-%1").arg(i),ann_class->net_76800_1024_1024_6.output_bias[i]);
    }

    for(u32 i = 0; i < INPUT_COUNT; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
            settings.setValue(QString("i2h-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_input_to_hidden[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
            settings.setValue(QString("h2h-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_to_hidden[i][j]);
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            settings.setValue(QString("h2o-%1-%2").arg(i).arg(j),ann_class->net_76800_1024_1024_6.w_hidden_to_output[i][j]);
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
    for(u32 i = 0; i < OUTPUT_COUNT; i++){
        ann_class->net_76800_1024_1024_6.output_bias[i] = settings.value(QString("w/ob-%1").arg(i)).toDouble();
    }

    for(u32 i = 0; i < INPUT_COUNT; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_1; j++){
            ann_class->net_76800_1024_1024_6.w_input_to_hidden[i][j] = settings.value(QString("w/i2h-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_1; i++){
        for(u32 j = 0; j < HIDDEN_COUNT_2; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_to_hidden[i][j] = settings.value(QString("w/h2h-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    for(u32 i = 0; i < HIDDEN_COUNT_2; i++){
        for(u32 j = 0; j < OUTPUT_COUNT; j++){
            ann_class->net_76800_1024_1024_6.w_hidden_to_output[i][j] = settings.value(QString("w/h2o-%1-%2").arg(i).arg(j)).toDouble();
        }
    }
    ui->label_76800_1024_1024_6_load_saved_weights->setText("Loaded..");
}
void MainWindow::_76800_1024_1024_6_stop_train_handler(void){
    ann_class->stop_the_training = 1;
}
void MainWindow::_76800_1024_1024_6_picture_to_arrays(void){
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast/fist.jpg",fist_image);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast/one.jpg",one_image);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast/two.jpg",two_image);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast/three.jpg",three_image);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast/four.jpg",four_image);
    image_to_array_240x320("/home/ahmet/Desktop/my_hand/32x42_full_contrast/five.jpg",five_image);
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
