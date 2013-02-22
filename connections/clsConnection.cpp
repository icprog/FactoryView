#include "connections/clsConnection.h"
#include "connections/clsGpib.h"
#include "connections/clsUsb.h"
connectionFactory::connectionFactory()
{
}

clsConnection *connectionFactory::getConnection(QString strConnect)
{
    if(strConnect.toUpper()=="GPIB")
    {
        return new clsGpib;
    }
    else if(strConnect.toUpper()=="USB")
    {
        return new clsUsb;
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
