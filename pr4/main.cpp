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

		//cout << "Size 2: ";
		//cin >> size2;
		//
		//double* arr2 = new double[size2];
		//
		//for (int i = 0; i < size2; i++) {
		//	cin >> arr2[i];
		//}

		cout << "\n";
		//CVector v1(size1, arr1);
		//CVector v2(size2, arr2);
		//
		//cout << "Vector 1: ";
		//v1.out();
		//
		//cout << "\nVector 2: ";
		//v2.out();

		CVector2 vec2(size1, arr1);
		CVector* p2 = &vec2; //& - взятие адреса *-указатель на родительский класс, используется функция родительского класса
		CVector& r2 = vec2; // & - сохраняем по ссылке на родительский класс, с типом родительского класса
		cout << "vector2 ";
		vec2.out();
		cout << endl;
		p2->out();
		cout << endl;
		r2.out();
		cout << endl;


		CVector3 vec3(size1, arr1);
		CVector* p3 = &vec3; // если виртуальную(virtual) функцию переопределили в классе потомка, то будет работать функция из класса потомка
		CVector& r3 = vec3;	// все время срабатывает метод из дочернего класса (CVector3) по принципу полиморфизма
		cout << "vector3 ";
		vec3.vout();
		cout << endl;
		p3->vout();
		cout << endl;
		r3.vout();


		delete[] arr1;
		//delete[] arr2;

	}

	return 0;
}
