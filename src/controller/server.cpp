#include "server.h"
#include "src/business/character.h"

Server* Server::instancia = 0;

Server::Server()
{
    qnam = new QNetworkAccessManager();

    // Direccion por defecto
    address = "http://localhost:3000";
}

Server* Server::get()
{
    if(instancia == 0){
        instancia = new Server();
    }

    return instancia;
}

void Server:: obtenerPersonajes()
{
    // Comprobar si estos datos están en cache

    // Si no estan en cache, obtener del servidor
    QUrl url(address + "/user/2/characters");
    reply = qnam->get(QNetworkRequest(url));

    QObject::connect(reply, SIGNAL(finished()), this, SLOT(networkDone()));
}

void Server::obtenerPersonajeSeleccionado()
{
    // Comprobar si estos datos están en cache

    // Si no estan en cache, obtener del servidor
    QUrl url(address + "/character/1");
    reply = qnam->get(QNetworkRequest(url));

    QObject::connect(reply, SIGNAL(finished()), this, SLOT(networkDone()));
}

void Server::networkDone()
{
    emit devolverDatos(reply->readAll());
}

