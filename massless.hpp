#ifndef __MASSLESS_HPP__
#define __MASSLESS_HPP__

#include <iRRAM/lib.h>
#include "vec4.hpp"
#include "bispinor.hpp"

class MASSLESS
{
public:
    VEC4 p;
    SPINOR s;
    SPINOR a;

    MASSLESS(VEC4 _p)
    {
        p = _p;
        a = SPINOR(p);
        s = conjugate(a);
    }
};

iRRAM::COMPLEX sb(MASSLESS p1, MASSLESS p2)
{
    return p1.s[0] * p2.s[1] - p1.s[1] * p2.s[0];
}

iRRAM::COMPLEX ab(MASSLESS p1, MASSLESS p2)
{
    return p1.a[0] * p2.a[1] - p1.a[1] * p2.a[0];
}

#endif