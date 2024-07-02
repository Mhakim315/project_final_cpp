#include "choose_the_difficulty_to_question_to_survival_mode.h"
#include "ui_choose_the_difficulty_to_question_to_survival_mode.h"
#include "window_of_question_player.h"
#include "question_of_player_to_survival_mode.h"
#include "ui_question_of_player_to_survival_mode.h"
#include "choose_the_type_of_game.h"
#include "QApplication"
#include "QWidget"
#include "QPushButton"
#include "QLabel"
#include "QVBoxLayout"
#include "unistd.h"
#include "QRadioButton"
#include "QStackedWidget"
#include "QComboBox"
#include "curl/curl.h"
#include "string"
#include "nlohmann/json.hpp"
#include "vector"
#include "ctime"
#include "QFont"
#include "QFile"
#include "QTextStream"
#include "QTimer"
#include "QTime"
#include "QObject"

std::string difficulty_of_category_for_question_of_survival_mode;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data)
{
    data->append((char*)contents, size*nmemb);
    return size*nmemb;
}

int conter_of_in_correct_answer_for_mode_survival = 0;
int conter_of_correct_answer_for_mode_survival = 0;
int conter_of_index_for_value_api = 0;


choose_the_difficulty_to_question_To_survival_mode::choose_the_difficulty_to_question_To_survival_mode(
    QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choose_the_difficulty_to_question_To_survival_mode)
{
    ui->setupUi(this);
}

choose_the_difficulty_to_question_To_survival_mode::
    ~choose_the_difficulty_to_question_To_survival_mode()
{
    delete ui;
}
int number_of_category;
std::string category;

QString question_in_file_survival_mode;
QString correct_answer_in_file_survival_mode;
QString incorrect_1;
QString incorrect_2;
QString incorrect_3;

std::vector <std::vector <std::string>> araye_in_correct_in_file_survival_mode;

question_of_player_to_survival_mode *window_for_show;
void geting_question_in_api()
{


    number_of_category = (rand() % 33);
    if(number_of_category < 10)
        number_of_category+=10;

    category = std::to_string(number_of_category);
    CURL *curl;
    CURLcode res;
    std::string response;
    nlohmann::json jsondata;

    std::string api = "https://opentdb.com/api.php?category="+ category + "&difficulty=" + difficulty_of_category_for_question_of_survival_mode +"&type=multiple&amount=1";
    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, api.c_str());
        curl_easy_setopt(curl,CURLOPT_CAINFO, "curl-ca-bundle.crt");
        curl_easy_setopt(curl , CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

    }

    curl_easy_cleanup(curl);
    curl = NULL;


    jsondata = nlohmann::json::parse(response);
    for(auto question : jsondata["results"])
    {
        question_in_file_survival_mode = QString::fromStdString(question["question"]);
        correct_answer_in_file_survival_mode = QString::fromStdString(question["correct_answer"]);
        araye_in_correct_in_file_survival_mode.push_back(question["incorrect_answers"]);
    }
    incorrect_1 = QString::fromStdString(araye_in_correct_in_file_survival_mode[conter_of_index_for_value_api][0]);
    incorrect_2 = QString::fromStdString(araye_in_correct_in_file_survival_mode[conter_of_index_for_value_api][1]);
    incorrect_3 = QString::fromStdString(araye_in_correct_in_file_survival_mode[conter_of_index_for_value_api][2]);
    qDebug() << correct_answer_in_file_survival_mode;
}
void question_of_player_to_survival_mode::show_window_for_click_just_in_ok()
{
    timer->stop();
    conter_of_in_correct_answer_for_mode_survival++;
    if(conter_of_in_correct_answer_for_mode_survival < 3)
    {
        //difficulty_of_category_for_question_of_survival_mode = "easy";
        window_for_show->setWindowTitle("Question for survival mode");
        window_for_show->resize(maximumSize());
        geting_question_in_api();
        window_for_show->geting_question_of_api_trivia();
        window_for_show->show();
    }
    else
    {
        window_for_show->geting_question_of_api_trivia();
    }
}
void question_of_player_to_survival_mode::show_window_for_question_new()
{
    timer->stop();
    conter_of_in_correct_answer_for_mode_survival++;
    window_for_show = new question_of_player_to_survival_mode();
    if(conter_of_in_correct_answer_for_mode_survival < 3)
    {
        //difficulty_of_category_for_question_of_survival_mode = "easy";
        window_for_show->setWindowTitle("Question for survival mode");
        window_for_show->resize(maximumSize());
        geting_question_in_api();
        window_for_show->geting_question_of_api_trivia();
        window_for_show->show();
    }
    if(conter_of_in_correct_answer_for_mode_survival == 3)
    {
        window_for_show->geting_question_of_api_trivia();
    }
    qDebug() << conter_of_in_correct_answer_for_mode_survival;
}
void question_of_player_to_survival_mode::set_time_in_window()
{
    if(sec == 0)
    {
        timer->stop();
        close();
        conter_of_in_correct_answer_for_mode_survival++;
        if(conter_of_in_correct_answer_for_mode_survival < 3)
        {
            window_for_show = new question_of_player_to_survival_mode();
            window_for_show->setWindowTitle("Question for survival mode");
            window_for_show->resize(maximumSize());
            geting_question_in_api();
            window_for_show->geting_question_of_api_trivia();
            window_for_show->show();
        }
        else
        {
            window_for_show->geting_question_of_api_trivia();
        }
    }
    ui->label_timer->setText("Time left to answer the question : " + QString::number(sec));
    sec--;
}

