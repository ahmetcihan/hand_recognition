#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ann.h"
#include <math.h>
#include <QDateTime>
#include <QElapsedTimer>
#include <QSettings>
#include <QProcess>
#include <QPainter>
#include <QPixmap>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "my_macros.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;

    u8 fist_image[INPUT_SET][30][40];
    u8 one_image[INPUT_SET][30][40];
    u8 two_image[INPUT_SET][30][40];
    u8 three_image[INPUT_SET][30][40];
    u8 four_image[INPUT_SET][30][40];
    u8 five_image[INPUT_SET][30][40];

    void image_to_array_30x40(QString location, u8 image_array[30][40]);

private:
    ann *ann_class;
    QTimer *_100_msec_timer;
    QTimer *periodic_timer;

    cv::VideoCapture my_vid;

private slots:
    void capture_video(void);

    void _100_msec_timer_handle(void);

    void _76800_1024_1024_6_prepare_io_pairs_handler(void);
    void _76800_1024_1024_6_random_initilize_handler(void);
    void _76800_1024_1024_6_load_saved_weights_handler(void);
    void _76800_1024_1024_6_train_handler(void);
    void _76800_1024_1024_6_test_handler(void);
    void _76800_1024_1024_6_show_weights_handler(void);
    void _76800_1024_1024_6_save_weights_handler(void);
    void _76800_1024_1024_6_stop_train_handler(void);
    void _76800_1024_1024_6_picture_to_arrays(void);

    void get_fist_1_picture();
    void get_fist_2_picture();
    void get_fist_3_picture();
    void get_fist_4_picture();
    void get_fist_5_picture();
    void get_fist_6_picture();
    void get_fist_7_picture();
    void get_fist_8_picture();
    void get_fist_9_picture();
    void get_fist_10_picture();
    void get_fist_11_picture();
    void get_fist_12_picture();
    void get_fist_13_picture();
    void get_fist_14_picture();
    void get_fist_15_picture();
    void get_fist_16_picture();
    void get_fist_17_picture();
    void get_fist_18_picture();
    void get_fist_19_picture();
    void get_fist_20_picture();
    void get_fist_21_picture();
    void get_fist_22_picture();
    void get_fist_23_picture();
    void get_fist_24_picture();

    void get_one_1_picture();
    void get_one_2_picture();
    void get_one_3_picture();
    void get_one_4_picture();
    void get_one_5_picture();
    void get_one_6_picture();
    void get_one_7_picture();
    void get_one_8_picture();
    void get_one_9_picture();
    void get_one_10_picture();
    void get_one_11_picture();
    void get_one_12_picture();
    void get_one_13_picture();
    void get_one_14_picture();
    void get_one_15_picture();
    void get_one_16_picture();
    void get_one_17_picture();
    void get_one_18_picture();
    void get_one_19_picture();
    void get_one_20_picture();
    void get_one_21_picture();
    void get_one_22_picture();
    void get_one_23_picture();
    void get_one_24_picture();

    void get_two_1_picture();
    void get_two_2_picture();
    void get_two_3_picture();
    void get_two_4_picture();
    void get_two_5_picture();
    void get_two_6_picture();
    void get_two_7_picture();
    void get_two_8_picture();
    void get_two_9_picture();
    void get_two_10_picture();
    void get_two_11_picture();
    void get_two_12_picture();
    void get_two_13_picture();
    void get_two_14_picture();
    void get_two_15_picture();
    void get_two_16_picture();
    void get_two_17_picture();
    void get_two_18_picture();
    void get_two_19_picture();
    void get_two_20_picture();
    void get_two_21_picture();
    void get_two_22_picture();
    void get_two_23_picture();
    void get_two_24_picture();

    void get_three_1_picture();
    void get_three_2_picture();
    void get_three_3_picture();
    void get_three_4_picture();
    void get_three_5_picture();
    void get_three_6_picture();
    void get_three_7_picture();
    void get_three_8_picture();
    void get_three_9_picture();
    void get_three_10_picture();
    void get_three_11_picture();
    void get_three_12_picture();
    void get_three_13_picture();
    void get_three_14_picture();
    void get_three_15_picture();
    void get_three_16_picture();
    void get_three_17_picture();
    void get_three_18_picture();
    void get_three_19_picture();
    void get_three_20_picture();
    void get_three_21_picture();
    void get_three_22_picture();
    void get_three_23_picture();
    void get_three_24_picture();

    void get_four_1_picture();
    void get_four_2_picture();
    void get_four_3_picture();
    void get_four_4_picture();
    void get_four_5_picture();
    void get_four_6_picture();
    void get_four_7_picture();
    void get_four_8_picture();
    void get_four_9_picture();
    void get_four_10_picture();
    void get_four_11_picture();
    void get_four_12_picture();
    void get_four_13_picture();
    void get_four_14_picture();
    void get_four_15_picture();
    void get_four_16_picture();
    void get_four_17_picture();
    void get_four_18_picture();
    void get_four_19_picture();
    void get_four_20_picture();
    void get_four_21_picture();
    void get_four_22_picture();
    void get_four_23_picture();
    void get_four_24_picture();

    void get_five_1_picture();
    void get_five_2_picture();
    void get_five_3_picture();
    void get_five_4_picture();
    void get_five_5_picture();
    void get_five_6_picture();
    void get_five_7_picture();
    void get_five_8_picture();
    void get_five_9_picture();
    void get_five_10_picture();
    void get_five_11_picture();
    void get_five_12_picture();
    void get_five_13_picture();
    void get_five_14_picture();
    void get_five_15_picture();
    void get_five_16_picture();
    void get_five_17_picture();
    void get_five_18_picture();
    void get_five_19_picture();
    void get_five_20_picture();
    void get_five_21_picture();
    void get_five_22_picture();
    void get_five_23_picture();
    void get_five_24_picture();

    void load_snapshot_pictures();

    void start_stream(void);

};

#endif // MAINWINDOW_H
