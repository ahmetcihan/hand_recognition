#ifndef ANN_H
#define ANN_H

#include <QWidget>
#include <QThread>
#include <QtConcurrentRun>
#include <QTimer>

namespace Ui {
class ann;
}
class MainWindow;

class ann : public QWidget
{
    Q_OBJECT

public:
    explicit ann(MainWindow *master, QWidget *parent = 0);
    ~ann();
    QThread *thread_1;

private:
    Ui::ann *ui;
    MainWindow *mainwindow;
    QTimer* thread_timer;

    double sigmoid_func(double val);
    double derivative_of_sigmoid_func(double val);


private slots:
    void thread_handler(void);

};

#endif // ANN_H
