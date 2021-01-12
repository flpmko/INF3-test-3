#include "DoublePole.h"

DoublePole::DoublePole(const DoublePole& zdroj)
{
    if (zdroj.aData && *zdroj.aData)
    {
        this->aPocet = zdroj.aPocet;
        aData = new double * [this->aPocet];
        for (int i = 0; i < this->aPocet; i++)
        {
            this->aData[i] = zdroj.aData[i];
        }
    }
}

DoublePole& DoublePole::operator=(const DoublePole& zdroj)
{
    if (this != &zdroj)
    {
        DoublePole::~DoublePole();
        this->aPocet = zdroj.aPocet;
        aData = new double * [this->aPocet];
        for (int i = 0; i < this->aPocet; i++)
        {
            this->aData[i] = zdroj.aData[i];
        }
    }
    return *this;
}

DoublePole::~DoublePole()
{
    for (int i = 0; i < this->aPocet; i++)
    {
        delete this->aData[i];
    }
    delete[] this->aData;
    aData = nullptr;
}
