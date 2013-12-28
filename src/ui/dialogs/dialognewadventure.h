#ifndef DIALOGNEWADVENTURE_H
#define DIALOGNEWADVENTURE_H

#include <QDialog>

namespace Ui {
class DialogNewAdventure;
}

class DialogNewAdventure : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewAdventure(QWidget *parent = 0);
    ~DialogNewAdventure();

private:
    Ui::DialogNewAdventure *ui;
};

#endif // DIALOGNEWADVENTURE_H
