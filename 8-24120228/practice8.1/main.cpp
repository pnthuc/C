#include "process1.h"
int main() {
    char *s, *f, *r;
    input(s, f, r);
    output(s, f, r);
    delete [] s, f, r;
    return 0;
}