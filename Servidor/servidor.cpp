#include "servidor.h"


Servidor::Servidor(QObject *parent) : QTcpServer(parent)
{

}

void Servidor::startServer(){
    if (!this->listen(QHostAddress::Any, 5050)){
        qDebug() << "No se pudo iniciar el servidor";
    } else {
        qDebug() << "Esperando conexion...";
    }
}

void Servidor::incomingConnection(qintptr socketID){
    qDebug() << socketID << "se ha conectado";
    Thread *thread = new Thread(socketID, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->run();
}
