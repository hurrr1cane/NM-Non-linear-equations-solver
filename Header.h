#ifndef HEADER_H
#define HEADER_H

double CubicEquation(double a, double b, double c, double d, double x);
double poh1(double a, double b, double c, double x);
double poh2(double a, double b, double x);
double IterationMethod(double a, double b, double c, double d, double l, double r, double eps, int* count);
double ChordeMethod(double a, double b, double c, double d, double l, double r, double eps, int* count);
double DychotomyMethod(double a, double b, double c, double d, double l, double r, double eps, int* count);
double NewtoneMethod(double a, double b, double c, double d, double l, double r, double eps, int* count);
int checker(double a, double b, double c, double d, double l, double r);
int getter(double a, double b, double c, double d, double* l, double* r, double* eps);
int printergeneral(double a, double b, double c, double d, double l, double r, double eps);
int printermethodal(const char* name, double x, int count);
#endif