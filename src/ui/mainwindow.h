#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QtWidgets/QMainWindow>

#include "src/ui/dialogs/dialogabout.h"
#include "src/controller/server.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;
    DialogAbout* about;
    QStandardItemModel* model;
    QMenu* treeContextMenu;
    Server* server;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void addNewAdventure();
    void addNewFolder();
    void addNewDocument();
    void contextMenu(QPoint point);
    void editBloc(QModelIndex index);
    void changeServer();
};

#endif // MAINWINDOW_H
