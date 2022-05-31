#include <iostream>
#include <conio.h>
using namespace std;

int min(int x, int y, int z) {
	if (x < y) {
		if (x < z) return x;
	}

	if (x < z) {
		if (x < y) return x;	
	}

	if (y < z) {
		if (y < x) return y;
	}

	if (y < x) {
		if (y < z) return y;
	}

	if (z < x) {
		if (z < y) return z;
	}

	if (z < y) {
		if (z < x) return z;
	}
}

int main() {
	int x = 0, y = 0, z = 0;
	cin >> x >> y >> z;
	cout << min(x - 1, y, z) + min(x, y - 1, x + y + z);
}
