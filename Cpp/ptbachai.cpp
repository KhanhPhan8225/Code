#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh vo so nghiem" << endl;
            } else {
                cout << "Phuong trinh vo nghiem" << endl;
            }
        } else {
            cout << "Phuong trinh co nghiem x = " << (float) -c / b << endl;
        }
    } else {
        float delta = pow(2, b) - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem" << endl;
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep x1 = x2 = " << (float) -b / (2 * a) << endl;
        } else {
            cout << "Phuong trinh co 2 nghiem phan biet x1 = " << (-b + sqrt(delta)) / (2 * a) << " va x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
        }
    }
}