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
        QTimer::singleShot(100,this,SLOT(get_object_picture_automatic()));
    }
    else{
        pic_no = 1;
    }
}
