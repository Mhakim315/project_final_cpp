#include "question_of_player_to_pvp_mode.h"
#include "ui_question_of_player_to_pvp_mode.h"

question_of_player_To_pvp_mode::question_of_player_To_pvp_mode(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::question_of_player_To_pvp_mode)
{
    ui->setupUi(this);
}

question_of_player_To_pvp_mode::~question_of_player_To_pvp_mode()
{
    delete ui;
}

void question_of_player_To_pvp_mode::on_pushButton_clicked()
{

}


void question_of_player_To_pvp_mode::on_label_linkActivated(const QString &link)
{

}


void question_of_player_To_pvp_mode::on_Question_1_clicked()
{

}


void question_of_player_To_pvp_mode::on_pushButton_2_clicked()
{
    ui->label->setText("Question 1 : how to use ?");
    ui->Question_1->setText("salam");
    ui->Question_2->setText("vagth");
    ui->Question_3->setText("boro");
    ui->Question_4->setText("blue");
}