void question_of_player_to_survival_mode::geting_question_of_api_trivia()
{

    srand(time(0));

    int random_number_for_correct_answer = (rand()% 4) + 1;


    if(random_number_for_correct_answer == 1)
    {
        ui->label->setText(question_in_file_survival_mode);
        ui->options_1->setText(correct_answer_in_file_survival_mode);
        ui->options_2->setText(incorrect_1);
        ui->options_3->setText(incorrect_2);
        ui->options_4->setText(incorrect_3);
        if(conter_of_in_correct_answer_for_mode_survival < 3)
        {
        QObject::connect(ui->options_4, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
        });
        QObject::connect(ui->options_2, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
        });
        QObject::connect(ui->options_3, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
        });
        QObject::connect(ui->options_1, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, &QPushButton::clicked, [&](){
                timer->stop();
                conter_of_correct_answer_for_mode_survival++;
                window_for_show = new question_of_player_to_survival_mode();
                window_for_show->setWindowTitle("Question for survival mode");
                window_for_show->resize(maximumSize());
                geting_question_in_api();
                window_for_show->geting_question_of_api_trivia();
                window_for_show->show();
            });
        });
        }

        conter_of_index_for_value_api++;
    }
    if(random_number_for_correct_answer == 2)
    {
        ui->label->setText(question_in_file_survival_mode);
        ui->options_2->setText(correct_answer_in_file_survival_mode);
        ui->options_1->setText(incorrect_1);
        ui->options_3->setText(incorrect_2);
        ui->options_4->setText(incorrect_3);
        if(conter_of_in_correct_answer_for_mode_survival < 3)
        {
        QObject::connect(ui->options_1, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
        });
        QObject::connect(ui->options_4, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
        });
        QObject::connect(ui->options_3, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
        });
        QObject::connect(ui->options_2, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, &QPushButton::clicked, [&](){
                timer->stop();
                conter_of_correct_answer_for_mode_survival++;
                window_for_show = new question_of_player_to_survival_mode();
                window_for_show->setWindowTitle("Question for survival mode");
                window_for_show->resize(maximumSize());
                geting_question_in_api();
                window_for_show->geting_question_of_api_trivia();
                window_for_show->show();
            });
        });
        }

        conter_of_index_for_value_api++;
    }
    if(random_number_for_correct_answer == 3)
    {
        ui->label->setText(question_in_file_survival_mode);
        ui->options_3->setText(correct_answer_in_file_survival_mode);
        ui->options_2->setText(incorrect_1);
        ui->options_1->setText(incorrect_2);
        ui->options_4->setText(incorrect_3);
        if(conter_of_in_correct_answer_for_mode_survival < 3)
        {
        QObject::connect(ui->options_1, &QRadioButton::clicked, [&](){
                QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
        });
        QObject::connect(ui->options_2, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
        });
        QObject::connect(ui->options_4, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
        });
        QObject::connect(ui->options_3, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, &QPushButton::clicked, [&](){
                timer->stop();
                conter_of_correct_answer_for_mode_survival++;
                window_for_show = new question_of_player_to_survival_mode();
                window_for_show->setWindowTitle("Question for survival mode");
                window_for_show->resize(maximumSize());
                geting_question_in_api();
                window_for_show->geting_question_of_api_trivia();
                window_for_show->show();
            });
        });
        }

        conter_of_index_for_value_api++;
    }
    if(random_number_for_correct_answer == 4)
    {
        ui->label->setText(question_in_file_survival_mode);
        ui->options_4->setText(correct_answer_in_file_survival_mode);
        ui->options_2->setText(incorrect_1);
        ui->options_3->setText(incorrect_2);
        ui->options_1->setText(incorrect_3);
        if(conter_of_in_correct_answer_for_mode_survival < 3)
        {
        QObject::connect(ui->options_1, &QRadioButton::clicked, [&](){
                QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
        });
        QObject::connect(ui->options_2, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
        });
        QObject::connect(ui->options_3, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
        });
        QObject::connect(ui->options_4, &QRadioButton::clicked, [&](){
            QObject::connect(ui->pushButton, &QPushButton::clicked, [&](){
                timer->stop();
                conter_of_correct_answer_for_mode_survival++;
                window_for_show = new question_of_player_to_survival_mode();
                window_for_show->setWindowTitle("Question for survival mode");
                window_for_show->resize(maximumSize());
                geting_question_in_api();
                window_for_show->geting_question_of_api_trivia();
                window_for_show->show();
            });
        });
        }
        conter_of_index_for_value_api++;
    }
    //QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(show_window_for_question_new()));
    std::string h;
    if(conter_of_in_correct_answer_for_mode_survival == 3)
    {
        QString high;
        if(difficulty_of_category_for_question_of_survival_mode == "easy")
        {
            QFile file("score.txt");
            if(!file.open(QFile::ReadOnly | QFile::Text))
            {
                qDebug()<<"error no fond this file";
            }
            QString n = file.readLine();
            high = n;
            QFile file_2("score.txt");
            if(conter_of_correct_answer_for_mode_survival > high.toInt())
            {
                high = QString::number(conter_of_correct_answer_for_mode_survival);
                file.close();
                if(!file_2.open(QFile::WriteOnly | QFile::Truncate))
                {
                    qDebug()<<"error no fond this file";
                }
            }
            QTextStream score(&file_2);
            score<<high;
            file_2.close();
            h = std::to_string(conter_of_correct_answer_for_mode_survival);
        }
        else if(difficulty_of_category_for_question_of_survival_mode == "medium")
        {
            QFile file("score2.txt");
            if(!file.open(QFile::ReadOnly | QFile::Text))
            {
                qDebug()<<"error no fond this file";
            }
            QString n = file.readLine();
            high = n;
            QFile file_2("score2.txt");
            if(conter_of_correct_answer_for_mode_survival > high.toInt())
            {
                high = QString::number(conter_of_correct_answer_for_mode_survival);
                file.close();
                if(!file_2.open(QFile::WriteOnly | QFile::Truncate))
                {
                    qDebug()<<"error no fond this file";
                }
            }
            QTextStream score(&file_2);
            score<<high;
            file_2.close();
            h = std::to_string(conter_of_correct_answer_for_mode_survival);

        }
        else if(difficulty_of_category_for_question_of_survival_mode == "hard")
        {
            QFile file("score3.txt");
            if(!file.open(QFile::ReadOnly | QFile::Text))
            {
                qDebug()<<"error no fond this file";
            }

            QString n = file.readLine();
            high = n;
            QFile file_2("score3.txt");
            if(conter_of_correct_answer_for_mode_survival > high.toInt())
            {
                high = QString::number(conter_of_correct_answer_for_mode_survival);
                file.close();
                if(!file_2.open(QFile::WriteOnly | QFile::Truncate))
                {
                    qDebug()<<"error no fond this file";
                }
            }
            QTextStream score(&file_2);
            score<<high;
            file_2.close();
            h = std::to_string(conter_of_correct_answer_for_mode_survival);

        }
        else
        {
            QFile file("score4.txt");
            if(!file.open(QFile::ReadOnly | QFile::Text))
            {
                qDebug()<<"error no fond this file";
            }
            QString n = file.readLine();
            high = n;
            QFile file_2("score4.txt");
            if(conter_of_correct_answer_for_mode_survival > high.toInt())
            {
                high = QString::number(conter_of_correct_answer_for_mode_survival);
                file.close();
                if(!file_2.open(QFile::WriteOnly | QFile::Truncate))
                {
                    qDebug()<<"error no fond this file";
                }
            }
            QTextStream score(&file_2);
            score<<high;
            file_2.close();
            h = std::to_string(conter_of_correct_answer_for_mode_survival);
        }

        QFont font("Times", 16, QFont::Bold);
        font.setItalic(true);
        QWidget *show_score_for_player = new QWidget();
        show_score_for_player->setWindowTitle("Score of player");
        show_score_for_player->resize(maximumSize());
        show_score_for_player->setStyleSheet("background-color: rgb(33, 85, 88)");
        QLabel *label_score = new QLabel("<b><i>Score To get now :   </b></i>"+ QString::number(conter_of_correct_answer_for_mode_survival));
        QLabel *high_score = new QLabel("<b>The high score recorded sp far with aveage difficulty "+ QString::fromStdString(difficulty_of_category_for_question_of_survival_mode) +" of the question :  "+ high);
        QVBoxLayout *layout = new QVBoxLayout();
        label_score->setFont(font);
        high_score->setFont(font);
        layout->addWidget(label_score);
        layout->addWidget(high_score);
        show_score_for_player->setLayout(layout);
        show_score_for_player->show();
        qDebug() << conter_of_correct_answer_for_mode_survival;
    }

}


