#include "mainwindow.h"
#include "choose_the_category_of_question.h"
#include "ui_choose_the_category_of_question.h"
#include "QPixmap"
#include "QWidget"
#include "QLabel"
#include <QApplication>
#include "QPushButton"
#include "QGraphicsView"
#include "QVBoxLayout"
#include "QDebug"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Start The Game");
    w.resize(1677721555, 16777215);
    // w.on_graphicsView_rubberBandChanged();
    // label->setStyleSheet("background-image : url('C:/Users/ModernSystem/Downloads/images_project.jfif');");
    //w.setStyleSheet("background-image : url('C:/Users/ModernSystem/Downloads/images_project.jfif');");
    //w.resize(900,900);
    //QLabel label(&w);
    //QPixmap image("C:/Users/ModernSystem/Downloads/Quiz-Of-Kings-Cover.jpg");
    //label.setPixmap(image);
    //label.resize(w.size());

    w.show();
    return a.exec();

}
