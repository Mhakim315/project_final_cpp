#ifndef CHOOSE_THE_TYPE_OF_GAME_H
#define CHOOSE_THE_TYPE_OF_GAME_H

#include <QDialog>

namespace Ui {
class Choose_the_type_of_game;
}

class Choose_the_type_of_game : public QDialog
{
    Q_OBJECT

public:
    explicit Choose_the_type_of_game(QWidget *parent = nullptr);
    ~Choose_the_type_of_game();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::Choose_the_type_of_game *ui;
};

#endif // CHOOSE_THE_TYPE_OF_GAME_H
