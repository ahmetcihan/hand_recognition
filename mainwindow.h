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
    u8 two_image[INPUT_SET][30][40];
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

    void get_fist_picture();
    void get_two_picture();
    void get_five_picture();

    void start_stream(void);

    void save_filter_parameters(void);
    void load_filter_parameters(void);
};

#endif // MAINWINDOW_H
