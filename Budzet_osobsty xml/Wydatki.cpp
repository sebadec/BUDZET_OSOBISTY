#include "Wydatki.h"

bool Wydatki::operator<(Wydatki& wydatki)
{
    return (data < wydatki.pobierzDate());
}