void choose_the_difficulty_to_question_To_survival_mode::on_pushButton_clicked()
{

    window_for_show = new question_of_player_to_survival_mode();
    difficulty_of_category_for_question_of_survival_mode = "easy";
    window_for_show->setWindowTitle("Question for survival mode");
    window_for_show->resize(maximumSize());
    geting_question_in_api();
    window_for_show->geting_question_of_api_trivia();
    window_for_show->show();


}


void choose_the_difficulty_to_question_To_survival_mode::on_pushButton_2_clicked()
{

    window_for_show = new question_of_player_to_survival_mode();
    difficulty_of_category_for_question_of_survival_mode = "medium";
    window_for_show->setWindowTitle("Question for survival mode");
    window_for_show->resize(maximumSize());
    geting_question_in_api();
    window_for_show->geting_question_of_api_trivia();
    window_for_show->show();

}


void choose_the_difficulty_to_question_To_survival_mode::on_pushButton_3_clicked()
{
    window_for_show = new question_of_player_to_survival_mode();
    difficulty_of_category_for_question_of_survival_mode = "hard";
    window_for_show->setWindowTitle("Question for survival mode");
    window_for_show->resize(maximumSize());
    geting_question_in_api();
    window_for_show->geting_question_of_api_trivia();
    window_for_show->show();
}


void choose_the_difficulty_to_question_To_survival_mode::on_pushButton_4_clicked()
{
    window_for_show = new question_of_player_to_survival_mode();
    difficulty_of_category_for_question_of_survival_mode = "";
    window_for_show->setWindowTitle("Question for survival mode");
    window_for_show->resize(maximumSize());
    geting_question_in_api();
    window_for_show->geting_question_of_api_trivia();
    window_for_show->show();

}


void choose_the_difficulty_to_question_To_survival_mode::on_commandLinkButton_clicked()
{
    choose_the_difficulty_to_question_To_survival_mode::close();
    Choose_the_type_of_game *window_for_show_return_choose = new Choose_the_type_of_game();
    window_for_show_return_choose->setWindowTitle("Choose the type the game");
    window_for_show_return_choose->resize(maximumSize());
    window_for_show_return_choose->show();

}

