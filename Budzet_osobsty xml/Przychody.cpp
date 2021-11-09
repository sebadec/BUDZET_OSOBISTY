#include "Przychody.h"

bool Przychody::operator<(Przychody& przychody)
{
    return (data < przychody.pobierzDate());
}
