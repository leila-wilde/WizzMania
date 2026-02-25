#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QObject>
#include <QTcpServer>

class ServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(ushort port = 4500, QObject *parent = nullptr);

private slots:
    void newClientConnectionReceived();

signals:

private: // fields
    QTcpServer *_server;
private: // methods
    void setupServer(ushort port);

};

#endif // SERVERMANAGER_H
