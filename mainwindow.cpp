#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "choose_the_type_of_game.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{
    //rui->graphicsView->setStyleSheet("background-image : url('C:/Users/ModernSystem/Documents/tamrin_asly/image.jpg');");
}


void MainWindow::on_pushButton_clicked()
{
    Choose_the_type_of_game *window = new Choose_the_type_of_game();
    window->setWindowTitle("Choose the type of game");
    window->resize(maximumSize());
    //window->setStyleSheet("background-image: {"Downloads"});
    window->show();
}


void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{
    //->setStyleSheet("background-image : url('C:/Users/ModernSystem/Documents/tamrin_asly/image.jpg');");
}


