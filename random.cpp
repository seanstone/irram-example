#include <iRRAM/lib.h>
#include <stdlib.h>
#include "random.hpp"

using namespace iRRAM;

REAL rand1() { return 2 * (float)rand()/(float)(RAND_MAX) - 1; }
COMPLEX rand1z() { return COMPLEX(rand1(),rand1()); }

VEC4 rand_massless()
{
    VEC4 p(0, rand1(), rand1(), rand1());
    p[0] = sqrt(p[1]*p[1] + p[2]*p[2] + p[3]*p[3]);
    return p;
}