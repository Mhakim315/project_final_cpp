#include "window_of_question_player.h"
#include "ui_window_of_question_player.h"
#include "QTimer"

window_of_question_player::window_of_question_player(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::window_of_question_player)
{
    ui->setupUi(this);
    sec_in_pvp = 30;
    timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(set_time_in_pvp_window()));
}
window_of_question_player::~window_of_question_player()
{
    delete ui;
}



