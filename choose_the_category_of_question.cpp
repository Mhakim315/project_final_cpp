#include "choose_the_category_of_question.h"
#include "ui_choose_the_category_of_question.h"
#include "choose_the_difficulty_to_question.h"
#include "window_of_question_player.h"
#include "ui_window_of_question_player.h"
#include "choose_the_difficulty.h"
#include "QLabel"
#include "QFont"
#include "QPushButton"
#include "QWidget"
#include "ctime"
#include "QString"
#include "QVector"
#include "curl/curl.h"
#include "nlohmann/json.hpp"
#include "string"
#include "vector"
#include "QCommandLinkButton"
#include "QVBoxLayout"
#include "QTimer"

int conter_number_window_stacket = 1;
int conter_of_stacket_widget = 1;
int conter_of_correct_answer_for_player_1 = 0;
int conter_of_correct_answer_for_player_2 = 0;

int random_number_for_correct_question[5];
int random_number_for_correct_question_2[5];


int conter_of_window_number = 1;
int conter_of_number_index_1_question = 0;
int number_window;
choose_the_category_of_question::choose_the_category_of_question(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choose_the_category_of_question)
{
    ui->setupUi(this);
}

choose_the_category_of_question::~choose_the_category_of_question()
{
    delete ui;
}
using namespace std;

size_t writeCallback(void *contents, size_t size, size_t nmemb, string *data)
{
    data->append((char *) contents, size*nmemb);
    return size*nmemb;
}
vector <vector <string>> araye_in_correct_in_file;
vector <vector <string>> araye_in_correct_in_file_2;
QString question_of_player_1_asl[10];
QString correct_answer_asl[10];
QString in_correct_answer_1_asl[10];
QString in_correct_answer_2_asl[10];
QString in_correct_answer_3_asl[10];

QString question_of_player_2_asl[10];
QString correct_answer_2_asl[10];
QString in_correct_answer_1_2_asl[10];
QString in_correct_answer_2_2_asl[10];
QString in_correct_answer_3_2_asl[10];

QString question_of_player_1[10];
QString correct_answer[10];
QString in_correct_answer_1[10];
QString in_correct_answer_2[10];
QString in_correct_answer_3[10];

QString question_of_player_2[10];
QString correct_answer_2[10];
QString in_correct_answer_1_2[10];
QString in_correct_answer_2_2[10];
QString in_correct_answer_3_2[10];

