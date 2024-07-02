#ifndef PVP_MODE_QUESTIONS_H
#define PVP_MODE_QUESTIONS_H

#include <QDialog>

namespace Ui {
class pvp_mode_questions;
}

class pvp_mode_questions : public QDialog
{
    Q_OBJECT

public:
    explicit pvp_mode_questions(QWidget *parent = nullptr);
    ~pvp_mode_questions();

private slots:
    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::pvp_mode_questions *ui;
};

#endif // PVP_MODE_QUESTIONS_H
