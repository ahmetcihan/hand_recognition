#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ann.h"
#include <math.h>
#include <QDateTime>
#include <QElapsedTimer>
#include <QSettings>
#include <QProcess>
#include <QFileDialog>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
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

    u8 object_image[80][60][3];
    u32 ball_pos_x;
    u32 ball_pos_y;
    u8 auto_pointer;

    QString tester_file_name;

    void image_to_array_80x60(QString location, u8 image_array[80][60][3]);

protected:
    void mousePressEvent(QMouseEvent * event);

private:
    ann *ann_class;
    QTimer *_100_msec_timer;
    QTimer *periodic_timer;

    cv::VideoCapture my_vid;

private slots:
    void capture_video(void);

    void _100_msec_timer_handle(void);

    void _76800_1024_1024_6_random_initilize_handler(void);
    void _76800_1024_1024_6_load_saved_weights_handler(void);
    void _76800_1024_1024_6_train_handler(void);
    void _76800_1024_1024_6_test_handler(void);
    void _76800_1024_1024_6_save_weights_handler(void);
    void _76800_1024_1024_6_stop_train_handler(void);

    void get_object_picture_automatic();

    void start_stream(void);

    void select_tester_file(void);

    void image_manipulation(void);

public slots:
    void _76800_1024_1024_6_picture_to_arrays(u32 inset);
    void get_image(void);
    void save_image_location(void);
    void start_auto_pointer(void);
    void stop_auto_pointer(void);

};

#endif // MAINWINDOW_H
