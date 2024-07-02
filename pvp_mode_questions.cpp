#include "pvp_mode_questions.h"
#include "ui_pvp_mode_questions.h"
#include "class_information_of_question.h"
#include "information_of_players.h"
#include "choose_the_type_of_game.h"
#include "choose_the_difficulty_to_question.h"

#include "QString"
#include "QVBoxLayout"
#include "QLabel"
#include "QFont"
pvp_mode_questions::pvp_mode_questions(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pvp_mode_questions)
{
    ui->setupUi(this);
}

pvp_mode_questions::~pvp_mode_questions()
{
    delete ui;
}
// void information_of_players::record_name_of_players(QString name_player_1, QString name_player_2)
// {
//     name_of_player_1 = name_player_1;
//     name_of_player_2 = name_player_2;
//     return ;
//     qDebug() << name_of_player_1 << " "<<name_of_player_2<<"\n";
// }
void pvp_mode_questions::on_pushButton_clicked()
{
    //information_of_players pl;
    //name_player p;
    QString line_edit_name_of_player_1 = ui->lineEdit->text();
    QString line_edit_name_of_player_2 = ui->lineEdit_2->text();
    name_of_player_1 = line_edit_name_of_player_1;
    name_of_player_2 = line_edit_name_of_player_2;

    choose_the_difficulty_To_question *window_of_choose_the_category = new choose_the_difficulty_To_question();
    window_of_choose_the_category->setWindowTitle("Choose the Difficulty of question");
    window_of_choose_the_category->resize(maximumSize());
    window_of_choose_the_category->show();



}


void pvp_mode_questions::on_commandLinkButton_clicked()
{
    Choose_the_type_of_game *window_for_show_mode = new Choose_the_type_of_game();
    window_for_show_mode->setWindowTitle("Choose the type of game");
    window_for_show_mode->resize(maximumSize());
    window_for_show_mode->show();
    pvp_mode_questions::close();
}

