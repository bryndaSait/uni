#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    while (true)
    {
        int size1;
        cout << "enter first vector capacity (0 = exit): \nn = ";
        cin >> size1;
        if (size1 == 0) { break; }

        cout << "enter first vector:\n";
        double* arr1 = new double[size1];
        for (int i = 0; i < size1; i++)
        {
            cin >> arr1[i];
        }

        TVector<double> vec1(size1, arr1);

        cout << "\nvector out:\n";
        vec1.out();

        cout << "\niterator (classic for):\n";
        for (auto it = vec1.begin(); it != vec1.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "\niterator (range for):\n";
        for (auto x : vec1)
        {
            cout << x << " ";
        }
        cout << endl;

        cout << "\ninitializer list constructor:\n";
        TVector<double> vec_init = { 1.5, 2.5, 3.5, 4.5 };
        vec_init.out();

        cout << endl << endl;

        delete[] arr1;
    }

    return 0;
}