void window_of_question_player::change_text_for_question_and_options_for_player_1(int number_correct_answer[5],QString correct_answer[5], QString in_correct_answer_1[5], QString in_correct_answer_2[5], QString in_correct_answer_3[5], QString question_of_player_1[5])
{
    bool check_options = false;
    if(number_correct_answer[0] == 1)
    {
        ui->label->setText(question_of_player_1_asl[conter_of_number_index_1_question]);
        ui->radioButton->setText(correct_answer_asl[conter_of_number_index_1_question]);
        ui->radioButton_2->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question][0]));
        ui->radioButton_3->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question][1]));
        ui->radioButton_4->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question][2]));
        check_options = false;
        ui->radioButton->connect(ui->radioButton, &QRadioButton::clicked, [&](){
            ui->commandLinkButton->connect(ui->commandLinkButton, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
        });
    });
    }
    if(number_correct_answer[0] == 2)
    {
        ui->label->setText(question_of_player_1_asl[conter_of_number_index_1_question]);
        ui->radioButton_2->setText(correct_answer_asl[conter_of_number_index_1_question]);
        ui->radioButton->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question][0]));
        ui->radioButton_3->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question][1]));
        ui->radioButton_4->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question][2]));
        check_options = false;
        ui->radioButton_2->connect(ui->radioButton_2, &QRadioButton::clicked, [&](){
            ui->commandLinkButton->connect(ui->commandLinkButton, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
        });
    });
    }
    if(number_correct_answer[0] == 3)
    {
        ui->label->setText(question_of_player_1_asl[conter_of_number_index_1_question]);
        ui->radioButton_3->setText(correct_answer_asl[conter_of_number_index_1_question]);
        ui->radioButton_2->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question][0]));
        ui->radioButton->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question][1]));
        ui->radioButton_4->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question][2]));

        check_options = false;
        ui->radioButton_3->connect(ui->radioButton_3, &QRadioButton::clicked, [&](){
            ui->commandLinkButton->connect(ui->commandLinkButton, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[0] == 4)
    {
        ui->label->setText(question_of_player_1_asl[conter_of_number_index_1_question]);
        ui->radioButton_4->setText(correct_answer_asl[conter_of_number_index_1_question]);
        ui->radioButton_2->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question][0]));
        ui->radioButton_3->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question][1]));
        ui->radioButton->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question][2]));

        check_options = false;
        ui->radioButton_4->connect(ui->radioButton_4, &QRadioButton::clicked, [&](){
            ui->commandLinkButton->connect(ui->commandLinkButton, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[1] == 1)
    {
        ui->label_2->setText(question_of_player_1_asl[conter_of_number_index_1_question + 1]);
        ui->radioButton_5->setText(correct_answer_asl[conter_of_number_index_1_question + 1]);
        ui->radioButton_6->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 1][0]));
        ui->radioButton_7->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 1][1]));
        ui->radioButton_8->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 1][2]));

        check_options = false;
        ui->radioButton_5->connect(ui->radioButton_5, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_2->connect(ui->commandLinkButton_2, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[1] == 2)
    {
        ui->label_2->setText(question_of_player_1_asl[conter_of_number_index_1_question + 1]);
        ui->radioButton_6->setText(correct_answer_asl[conter_of_number_index_1_question + 1]);
        ui->radioButton_5->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 1][0]));
        ui->radioButton_7->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 1][1]));
        ui->radioButton_8->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 1][2]));

        check_options = false;
        ui->radioButton_6->connect(ui->radioButton_6, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_2->connect(ui->commandLinkButton_2, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[1] == 3)
    {
        ui->label_2->setText(question_of_player_1_asl[conter_of_number_index_1_question + 1]);
        ui->radioButton_7->setText(correct_answer_asl[conter_of_number_index_1_question + 1]);
        ui->radioButton_6->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 1][0]));
        ui->radioButton_5->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 1][1]));
        ui->radioButton_8->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 1][2]));

        check_options = false;
        ui->radioButton_7->connect(ui->radioButton_7, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_2->connect(ui->commandLinkButton_2, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[1] == 4)
    {
        ui->label_2->setText(question_of_player_1_asl[conter_of_number_index_1_question + 1]);
        ui->radioButton_8->setText(correct_answer_asl[conter_of_number_index_1_question + 1]);
        ui->radioButton_6->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 1][0]));
        ui->radioButton_7->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 1][1]));
        ui->radioButton_5->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 1][2]));

        check_options = false;
        ui->radioButton_8->connect(ui->radioButton_8, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_2->connect(ui->commandLinkButton_2, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[2] == 1)
    {
        ui->label_3->setText(question_of_player_1_asl[conter_of_number_index_1_question + 2]);
        ui->radioButton_9->setText(correct_answer_asl[conter_of_number_index_1_question + 2]);
        ui->radioButton_10->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 2][0]));
        ui->radioButton_11->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 2][1]));
        ui->radioButton_12->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 2][2]));

        check_options = false;
        ui->radioButton_9->connect(ui->radioButton_9, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_3->connect(ui->commandLinkButton_3, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });

    }
    if(number_correct_answer[2] == 2)
    {
        ui->label_3->setText(question_of_player_1_asl[conter_of_number_index_1_question + 2]);
        ui->radioButton_10->setText(correct_answer_asl[conter_of_number_index_1_question + 2]);
        ui->radioButton_9->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 2][0]));
        ui->radioButton_11->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 2][1]));
        ui->radioButton_12->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 2][2]));

        check_options = false;
        ui->radioButton_10->connect(ui->radioButton_10, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_3->connect(ui->commandLinkButton_3, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[2] == 3)
    {
        ui->label_3->setText(question_of_player_1_asl[conter_of_number_index_1_question + 2]);
        ui->radioButton_11->setText(correct_answer_asl[conter_of_number_index_1_question + 2]);
        ui->radioButton_10->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 2][0]));
        ui->radioButton_9->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 2][1]));
        ui->radioButton_12->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 2][2]));

        check_options = false;
        ui->radioButton_11->connect(ui->radioButton_11, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_3->connect(ui->commandLinkButton_3, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[2] == 4)
    {
        ui->label_3->setText(question_of_player_1_asl[conter_of_number_index_1_question + 2]);
        ui->radioButton_12->setText(correct_answer_asl[conter_of_number_index_1_question + 2]);
        ui->radioButton_10->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 2][0]));
        ui->radioButton_11->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 2][1]));
        ui->radioButton_9->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 2][2]));

        check_options = false;
        ui->radioButton_12->connect(ui->radioButton_12, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_3->connect(ui->commandLinkButton_3, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[3] == 1)
    {
        ui->label_4->setText(question_of_player_1_asl[conter_of_number_index_1_question + 3]);
        ui->radioButton_13->setText(correct_answer_asl[conter_of_number_index_1_question + 3]);
        ui->radioButton_14->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 3][0]));
        ui->radioButton_15->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 3][1]));
        ui->radioButton_16->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 3][2]));

        check_options = false;
        ui->radioButton_13->connect(ui->radioButton_13, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_4->connect(ui->commandLinkButton_4, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[3] == 2)
    {
        ui->label_4->setText(question_of_player_1_asl[conter_of_number_index_1_question + 3]);
        ui->radioButton_14->setText(correct_answer_asl[conter_of_number_index_1_question + 3]);
        ui->radioButton_13->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 3][0]));
        ui->radioButton_15->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 3][1]));
        ui->radioButton_16->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 3][2]));

        check_options = false;
        ui->radioButton_14->connect(ui->radioButton_14, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_4->connect(ui->commandLinkButton_4, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[3] == 3)
    {
        ui->label_4->setText(question_of_player_1_asl[conter_of_number_index_1_question + 3]);
        ui->radioButton_15->setText(correct_answer_asl[conter_of_number_index_1_question + 3]);
        ui->radioButton_14->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 3][0]));
        ui->radioButton_13->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 3][1]));
        ui->radioButton_16->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 3][2]));

        check_options = false;
        ui->radioButton_15->connect(ui->radioButton_15, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_4->connect(ui->commandLinkButton_4, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[3] == 4)
    {
        ui->label_4->setText(question_of_player_1_asl[conter_of_number_index_1_question + 3]);
        ui->radioButton_16->setText(correct_answer_asl[conter_of_number_index_1_question + 3]);
        ui->radioButton_14->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 3][0]));
        ui->radioButton_15->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 3][1]));
        ui->radioButton_13->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 3][2]));

        check_options = false;
        ui->radioButton_16->connect(ui->radioButton_16, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_4->connect(ui->commandLinkButton_4, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[4] == 1)
    {
        ui->label_5->setText(question_of_player_1_asl[conter_of_number_index_1_question + 4]);
        ui->radioButton_17->setText(correct_answer_asl[conter_of_number_index_1_question + 4]);
        ui->radioButton_18->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 4][0]));
        ui->radioButton_19->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 4][1]));
        ui->radioButton_20->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 4][2]));

        check_options = false;
        ui->radioButton_17->connect(ui->radioButton_17, &QRadioButton::clicked, [&](){
            ui->pushButton->connect(ui->pushButton, &QPushButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[4] == 2)
    {
        ui->label_5->setText(question_of_player_1_asl[conter_of_number_index_1_question + 4]);
        ui->radioButton_18->setText(correct_answer_asl[conter_of_number_index_1_question + 4]);
        ui->radioButton_17->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 4][0]));
        ui->radioButton_19->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 4][1]));
        ui->radioButton_20->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 4][2]));

        check_options = false;
        ui->radioButton_18->connect(ui->radioButton_18, &QRadioButton::clicked, [&](){
            ui->pushButton->connect(ui->pushButton, &QPushButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[4] == 3)
    {
        ui->label_5->setText(question_of_player_1_asl[conter_of_number_index_1_question + 4]);
        ui->radioButton_19->setText(correct_answer_asl[conter_of_number_index_1_question + 4]);
        ui->radioButton_18->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 4][0]));
        ui->radioButton_17->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 4][1]));
        ui->radioButton_20->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 4][2]));

        check_options = false;
        ui->radioButton_19->connect(ui->radioButton_19, &QRadioButton::clicked, [&](){
            ui->pushButton->connect(ui->pushButton, &QPushButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    if(number_correct_answer[4] == 4)
    {
        ui->label_5->setText(question_of_player_1_asl[conter_of_number_index_1_question + 4]);
        ui->radioButton_20->setText(correct_answer_asl[conter_of_number_index_1_question + 4]);
        ui->radioButton_18->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 4][0]));
        ui->radioButton_19->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 4][1]));
        ui->radioButton_17->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 4][2]));

        check_options = false;
        ui->radioButton_20->connect(ui->radioButton_20, &QRadioButton::clicked, [&](){
            ui->pushButton->connect(ui->pushButton, &QPushButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_1++;
            });
        });
    }
    ui->pushButton->connect(ui->pushButton, &QPushButton::clicked, [&](){
        if(conter_of_window_number <= 4)
        {
            choose_the_difficulty_To_question *window_for_show_difficulty = new choose_the_difficulty_To_question();
            window_for_show_difficulty->setWindowTitle("Choose the Difficulty of question");
            window_for_show_difficulty->resize(maximumSize());
            window_for_show_difficulty->show();
            conter_number_window_stacket = 1;
        }
    });
    if(conter_of_window_number > 4)
    {
        ui->pushButton->connect(ui->pushButton, &QPushButton::clicked, [&](){
            conter_number_window_stacket = 1;
            if(conter_of_correct_answer_for_player_1 == conter_of_correct_answer_for_player_2)
            {

                srand(time(0));
                random_number_for_correct_question[5];
                random_number_for_correct_question_2[5];
                for(int i=0; i<5; i++)
                {
                    random_number_for_correct_question[i] = (rand() % 4) + 1;
                    random_number_for_correct_question_2[i] = (rand() % 4) + 1;
                }

                QFont font("Times", 30, QFont::Bold);
                font.setItalic(true);
                QWidget *window_for_number_round = new QWidget();
                window_for_number_round->setWindowTitle("number of round");
                window_for_number_round->resize(maximumSize());
                QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
                QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
                tozih->setFont(font);
                QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
                button_ok->setFont(font);
                number_of_round->setFont(font);
                number_of_round->move(600,200);
                tozih->move(450,300);
                button_ok->move(600,500);
                button_ok->setGeometry(600,500,180,100);
                button_ok->connect(button_ok, &QPushButton::clicked, [&](){
                    number_window = 1;
                    window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
                    window_for_show_question_player_1->setWindowTitle("Question To player 1");
                    window_for_show_question_player_1->resize(maximumSize());
                    window_for_show_question_player_1->geting_question_for_player_2_in_api("");
                    window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
                    window_for_show_question_player_1->show();
                });
                button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
                window_for_number_round->show();
                conter_of_window_number++;
            }
            else
            {
                QFont font("Times", 17, QFont::Bold);
                font.setItalic(true);
                QWidget *show_player_winer = new QWidget();
                show_player_winer->setWindowTitle("Score for winner and loser");
                show_player_winer->resize(maximumSize());
                show_player_winer->setStyleSheet("background-color: rgb(33, 85, 88)");
                QLabel *score_for_player_1 = new QLabel("The number of correct answers of the first  player : " + QString::number(conter_of_correct_answer_for_player_1));
                QLabel *score_for_player_2 = new QLabel("The number of correct answers of the second player : " + QString::number(conter_of_correct_answer_for_player_2));
                score_for_player_1->setFont(font);
                score_for_player_2->setFont(font);
                QLabel *winner_comp;
                QPushButton *button_ok = new QPushButton(" ok ");
                button_ok->setFont(font);
                if(conter_of_correct_answer_for_player_1 > conter_of_correct_answer_for_player_2)
                    winner_comp = new QLabel("The winner of this competition : player 1");
                else
                    winner_comp = new QLabel("The winner of this competition : player 2");
                winner_comp->setFont(font);
                QVBoxLayout *layout = new QVBoxLayout();
                layout->addWidget(score_for_player_1);
                layout->addWidget(score_for_player_2);
                layout->addWidget(winner_comp);
                layout->addWidget(button_ok);
                show_player_winer->setLayout(layout);
                button_ok->connect(button_ok, SIGNAL(clicked(bool)), show_player_winer, SLOT(close()));
                show_player_winer->show();
            }
        });
    }




}

