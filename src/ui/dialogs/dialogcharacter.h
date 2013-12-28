#ifndef DIALOGCHARACTER_H
#define DIALOGCHARACTER_H

#include <QDialog>

namespace Ui {
class DialogCharacter;
}

class DialogCharacter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCharacter(QWidget *parent = 0);
    ~DialogCharacter();

private:
    Ui::DialogCharacter *ui;
};

#endif // DIALOGCHARACTER_H
