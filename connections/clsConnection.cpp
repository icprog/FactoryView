#include "connections/clsConnection.h"
#include "connections/clsGpib.h"

connectionFactory::connectionFactory()
{
}

clsConnection *connectionFactory::getConnection(QString strConnect)
{
    if(strConnect.toUpper()=="GPIB")
    {
        return new clsGpib;
    }
    else
    {
        return (clsConnection *)0;
    }

}


clsConnection *connectionFactory::getGpib()
{
    return new clsGpib;
}
