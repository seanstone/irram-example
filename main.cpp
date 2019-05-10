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
    iRRAM::exec(compute);
    iRRAM_finalize();

    return 0;
}

REAL rand1() { return 2 * (float)rand()/(float)(RAND_MAX) - 1; }
COMPLEX rand1z() { return COMPLEX(rand1(),rand1()); }

vec4 lorentz_x(REAL eta, vec4 p)
{
    vec4 q = p;
    q[0] = cosh(eta) * p[0] + sinh(eta) * p[1];
    q[1] = sinh(eta) * p[0] + cosh(eta) * p[1];
    return q;
}

void compute()
{
    vec4 p;
    p[1] = rand1();
    p[2] = rand1();
    p[3] = rand1();
    p[0] = sqrt(p[1]*p[1] + p[2]*p[2] + p[3]*p[3]);

    int deci_places = 8;
    cout << setRwidth(deci_places + 8);

    cout << p << "\n";
    cout << p.norm() << "\n";

    vec4 q = lorentz_x(1, p);
    cout << q << "\n";
    cout << q.norm() << "\n";

    bispinor b;
    b[0][0] = rand1z();
    b[0][1] = rand1z();
    b[1][0] = rand1z();
    b[1][1] = rand1z();
    cout << b << "\n";
}
