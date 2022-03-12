#include <iostream>
using namespace std;
long long fac (int n) {
	if (1 == n) return 1;
	return n * fac(n - 1);
}
void print(int n) {
	cout << fac(n) << endl;
}
