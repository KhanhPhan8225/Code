#include <iostream>
using namespace std;

bool Kiemtrasoduong(int N) {
	if ((N > 0) && (N < 10)) {
		return true;
	} else{
		return false;
	}
}

int main() {
	int N;
	do{
		cout << "Nhap N: ";
		cin >> N;
	} while (Kiemtrasoduong(N) == false);
	cout << "Ban vua nhap so: " << N;
}
