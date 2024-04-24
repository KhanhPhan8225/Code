#include <iostream>
using namespace std;

int main() {
    int n; // So luong phan tu trong day so
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    int numbers[n]; // Khai bao mang de luu tru day so

    // Nhap day so
    cout << "Nhap day so:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Tim so lon nhat
    int max = numbers[0]; // Gia su phan tu dau tien la lon nhat
    for (int i = 1; i < n; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    // In ra so lon nhat
    cout << "So lon nhat la: " << max << endl;

    return 0;
}
