#ifndef SERVIDOR_H
#define SERVIDOR_H
#include "thread.h"
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>

class Servidor : public QTcpServer
{
    Q_OBJECT
public:
    explicit Servidor(QObject *parent = nullptr);
    void startServer();
signals:

public slots:

protected:
    void incomingConnection(qintptr sockedID);
};

#endif // SERVIDOR_H
