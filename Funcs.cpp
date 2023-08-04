#include <iostream>
#include <cmath>
#include "Header.h"

using namespace std;

double CubicEquation(double a, double b, double c, double d, double x) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

double poh1(double a, double b, double c, double x) {
    return 3 * a * x * x + 2 * b * x + c;
}

double poh2(double a, double b, double x) {
    return 6 * a * x + 2 * b;
}

double ChordeMethod(double a, double b, double c, double d, double l, double r, double eps, int* count) {

    int variant;
    (*count) = 0;

    if (poh1(a, b, c, (l + r) / 2) * poh2(a, b, (l + r) / 2) > 0) {
        variant = 1;
    }
    else {
        variant = 0;
    }

    double diff = fabs(r - l);
    double x = r;

    switch (variant) {
    case 1:
        while (diff > eps) {
            x = l - ((CubicEquation(a, b, c, d, l)) * (r - l)) / (CubicEquation(a, b, c, d, r) - CubicEquation(a, b, c, d, l));
            diff = fabs(x - l);
            l = x;
            (*count)++;
            if (fabs(CubicEquation(a, b, c, d, x)) < eps) {
                return x;
            }
        }
        break;
    case 0:
        while (diff > eps) {
            x = r - ((CubicEquation(a, b, c, d, r)) * (r - l)) / (CubicEquation(a, b, c, d, r) - CubicEquation(a, b, c, d, l));
            diff = fabs(r - x);
            r = x;
            (*count)++;
            if (fabs(CubicEquation(a, b, c, d, x)) < eps) {
                return x;
            }
        }
        break;
    }

    return x;
}

double DychotomyMethod(double a, double b, double c, double d, double l, double r, double eps, int* count) {

    *count = 0;

    double middle, x, length;
    length = r - l;
    x = (r + l) / 2;

    while (length > eps) {
        middle = (l + r) / 2;
        if (CubicEquation(a, b, c, d, middle) * CubicEquation(a, b, c, d, l) < 0) {
            length /= 2;
            r = middle;
            x = middle;
        }
        else {
            length /= 2;
            l = middle;
            x = middle;
        }
        (*count)++;
        if (fabs(CubicEquation(a, b, c, d, x)) < eps) {
            return x;
        }
    }
    return x;
}

double NewtoneMethod(double a, double b, double c, double d, double l, double r, double eps, int* count) {
    *count = 0;

    double x = 0, diff = fabs(r-l), temp = diff;

    if (CubicEquation(a, b, c, d, l) * poh2(a, b, l) > 0) {
        x = l;
    }
    else if (CubicEquation(a, b, c, d, r) * poh2(a, b, r) > 0) {
        x = r;
    }

    while (diff > eps) {
        temp = x;
        x = x - CubicEquation(a, b, c, d, x) / poh1(a, b, c, x);
        diff = fabs(temp - x);
        (*count)++;
    }

    return x;
}

double IterationMethod(double a, double b, double c, double d, double l, double r, double eps, int* count) {
    double k = (abs(poh1(a, b, c, l)) > abs(poh1(a, b, c, r))) ?
        abs(poh1(a, b, c, l)) : abs(poh1(a, b, c, r));
    int n = 0;
    if (poh1(a, b, c, l) < 0) k = -k;
    double x = l - (CubicEquation(a, b, c, d, l) / k), prevx = l;
    while (fabs(x - prevx) > eps) {
        prevx = x;
        x = x - CubicEquation(a, b, c, d, x) / k;
        n++;
    }
    (*count) = n;
    return x;
}

int checker(double a, double b, double c, double d, double l, double r) {
    if (CubicEquation(a, b, c, d, l) * CubicEquation(a, b, c, d, r) < 0) {
        return 1;
    }
    else {
        cout << "Your interval doesn't have a root!\n";
        return 0;
    }
}

int getter(double a, double b, double c, double d, double* l, double* r, double* eps) {
    int check = 0;

    do {
        cout << "\nEnter a, b, eps: ";
        cin >> *l >> *r >> *eps;
        cout << "\n";
        check = checker(a, b, c, d, *l, *r);
    } while (check == 0);

    return 0;
}

int printergeneral(double a, double b, double c, double d, double l, double r, double eps) {
    cout << "Func " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " = 0\nA = " << l << " B = " << r << " Eps = " << eps << "\n";
    return 0;
}

int printermethodal(const char* name, double x, int count) {
    cout << name << ": x = " << x << " Iterations: " << count << '\n';
    return 0;
}