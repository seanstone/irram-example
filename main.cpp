#include <iRRAM/lib.h>
#include <stdlib.h>
#include "vec4.hpp"

using namespace iRRAM;

void compute();

int main(int argc, char **argv)
{
    iRRAM_initialize2(&argc, argv);
    iRRAM::exec(compute);
    iRRAM_finalize();

    return 0;
}

void compute()
{
    srand(time(NULL));

    vec4 p;

    p[1] = 2 * (float)rand()/(float)(RAND_MAX) - 1;
    p[2] = 2 * (float)rand()/(float)(RAND_MAX) - 1;
    p[3] = 2 * (float)rand()/(float)(RAND_MAX) - 1;
    p[0] = sqrt(p[1]*p[1] + p[2]*p[2] + p[3]*p[3]);

    int deci_places = 16;
    cout << setRwidth(deci_places + 8);

    cout << p << "\n";
    cout << p.norm() << "\n";
}
