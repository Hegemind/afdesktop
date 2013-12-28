#ifndef ADVENTURE_H
#define ADVENTURE_H

#include <QObject>

struct Planteamiento
{
    QString introduccion, posibilidades;
};

struct Escena
{
    QString titulo, descripcion;
};

struct Nudo
{
    QString titulo, descripcion;
    QList<Escena> escenas;
};

struct Desenlace
{
    QList<Escena> escenas;
    QString desenlace;
};

struct Adventure
{
    QString titulo;
    QString resumen;
    QList<double> pnjs;
    QList<QString> anotaciones;
    Planteamiento planteamiento;
    QList<Nudo> nudos;
    Desenlace desenlace;

public:
    Adventure();
};


#endif // ADVENTURE_H
