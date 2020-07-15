#include "mainwindow.h"

double ann::sigmoid_func(double val){
    //return (1 / (1 + exp(-val)));     //sigmoid   - good
    //return tanh(val);                 //tanh      - not worked
    //return val;                       //identity  - not properly worked
    return atan(val);                 //atan      - not bad but slower
    //return (log(1+exp(val)));         //softplus  - good but slower
    /*********Leaky RELU**********/     //ReLU      -
//    if(val <= 0) return (0.01*val);
//    else return val;
    /*****************************/
    //return (val / (1 + exp(-val)));   //swish     - not bad but not good
    //return exp(-1*val*val);           //gaussien  - not worked
    /***********MINE FUNCTION**********/                                             //ReLU      - very good training but test is bad u:0.000132 is the best
//    if(val > 6) return 1;
//    else if (val < -6) return 0;
//    else return (val + 6)/12;
    /*****************************/
    //return val/(1+fabs(val));           //softsign
}
double ann::derivative_of_sigmoid_func(double val){
    //return (sigmoid_func(val) * (1 - sigmoid_func(val)));                     //sigmoid   - good - u:0.8 is the best
    //return (1 - tanh(val)*tanh(val));                                         //tanh      - not worked
    //return 1;                                                                 //identity  - not properly worked
    return (1 / (1 + val*val));                                               //atan      - not bad but slower
    //return (1 / (1 + exp(-val)));                                             //softplus  - good but slower
    /***************RELU**********/                                             //ReLU      - very good training but test is bad u:0.000132 is the best
//    if(val <= 0) return 0.01;
//    else return 1;
    /*****************************/
    //return (1 + exp(-val) + val*exp(-val))/((1 + exp(-val))*(1 + exp(-val))); //swish     - not bad but not good
    //return -2*val*sigmoid_func(val);                                          //gaussien  - not worked
    /***********MINE FUNCTION**********/                                             //ReLU      - very good training but test is bad u:0.000132 is the best
//    if(val > 6) return 0;
//    else if (val < -6) return 0;
//    else return 1/12;
    /*****************************/
    //return val/((1+fabs(val)) * (1+fabs(val)));           //softsign
}
double ann::output_sigmoid_func(double val){
    //return (1 / (1 + exp(-val)));     //sigmoid   - good
    //return exp(-1*val*val);           //gaussien
    /*********Leaky RELU**********/     //ReLU      -
    //if(val <= 0) return (0.01*val);
    //else return val;
    /*****************************/
    return atan(val);                 //atan      - not bad but slower
    //return (log(1+exp(val)));         //softplus  - good but slower
    //return tanh(val);                 //tanh      - not worked
    //return val;                       //identity  - not properly worked
    //return val/(1+fabs(val));           //softsign
}
double ann::output_derivative_of_sigmoid_func(double val){
    //return (sigmoid_func(val) * (1 - sigmoid_func(val)));                     //sigmoid   - good - u:0.8 is the best
    //return -2*val*sigmoid_func(val);                                          //gaussien
    /***************RELU**********/                                             //ReLU      - very good training but test is bad u:0.000132 is the best
    //if(val <= 0) return 0.01;
    //else return 1;
    /*****************************/
    return (1 / (1 + val*val));                                               //atan      - not bad but slower
    //return (1 / (1 + exp(-val)));                                             //softplus  - good but slower
    //return (1 - tanh(val)*tanh(val));                                         //tanh      - not worked
    //return 1;                                                                 //identity  - not properly worked
    //return val/((1+fabs(val)) * (1+fabs(val)));           //softsign
}
double ann::classic_MA_1(double raw_signal){
    static double running_average[64];
    double processed_value = 0;
    uint16_t j;
    static u8 do_it_once = 1;
    u8 filter_coefficient = 8;

    if(do_it_once == 1){
        do_it_once = 0;
        for(u8 i = 0; i < 64; i++){
            running_average[i] = 0;
        }
    }

    for (j = 0; j < (filter_coefficient-1); j++){
        running_average[j] = running_average[j+1];
        processed_value += running_average[j];
    }
    running_average[filter_coefficient-1] = raw_signal;
    processed_value += raw_signal;

    processed_value = (processed_value)/(filter_coefficient);

    return processed_value;
}
double ann::classic_MA_2(double raw_signal){
    static double running_average[64];
    double processed_value = 0;
    uint16_t j;
    static u8 do_it_once = 1;
    u8 filter_coefficient = 8;

    if(do_it_once == 1){
        do_it_once = 0;
        for(u8 i = 0; i < 64; i++){
            running_average[i] = 0;
        }
    }

    for (j = 0; j < (filter_coefficient-1); j++){
        running_average[j] = running_average[j+1];
        processed_value += running_average[j];
    }
    running_average[filter_coefficient-1] = raw_signal;
    processed_value += raw_signal;

    processed_value = (processed_value)/(filter_coefficient);

    return processed_value;
}
