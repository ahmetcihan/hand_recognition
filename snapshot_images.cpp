#include "ann.h"
#include "mainwindow.h"
#include "ui_ann.h"
#include "ui_mainwindow.h"

void MainWindow::get_fist_picture_automatic(){
    static int pic_no = 1;
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    img.save(QString("/home/ahmet/Desktop/gloves/fist/fist_%1.jpg").arg(pic_no),0,100);
    ui->label_snap_auto_fist->setText(QString::number(pic_no));
    if(pic_no < ui->spinBox_snapshot_fist_last->value()){
        pic_no++;
        QTimer::singleShot(100,this,SLOT(get_fist_picture_automatic()));
    }
    else{
        pic_no = 1;
    }
}
void MainWindow::get_stop_picture_automatic(){
    static int pic_no = 1;
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    img.save(QString("/home/ahmet/Desktop/gloves/stop/stop_%1.jpg").arg(pic_no),0,100);
    ui->label_snap_auto_stop->setText(QString::number(pic_no));
    if(pic_no < ui->spinBox_snapshot_stop_last->value()){
        pic_no++;
        QTimer::singleShot(100,this,SLOT(get_stop_picture_automatic()));
    }
    else{
        pic_no = 1;
    }
}
void MainWindow::get_left_picture_automatic(){
    static int pic_no = 1;
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    img.save(QString("/home/ahmet/Desktop/gloves/left/left_%1.jpg").arg(pic_no),0,100);
    ui->label_snap_auto_left->setText(QString::number(pic_no));
    if(pic_no < ui->spinBox_snapshot_left_last->value()){
        pic_no++;
        QTimer::singleShot(100,this,SLOT(get_left_picture_automatic()));
    }
    else{
        pic_no = 1;
    }
}
