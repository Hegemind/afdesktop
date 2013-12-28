#include "server.h"
#include "src/business/character.h"

Server::Server()
{
    qnam = new QNetworkAccessManager();
}

void Server:: obtenerPersonajes()
{
    // Comprobar si estos datos están en cache

    // Si no estan en cache, obtener del servidor
    QUrl url("http://localhost:3000/user/2/characters");
    reply = qnam->get(QNetworkRequest(url));

    QObject::connect(reply, SIGNAL(finished()), this, SLOT(networkDone()));
}

void Server::obtenerPersonajeSeleccionado()
{
    // Comprobar si estos datos están en cache

    // Si no estan en cache, obtener del servidor
    QUrl url("http://localhost:3000/character/1");
    reply = qnam->get(QNetworkRequest(url));

    QObject::connect(reply, SIGNAL(finished()), this, SLOT(networkDone()));
}

void Server::networkDone()
{
    emit devolverDatos(reply->readAll());
}

