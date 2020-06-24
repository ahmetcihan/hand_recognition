#include "ann.h"
#include "mainwindow.h"
#include "ui_ann.h"
#include "ui_mainwindow.h"

void MainWindow::get_object_picture_automatic(){
    static int pic_no = 1;
    QImage img = ui->label_video_small_monochrome_2->pixmap()->toImage();

    img.save(QString("/home/ahmet/Desktop/objects/object_%1.jpg").arg(pic_no),0,100);
    ui->label_snap_auto_object->setText(QString::number(pic_no));
    if(pic_no < ui->spinBox_snapshot_object_last->value()){
        pic_no++;
        QTimer::singleShot(1000,this,SLOT(get_object_picture_automatic()));
    }
    else{
        pic_no = 1;
    }
}
void MainWindow::get_image(void){
    QImage read_image;
    read_image.load(QString("/home/ahmet/Desktop/objects/object_%1.jpg").arg(ui->spinBox_get_image_no->value()));

    QPixmap my_pix = QPixmap::fromImage(read_image);
    ui->label_small_image->setPixmap(my_pix);

}
void MainWindow::save_image_location(void){

    QSettings settings("x_y_pos.ini",QSettings::IniFormat);

    settings.beginGroup("pos");
    settings.setValue(QString("x_%1").arg(ui->spinBox_get_image_no->value()),ball_pos_x);
    settings.setValue(QString("y_%1").arg(ui->spinBox_get_image_no->value()),ball_pos_y);
    settings.endGroup();
    settings.sync();

}
void MainWindow::start_auto_pointer(void){
    auto_pointer = 1;
}
void MainWindow::stop_auto_pointer(void){
    auto_pointer = 0;
}
