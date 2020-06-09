#include "thread.h"

Thread::Thread(int ID, QObject *parent)
    :QThread(parent)
{
 this->socketID = ID;
}
void Thread::run(){
    // El thread empieza aqui
    qDebug() << "Iniciando thread...";
    socket = new QTcpSocket();
    if (!socket->setSocketDescriptor(this->socketID)) {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);

    qDebug() << socketID << "Cliente conectado";

    exec();
}

void Thread::readyRead(){

    QByteArray data = socket->readAll();

    socket->write(data);
}

void Thread::disconnected(){

     qDebug() << socketID << "Cliente desconectado";
    socket->deleteLater();
    exit(0);
}
