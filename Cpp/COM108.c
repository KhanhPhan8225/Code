#include <stdio.h>
#include <string.h>

// Khai bao cau truc lap SinhVien
struct SinhVien {
    char ten[100];
    int tuoi;
    char diaChi[100];
    char kyHoc[100];
    char chuyenNganh[100];
};

// Ham de nhap thong tin ca nhan
void NhapThongTinCaNhan(struct SinhVien *sv) {
    printf("Nhap ten: ");
    fflush(stdin);
    fgets(sv->ten, sizeof(sv->ten), stdin);
    sv->ten[strcspn(sv->ten, "\n")] = '\0'; // Loai bo dau xuong dong
    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);
    printf("Nhap dia chi: ");
    fflush(stdin);
    fgets(sv->diaChi, sizeof(sv->diaChi), stdin);
    sv->diaChi[strcspn(sv->diaChi, "\n")] = '\0'; // Loai bo dau xuong dong
    printf("Nhap ky hoc: ");
    fflush(stdin);
    fgets(sv->kyHoc, sizeof(sv->kyHoc), stdin);
    sv->kyHoc[strcspn(sv->kyHoc, "\n")] = '\0'; // Lo?i b? d?u xu?ng dòng
    printf("Nhap chuyen nganh: ");
    fflush(stdin);
    fgets(sv->chuyenNganh, sizeof(sv->chuyenNganh), stdin);
    sv->chuyenNganh[strcspn(sv->chuyenNganh, "\n")] = '\0'; // Loai bo dau xuong dong
}

// Ham de hien thi thong tin ca nhan
void HienThiThongTinCaNhan(const struct SinhVien *sv) {
    printf("Ten: %s\n", sv->ten);
    printf("Tuoi: %d\n", sv->tuoi);
    printf("Dia chi: %s\n", sv->diaChi);
    printf("Ky hoc: %s\n", sv->kyHoc);
    printf("Chuyen nganh: %s\n", sv->chuyenNganh);
}

// Ham de tinh tong tu 1 den n
int TinhTong() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    
    int tong = 0;
    
    for (int i = 1; i <= n; i++) {
        tong += i;
    }
    
    printf("Tong: %d\n", tong);
    return tong;
}

// Ham de hien thi thong tin sinh vien
void HienThiThongTinSinhVien(const struct SinhVien danhSachSinhVien[], int soLuongSinhVien) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < soLuongSinhVien; i++) {
        HienThiThongTinCaNhan(&danhSachSinhVien[i]); // Hien thi thong tin ca nhan cua tung sinh vien
        printf("-------------------------\n");
    }
}

int main() {
    struct SinhVien danhSachSinhVien[100]; // Gia su toi da co 100 sinh vien
    int soLuongSinhVien = 0;
    int luaChon;

    do {
        printf("+--------------------------Menu------------------------+\n");
        printf("1. Nhap thong tin ca nhan\n");
        printf("2. Tinh tong\n");
        printf("3. Thong tin sinh vien cac lop\n");
        printf("0. Thoat\n");
        printf("+--------------------------------------------------------+\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        struct SinhVien sv;
        int tong;

        switch (luaChon) {
            case 1:
                NhapThongTinCaNhan(&sv);
                danhSachSinhVien[soLuongSinhVien] = sv;
                soLuongSinhVien++;
                HienThiThongTinCaNhan(&sv);
                break;
            case 2:
                tong = TinhTong();
                break;
            case 3:
                HienThiThongTinSinhVien(danhSachSinhVien, soLuongSinhVien);
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 0);

    return 0;
}

