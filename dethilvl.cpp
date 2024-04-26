// Xây dựng các hàm thực hiện các công việc sau:
// 1. Kiểm tra xem xâu S có bắt đầu bằng chữ cái không?
// 2. Đếm số lần xuất hiện của dấu cách trong xâu S.
// 3. Viêt hàm đổi các chữ cái đầu tiên của xâu sang chữ hoa.
// Viết hàm đổi các chữ cái đầu tiền cảu mỗi từ trong xâu S sang chữ hoa.
// Sử dụng các hàm đã xây dựng ở trên, viết hàm main() để thực hiện các yêu cầu sau:
// 1. Nhập vào 1 xâu kí tự bắt đầu bằng bảnh chữ cái, dùng hàm đã xây dựng ở mục 1.1 để kiểm tra tính hợp lệ của xâu, nếu xâu nhập vào không hợp lệ thì cho nhập lại đến khi nhập đúng thì thôi.
// 2. Sử dụng hàm ở mục 1.2 để đếm số lần xuất hiện của dấu cách trong xâu.
// 3. Sử dụng hàm ở mục 1.3 để đổi các chữ cái đầu tiên của mỗi từ trong xâu S sang chữ hoa.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool KiemTraXau(string s) {
    if (s[0] >= 'a' &&  s[0] <= 'z') {
        return true;
    } return false;
}

void vietHoaChuCaiDau(string &s) {
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == ' ') {
            s[i + 1] = toupper(s[i + 1]);
        }
    }
}

int demDauCach(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            count++;
        }
    }
    return count;
}

int main() {
    string s;
    cout << "Nhap xau ki tu bat dau bang chu cai: ";
    getline(cin, s);
    while (!KiemTraXau(s)) {
        cout << "Nhap lai xau ki tu bat dau bang chu cai: ";
        getline(cin, s);
    }
    cout << "So lan xuat hien dau cach trong xau: " << demDauCach(s) << endl;
    vietHoaChuCaiDau(s);
    cout << "Xau sau khi viet hoa chu cai dau cua moi tu: " << s << endl;
    return 0;
}