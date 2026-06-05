#pragma once

void AllocateMemory(double*& a, int n);
void FillAB(double* a, double* b, int n);
void FillZero(double* a, int n);
double MultiplyIJK(double* a, double* b, double* c, int n);
double MultiplyJKI(double* a, double* b, double* c, int n);
double MultiplyKIJ(double* a, double* b, double* c, int n);
double MultiplyIKJ(double* a, double* b, double* c, int n);
double MultiplyJIK(double* a, double* b, double* c, int n);
double MultiplyKJI(double* a, double* b, double* c, int n);
void ReleaseMemory(double* a);