void window_of_question_player::change_text_for_question_and_options_for_player_2(int number_correct_answer[5], QString correct_answer_2[5], QString in_correct_answer_1_2[5], QString in_correct_answer_2[5], QString in_correct_answer_3_2[5],QString question_of_player_2[5])
{
    bool check_options = false;
    if(number_correct_answer[0] == 1)
    {
        ui->label->setText(question_of_player_1_asl[conter_of_number_index_1_question + 5]);
        ui->radioButton->setText(correct_answer_asl[conter_of_number_index_1_question + 5]);
        ui->radioButton_2->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 5][0]));
        ui->radioButton_3->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 5][1]));
        ui->radioButton_4->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 5][2]));

        check_options = false;
        ui->radioButton->connect(ui->radioButton, &QRadioButton::clicked, [&](){
            ui->commandLinkButton->connect(ui->commandLinkButton, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[0] == 2)
    {
        ui->label->setText(question_of_player_1_asl[conter_of_number_index_1_question + 5]);
        ui->radioButton_2->setText(correct_answer_asl[conter_of_number_index_1_question + 5]);
        ui->radioButton->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 5][0]));
        ui->radioButton_3->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 5][1]));
        ui->radioButton_4->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 5][2]));

        check_options = false;
        ui->radioButton_2->connect(ui->radioButton_2, &QRadioButton::clicked, [&](){
            ui->commandLinkButton->connect(ui->commandLinkButton, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[0] == 3)
    {
        ui->label->setText(question_of_player_1_asl[conter_of_number_index_1_question + 5]);
        ui->radioButton_3->setText(correct_answer_asl[conter_of_number_index_1_question + 5]);
        ui->radioButton_2->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 5][0]));
        ui->radioButton->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 5][1]));
        ui->radioButton_4->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 5][2]));

        check_options = false;
        ui->radioButton_3->connect(ui->radioButton_3, &QRadioButton::clicked, [&](){
            ui->commandLinkButton->connect(ui->commandLinkButton, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[0] == 4)
    {
        ui->label->setText(question_of_player_1_asl[conter_of_number_index_1_question + 5]);
        ui->radioButton_4->setText(correct_answer_asl[conter_of_number_index_1_question + 5]);
        ui->radioButton_2->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 5][0]));
        ui->radioButton_3->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 5][1]));
        ui->radioButton->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 5][2]));

        check_options = false;
        ui->radioButton_4->connect(ui->radioButton_4, &QRadioButton::clicked, [&](){
            ui->commandLinkButton->connect(ui->commandLinkButton, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[1] == 1)
    {
        ui->label_2->setText(question_of_player_1_asl[conter_of_number_index_1_question + 6]);
        ui->radioButton_5->setText(correct_answer_asl[conter_of_number_index_1_question + 6]);
        ui->radioButton_6->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 6][0]));
        ui->radioButton_7->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 6][1]));
        ui->radioButton_8->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 6][2]));

        check_options = false;
        ui->radioButton_5->connect(ui->radioButton_5, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_2->connect(ui->commandLinkButton_2, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;

            });
        });
    }
    if(number_correct_answer[1] == 2)
    {
        ui->label_2->setText(question_of_player_1_asl[conter_of_number_index_1_question + 6]);
        ui->radioButton_6->setText(correct_answer_asl[conter_of_number_index_1_question + 6]);
        ui->radioButton_5->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 6][0]));
        ui->radioButton_7->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 6][1]));
        ui->radioButton_8->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 6][2]));

        check_options = false;
        ui->radioButton_6->connect(ui->radioButton_6, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_2->connect(ui->commandLinkButton_2, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[1] == 3)
    {
        ui->label_2->setText(question_of_player_1_asl[conter_of_number_index_1_question + 6]);
        ui->radioButton_7->setText(correct_answer_asl[conter_of_number_index_1_question + 6]);
        ui->radioButton_6->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 6][0]));
        ui->radioButton_5->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 6][1]));
        ui->radioButton_8->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 6][2]));

        check_options = false;
        ui->radioButton_7->connect(ui->radioButton_7, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_2->connect(ui->commandLinkButton_2, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[1] == 4)
    {
        ui->label_2->setText(question_of_player_1_asl[conter_of_number_index_1_question + 6]);
        ui->radioButton_8->setText(correct_answer_asl[conter_of_number_index_1_question + 6]);
        ui->radioButton_6->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 6][0]));
        ui->radioButton_7->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 6][1]));
        ui->radioButton_5->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 6][2]));

        check_options = false;
        ui->radioButton_8->connect(ui->radioButton_8, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_2->connect(ui->commandLinkButton_2, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;

            });
        });
    }
    if(number_correct_answer[2] == 1)
    {
        ui->label_3->setText(question_of_player_1_asl[conter_of_number_index_1_question + 7]);
        ui->radioButton_9->setText(correct_answer_asl[conter_of_number_index_1_question + 7]);
        ui->radioButton_10->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 7][0]));
        ui->radioButton_11->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 7][1]));
        ui->radioButton_12->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 7][2]));

        check_options = false;
        ui->radioButton_9->connect(ui->radioButton_9, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_3->connect(ui->commandLinkButton_3, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[2] == 2)
    {
        ui->label_3->setText(question_of_player_1_asl[conter_of_number_index_1_question + 7]);
        ui->radioButton_10->setText(correct_answer_asl[conter_of_number_index_1_question + 7]);
        ui->radioButton_9->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 7][0]));
        ui->radioButton_11->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 7][1]));
        ui->radioButton_12->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 7][2]));

        check_options = false;
        ui->radioButton_10->connect(ui->radioButton_10, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_3->connect(ui->commandLinkButton_3, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[2] == 3)
    {
        ui->label_3->setText(question_of_player_1_asl[conter_of_number_index_1_question + 7]);
        ui->radioButton_11->setText(correct_answer_asl[conter_of_number_index_1_question + 7]);
        ui->radioButton_10->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 7][0]));
        ui->radioButton_9->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 7][1]));
        ui->radioButton_12->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 7][2]));

        check_options = false;
        ui->radioButton_11->connect(ui->radioButton_11, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_3->connect(ui->commandLinkButton_3, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[2] == 4)
    {
        ui->label_3->setText(question_of_player_1_asl[conter_of_number_index_1_question + 7]);
        ui->radioButton_12->setText(correct_answer_asl[conter_of_number_index_1_question + 7]);
        ui->radioButton_10->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 7][0]));
        ui->radioButton_11->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 7][1]));
        ui->radioButton_9->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 7][2]));

        check_options = false;
        ui->radioButton_12->connect(ui->radioButton_12, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_3->connect(ui->commandLinkButton_3, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;

            });
        });
    }
    if(number_correct_answer[3] == 1)
    {
        ui->label_4->setText(question_of_player_1_asl[conter_of_number_index_1_question + 8]);
        ui->radioButton_13->setText(correct_answer_asl[conter_of_number_index_1_question + 8]);
        ui->radioButton_14->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 8][0]));
        ui->radioButton_15->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 8][1]));
        ui->radioButton_16->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 8][2]));

        check_options = false;
        ui->radioButton_13->connect(ui->radioButton_13, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_4->connect(ui->commandLinkButton_4, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[3] == 2)
    {
        ui->label_4->setText(question_of_player_1_asl[conter_of_number_index_1_question + 8]);
        ui->radioButton_14->setText(correct_answer_asl[conter_of_number_index_1_question + 8]);
        ui->radioButton_13->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 8][0]));
        ui->radioButton_15->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 8][1]));
        ui->radioButton_16->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 8][2]));

        check_options = false;
        ui->radioButton_14->connect(ui->radioButton_14, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_4->connect(ui->commandLinkButton_4, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[3] == 3)
    {
        ui->label_4->setText(question_of_player_1_asl[conter_of_number_index_1_question + 8]);
        ui->radioButton_15->setText(correct_answer_asl[conter_of_number_index_1_question + 8]);
        ui->radioButton_14->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 8][0]));
        ui->radioButton_13->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 8][1]));
        ui->radioButton_16->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 8][2]));

        check_options = false;
        ui->radioButton_15->connect(ui->radioButton_15, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_4->connect(ui->commandLinkButton_4, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[3] == 4)
    {
        ui->label_4->setText(question_of_player_1_asl[conter_of_number_index_1_question + 8]);
        ui->radioButton_16->setText(correct_answer_asl[conter_of_number_index_1_question + 8]);
        ui->radioButton_14->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 8][0]));
        ui->radioButton_15->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 8][1]));
        ui->radioButton_13->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 8][2]));

        check_options = false;
        ui->radioButton_16->connect(ui->radioButton_16, &QRadioButton::clicked, [&](){
            ui->commandLinkButton_4->connect(ui->commandLinkButton_4, &QCommandLinkButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[4] == 1)
    {
        ui->label_5->setText(question_of_player_1_asl[conter_of_number_index_1_question + 9]);
        ui->radioButton_17->setText(correct_answer_asl[conter_of_number_index_1_question + 9]);
        ui->radioButton_18->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 9][0]));
        ui->radioButton_19->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 9][1]));
        ui->radioButton_20->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 9][2]));

        check_options = false;
        ui->radioButton_17->connect(ui->radioButton_17, &QRadioButton::clicked, [&](){
            ui->pushButton->connect(ui->pushButton, &QPushButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[4] == 2)
    {
        ui->label_5->setText(question_of_player_1_asl[conter_of_number_index_1_question + 9]);
        ui->radioButton_18->setText(correct_answer_asl[conter_of_number_index_1_question + 9]);
        ui->radioButton_17->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 9][0]));
        ui->radioButton_19->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 9][1]));
        ui->radioButton_20->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 9][2]));

        check_options = false;
        ui->radioButton_18->connect(ui->radioButton_18, &QRadioButton::clicked, [&](){
            ui->pushButton->connect(ui->pushButton, &QPushButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[4] == 3)
    {
        ui->label_5->setText(question_of_player_1_asl[conter_of_number_index_1_question + 9]);
        ui->radioButton_19->setText(correct_answer_asl[conter_of_number_index_1_question + 9]);
        ui->radioButton_18->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 9][0]));
        ui->radioButton_17->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 9][1]));
        ui->radioButton_20->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 9][2]));

        check_options = false;
        ui->radioButton_19->connect(ui->radioButton_19, &QRadioButton::clicked, [&](){
            ui->pushButton->connect(ui->pushButton, &QPushButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    if(number_correct_answer[4] == 4)
    {
        ui->label_5->setText(question_of_player_1_asl[conter_of_number_index_1_question + 9]);
        ui->radioButton_20->setText(correct_answer_asl[conter_of_number_index_1_question + 9]);
        ui->radioButton_18->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 9][0]));
        ui->radioButton_19->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 9][1]));
        ui->radioButton_17->setText(QString::fromStdString(araye_in_correct_in_file[conter_of_number_index_1_question + 9][2]));

        check_options = false;
        ui->radioButton_20->connect(ui->radioButton_20, &QRadioButton::clicked, [&](){
            ui->pushButton->connect(ui->pushButton, &QPushButton::clicked, [&](){
                check_options = true;
                conter_of_correct_answer_for_player_2++;
            });
        });
    }
    ui->pushButton->connect(ui->pushButton, &QPushButton::clicked, [&](){
        conter_number_window_stacket = 2;
        window_of_question_player *window_for_show_question_player_2 = new window_of_question_player();
        window_for_show_question_player_2->setWindowTitle("Question To player 2");
        window_for_show_question_player_2->resize(maximumSize());
        window_for_show_question_player_2->change_text_for_question_and_options_for_player_1(random_number_for_correct_question,correct_answer,in_correct_answer_1,in_correct_answer_2,in_correct_answer_3,question_of_player_1);
        window_for_show_question_player_2->show();

    });
    // conter_of_number_index_1_question+=10;
}

