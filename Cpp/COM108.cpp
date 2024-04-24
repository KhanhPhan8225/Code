#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Khai bao cau truc lop SinhVien
struct SinhVien {
    string ten;
    int tuoi;
    string diaChi;
    string kyHoc;
    string chuyenNganh;
};

// Ham de nhap thong tin ca nhan
void NhapThongTinCaNhan(SinhVien &sv) {
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, sv.ten);
    cout << "Nhap tuoi: ";
    cin >> sv.tuoi;
    cin.ignore(); // Xoa dau xuong dong sau cin >> sv.tuoi
    cout << "Nhap dia chi: ";
    getline(cin, sv.diaChi);
    cout << "Nhap ky hoc: ";
    getline(cin, sv.kyHoc);
    cout << "Nhap chuyen nganh: ";
    getline(cin, sv.chuyenNganh);
}

// Hàm de hien thi thong tin ca nhan
void HienThiThongTinCaNhan(const SinhVien &sv) {
    cout << "Ten: " << sv.ten << endl;
    cout << "Tuoi: " << sv.tuoi << endl;
    cout << "Dia chi: " << sv.diaChi << endl;
    cout << "Ky hoc: " << sv.kyHoc << endl;
    cout << "Chuyen nganh: " << sv.chuyenNganh << endl;
}

// Hàm de tinh tong
int TinhTong() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    
    int tong = 0;
    
    for (int i = 1; i <= n; i++) {
        tong += i;
    }
    
    cout << "Tong: " << tong << endl;
    return tong;
}


// Ham de hien thi thong tin sinh vien
void HienThiThongTinSinhVien(const vector<SinhVien> &danhSachSinhVien) {
    cout << "Danh sach sinh vien:\n";
    for (const SinhVien &sv : danhSachSinhVien) {
        HienThiThongTinCaNhan(sv); // Hien thi thong tin ca nhan cua tung sinh vien
        cout << "-------------------------\n";
    }
}

int main() {
    vector<SinhVien> danhSachSinhVien;
    int luaChon;

    do {
        cout << "+--------------------------Menu------------------------+" << endl;
        cout << "1. Nhap thong tin ca nhan" << endl;
        cout << "2. Tinh tong" << endl;
        cout << "3. Thong tin sinh vien cac lop" << endl;
        cout << "0. Thoat" << endl;
        cout << "+--------------------------------------------------------+" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        
        SinhVien sv;
        int tong;

        switch (luaChon) {
            case 1:
                NhapThongTinCaNhan(sv);
                danhSachSinhVien.push_back(sv);
                break;
            case 2:
                TinhTong();
                break;
            case 3:
                HienThiThongTinSinhVien(danhSachSinhVien);
                break;
            case 0:
                cout << "Ket thuc chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }
    } while (luaChon != 0);

    return 0;
}

