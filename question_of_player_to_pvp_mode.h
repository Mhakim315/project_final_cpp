#ifndef QUESTION_OF_PLAYER_TO_PVP_MODE_H
#define QUESTION_OF_PLAYER_TO_PVP_MODE_H

#include <QDialog>


namespace Ui {
class question_of_player_To_pvp_mode;
}

class question_of_player_To_pvp_mode : public QDialog
{
    Q_OBJECT

public:
    explicit question_of_player_To_pvp_mode(QWidget *parent = nullptr);
    ~question_of_player_To_pvp_mode();

private slots:
    void on_pushButton_clicked();

    void on_label_linkActivated(const QString &link);

    void on_Question_1_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::question_of_player_To_pvp_mode *ui;
};

#endif // QUESTION_OF_PLAYER_TO_PVP_MODE_H
