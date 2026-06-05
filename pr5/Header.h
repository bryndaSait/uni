#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>

class CVector {

	friend CVector sum(const CVector& v1, const CVector& v2);
	friend CVector dif(const CVector& v1, const CVector& v2);
	friend double scalar(const CVector& v1, const CVector& v2);

protected:
	int size;
	double* data;

	void init();

public:
	CVector(int s = 0, double* arr = nullptr);
	CVector(const CVector& other);
	//
	~CVector();

	void copy(int s, double* arr);
	void copy(const CVector& other);
	//
	void out() const;
	virtual void vout() const;
	void clear();

	double module() const;

	void add(const CVector& other);
	void diff(const CVector& other);

	CVector& operator=(const CVector& other);
	CVector(CVector&& other) noexcept;
	CVector& operator=(CVector&& other) noexcept;
	int move(CVector& other);//

	double& operator[](int index);
	const double operator[](int index) const;

	CVector& operator+=(const CVector& other);
	CVector& operator-=(const CVector& other);
	double operator()() const;



};
CVector operator+(const CVector& v1, const CVector& v2);
CVector operator-(const CVector& v1, const CVector& v2);
double operator*(const CVector& v1, const CVector& v2);


#endif
