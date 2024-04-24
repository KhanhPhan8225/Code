#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <vector>   
#include <algorithm> 

using namespace std;

// Kiểm tra số nguyên
bool KiemTraSoNguyen(const string& str) {
    if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')))
    {
        return false;
    }

    istringstream iss(str);
    int num;
    iss >> num;

    return iss.eof() && (iss.fail() == false);
}

// Kiểm tra số nguyên tố
bool KiemTraSoNguyenTo(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Kiểm tra số chính phương
bool KiemTraSoChinhPhuong(int n) {
    int sqrt_n = sqrt(n);
    return (sqrt_n * sqrt_n == n);
}

// Hàm tính ước chung lớn nhất
int TimUocChungLonNhat(int a, int b) {
    if (b == 0) {
        return a;
    }
    return TimUocChungLonNhat(b, a % b);
}

// Hàm tính bội chung nhỏ nhất
int TimBoiC1hungNhoNhat(int a, int b) {
    return (a * b) / TimUocChungLonNhat(a, b);
}

// Tính tiền Karaoke
double TinhTienKaraoke(int gioBatDau, int gioKetThuc) {
    if (gioBatDau < 12 || gioBatDau > 23) {
        return 0.0; // Không hoạt động ngoài khung giờ
    }
    
    double giaTien = 0.0;
    for (int gio = gioBatDau; gio < gioKetThuc; gio++) {
        if (gio < 12) {
            giaTien += 0.0; // Giờ 0 - 11: Không tính phí
        } else if (gio < 15) {
            giaTien += 50000.0; // Giờ 12 - 14: 50,000 VND/giờ
        } else if (gio < 17) {
            giaTien += 45000.0; // Giờ 15 - 16: 45,000 VND/giờ
        } else {
            giaTien += 40000.0; // Giờ 17 - 23: 40,000 VND/giờ
        }
    }

    return giaTien;
}

// Xác định học lực dựa trên điểm
string XacDinhHocLuc(double diem) {
    if (diem >= 9.0) {
        return "Xuat sac";
    } else if (diem >= 8.0) {
        return "Gioi";
    } else if (diem >= 6.5) {
        return "Kha";
    } else if (diem >= 5.0) {
        return "Trung binh";
    } else {
        return "Yeu";
    }
}

// Struct để lưu trữ thông tin sinh viên
struct SinhVien {
    string hoTen;
    double diem;
    string hocLuc;
};

bool SoSanhTheoDiemGiamDan(const SinhVien& sv1, const SinhVien& sv2) {
    return sv1.diem > sv2.diem;
}

int main() {
    int luachon;
    vector<SinhVien> danhSachSinhVien; // Khai báo danh sách sinh viên
    SinhVien sv;

    cout << "1. Kiem tra so nguyen" << endl;
    cout << "2. Tim uoc chung va boi chung hai so" << endl;
    cout << "3. Tinh tien quan karaoke" << endl;
    cout << "4. Tinh tien dien" << endl;
    cout << "5. Chuc nang doi tien" << endl;
    cout << "6. Lai suat vay ngan hang, tra gop" << endl;
    cout << "7. Vay tien mua xe" << endl;
    cout << "8. Sap xep thong tin sinh vien" << endl;
    cout << "9. Xay dung game FPOLY-LOTT" << endl;
    cout << "10. Tinh toan phan so" << endl;
    cout << "11. Thoat" << endl;
    cout << "Moi thi chu nhap lua chon: ";
    cin >> luachon;

    switch (luachon)
    {
    case 1: {
        string str;
        cout << "Nhap mot so: ";
        cin >> str;

        int n = atoi(str.c_str());
        cout << "So " << n << " co phai so nguyen? " << (KiemTraSoNguyen(str) ? "Yes" : "No") << endl;
        cout << "So " << n << " co phai so nguyen to? " << (KiemTraSoNguyenTo(n) ? "Yes" : "No") << endl;
        cout << "So " << n << " co phai so chinh phuong? " << (KiemTraSoChinhPhuong(n) ? "Yes" : "No") << endl;
        break;
    }

    case 2: {
        int a, b;
        cout << "Nhap so thu nhat: ";
        cin >> a;
        cout << "Nhap so thu hai: ";
        cin >> b;
        int uocChung = TimUocChungLonNhat(a, b);
        int boiChung = TimBoiChungNhoNhat(a, b);
        cout << "Uoc chung lon nhat cua " << a << " va " << b << " la " << uocChung << endl;
        cout << "Boi chung nho nhat cua " << a << " va " << b << " la " << boiChung << endl;
    }
        cout << "Tim uoc chung va boi chung hai so thanh cong" << endl;
        break; 
    case 3: {
        int gioBatDau, gioKetThuc;
        cout << "Nhap gio bat dau: ";
        cin >> gioBatDau;
        cout << "Nhap gio ket thuc: ";
        cin >> gioKetThuc;

        if (gioKetThuc <= gioBatDau) {
            cout << "Gio ket thuc phai lon hon gio bat dau." << endl;
        } else {
            double giaTien = TinhTienKaraoke(gioBatDau, gioKetThuc);
            cout << "Gia tien can thanh toan: " << giaTien << " VND" << endl;
        }
        break;
    }
    case 4:
        cout << "Tinh tien dien thanh cong" << endl;
        break; 
    case 5:
        cout << "Doi tien thanh cong" << endl;
        break; 
    case 6:
        cout << "Vay ngan hang, tra gop thanh cong" << endl;
        break; 
    case 7:
        cout << "Vay tien mua xe thanh cong" << endl;
        break; 
    case 8:
        cout << "Nhap ho ten sinh vien: ";
        cin.ignore();
        getline(cin, sv.hoTen);
        cout << "Nhap diem sinh vien: ";
        cin >> sv.diem;
        sv.hocLuc = XacDinhHocLuc(sv.diem);
        danhSachSinhVien.push_back(sv);

        // Sắp xếp danh sách sinh viên theo điểm giảm dần
        sort(danhSachSinhVien.begin(), danhSachSinhVien.end(), SoSanhTheoDiemGiamDan);

        // In danh sách sinh viên
        cout << "Danh sach sinh vien:" << endl;
        for (int i = 0; i < danhSachSinhVien.size(); ++i) {
            const SinhVien& sinhVien = danhSachSinhVien[i];
            cout << "Ho ten: " << sinhVien.hoTen << ", Diem: " << sinhVien.diem << ", Hoc luc: " << sinhVien.hocLuc << endl;
        }
        cout << "Sap xep thong tin sinh vien thanh cong" << endl;
        break; 
    case 9:
        cout << "Xay dung game FPOLY-LOTT thanh cong" << endl;
        break; 
    case 10:
        cout << "Tinh toan phan so thanh cong" << endl;
        break; 
    case 11:
        cout << "Thoat thanh cong" << endl;
        return 0;

    default:
        cout << "Lua chon cua ban khong hop le." << endl;
        break;
    }

    return 0;
}
