#include "ann.h"
#include "mainwindow.h"
#include "ui_ann.h"
#include "ui_mainwindow.h"

void MainWindow::get_fist_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_fist->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/hands/fist_%1.jpg").arg(ui->spinBox_snapshot_no->value()));
}
void MainWindow::get_two_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_two->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/hands/two_%1.jpg").arg(ui->spinBox_snapshot_no->value()));
}
void MainWindow::get_five_picture(){
    QImage img = ui->label_video_small_monochrome->pixmap()->toImage();
    ui->label_snapshot_five->setPixmap(QPixmap::fromImage(img));
    img.save(QString("/home/ahmet/Desktop/hands/five_%1.jpg").arg(ui->spinBox_snapshot_no->value()));
}
