#include <iostream>
#include "Header.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
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


        // copy constructor
        CVector v2(v1);
        cout << "v2 (copy из v1): ";
        v2.out();
        cout << "v1 (начальный): ";
        v1.out();
        
        // copy operator=
        CVector v3;
        v3 = v2;
        cout << "v3 (сopy v2): ";
        v3.out();
        cout << "v2: ";
        v2.out();
       
        

        // move operator=
        CVector v4;
        v4 = v1 + v2;
        cout << "v4 ( = v1): ";
        v4.out();
        cout << "v1 (начальный): ";
        v1.out();

        // move constructor
        CVector v5;
        v5.move(v3);
        cout << "v5 (move из v3): ";
        v5.out();
        cout << "v3: ";
        v3.out();
        
        delete[] arr1;
		
        //♥♥//
	}

	return 0;
}
