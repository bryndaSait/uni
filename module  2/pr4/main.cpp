#include <iostream>
#include "Header.h"
using namespace std;


int main()
{
	
		cout << "matrix: ";

		int n; cin >> n; 
		double* v1 = nullptr, * v2 = nullptr, * v3 = nullptr;
		AllocateMemory(v1, n);
		AllocateMemory(v2, n);
		AllocateMemory(v3, n);
		FillAB(v1, v2, n);
		FillZero(v3, n);

		double time_s = MultiplyIJK(v1, v2, v3, n);
		cout << "Time = " << time_s * 1000 << " ms;\nC[n/2][n/2] = " << v3[(n * n / 2) + n / 2] << ";\n";
		cout << "GFlops: " << (2 * pow(n, 3) / time_s) / pow(2, 30) << ";\n\n";

		 FillZero(v3, n);
		time_s = MultiplyJKI(v1, v2, v3, n);
		cout << "Time = " << time_s * 1000 << " ms;\nC[n/2][n/2] = " << v3[(n * n / 2) + n / 2] << ";\n";
		cout << "GFlops: " << (2 * pow(n, 3) / time_s) / pow(2, 30) << ";\n\n";

		 FillZero(v3, n);
		time_s = MultiplyKIJ(v1, v2, v3, n);
		cout << "Time = " << time_s * 1000 << " ms;\nC[n/2][n/2] = " << v3[(n * n / 2) + n / 2] << ";\n";
		cout << "GFlops: " << (2 * pow(n, 3) / time_s) / pow(2, 30) << ";\n\n";

		 FillZero(v3, n);
		time_s = MultiplyIKJ(v1, v2, v3, n);
		cout << "Time = " << time_s * 1000 << " ms;\nC[n/2][n/2] = " << v3[(n * n / 2) + n / 2] << ";\n";
		cout << "GFlops: " << (2 * pow(n, 3) / time_s) / pow(2, 30) << ";\n\n";

		 FillZero(v3, n);
		time_s = MultiplyJIK(v1, v2, v3, n);
		cout << "Time = " << time_s * 1000 << " ms;\nC[n/2][n/2] = " << v3[(n * n / 2) + n / 2] << ";\n";
		cout << "GFlops: " << (2 * pow(n, 3) / time_s) / pow(2, 30) << ";\n\n";

		 FillZero(v3, n);
		time_s = MultiplyKJI(v1, v2, v3, n);
		cout << "Time = " << time_s * 1000 << " ms;\nC[n/2][n/2] = " << v3[(n * n / 2) + n / 2] << ";\n";
		cout << "GFlops: " << (2 * pow(n, 3) / time_s) / pow(2, 30) << ";\n\n";

		ReleaseMemory(v1);
		ReleaseMemory(v2);
		ReleaseMemory(v3);
	
}
