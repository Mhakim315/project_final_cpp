#ifndef CATEGORY_OF_QUESTION_MODE_PVP_H
#define CATEGORY_OF_QUESTION_MODE_PVP_H

#include <QDialog>

namespace Ui {
class category_of_question_mode_pvp;
}

class category_of_question_mode_pvp : public QDialog
{
    Q_OBJECT

public:
    explicit category_of_question_mode_pvp(QWidget *parent = nullptr);
    ~category_of_question_mode_pvp();

private slots:
    void on_label_linkActivated(const QString &link);

    void on_pushButton_clicked();

    void on_Sport_clicked();

private:
    Ui::category_of_question_mode_pvp *ui;
};

#endif // CATEGORY_OF_QUESTION_MODE_PVP_H
