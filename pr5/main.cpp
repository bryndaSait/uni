#include <iostream>
#include "Header.h"
using namespace std;

int main() {

	while (true) {
		int size1;

		cout << "\nSize (0 - stop): ";
		cin >> size1;

		if (size1 == 0) {
			break;
		}

		double* arr1 = new double[size1];

		for (int i = 0; i < size1; i++) {
			cin >> arr1[i];
		}
		CVector v1(size1, arr1);
		CVector v2(v1);
		v2.out(); cout << endl;
		CVector v3(std::move(v1));
		v3.out(); cout << endl;

		v1 = v2;
		v1.out(); cout << endl;
		CVector v4 = std::move(v1);
		v4.out(); 
		
		delete[] arr1;
		

	}

	return 0;
}
