#include "tabpjs.h"
#include "ui_tabpjs.h"

#include <QStandardItemModel>
#include <QMessageBox>

#include "src/ui/views/characteritemview.h"

TabPjs::TabPjs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabPjs)
{
    // Preparar UI
    ui->setupUi(this);

    charWidget = new CharacterWidget();
    ui->frameDerecha->layout()->addWidget(charWidget);

    charController = CharacterController::get();

    // Eventos de pulsar botones
    connect(ui->botonObtener, SIGNAL(clicked()), charController, SLOT(requestRefresh()));
    connect(ui->listaPersonajes, SIGNAL(clicked(QModelIndex)), this, SLOT(personajeSeleccionado(QModelIndex)));


    // Eventos de datos recibidos
    connect(charController, SIGNAL(refreshCompleted()), this, SLOT(poblarListaPersonajes()));
}

TabPjs::~TabPjs()
{
    delete ui;
    delete charWidget;
}

void TabPjs::personajeSeleccionado(QModelIndex i)
{

}

// Lanza una actualización por defecto
void TabPjs::recargar()
{
    emit ui->botonObtener->clicked();
}

void TabPjs::poblarListaPersonajes()
{
    QStandardItemModel *modelo = new QStandardItemModel();

    for(Character* c : charController->getAllPC())
    {
        QStandardItem* item = new QStandardItem(c->getName());
        modelo->appendRow(item);
    }

    // Poner los datos en la lista
    ui->listaPersonajes->setModel(modelo);
}

void TabPjs::mostrarPersonajeEnCaja(QByteArray data)
{
//    ui->cajaRespuestas->append(data);
}
