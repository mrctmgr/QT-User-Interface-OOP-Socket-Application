#include "localserver.h"
#include <QLocalSocket>
#include <QTextStream>
LocalServer::LocalServer(QObject *parent)
    : QLocalServer{parent}
{
    mSocket = nullptr;
    connect(this,&LocalServer::newConnection,[&](){
        mSocket = nextPendingConnection();

    });
}

void LocalServer::send(const QString &msg){
    if(mSocket){
    QTextStream T(mSocket);
    T<<msg;
    mSocket->flush();
    }
}
