#include "charactercontroller.h"

CharacterController* CharacterController::instancia = 0;

CharacterController::CharacterController(Server* server) :
    server(server)
{
    cache = new CharacterCache();

    // Eventos de pulsar botones
    QObject::connect(this, SIGNAL(refresh()), server, SLOT(obtenerPersonajes()));

    // Eventos de datos recibidos
    QObject::connect(server, SIGNAL(devolverDatos(QByteArray)), this, SLOT(refreshResponse(QByteArray)));
}

CharacterController::~CharacterController()
{
    delete cache;
}

CharacterController* CharacterController::get()
{
    if(instancia == 0){
        instancia = new CharacterController(Server::get());
    }

    return instancia;
}

QList<Character*> CharacterController::search(QString text)
{
    QList<Character*> ret;
    text = "no molestes";
    return ret;
}

QList<Character*> CharacterController::getAllCharacters(bool PCness)
{
    QList<Character*> ret;

    for(Character* c : cache->values())
    {
        if(c->isNPC() == PCness)
            ret.push_back(c);
    }

    return ret;
}

void CharacterController::doRefresh()
{
    // Descargar datos
    emit refresh();

    // Comprobar si hay datos nuevos y actualizar si es necesario
}

// SLOT
void CharacterController::requestRefresh()
{
    // TODO
    // Comprobar que los datos los tenemos anticuados:
    // temporizador, comprobacion directa, ...
    bool datosLimpios = false;


    // Si los datos estan limpios ignorar señal
    // Si estan sucios pasarela de la señal hacia el servidor
    if(datosLimpios)
    {
        emit refreshCompleted();
    }
    else {
        emit refresh();
    }
}

// SLOT
void CharacterController::refreshResponse(QByteArray data)
{
    // Recibe señal del servidor con los datos listos, parsear
    // los datos y almacenarlos en cache

    QJsonDocument doc = QJsonDocument::fromJson(data);

    // Rellenar esta lista con los nombres
    QJsonArray array = doc.array();

    Character* c = 0;
    for(int i = 0; i < array.size(); i++){
        QJsonObject character = array[i].toObject();
        QString name = character.value(QString("name")).toString();
        double id = character.value(QString("id")).toDouble();
        bool isNPC = character.value(QString("is_npc")).toDouble() == 1;

        c = new Character(id);
        c->setName(name);
        c->isNPC(isNPC);

        insert(c);
    }

    // Emite señal al que este interesado
    emit refreshCompleted();
}
