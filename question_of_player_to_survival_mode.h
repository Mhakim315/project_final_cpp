#ifndef QUESTION_OF_PLAYER_TO_SURVIVAL_MODE_H
#define QUESTION_OF_PLAYER_TO_SURVIVAL_MODE_H

#include <QDialog>
#include "QTimer"

namespace Ui {
class question_of_player_to_survival_mode;
}

class question_of_player_to_survival_mode : public QDialog
{
    Q_OBJECT

public:

    explicit question_of_player_to_survival_mode(QWidget *parent = nullptr);
    ~question_of_player_to_survival_mode();
    void geting_question_of_api_trivia();

public slots:
    void set_time_in_window();
private slots:
    void show_window_for_click_just_in_ok();
    void show_window_for_question_new();


private:
    int sec;
    QTimer *timer;
    Ui::question_of_player_to_survival_mode *ui;
};

#endif // QUESTION_OF_PLAYER_TO_SURVIVAL_MODE_H
