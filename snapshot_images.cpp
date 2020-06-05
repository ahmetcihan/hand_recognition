#include "ann.h"
#include "mainwindow.h"
#include "ui_ann.h"
#include "ui_mainwindow.h"

void MainWindow::get_fist_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_fist->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/gloves/fist/fist_%1.jpg").arg(ui->spinBox_snapshot_no->value()));
}
void MainWindow::get_stop_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_stop->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/gloves/stop/stop_%1.jpg").arg(ui->spinBox_snapshot_no->value()));
}
void MainWindow::get_up_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_up->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/gloves/up/up_%1.jpg").arg(ui->spinBox_snapshot_no->value()));
}
void MainWindow::get_left_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_left->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/gloves/left/left_%1.jpg").arg(ui->spinBox_snapshot_no->value()));
}
void MainWindow::get_right_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_right->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/gloves/right/right_%1.jpg").arg(ui->spinBox_snapshot_no->value()));
}
void MainWindow::get_five_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_five->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/gloves/five/five_%1.jpg").arg(ui->spinBox_snapshot_no->value()));
}
