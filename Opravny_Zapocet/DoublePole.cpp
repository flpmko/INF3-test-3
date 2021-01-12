#include "DoublePole.h"

DoublePole::DoublePole(const DoublePole& zdroj)
{
    if (this != &zdroj)
    {
        this->aPocet = zdroj.aPocet;
        aData = new double * [this->aPocet];
        for (int i = 0; i < this->aPocet; i++)
        {
            aData[i] = new double(*zdroj.aData[i]);
        }
    }
}

DoublePole& DoublePole::operator=(const DoublePole& zdroj)
{
    if (this != &zdroj)
    {
        DoublePole::~DoublePole();
        this->aPocet = zdroj.aPocet;
        aData = new double * [zdroj.aPocet];
        for (int i = 0; i < this->aPocet; i++)
        {
            aData[i] = new double(*zdroj.aData[i]);
        }
    }
    return *this;
}

DoublePole::~DoublePole()
{
    for (int i = 0; i < this->aPocet; i++)
    {
        delete aData[i];
    }
    delete[] aData;
}
