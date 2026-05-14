#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>

class CVector {

	friend CVector sum(const CVector& v1, const CVector& v2);
	friend CVector dif(const CVector& v1, const CVector& v2);
	friend double scalar(const CVector& v1, const CVector& v2);

private:
	int size;
	double* data;

	void init();

public:
	CVector(int s = 0, double* arr = nullptr);
	CVector(const CVector& other);
	~CVector();

	void copy(int s, double* arr);
	void copy(const CVector& other);

	void out();
	virtual void vout();
	void clear();

	double module() const;

	void add(const CVector& other);
	void diff(const CVector& other);

	CVector& operator=(const CVector& other);
	double& operator[](int index);
	const double operator[](int index) const;

	CVector& operator+=(const CVector& other);
	CVector& operator-=(const CVector& other);
	double operator()() const;


	
};
CVector operator+(const CVector& v1, const CVector& v2);
CVector operator-(const CVector& v1, const CVector& v2);
double operator*(const CVector& v1, const CVector& v2);

class CVector2 :public CVector {
public:
	CVector2(int s = 0, double* arr = nullptr);
	CVector2(const CVector2& other);
	void out();
};
class CVector3 :public CVector {
public:
	CVector3(int s = 0, double* arr = nullptr);
	CVector3(const CVector3& other);
	void vout();
};

#endif
