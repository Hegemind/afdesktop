#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QtNetwork>

class Server : public QObject
{
    Q_OBJECT

    QNetworkAccessManager* qnam;
    QNetworkReply *reply;

public:
    Server();

public slots:
    void obtenerPersonajes();
    void obtenerPersonajeSeleccionado();

private slots:
    void networkDone();

signals:
    void devolverDatos(QByteArray data);
};

#endif // SERVER_H
