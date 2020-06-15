#include "ann.h"
#include "mainwindow.h"
#include "ui_ann.h"
#include "ui_mainwindow.h"

void MainWindow::get_fist_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_fist->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/gloves/fist/fist_%1.jpg").arg(ui->spinBox_snapshot_no->value()),0,100);
}
void MainWindow::get_stop_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_stop->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/gloves/stop/stop_%1.jpg").arg(ui->spinBox_snapshot_no->value()),0,100);
}
void MainWindow::get_up_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_up->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/gloves/up/up_%1.jpg").arg(ui->spinBox_snapshot_no->value()),0,100);
}
void MainWindow::get_left_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_left->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/gloves/left/left_%1.jpg").arg(ui->spinBox_snapshot_no->value()),0,100);
}
void MainWindow::get_right_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_right->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/gloves/right/right_%1.jpg").arg(ui->spinBox_snapshot_no->value()),0,100);
}
void MainWindow::get_five_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_five->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/gloves/five/five_%1.jpg").arg(ui->spinBox_snapshot_no->value()),0,100);
}

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
void MainWindow::get_up_picture_automatic(){
    static int pic_no = 1;
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    img.save(QString("/home/ahmet/Desktop/gloves/up/up_%1.jpg").arg(pic_no),0,100);
    ui->label_snap_auto_up->setText(QString::number(pic_no));
    if(pic_no < ui->spinBox_snapshot_up_last->value()){
        pic_no++;
        QTimer::singleShot(100,this,SLOT(get_up_picture_automatic()));
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
void MainWindow::get_right_picture_automatic(){
    static int pic_no = 1;
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    img.save(QString("/home/ahmet/Desktop/gloves/right/right_%1.jpg").arg(pic_no),0,100);
    ui->label_snap_auto_right->setText(QString::number(pic_no));
    if(pic_no < ui->spinBox_snapshot_right_last->value()){
        pic_no++;
        QTimer::singleShot(100,this,SLOT(get_right_picture_automatic()));
    }
    else{
        pic_no = 1;
    }
}
void MainWindow::get_five_picture_automatic(){
    static int pic_no = 1;
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    img.save(QString("/home/ahmet/Desktop/gloves/five/five_%1.jpg").arg(pic_no),0,100);
    ui->label_snap_auto_five->setText(QString::number(pic_no));
    if(pic_no < ui->spinBox_snapshot_five_last->value()){
        pic_no++;
        QTimer::singleShot(100,this,SLOT(get_five_picture_automatic()));
    }
    else{
        pic_no = 1;
    }
}
