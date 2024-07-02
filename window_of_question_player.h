#ifndef WINDOW_OF_QUESTION_PLAYER_H
#define WINDOW_OF_QUESTION_PLAYER_H

#include <QDialog>
#include "QVector"
namespace Ui {
class window_of_question_player;
}

class window_of_question_player : public QDialog
{
    Q_OBJECT

public:
    explicit window_of_question_player(QWidget *parent = nullptr);
    ~window_of_question_player();

public slots:


    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void geting_question_for_player_1_in_api(std::string category_player_1);

    void geting_question_for_player_2_in_api(std::string category_player_2);

    void change_text_for_question_and_options_for_player_1(int number_correct_answer[5],QString correct_answer[5], QString in_correct_answer_1[5], QString in_correct_answer_2[5], QString in_correct_answer_3[5],QString question_of_player_1[5]);

    void change_text_for_question_and_options_for_player_2(int number_correct_answer[5],QString correct_answer[5], QString in_correct_answer_1[5], QString in_correct_answer_2[5], QString in_correct_answer_3[5],QString question_of_player_2[5]);

    void set_time_in_pvp_window();
    void set_time_in_pvp_window_2();
    void set_time_in_pvp_window_3();
    void set_time_in_pvp_window_4();
    void set_time_in_pvp_window_5();

private slots:

    void gold_round();

private:
    int sec_in_pvp;
    QTimer *timer;
    Ui::window_of_question_player *ui;
};

#endif // WINDOW_OF_QUESTION_PLAYER_H
