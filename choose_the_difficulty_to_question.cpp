#include "choose_the_difficulty_to_question.h"
#include "ui_choose_the_difficulty_to_question.h"
#include "window_of_question_player.h"
#include "ui_window_of_question_player.h"
#include "choose_the_category_of_question.h"
#include "information_of_players.h"
#include "mainwindow.h"




choose_the_difficulty_To_question::choose_the_difficulty_To_question(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choose_the_difficulty_To_question)
{
    ui->setupUi(this);
}



choose_the_difficulty_To_question::~choose_the_difficulty_To_question()
{
    delete ui;
}

void choose_the_difficulty_To_question::on_easy_clicked()
{


    // int conter_of_incorrect_answer = 0;


    // QFont font("Times", 12, QFont::Bold);
    // font.setItalic(true);
    // question_of_player_To_pvp_mode *pre = nullptr;
    // while(true)
    // {
    //     question_of_player_To_pvp_mode *window_for_show_question_of_survival_mode = new question_of_player_To_pvp_mode();
    //     window_for_show_question_of_survival_mode->setWindowTitle("Qusetion To player ");
    //     // window_for_show_question_of_survival_mode->resize(600,600);
    //     // QLabel *label = new QLabel("Question for player 1");
    //     // label->setFont(font);
    //     // label->setFixedSize(200,30);
    //     // QVBoxLayout *layout = new QVBoxLayout();
    //     // QPushButton *button_ok = new QPushButton( " ok ");
    //     // button_ok->setFixedSize(130,40);
    //     // button_ok->setFont(font);


    //     // QRadioButton *radio_1 = new QRadioButton("options 1");
    //     // QRadioButton *radio_2 = new QRadioButton("options 2");
    //     // QRadioButton *radio_3 = new QRadioButton("options 3");
    //     // QRadioButton *radio_4 = new QRadioButton("options 4");

    //     // radio_1->setFont(font);
    //     // radio_2->setFont(font);
    //     // radio_3->setFont(font);
    //     // radio_4->setFont(font);

    //     // layout->addWidget(label);
    //     // layout->addWidget(radio_1);
    //     // layout->addWidget(radio_2);
    //     // layout->addWidget(radio_3);
    //     // layout->addWidget(radio_4);
    //     // layout->addWidget(button_ok);


    //     if(pre != nullptr)
    //     {
    //         conter_of_incorrect_answer++;
    //         QObject::connect(pre, &QWidget::destroyed, window_for_show_question_of_survival_mode, &QWidget::show);
    //     }
    //     if(conter_of_incorrect_answer == 5)
    //     {
    //         break;
    //     }
    //     //button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_show_question_of_survival_mode, SLOT(close()));
    //     //window_for_show_question_of_survival_mode->setLayout(layout);
    //     window_for_show_question_of_survival_mode->show();
    //     pre = window_for_show_question_of_survival_mode;

    // }
    //difficulty_of_question_for_pvp_mode = "easy";
    choose_the_category_of_question *window_for_choose_the_difficulty_of_question = new choose_the_category_of_question();
    window_for_choose_the_difficulty_of_question->setWindowTitle("Choose the category of question");
    window_for_choose_the_difficulty_of_question->resize(maximumSize());
    window_for_choose_the_difficulty_of_question->show();


}
void choose_the_difficulty_To_question::on_medium_clicked()
{
    //difficulty_of_question_for_pvp_mode = "medium";
    choose_the_category_of_question *window_for_choose_the_difficulty_of_question = new choose_the_category_of_question();
    window_for_choose_the_difficulty_of_question->setWindowTitle("Choose the category of question");
    window_for_choose_the_difficulty_of_question->resize(maximumSize());
    window_for_choose_the_difficulty_of_question->show();
}


void choose_the_difficulty_To_question::on_hard_clicked()
{
    //difficulty_of_question_for_pvp_mode = "hard";
    choose_the_category_of_question *window_for_choose_the_difficulty_of_question = new choose_the_category_of_question();
    window_for_choose_the_difficulty_of_question->setWindowTitle("Choose the category of question");
    window_for_choose_the_difficulty_of_question->resize(maximumSize());
    window_for_choose_the_difficulty_of_question->show();

}


void choose_the_difficulty_To_question::on_any_difficulty_clicked()
{
    //difficulty_of_question_for_pvp_mode = "";
    choose_the_category_of_question *window_for_choose_the_difficulty_of_question = new choose_the_category_of_question();
    window_for_choose_the_difficulty_of_question->setWindowTitle("Choose the category of question");
    window_for_choose_the_difficulty_of_question->resize(maximumSize());
    window_for_choose_the_difficulty_of_question->show();

}



