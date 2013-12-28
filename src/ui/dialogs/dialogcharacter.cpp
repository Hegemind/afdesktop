#include "dialogcharacter.h"
#include "ui_dialogcharacter.h"

DialogCharacter::DialogCharacter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCharacter)
{
    ui->setupUi(this);
}

DialogCharacter::~DialogCharacter()
{
    delete ui;
}
