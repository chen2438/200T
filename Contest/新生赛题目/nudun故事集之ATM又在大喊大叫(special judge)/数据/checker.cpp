#include "testlib.h"
#define eps 1e-6
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    double pans = ouf.readDouble();
    double jans = ans.readDouble();

    if (fabs(pans - jans)/jans<eps)
        quitf(_ok, "The answer is correct.");
    else
        quitf(_wa, "The answer is wrong: expected = %f, found = %f", jans, pans);
}
