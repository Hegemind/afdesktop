#include "tabpjs.h"
#include "ui_tabpjs.h"

#include <QStandardItemModel>
#include <QMessageBox>

#include "src/ui/dialogs/dialogcharacter.h"
#include "src/ui/views/characteritemview.h"

TabPjs::TabPjs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabPjs)
{
    ui->setupUi(this);

    charController = CharacterController::get();

    // Eventos de pulsar botones
    connect(ui->botonObtener, SIGNAL(clicked()), charController, SLOT(requestRefresh()));
    //QObject::connect(ui->botonObtenerSeleccionado, SIGNAL(clicked()), server, SLOT(obtenerPersonajeSeleccionado()));

    // Eventos de datos recibidos
    connect(charController, SIGNAL(refreshCompleted()), this, SLOT(poblarListaPersonajes()));
    //QObject::connect(server, SIGNAL(obtenerPersonajeSeleccionadoTerminado(QByteArray)), this, SLOT(mostrarPersonajeEnCaja(QByteArray)));

    connect(ui->listaPersonajes, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onListMailItemClicked(QModelIndex)));
}

TabPjs::~TabPjs()
{
    delete ui;
}

void TabPjs::onListMailItemClicked(QModelIndex i)
{
    //QMessageBox::information(0, "Try Again", "Please try to activate your Bluetooth again.");
    DialogCharacter* dc = new DialogCharacter();
    dc->setModal(true);
    dc->exec();

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
    ui->cajaRespuestas->append(data);
}
