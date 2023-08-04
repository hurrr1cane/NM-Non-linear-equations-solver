#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Header.h"

using namespace std;

int main(void) {
    int count = 0, check = 0;
    double a = 1, b = -4, c = -9, d = 2, x, eps = 0.000001,
        l = 4, r = 8;

    cout << '\n';
    for (int i = 0; i < 3; i++) {
        getter(a, b, c, d, &l, &r, &eps);
        printergeneral(a, b, c, d, l, r, eps);
        x = DychotomyMethod(a, b, c, d, l, r, eps, &count);
        printermethodal("Dychotomy", x, count);
        x = ChordeMethod(a, b, c, d, l, r, eps, &count);
        printermethodal("Chorde", x, count);
        x = NewtoneMethod(a, b, c, d, l, r, eps, &count);
        printermethodal("Newtone", x, count);
        x = IterationMethod(a, b, c, d, l, r, eps, &count);
        printermethodal("Iterational", x, count);
    }
}