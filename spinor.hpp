#ifndef __SPINOR_HPP__
#define __SPINOR_HPP__

#include <iRRAM/lib.h>
#include "complex.hpp"

class spinor
{
    iRRAM::COMPLEX x[2];

public:

    iRRAM::COMPLEX& operator[](std::size_t idx)       { return x[idx]; }
    const iRRAM::COMPLEX& operator[](std::size_t idx) const { return x[idx]; }
};

static iRRAM::orstream& operator<<(iRRAM::orstream& os, const spinor& v)
{
    return os << "[" << v[0] << ", " << v[1] << "]";
}

#endif