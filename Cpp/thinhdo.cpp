#include <iostream>
using namespace std;

// Bài 1
int main() {
    int r, r2;
    cout << "Nhap ban kinh r: ";
    cin >> r;
    double PI = 3.14159;
    double S = 4 * PI * r * r;
    cout << "Dien tich hinh tron la: " << S << endl;
    return 0;
}

// Bài 2
int main() {
    int weight;
    double height;
    cout << "Nhap can nang(kg): ";
    cin >> weight;
    cout << "\rNhap chieu cao(m): ";
    cin >> height;
    double BMI = weight / (height * height);
    cout << "\rChi so BMI cua ban la: " << BMI;
    return 0;
}

// Bài 3
int main() {
    int giolam, luongtheogio, tongluong;
    cout << "So gio lam viec: ";
    cin >> giolam;
    cout << "\rLuong theo gio: ";
    cin >> luongtheogio;
    if (giolam > 40) {
        tongluong = giolam * luongtheogio * 1.5;
        cout << "\rLuong cua ban la: " << tongluong << "VND";
    } else {
        tongluong = giolam * luongtheogio;
        cout << "\rLuong cua ban la: " << tongluong << "VND";
    }
    return 0;
}