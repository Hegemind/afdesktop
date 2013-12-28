#include "dialognewadventure.h"
#include "ui_dialognewadventure.h"

DialogNewAdventure::DialogNewAdventure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewAdventure)
{
    ui->setupUi(this);
}

DialogNewAdventure::~DialogNewAdventure()
{
    delete ui;
}