void window_of_question_player::geting_question_for_player_2_in_api(string category_player_1)
{
    CURL *curl;
    CURLcode res;
    string response;
    nlohmann::json jsondata;
    string api = "https://opentdb.com/api.php?category=" + category_player_1 + "&difficulty="+ +"&type=multiple&amount=10";
    if(conter_of_window_number > 4)
    {
        int category_number = (rand()%33)+9;
        int difficulty_random = (rand()%4)+1;
        std::string difficulty_f;
        if(difficulty_random == 1)
            difficulty_f = "easy";
        if(difficulty_random == 2)
            difficulty_f = "medium";
        if(difficulty_random == 3)
            difficulty_f = "hard";
        if(difficulty_random == 4)
            difficulty_f = "";
        if(category_number < 9)
            category_number+=9;
        api = "https://opentdb.com/api.php?category=" + std::to_string(category_number) + "&difficulty="+ difficulty_f +"&type=multiple&amount=10";
    }
    curl = curl_easy_init();


    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, api.c_str());
        curl_easy_setopt(curl,CURLOPT_CAINFO, "curl-ca-bundle.crt");
        curl_easy_setopt(curl , CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);


    }
    curl_easy_cleanup(curl);
    curl = NULL;

    vector <string> question_in_file;
    vector <string> correct_answer_in_file ;

    araye_in_correct_in_file.clear();

    jsondata = nlohmann::json::parse(response);
    for(auto question : jsondata["results"])
    {

        question_in_file.push_back(question["question"]);
        correct_answer_in_file.push_back(question["correct_answer"]);
        araye_in_correct_in_file.push_back(question["incorrect_answers"]);

    }

    qDebug() << response;

    for(int i=0; i<10; i++)
    {
        question_of_player_1_asl[i] = QString::fromStdString(question_in_file[i]);
        correct_answer_asl[i] = QString::fromStdString(correct_answer_in_file[i]);
        in_correct_answer_1_asl[i] == QString::fromStdString(araye_in_correct_in_file[i][0]);
        in_correct_answer_2_asl[i] == QString::fromStdString(araye_in_correct_in_file[i][1]);
        in_correct_answer_3_asl[i] == QString::fromStdString(araye_in_correct_in_file[i][2]);
        qDebug() << in_correct_answer_1_asl[i]<<QString::fromStdString(araye_in_correct_in_file[i][0])<<araye_in_correct_in_file[i][1]<<araye_in_correct_in_file[i][2];
    }

}
void window_of_question_player::geting_question_for_player_1_in_api(string category_player_1)
{

}
void window_of_question_player::gold_round()
{
    // srand(time(0));
    // int number_category = (rand()%33) + 9;
    // if(number_category < 9)
    //     number_category+=9;
    // int random_number_for_correct_question[5];
    // int random_number_for_correct_question_2[5];
    // for(int i=0; i<5; i++)
    // {
    //     random_number_for_correct_question[i] = (rand() % 4) + 1;
    //     random_number_for_correct_question_2[i] = (rand() % 4) + 1;
    // }

    // choose_the_difficulty_To_question *window_for_show_difficulty = new choose_the_difficulty_To_question();
    // window_for_show_difficulty->setWindowTitle("Choose the Difficulty of question");
    // window_for_show_difficulty->resize(maximumSize());
    // window_for_show_difficulty->show();

    // window_of_question_player *window_for_show_question_player_2 = new window_of_question_player();
    // window_for_show_question_player_2->setWindowTitle("Question To player 2");
    // window_for_show_question_player_2->resize(maximumSize());
    // window_for_show_question_player_2->geting_question_for_player_2_in_api(std::to_string(number_category));
    // window_for_show_question_player_2->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
    // window_for_show_question_player_2->show();


    // window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
    // window_for_show_question_player_1->setWindowTitle("Question To player 1");
    // window_for_show_question_player_1->resize(maximumSize());
    // window_for_show_question_player_1->change_text_for_question_and_options_for_player_1(random_number_for_correct_question,correct_answer,in_correct_answer_1,in_correct_answer_2,in_correct_answer_3,question_of_player_1);
    // window_for_show_question_player_1->show();


    // QFont font("Times", 30, QFont::Bold);
    // font.setItalic(true);
    // QWidget *window_for_number_round = new QWidget();
    // window_for_number_round->setWindowTitle("number of round");
    // window_for_number_round->resize(maximumSize());
    // QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
    // QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
    // button_ok->setFont(font);
    // number_of_round->setFont(font);
    // number_of_round->move(600,200);
    // button_ok->move(600,500);
    // button_ok->setGeometry(600,500,180,100);
    // button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
    // window_for_number_round->show();
}
void choose_the_category_of_question::on_pushButton_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;

}


