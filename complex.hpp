#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

#include <iRRAM/lib.h>

static iRRAM::orstream& operator<<(iRRAM::orstream& os, const iRRAM::COMPLEX& z)
{
    return os << z._real << z._imag << "i";
}

#endif