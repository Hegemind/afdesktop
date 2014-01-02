#ifndef TABPJS_H
#define TABPJS_H

#include <QWidget>
#include <QListWidgetItem>

#include "src/controller/charactercontroller.h"
#include "src/ui/widgets/characterwidget.h"

namespace Ui {
class TabPjs;
}

class TabPjs : public QWidget
{
    Q_OBJECT

public:
    explicit TabPjs(QWidget *parent = 0);
    ~TabPjs();

    void recargar();

private slots:
    void poblarListaPersonajes();
    void mostrarPersonajeEnCaja(QByteArray data);
    void personajeSeleccionado(QModelIndex i);

private:
    Ui::TabPjs *ui;
    CharacterController* charController;
    CharacterWidget* charWidget;
};

#endif // TABPJS_H