void choose_the_category_of_question::on_pushButton_2_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("9");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();
    }
    conter_of_window_number++;

}


void choose_the_category_of_question::on_pushButton_3_clicked()
{

    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("10");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}

void choose_the_category_of_question::on_pushButton_4_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("11");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_Music_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("12");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_pushButton_7_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("14");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_pushButton_8_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("15");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_board_games_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("16");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_sicence_nature_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("17");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_comuter_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("18");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;

}


void choose_the_category_of_question::on_mytholoy_clicked()
{

    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("19");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;

}


void choose_the_category_of_question::on_sports_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("21");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_geography_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("22");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_histoory_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("23");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_politics_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("24");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;

}


void choose_the_category_of_question::on_celebrities_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("26");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_animals_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("27");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_vehicles_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("28");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_comics_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("29");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_gadgets_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("30");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_musical_and_theatres_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("13");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
}


void choose_the_category_of_question::on_mathematics_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("19");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_art_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("25");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_japanese_anime_manga_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("31");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}


void choose_the_category_of_question::on_cartoon_and_animations_clicked()
{
    if(conter_of_window_number <= 4)
    {
        srand(time(0));
        random_number_for_correct_question[5];
        random_number_for_correct_question_2[5];
        for(int i=0; i<5; i++)
        {
            random_number_for_correct_question[i] = (rand() % 4) + 1;
            random_number_for_correct_question_2[i] = (rand() % 4) + 1;
        }

        QFont font("Times", 30, QFont::Bold);
        font.setItalic(true);
        QWidget *window_for_number_round = new QWidget();
        window_for_number_round->setWindowTitle("number of round");
        window_for_number_round->resize(maximumSize());
        QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
        QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
        tozih->setFont(font);
        QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
        button_ok->setFont(font);
        number_of_round->setFont(font);
        number_of_round->move(600,200);
        tozih->move(450,300);
        button_ok->move(600,500);
        button_ok->setGeometry(600,500,180,100);
        button_ok->connect(button_ok, &QPushButton::clicked, [&](){
            number_window = 1;
            window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
            window_for_show_question_player_1->setWindowTitle("Question To player 1");
            window_for_show_question_player_1->resize(maximumSize());
            window_for_show_question_player_1->geting_question_for_player_2_in_api("32");
            window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
            window_for_show_question_player_1->show();
        });
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
        window_for_number_round->show();



    }
    conter_of_window_number++;
}
void window_of_question_player::set_time_in_pvp_window()
{
    if(sec_in_pvp == 0)
    {
        timer->stop();
        if(conter_of_stacket_widget == 1)
        {
            ui->page->close();
            sec_in_pvp = 3;
            timer->start(1000);
            ui->page_2->show();
            conter_of_stacket_widget = 2;
        }
        else if(conter_of_stacket_widget == 2)
        {
            ui->page_2->close();
            sec_in_pvp = 3;
            timer->start(1000);
            ui->page_3->show();
            conter_of_stacket_widget = 3;
        }
        else if(conter_of_stacket_widget == 3)
        {
            ui->page_3->close();
            sec_in_pvp = 3;
            timer->start(1000);
            ui->page_4->show();
            conter_of_stacket_widget = 4;
        }
        else if(conter_of_stacket_widget == 4)
        {
            ui->page_4->close();
            sec_in_pvp = 3;
            timer->start(1000);
            ui->page_5->show();
            conter_of_stacket_widget = 5;
        }
        else
        {
            window_of_question_player::close();
            if(conter_of_window_number <= 4 && conter_number_window_stacket == 1)
            {
                window_of_question_player *window_for_show_question_player_2 = new window_of_question_player();
                window_for_show_question_player_2->setWindowTitle("Question To player 2");
                window_for_show_question_player_2->resize(maximumSize());
                window_for_show_question_player_2->change_text_for_question_and_options_for_player_1(random_number_for_correct_question,correct_answer,in_correct_answer_1,in_correct_answer_2,in_correct_answer_3,question_of_player_1);
                window_for_show_question_player_2->show();
                conter_number_window_stacket = 2;
            }
            else if(conter_of_window_number <= 4 && conter_number_window_stacket == 2)
            {
                choose_the_difficulty_To_question *window_for_show_difficulty = new choose_the_difficulty_To_question();
                window_for_show_difficulty->setWindowTitle("Choose the Difficulty of question");
                window_for_show_difficulty->resize(maximumSize());
                window_for_show_difficulty->show();
                conter_number_window_stacket = 1;
            }
            else if(conter_of_window_number >= 5 && conter_number_window_stacket == 1)
            {
                window_of_question_player *window_for_show_question_player_2 = new window_of_question_player();
                window_for_show_question_player_2->setWindowTitle("Question To player 2");
                window_for_show_question_player_2->resize(maximumSize());
                window_for_show_question_player_2->change_text_for_question_and_options_for_player_1(random_number_for_correct_question,correct_answer,in_correct_answer_1,in_correct_answer_2,in_correct_answer_3,question_of_player_1);
                window_for_show_question_player_2->show();
                conter_number_window_stacket = 2;
            }
            else if(conter_of_window_number >=5 && conter_number_window_stacket == 2)
            {
                if(conter_of_correct_answer_for_player_1 == conter_of_correct_answer_for_player_2)
                {
                    srand(time(0));
                    random_number_for_correct_question[5];
                    random_number_for_correct_question_2[5];
                    for(int i=0; i<5; i++)
                    {
                        random_number_for_correct_question[i] = (rand() % 4) + 1;
                        random_number_for_correct_question_2[i] = (rand() % 4) + 1;
                    }

                    QFont font("Times", 30, QFont::Bold);
                    font.setItalic(true);
                    QWidget *window_for_number_round = new QWidget();
                    window_for_number_round->setWindowTitle("number of round");
                    window_for_number_round->resize(maximumSize());
                    QLabel *number_of_round = new QLabel("Round " + QString::number(conter_of_window_number), window_for_number_round);
                    QLabel *tozih = new QLabel("Click the ok button to Start", window_for_number_round);
                    tozih->setFont(font);
                    QPushButton *button_ok = new QPushButton(" ok ", window_for_number_round);
                    button_ok->setFont(font);
                    number_of_round->setFont(font);
                    number_of_round->move(600,200);
                    tozih->move(450,300);
                    button_ok->move(600,500);
                    button_ok->setGeometry(600,500,180,100);
                    button_ok->connect(button_ok, &QPushButton::clicked, [&](){
                        number_window = 1;
                        window_of_question_player *window_for_show_question_player_1 = new window_of_question_player();
                        window_for_show_question_player_1->setWindowTitle("Question To player 1");
                        window_for_show_question_player_1->resize(maximumSize());
                        window_for_show_question_player_1->geting_question_for_player_2_in_api("");
                        window_for_show_question_player_1->change_text_for_question_and_options_for_player_2(random_number_for_correct_question_2,correct_answer_2,in_correct_answer_1_2,in_correct_answer_2_2,in_correct_answer_3_2,question_of_player_2);
                        window_for_show_question_player_1->show();
                    });
                    button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_for_number_round, SLOT(close()));
                    window_for_number_round->show();
                }
                else
                {
                    QFont font("Times", 17, QFont::Bold);
                    font.setItalic(true);
                    QWidget *show_player_winer = new QWidget();
                    show_player_winer->setWindowTitle("Score for winner and loser");
                    show_player_winer->resize(maximumSize());
                    show_player_winer->setStyleSheet("background-color: rgb(33, 85, 88)");
                    QLabel *score_for_player_1 = new QLabel("The number of correct answers of the first  player : " + QString::number(conter_of_correct_answer_for_player_1));
                    QLabel *score_for_player_2 = new QLabel("The number of correct answers of the second player : " + QString::number(conter_of_correct_answer_for_player_2));
                    score_for_player_1->setFont(font);
                    score_for_player_2->setFont(font);
                    QLabel *winner_comp;
                    QPushButton *button_ok = new QPushButton(" ok ");
                    button_ok->setFont(font);
                    if(conter_of_correct_answer_for_player_1 > conter_of_correct_answer_for_player_2)
                        winner_comp = new QLabel("The winner of this competition : player 1");
                    else
                        winner_comp = new QLabel("The winner of this competition : player 2");
                    winner_comp->setFont(font);
                    QVBoxLayout *layout = new QVBoxLayout();
                    layout->addWidget(score_for_player_1);
                    layout->addWidget(score_for_player_2);
                    layout->addWidget(winner_comp);
                    layout->addWidget(button_ok);
                    show_player_winer->setLayout(layout);
                    button_ok->connect(button_ok, SIGNAL(clicked(bool)), show_player_winer, SLOT(close()));
                    show_player_winer->show();

                }
                conter_of_window_number++;
                conter_number_window_stacket = 1;
            }
            conter_of_stacket_widget = 1;
        }
    }

    ui->timer_pvp->setText("Time left to answer the question : " + QString::number(sec_in_pvp));
    sec_in_pvp--;
}
void window_of_question_player::set_time_in_pvp_window_2()
{
    if(sec_in_pvp == 0)
    {
        timer->stop();
    }
    ui->timer_pvp->setText("Time left to answer the question : " + QString::number(sec_in_pvp));
    sec_in_pvp--;
}
void window_of_question_player::set_time_in_pvp_window_3()
{
    if(sec_in_pvp == 0)
    {
        timer->stop();
    }
    ui->timer_pvp->setText("Time left to answer the question : " + QString::number(sec_in_pvp));
    sec_in_pvp--;
}
void window_of_question_player::set_time_in_pvp_window_4()
{
    if(sec_in_pvp == 0)
    {
        timer->stop();
    }
    ui->timer_pvp->setText("Time left to answer the question : " + QString::number(sec_in_pvp));
    sec_in_pvp--;
}
void window_of_question_player::set_time_in_pvp_window_5()
{

    if(sec_in_pvp == 0)
    {
        timer->stop();

    }
    ui->timer_pvp->setText("Time left to answer the question : " + QString::number(sec_in_pvp));
    sec_in_pvp--;
}


void window_of_question_player::on_pushButton_clicked()
{
    timer->stop();
    conter_of_stacket_widget = 1;
    window_of_question_player::close();
}


void window_of_question_player::on_commandLinkButton_clicked()
{
    ui->page->close();
    timer->stop();
    ui->page_2->show();
    conter_of_stacket_widget = 2;
    sec_in_pvp = 30;
    timer->start(1000);
}


void window_of_question_player::on_commandLinkButton_2_clicked()
{
    ui->page_2->close();
    timer->stop();
    ui->page_3->show();
    conter_of_stacket_widget = 3;
    sec_in_pvp = 30;
    timer->start(1000);



}
void window_of_question_player::on_commandLinkButton_3_clicked()
{
    ui->page_3->close();
    timer->stop();
    ui->page_4->show();
    conter_of_stacket_widget = 4;
    sec_in_pvp = 30;
    timer->start(1000);
}
void window_of_question_player::on_commandLinkButton_4_clicked()
{
    ui->page_4->close();
    timer->stop();
    ui->page_5->show();
    conter_of_stacket_widget = 5;
    sec_in_pvp = 30;
    timer->start(1000);
}


