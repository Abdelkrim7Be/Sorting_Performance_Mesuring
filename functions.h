// functions.h


#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define nl 3
#define nc 10

void remplissage(int T[], int n);
void tri_bulles(int T[], int n);
void tri_insertion(int T[], int n);
void tri_selection(int T[], int n);
double CalculTemps(void (*trier)(int T[], int n), int n);
void Interpolation(double Mat[nl][nc]);
void plot(double Mat[nl][nc]);

#endif
