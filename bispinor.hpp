#ifndef __BISPINOR_HPP__
#define __BISPINOR_HPP__

#include <iRRAM/lib.h>
#include "spinor.hpp"

class bispinor
{
    spinor x[2];

public:

    spinor& operator[](std::size_t idx)       { return x[idx]; }
    const spinor& operator[](std::size_t idx) const { return x[idx]; }
};

static iRRAM::orstream& operator<<(iRRAM::orstream& os, const bispinor& v)
{
    return os
    << "|" << v[0][0] << ", " << v[0][1] << "|" << "\n"
    << "|" << v[1][0] << ", " << v[1][1] << "|";
}

#endif