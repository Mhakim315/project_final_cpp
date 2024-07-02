#include "category_of_question_mode_pvp.h"
#include "ui_category_of_question_mode_pvp.h"
#include "information_of_players.h"



category_of_question_mode_pvp::category_of_question_mode_pvp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::category_of_question_mode_pvp)
{
    ui->setupUi(this);
}

category_of_question_mode_pvp::~category_of_question_mode_pvp()
{
    delete ui;
}

void category_of_question_mode_pvp::on_label_linkActivated(const QString &link)
{
    // choose_the_difficulty *window_of_difficulty = new choose_the_difficulty();
    // window_of_difficulty->setWindowTitle("Choose the Difficulty of question");
    // window_of_difficulty->show
}


void category_of_question_mode_pvp::on_pushButton_clicked()
{

}


void category_of_question_mode_pvp::on_Sport_clicked()
{

}

