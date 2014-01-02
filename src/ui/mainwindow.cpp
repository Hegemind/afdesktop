#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>

#include "src/ui/tabs/tabpjs.h"
#include "src/ui/tabs/tabpnjs.h"
#include "src/controller/charactercontroller.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Preparar GUI
    ui->setupUi(this);
    about = new DialogAbout();
    connect(ui->actionNuevoBloc, SIGNAL(triggered()), this, SLOT(addNewAdventure()));

    // Arbol izquierdo
    model = new QStandardItemModel();
    ui->treeView->setModel(model);
    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    // Menu contextual del arbol de la izquierda
    treeContextMenu = new QMenu(ui->treeView);
    treeContextMenu->addAction(ui->actionNuevoBloc);
    treeContextMenu->addSeparator();
    treeContextMenu->addAction(ui->actionNuevaCarpeta);
    treeContextMenu->addAction(ui->actionNuevoDocumento);
    connect(ui->actionNuevaCarpeta, SIGNAL(triggered()), this, SLOT(addNewFolder()));
    connect(ui->actionNuevoDocumento, SIGNAL(triggered()), this, SLOT(addNewDocument()));
    connect(ui->treeView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
    connect(ui->treeView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(editBloc(QModelIndex)));

    // Configurar Acerca de...
    connect(ui->actionAcerca_de, SIGNAL(triggered()), about, SLOT(open()));

    // Quitar Tabs por defecto
    QTabWidget* tabs = ui->tabWidget;
    tabs->removeTab(1);
    tabs->removeTab(0);
    // Preparar iconos de los tabs
    QIcon i0(QString(":/icon/location"));
    QIcon i1(QString(":/icon/cmd"));
    QIcon i2(QString(":/icon/calendar"));
    QIcon i3(QString(":/icon/eye"));
    QIcon i4(QString(":/icon/man"));
    QIcon i5(QString(":/icon/pnjs"));
    QIcon i6(QString(":/icon/settings"));
    // Añadir mis propios tabs
    tabs->addTab(new QTabWidget(), i0, "Localización");
    tabs->addTab(new QTabWidget(), i1, "Combate");
    tabs->addTab(new QTabWidget(), i2, "Encuentros");
    tabs->addTab(new QTabWidget(), i3, "Pantalla");
    tabs->addTab(new TabPjs(),     i4, "PJs");
    tabs->addTab(new TabPnjs(),    i5, "PNJs");
    tabs->addTab(new QTabWidget(), i6, "Reglas");
    // Estilo para los tabs
    tabs->setStyleSheet("QTabBar::tab { height: 50px; width: 120px; }");


    // Cargar datos inicialmente
    CharacterController::get()->requestRefresh();


    // Arbol de la izquierda

//    QIcon folders(":icon/folders");
//    QStandardItem* aventura = new QStandardItem(folders, QString("Aventura"));
//    aventura->appendRow(new QStandardItem(QString("Resumen")));
//    aventura->appendRow(new QStandardItem(QString("PNJs")));
//    aventura->appendRow(new QStandardItem(QString("Anotaciones")));
//    QStandardItem* planteamiento = new QStandardItem(QString("Planteamiento"));
//    planteamiento->appendRow(new QStandardItem(QString("Introducción")));
//    planteamiento->appendRow(new QStandardItem(QString("Posibilidades")));
//    aventura->appendRow(planteamiento);
//    QStandardItem* nudo = new QStandardItem(QString("Nudo 1"));
//    nudo->appendRow(new QStandardItem(QString("Escena 1")));
//    nudo->appendRow(new QStandardItem(QString("Escena 2")));
//    nudo->appendRow(new QStandardItem(QString("Escena 3")));
//    aventura->appendRow(nudo);
//    nudo = new QStandardItem(QString("Nudo 2"));
//    nudo->appendRow(new QStandardItem(QString("Escena 1")));
//    nudo->appendRow(new QStandardItem(QString("Escena 2")));
//    nudo->appendRow(new QStandardItem(QString("Escena 3")));
//    aventura->appendRow(nudo);
//    QStandardItem* desenlace = new QStandardItem(QString("Desenlace"));
//    desenlace->appendRow(new QStandardItem(QString("Escena 1")));
//    desenlace->appendRow(new QStandardItem(QString("Desenlace")));
//    aventura->appendRow(desenlace);
//    aventura->appendRow(new QStandardItem(QString("Extras")));
//    aventura->appendRow(new QStandardItem(QString("Localización")));
//    model->invisibleRootItem()->appendRow(aventura);
    // Fin configuracion del arbol


}

MainWindow::~MainWindow()
{
    delete ui;
    delete treeContextMenu;
    delete about;
    delete model;
}

void MainWindow::addNewAdventure()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Nueva aventura"), tr("Nombre de la aventura:"), QLineEdit::Normal, QString(), &ok);

    if(ok && !text.isEmpty())
    {
        QStandardItem* aventuraItem = new QStandardItem(QString(text));
        model->invisibleRootItem()->appendRow(aventuraItem);
    }
}

void MainWindow::addNewFolder()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Nueva carpeta"), tr("Nombre de la carpeta:"), QLineEdit::Normal, QString(), &ok);
}

void MainWindow::addNewDocument()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Nuevo documento"), tr("Nombre del documento:"), QLineEdit::Normal, QString(), &ok);
}

void MainWindow::contextMenu(QPoint point)
{
    treeContextMenu->popup(point);
}

void MainWindow::editBloc(QModelIndex index)
{
    bool ok;
    QString nombre = model->itemFromIndex(index)->text();
    QString text = QInputDialog::getText(this, tr("Editar aventura"), tr("Nombre de la aventura:"), QLineEdit::Normal, nombre, &ok);
}
