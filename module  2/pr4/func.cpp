#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;


void AllocateMemory(double*& a, int n)
{
	a = new double[n * n];
}


void FillAB(double* a, double* b, int n)
{
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[(i * n) + j] = cos(i - j);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) b[(i * n) + j] = 10.0 / (i + j + 5.0);
}


void FillZero(double* a, int n)
{
	for (int i = 0; i < n * n; i++) a[i] = 0;
}


double MultiplyIJK(double* a, double* b, double* c, int n)
{
	auto start = chrono::steady_clock::now();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				c[(i * n) + j] += a[(i * n) + k] * b[(k * n) + j];
	auto finish = chrono::steady_clock::now();
	chrono::duration<double> time = finish - start;
	return time.count();
}


double MultiplyJKI(double* a, double* b, double* c, int n)
{
	auto start = chrono::steady_clock::now();

	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				c[(i * n) + j] += a[(i * n) + k] * b[(k * n) + j];
	auto finish = chrono::steady_clock::now();
	chrono::duration<double> time = finish - start;
	return time.count();
}


double MultiplyKIJ(double* a, double* b, double* c, int n)
{
	auto start = chrono::steady_clock::now();

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				c[(i * n) + j] += a[(i * n) + k] * b[(j * n) + k];
	auto finish = chrono::steady_clock::now();
	chrono::duration<double> time = finish - start;
	return time.count();
}


double MultiplyIKJ(double* a, double* b, double* c, int n)
{
	auto start = chrono::steady_clock::now();

	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++)
			for (int j = 0; j < n; j++)
				c[(i * n) + j] += a[(i * n) + k] * b[(j * n) + k];
	auto finish = chrono::steady_clock::now();
	chrono::duration<double> time = finish - start;
	return time.count();
}


double MultiplyJIK(double* a, double* b, double* c, int n)
{
	auto start = chrono::steady_clock::now();

	for (int j = 0; j < n; j++)
		for (int i = 0; i < n; i++)
			for (int k = 0; k < n; k++)
				c[(i * n) + j] += a[(i * n) + k] * b[(k * n) + j];
	auto finish = chrono::steady_clock::now();
	chrono::duration<double> time = finish - start;
	return time.count();
}


double MultiplyKJI(double* a, double* b, double* c, int n)
{
	auto start = chrono::steady_clock::now();

	for (int k = 0; k < n; k++)
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++)
				c[(i * n) + j] += a[(i * n) + k] * b[(j * n) + k];
	auto finish = chrono::steady_clock::now();
	chrono::duration<double> time = finish - start;
	return time.count();
}


void ReleaseMemory(double* a) { free(a); }
