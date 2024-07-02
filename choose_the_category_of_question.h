#ifndef CHOOSE_THE_CATEGORY_OF_QUESTION_H
#define CHOOSE_THE_CATEGORY_OF_QUESTION_H

#include <QDialog>
#include "window_of_question_player.h"
#include "QTimer"


namespace Ui {
class choose_the_category_of_question;
}

class choose_the_category_of_question : public QDialog
{
    Q_OBJECT

public:
    explicit choose_the_category_of_question(QWidget *parent = nullptr);
    ~choose_the_category_of_question();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_Music_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_board_games_clicked();

    void on_sicence_nature_clicked();

    void on_comuter_clicked();

    void on_mytholoy_clicked();

    void on_sports_clicked();

    void on_geography_clicked();

    void on_histoory_clicked();

    void on_politics_clicked();

    void on_celebrities_clicked();

    void on_animals_clicked();

    void on_vehicles_clicked();

    void on_comics_clicked();

    void on_gadgets_clicked();

    void on_musical_and_theatres_clicked();

    void on_mathematics_clicked();

    void on_art_clicked();

    void on_japanese_anime_manga_clicked();

    void on_cartoon_and_animations_clicked();


private:
    Ui::choose_the_category_of_question *ui;
};

#endif // CHOOSE_THE_CATEGORY_OF_QUESTION_H
