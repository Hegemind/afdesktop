#include "tabpnjs.h"
#include "ui_tabpnjs.h"

#include <QStandardItemModel>

TabPnjs::TabPnjs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabPnjs)
{
    ui->setupUi(this);

    charController = CharacterController::get();

    // Eventos de pulsar botones
    QObject::connect(ui->botonObtener, SIGNAL(clicked()), charController, SLOT(requestRefresh()));
    //QObject::connect(ui->botonObtenerSeleccionado, SIGNAL(clicked()), server, SLOT(obtenerPersonajeSeleccionado()));

    // Eventos de datos recibidos
    QObject::connect(charController, SIGNAL(refreshCompleted()), this, SLOT(poblarListaPersonajes()));
    //QObject::connect(server, SIGNAL(obtenerPersonajeSeleccionadoTerminado(QByteArray)), this, SLOT(mostrarPersonajeEnCaja(QByteArray)));
}

TabPnjs::~TabPnjs()
{
    delete ui;
}

// Lanza una actualización por defecto
void TabPnjs::recargar()
{
    emit ui->botonObtener->clicked();
}

void TabPnjs::poblarListaPersonajes()
{
    QStandardItemModel *modelo = new QStandardItemModel();

    for(Character* c : charController->getAllNPC())
    {
        QStandardItem* item = new QStandardItem(c->getName());
        modelo->appendRow(item);
    }

    // Poner los datos en la lista
    ui->listaPersonajes->setModel(modelo);
}

void TabPnjs::mostrarPersonajeEnCaja(QByteArray data)
{
    ui->cajaRespuestas->append(data);
}
