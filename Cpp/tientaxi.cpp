#include <iostream>
using namespace std;

// Câu 2: Viết hàm tính tiền taxi dựa vào số km đi được
int tienTaxi(int km) {
    int tien;
    if (km <= 1) {
        tien = 15000;
    } else if (km >= 2 && km <= 5) {
        tien = 15000 + (km - 1) * 13500;
    } else if (km >= 6 && km <= 120) {
        tien = 15000 + 4 * 13500 + (km - 5) * 11000;
    } else {
        // from 121 km reduce 10% of total money
        tien = (15000 + 4 * 13500 + 115 * 11000 + (km - 120) * 11000) * 0.9;
    }
    return tien;
}

// Hàm main để chạy chương trình
int main() {
    // Câu 2
    int km;
    cout << "Nhap so km: ";
    cin >> km;
    cout << "So tien taxi can tra: " << tienTaxi(km) << " VND." << endl;
    return 0;
}