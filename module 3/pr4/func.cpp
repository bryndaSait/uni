#include "Header.h"
#include <cmath>
#include <iostream>

using namespace std;

void CVector::init() {
	size = 0;
	data = nullptr;
}

CVector::CVector(int s, double* arr) : size(s), data(arr) {
	init();
	copy(s, arr);
}

CVector::CVector(const CVector& other) : size(other.size), data(other.data) {
	init();
	copy(other);
}

CVector::~CVector() {
	clear();
}

void CVector::copy(int s, double* arr) {
	if (this->data != arr) {
		clear();
		size = s;
		data = new double[size];
		for (int i = 0; i < size; i++) {
			data[i] = arr[i];
		}
	}
}

void CVector::copy(const CVector& other) {
	copy(other.size, other.data);
}

//void CVector::out() const {
//cout << "Num: " << size << " Data: ";
//for (int i = 0; i < size; i++) {
//	cout << data[i] << " ";
//}
//}

void CVector::clear() {
	if (data != nullptr) delete[] data;
	init();
}

double CVector::module() const {
	return sqrt(scalar(*this, *this));
}

void CVector::add(const CVector& other) {
	copy(sum(*this, other));
}

void CVector::diff(const CVector& other) {
	copy(dif(*this, other));
}

CVector sum(const CVector& v1, const CVector& v2) {
	int mins = min(v1.size, v2.size);
	int maxs = max(v1.size, v2.size);
	CVector v3;
	v3.size = maxs;
	v3.data = new double[maxs];
	for (int i = 0; i < mins; i++) {
		v3.data[i] = v1.data[i] + v2.data[i];
	}
	for (int i = mins; i < v1.size; i++) {
		v3.data[i] = v1.data[i];
	}
	for (int i = mins; i < v2.size; i++) {
		v3.data[i] = v2.data[i];
	}
	return v3;
}

CVector dif(const CVector& v1, const CVector& v2) {
	int mins = min(v1.size, v2.size);
	int maxs = max(v1.size, v2.size);
	CVector v3;
	v3.size = maxs;
	v3.data = new double[maxs];
	for (int i = 0; i < mins; i++) {
		v3.data[i] = v1.data[i] - v2.data[i];
	}
	for (int i = mins; i < v1.size; i++) {
		v3.data[i] = v1.data[i];
	}
	for (int i = mins; i < v2.size; i++) {
		v3.data[i] = -v2.data[i];
	}
	return v3;
}

double scalar(const CVector& v1, const CVector& v2) {

	int ms = min(v1.size, v2.size);
	double result = 0.0;
	for (int i = 0; i < ms; i++) {
		result += v1.data[i] * v2.data[i];
	}
	return result;
}
CVector& CVector::operator=(const CVector& other) {
	if (this != &other) {
		copy(other);
	}
	return *this;
}

double& CVector::operator[](int index) {
	return data[index];
}

const double CVector::operator[](int index) const {
	return data[index];
}

double operator*(const CVector& v1, const CVector& v2) {
	return scalar(v1, v2);
}

CVector operator+(const CVector& v1, const CVector& v2) {
	return sum(v1, v2);
}

CVector operator-(const CVector& v1, const CVector& v2) {
	return dif(v1, v2);
}

CVector& CVector::operator+=(const CVector& other) {
	add(other);
	return *this;
}

CVector& CVector::operator-=(const CVector& other) {
	diff(other);
	return *this;
}

double CVector::operator()() const {
	return module();
}

void CVector::out() const {
	cout << "Num: " << size << " Data: ";
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
}

void CVector::vout() const {
	out();
}

CVector2::CVector2(const CVector2& other) : CVector(other) {}
CVector2::CVector2(int s, double* arr) : CVector(s, arr) {}

void CVector2::out() const {
	cout << "Num: " << this->size << endl;
	for (int i = 0; i < this->size; i++) {
		cout << i + 1 << ": " << this->data[i] << endl;
	}
};
CVector3::CVector3(const CVector3& other) : CVector(other) {}
CVector3::CVector3(int s, double* arr) : CVector(s, arr) {}




void CVector3::vout() const {
	cout << "Num: " << this->size << endl;
	for (int i = 0; i < this->size; i++) {
		cout << i + 1 << ": " << this->data[i] << endl;
	}
};
