#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QtNetwork>

class Server : public QObject
{
    Q_OBJECT

    QNetworkAccessManager* qnam;
    QNetworkReply *reply;
    QString address;
    static Server* instancia;
    Server();
public:
    static Server* get();


public slots:
    void obtenerPersonajes();
    void obtenerPersonajeSeleccionado();
    bool setAddress(const QString& addr){ address = addr; return true; }

private slots:
    void networkDone();

signals:
    void devolverDatos(QByteArray data);
};

#endif // SERVER_H
