#ifndef CHOOSE_THE_DIFFICULTY_H
#define CHOOSE_THE_DIFFICULTY_H

#include <QDialog>

namespace Ui {
class choose_the_difficulty;
}

class choose_the_difficulty : public QDialog
{
    Q_OBJECT

public:
    explicit choose_the_difficulty(QWidget *parent = nullptr);
    ~choose_the_difficulty();

private:
    Ui::choose_the_difficulty *ui;
};

#endif // CHOOSE_THE_DIFFICULTY_H
