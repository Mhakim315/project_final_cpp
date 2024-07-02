#include "choose_the_difficulty.h"
#include "ui_choose_the_difficulty.h"

choose_the_difficulty::choose_the_difficulty(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choose_the_difficulty)
{
    ui->setupUi(this);
}

choose_the_difficulty::~choose_the_difficulty()
{
    delete ui;
}
