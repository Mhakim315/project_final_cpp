#include "choose_the_type_of_game.h"
#include "ui_choose_the_type_of_game.h"
#include "mainwindow.h"
#include "choose_the_difficulty_to_question_to_survival_mode.h"
#include "QPushButton"
#include "QWidget"
#include "QLabel"
#include "QPlainTextEdit"
#include "QVBoxLayout"
#include "pvp_mode_questions.h"
#include "ctime"
#include "QTimer"
#include "QTime"
#include "QFont"

Choose_the_type_of_game::Choose_the_type_of_game(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Choose_the_type_of_game)
{
    ui->setupUi(this);
}

Choose_the_type_of_game::~Choose_the_type_of_game()
{
    delete ui;
}

void Choose_the_type_of_game::on_pushButton_3_clicked()
{

    QFont font("Times", 12, QFont::Bold);
    font.setItalic(true);
    QWidget *window_of_descript = new QWidget();
    window_of_descript->setWindowTitle("Description of mode pvp ");
    window_of_descript->resize(400,500);

    // QLabel *descript_of_mode = new QLabel("The series is done, 5 questions for each person in the subject and difficulty level");
    // QLabel *descript_of_mode_1 = new QLabel(" Each round is selected in turn, players are displayed in turn in the round ");
    // QLabel *descript_of_mode_2 = new QLabel(" First, they answer their 5 questions on the topic specified by the first player, ");
    // QLabel *descript_of_mode_3 = new QLabel(" The player who gives the most correct answers among the 5 questions will win the round and ");
    // QLabel *descript_of_mode_4 = new QLabel(" The round points will be awarded to him gave or did not give to both players. ");
    // QLabel *descript_of_mode_5 = new QLabel("The second round of the same operation is repeated with this differenceThe subject of the questions ");
    // QLabel *descript_of_mode_6 = new QLabel("and the level of the questions are determined by the second player . ");

    QTextEdit *text = new QTextEdit("The series is done, 5 questions for each person in the subject and difficulty level  Each round is selected in turn, players are displayed in turn in the round First, they answer their 5 questions on the topic specified by the first player, The player who gives the most correct answers among the 5 questions will win the round and The round points will be awarded to him gave or did not give to both players. The second round of the same operation is repeated with this differenceThe subject of the questions and the level of the questions are determined by the second player .");
    text->setFont(font);
    QVBoxLayout *layout = new QVBoxLayout();
    // layout->addWidget(descript_of_mode);
    // layout->addWidget(descript_of_mode_1);
    // layout->addWidget(descript_of_mode_2);
    // layout->addWidget(descript_of_mode_3);
    // layout->addWidget(descript_of_mode_4);
    // layout->addWidget(descript_of_mode_5);
    // layout->addWidget(descript_of_mode_6);
    layout->addWidget(text);


    QPushButton *ok = new QPushButton("  ok  ");
    layout->addWidget(ok);
    ok->setFixedSize(120,40);
    ok->setFont(font);

    ok->connect(ok, SIGNAL(clicked(bool)), window_of_descript, SLOT(close()));

    window_of_descript->setLayout(layout);


    window_of_descript->show();


}


