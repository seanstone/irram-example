#ifndef __SPINOR_HPP__
#define __SPINOR_HPP__

#include <iRRAM/lib.h>
#include "complex.hpp"

class spinor
{
    iRRAM::COMPLEX x[2];

public:

    spinor() { x[0] = x[1] = iRRAM::COMPLEX(0); }
    spinor(iRRAM::COMPLEX x0, iRRAM::COMPLEX x1) { x[0] = x0; x[1] = x1; }

    iRRAM::COMPLEX& operator[](std::size_t idx)       { return x[idx]; }
    const iRRAM::COMPLEX& operator[](std::size_t idx) const { return x[idx]; }
};

static iRRAM::orstream& operator<<(iRRAM::orstream& os, const spinor& v)
{
    return os << "[" << v[0] << ", " << v[1] << "]";
}

#endif