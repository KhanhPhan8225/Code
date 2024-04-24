#include<iostream>
using namespace std;

int main() {
    int a[10];
    int sum = 0;
    for (int i = 0; i < 10; i++) {
	cout << "Nhap so thu " << i + 1 << " : ";
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++) {
        sum += a[i];
    }
    cout << "Tong: " << sum;
    return 0;
}

