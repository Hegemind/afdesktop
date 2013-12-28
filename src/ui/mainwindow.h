#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QtWidgets/QMainWindow>

#include "src/ui/dialogs/dialogabout.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();




private:
    Ui::MainWindow *ui;
    DialogAbout* about;

    QStandardItemModel* model;
    QMenu* treeContextMenu;
private slots:
    void addNewAdventure();
    void addNewFolder();
    void addNewDocument();
    void contextMenu(QPoint point);

};

#endif // MAINWINDOW_H
