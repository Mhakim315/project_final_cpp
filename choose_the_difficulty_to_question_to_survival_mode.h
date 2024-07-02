#ifndef CHOOSE_THE_DIFFICULTY_TO_QUESTION_TO_SURVIVAL_MODE_H
#define CHOOSE_THE_DIFFICULTY_TO_QUESTION_TO_SURVIVAL_MODE_H

#include <QDialog>

namespace Ui {
class choose_the_difficulty_to_question_To_survival_mode;
}

class choose_the_difficulty_to_question_To_survival_mode : public QDialog
{
    Q_OBJECT

public:
    explicit choose_the_difficulty_to_question_To_survival_mode(QWidget *parent = nullptr);
    ~choose_the_difficulty_to_question_To_survival_mode();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::choose_the_difficulty_to_question_To_survival_mode *ui;
};

#endif // CHOOSE_THE_DIFFICULTY_TO_QUESTION_TO_SURVIVAL_MODE_H
