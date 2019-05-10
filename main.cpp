#include <iRRAM/lib.h>
#include <stdlib.h>
#include "vec4.hpp"
#include "bispinor.hpp"

using namespace iRRAM;

void compute();

int main(int argc, char **argv)
{
    srand(time(NULL));

    iRRAM_initialize2(&argc, argv);

    int deci_places = 8;
    cout << setRwidth(deci_places + 8);

    iRRAM::exec(compute);
    iRRAM_finalize();

    return 0;
}

REAL rand1() { return 2 * (float)rand()/(float)(RAND_MAX) - 1; }
COMPLEX rand1z() { return COMPLEX(rand1(),rand1()); }

VEC4 lorentz_x(REAL eta, VEC4 p)
{
    VEC4 q = p;
    q[0] = cosh(eta) * p[0] + sinh(eta) * p[1];
    q[1] = sinh(eta) * p[0] + cosh(eta) * p[1];
    return q;
}

VEC4 rand_massless()
{
    VEC4 p(0, rand1(), rand1(), rand1());
    p[0] = sqrt(p[1]*p[1] + p[2]*p[2] + p[3]*p[3]);
    return p;
}

void compute()
{
    VEC4 p = rand_massless();

    cout << p << "\n";
    cout << p.norm() << "\n";

    SPINOR l(p);
    BISPINOR b(l, conjugate(l));
    cout << b << "\n";
    cout << b.norm() << "\n";
}
