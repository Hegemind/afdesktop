#ifndef TABPNJS_H
#define TABPNJS_H

#include <QWidget>
#include "src/controller/charactercontroller.h"

namespace Ui {
class TabPnjs;
}

class TabPnjs : public QWidget
{
    Q_OBJECT

public:
    explicit TabPnjs(QWidget *parent = 0);
    ~TabPnjs();

    void recargar();

private slots:
    void poblarListaPersonajes();
    void mostrarPersonajeEnCaja(QByteArray data);

private:
    Ui::TabPnjs *ui;
    CharacterController* charController;
};

#endif // TABPNJS_H
