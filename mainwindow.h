#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ann.h"
#include <math.h>
#include <QDateTime>
#include <QSettings>
#include <QProcess>
#include <QPainter>
#include <QPixmap>

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

    u8 fist_image[32][42];
    u8 one_image[32][42];
    u8 two_image[32][42];
    u8 three_image[32][42];
    u8 four_image[32][42];
    u8 five_image[32][42];

    void image_to_array_240x320(QString location, u8 image_array[32][42]);

private:
    ann *ann_class;
    QTimer *_100_msec_timer;

private slots:
    void _100_msec_timer_handle(void);

    void _76800_1024_1024_6_random_initilize_handler(void);
    void _76800_1024_1024_6_load_saved_weights_handler(void);
    void _76800_1024_1024_6_train_handler(void);
    void _76800_1024_1024_6_test_handler(void);
    void _76800_1024_1024_6_show_weights_handler(void);
    void _76800_1024_1024_6_save_weights_handler(void);
    void _76800_1024_1024_6_stop_train_handler(void);
    void _76800_1024_1024_6_picture_to_arrays(void);

};

#endif // MAINWINDOW_H
