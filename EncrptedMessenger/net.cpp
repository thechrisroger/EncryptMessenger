#include "net.h"

Net::Net()
{

}

Net::Net(qint32 port)
{
    localServer = new QTcpServer;
    localServer->listen(QHostAddress::Any,port);
}

Net::~Net()
{

}
