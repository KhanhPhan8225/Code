#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// Kiem tra san pham
bool KiemTraSoNguyen(const char* str) {
    if (strlen(str) == 0 || (!isdigit(str[0]) && str[0] != '-' && str[0] != '+')) {
        return false;
    }

    int num;
    if (sscanf(str, "%d", &num) == 1) {
        return true;
    }

    return false;
}

// Kiem tra so nguyen to
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

// Kiem tra so chinh phuong 
bool KiemTraSoChinhPhuong(int n) {
    int sqrt_n = (int)sqrt(n);
    return (sqrt_n * sqrt_n == n);
}

// H�m t�m uoc chung lon nhat
int TimUocChungLonNhat(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Ham tim boi chung nho nhat
int TimBoiChungNhoNhat(int a, int b) {
    int uocChung = TimUocChungLonNhat(a, b);
    return (a * b) / uocChung;
}

// Tinh tien Karaoke
double TinhTienKaraoke(int gioBatDau, int gioKetThuc) {
    if (gioBatDau < 12 || gioBatDau > 23) {
        return 0.0; // Không hoạt động ngoài khung giờ
    }

    double giaTien = 0.0;
    for (int gio = gioBatDau; gio < gioKetThuc; gio++) {
        if (gio < 12) {
            giaTien += 0.0; // Giờ 0 - 11: Khong tinh gia
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
const char* XacDinhHocLuc(double diem) {
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
    char hoTen[100];
    double diem;
    char hocLuc[20];
};

int SoSanhTheoDiemGiamDan(const void* sv1, const void* sv2) {
    double diem1 = ((struct SinhVien*)sv1)->diem;
    double diem2 = ((struct SinhVien*)sv2)->diem;
    if (diem1 > diem2) return -1;
    if (diem1 < diem2) return 1;
    return 0;
}

int main() {
    int luachon;
    struct SinhVien danhSachSinhVien[100]; // Khai bao danh sach sinh vien
    struct SinhVien sv;
    int soLuongSinhVien = 0;

    printf("1. Kiem tra so nguyen\n");
    printf("2. Tim uoc chung va boi chung hai so\n");
    printf("3. Tinh tien quan karaoke\n");
    printf("4. Tinh tien dien\n");
    printf("5. Chuc nang doi tien\n");
    printf("6. Lai suat vay ngan hang, tra gop\n");
    printf("7. Vay tien mua xe\n");
    printf("8. Sap xep thong tin sinh vien\n");
    printf("9. Xay dung game FPOLY-LOTT\n");
    printf("10. Tinh toan phan so\n");
    printf("11. Thoat\n");
    printf("Moi thi chu nhap lua chon: ");
    scanf("%d", &luachon);

    switch (luachon) {
    case 1: {
        char str[100];
        printf("Nhap mot so: ");
        scanf("%s", str);

        int n = atoi(str);
        printf("So %d co phai so nguyen? %s\n", n, KiemTraSoNguyen(str) ? "Yes" : "No");
        printf("So %d co phai so nguyen to? %s\n", n, KiemTraSoNguyenTo(n) ? "Yes" : "No");
        printf("So %d co phai so chinh phuong? %s\n", n, KiemTraSoChinhPhuong(n) ? "Yes" : "No");
        break;
    }

    case 2: {
        int a, b;
        printf("Nhap so thu nhat: ");
        scanf("%d", &a);
        printf("Nhap so thu hai: ");
        scanf("%d", &b);
        int uocChung = TimUocChungLonNhat(a, b);
        int boiChung = TimBoiChungNhoNhat(a, b);
        printf("Uoc chung lon nhat cua %d va %d la %d\n", a, b, uocChung);
        printf("Boi chung nho nhat cua %d va %d la %d\n", a, b, boiChung);
        break;
    }

    case 3: {
        int gioBatDau, gioKetThuc;
        printf("Nhap gio bat dau: ");
        scanf("%d", &gioBatDau);
        printf("Nhap gio ket thuc: ");
        scanf("%d", &gioKetThuc);

        if (gioKetThuc <= gioBatDau) {
            printf("Gio ket thuc phai lon hon gio bat dau.\n");
        } else {
            double giaTien = TinhTienKaraoke(gioBatDau, gioKetThuc);
            printf("Gia tien can thanh toan: %.2f VND\n", giaTien);
        }
        break;
    }

    case 4:
        printf("Tinh tien dien thanh cong\n");
        break;
    case 5:
        printf("Doi tien thanh cong\n");
        break;
    case 6:
        printf("Vay ngan hang, tra gop thanh cong\n");
        break;
    case 7:
        printf("Vay tien mua xe thanh cong\n");
        break;
    case 8:
        printf("Nhap ho ten sinh vien: ");
        scanf(" %[^\n]s", sv.hoTen);
        printf("Nhap diem sinh vien: ");
        scanf("%lf", &sv.diem);
        strcpy(sv.hocLuc, XacDinhHocLuc(sv.diem));
        danhSachSinhVien[soLuongSinhVien] = sv;
        soLuongSinhVien++;

        // Sap xep thon tin sinh vien theo diem giam dan
        qsort(danhSachSinhVien, soLuongSinhVien, sizeof(struct SinhVien), SoSanhTheoDiemGiamDan);

        // In danh sach sinh vien
        printf("Danh sach sinh vien:\n");
        for (int i = 0; i < soLuongSinhVien; ++i) {
            const struct SinhVien* sinhVien = &danhSachSinhVien[i];
            printf("Ho ten: %s, Diem: %.2f, Hoc luc: %s\n", sinhVien->hoTen, sinhVien->diem, sinhVien->hocLuc);
        }
        printf("Sap xep thong tin sinh vien thanh cong\n");
        break;
    case 9:
        printf("Xay dung game FPOLY-LOTT thanh cong\n");
        break;
    case 10:
        printf("Tinh toan phan so thanh cong\n");
        break;
    case 11:
        printf("Thoat thanh cong\n");
        return 0;

    default:
        printf("Lua chon cua ban khong hop le.\n");
        break;
    }

    return 0;
}