void Choose_the_type_of_game::on_pushButton_4_clicked()
{
    QFont font("Times", 12, QFont::Bold);
    font.setItalic(true);
    QWidget *window_of_descript = new QWidget();
    window_of_descript->setWindowTitle("Description of mode pvp ");
    window_of_descript->resize(400,500);

    // QLabel *descript_of_mode   = new QLabel("This mod, which is single-player, questions are combined by The computer is selected, ");
    // QLabel *descript_of_mode_1 = new QLabel("only the player must match the level of the match as in the previous mode ");
    // QLabel *descript_of_mode_2 = new QLabel("and he gets points as long as he answers three questions wrongly ");
    // QLabel *descript_of_mode_3 = new QLabel(" Slow and saves High Score for each difficulty level separately.In this mode,");
    // QLabel *descript_of_mode_4 = new QLabel(" the time to answer each question will be 15 seconds ");

    // descript_of_mode->setFont(font);
    // descript_of_mode_1->setFont(font);
    // descript_of_mode_2->setFont(font);
    // descript_of_mode_3->setFont(font);
    // descript_of_mode_4->setFont(font);

    QPlainTextEdit *text = new QPlainTextEdit("This mod, which is single-player, questions are combined by The computer is selected,only the player must match the level of the match as in the previous mode and he gets points as long as he answers three questions wrongly Slow and saves High Score for each difficulty level separately.In this mode,  the time to answer each question will be 15 seconds");
    text->setFont(font);
    QVBoxLayout *layout = new QVBoxLayout();

    // layout->addWidget(descript_of_mode);
    // layout->addWidget(descript_of_mode_1);
    // layout->addWidget(descript_of_mode_2);
    // layout->addWidget(descript_of_mode_3);
    // layout->addWidget(descript_of_mode_4);
    layout->addWidget(text);


    QPushButton *ok = new QPushButton("  ok  ");
    ok->setFixedSize(120,40);
    ok->setFont(font);
    layout->addWidget(ok);
    ok->connect(ok, SIGNAL(clicked(bool)), window_of_descript, SLOT(close()));


    window_of_descript->setLayout(layout);


    window_of_descript->show();


}


void Choose_the_type_of_game::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{

}
// void show_time_in_window_of_question()
// {
//     pvp_mode_questions *window_of_question = new pvp_mode_questions();
//     window_of_question->setWindowTitle("pvp mode question");
//     QString timestring = QTime::currentTime().toString(("ss"));
//     QLabel *time = new QLabel(timestring);
//     QVBoxLayout *layout = new QVBoxLayout();
//     layout->addWidget(time);
//     window_of_question->setLayout(layout);
//     window_of_question->show();
// }

void Choose_the_type_of_game::on_pushButton_clicked()
{
    Choose_the_type_of_game::close();

    pvp_mode_questions *window_new_for_show_question_pvp = new pvp_mode_questions();
    window_new_for_show_question_pvp->setWindowTitle("Choose the type of game");
    window_new_for_show_question_pvp->resize(maximumSize());


    // time_t now = time(0);
    // tm *ltm = localtime(& now);
    // int time_system = ltm->tm_sec;
    // int time_show = 1;
    // QString time_show_string = QString::number(time_show);
    // QVBoxLayout *layout = new QVBoxLayout();

    // while(true)
    // {
    //     if(abs(time_system-ltm->tm_sec) == 1)
    //     {
    //         time_show_string = QString::number(time_show);
    //         QLabel *label = new QLabel(time_show_string);
    //         layout->addWidget(label);
    //         time_show++;
    //         time_system++;
    //     }
    //     if(time_show == 4)
    //         break;
    // }
    //window_new_for_show_question_pvp->setLayout(layout);
    window_new_for_show_question_pvp->show();

}






void Choose_the_type_of_game::on_pushButton_2_clicked()
{
    Choose_the_type_of_game::close();

    choose_the_difficulty_to_question_To_survival_mode *window_for_show_difficulty_of_question_for_mode_survival = new choose_the_difficulty_to_question_To_survival_mode();
    window_for_show_difficulty_of_question_for_mode_survival->setWindowTitle("Choose The Difficulty To Question");
    window_for_show_difficulty_of_question_for_mode_survival->resize(maximumSize());
    window_for_show_difficulty_of_question_for_mode_survival->show();
}


void Choose_the_type_of_game::on_commandLinkButton_clicked()
{

    MainWindow *window_start_the_game = new MainWindow();
    window_start_the_game->setWindowTitle("Start The Game");
    window_start_the_game->resize(maximumSize());
    window_start_the_game->show();
    Choose_the_type_of_game::close();
}

