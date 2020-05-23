#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ann_class = new ann(this);

    QPixmap my_pixmap;
    my_pixmap.load("/home/ahmet/Desktop/my_hand/240x320_full_contrast/two.jpg");
    ui->label_hand_two->setPixmap(my_pixmap);

}

MainWindow::~MainWindow()
{
    delete ui;
}
