#include <iostream>
using namespace std;

int main() {
    int biensoxe, diem;
    cout << "Nhap bien so xe: ";
    cin >> biensoxe;
    diem += biensoxe % 10;
    biensoxe /= 10;
    cout << "Diem bien so xe la: " << diem;
    return 0;
}