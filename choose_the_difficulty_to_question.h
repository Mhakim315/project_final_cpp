#ifndef CHOOSE_THE_DIFFICULTY_TO_QUESTION_H
#define CHOOSE_THE_DIFFICULTY_TO_QUESTION_H

#include <QDialog>

namespace Ui {
class choose_the_difficulty_To_question;
}

class choose_the_difficulty_To_question : public QDialog
{
    Q_OBJECT

public:
    explicit choose_the_difficulty_To_question(QWidget *parent = nullptr);
    ~choose_the_difficulty_To_question();

private slots:
    void on_easy_clicked();

    void on_medium_clicked();

    void on_any_difficulty_clicked();

    void on_hard_clicked();

private:
    Ui::choose_the_difficulty_To_question *ui;
};

#endif // CHOOSE_THE_DIFFICULTY_TO_QUESTION_H
