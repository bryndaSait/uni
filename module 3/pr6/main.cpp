#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    while (true)
    {
        int size1;
        cout << "enter first vector size (0 = exit): \n"; cin >> size1;
        if (size1 == 0) { break; }

        cout << "enter first vector:\n";
        double* arr1 = new double[size1];
        for (int i = 0; i < size1; i++)
        {
            cin >> arr1[i];
        }

        int size2;
        cout << "enter second vector size (0 = exit): \n"; cin >> size2;
        if (size2 == 0) { break; }

        cout << "enter second vector:\n";
        double* arr2 = new double[size2];
        for (int i = 0; i < size2; i++)
        {
            cin >> arr2[i];
        }

        TVector<double> vec1(size1, arr1);
        TVector<double> vec2(size2, arr2);

        cout << endl << "vec1, vec2\n";
        vec1.out();
        vec2.out();

        TVector<double> vec3(vec1);

        cout << endl << "copied vec3 from vec1:\n";
        vec3.out();

        TVector<double> vec4;
        vec4 = vec1 + vec2;

        cout << endl << "vec4 = vec1 + vec2:\n";
        vec4.out();

        TVector<double> vec5;
        vec5= vec1 - vec2;

        cout << endl << "vec5 = vec1 - vec2:\n";
        vec5.out();

        double scal = vec1 * vec2;

        cout << endl << " vec1 * vec2:\n" << scal << endl;

        double mod1 = vec1();
        

        cout << endl << "module vec1:\n" << mod1 << endl;

        double mod2 = vec2();

        cout << endl << "module vec2:\n" << mod2 << endl;

        cout << endl;

        delete[] arr1;
        delete[] arr2;
    }

    return 0;
}
