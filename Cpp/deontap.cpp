// I.	Xây dựng các hàm thực hiện công việc sau:
// 1.	Kiểm tra 1 số nguyên dương n có 4 chữ số hay không (2,5đ)
// 2.	Tính tổng các chữ số của 1 số nguyên 4 chữ số (3)
// II.	Xây dựng hàm main, sử dụng các hàm đã xây dựng ở trên để thực hiện công việc sau:
// 1.	Nhập vào 1 số nguyên dương n có 4 chữ số, kiểm tra số vừa nhập nếu không hợp lệ thì cho nhập lại đến khi nhập đúng thì thôi. (2,5đ)
// 2.	Tính số nút (điểm) của n (2đ)

#include <iostream>
using namespace std;

bool KiemTraSoNguyenDuong(int n)
{
    if (n >= 1000 && n <= 9999)
        return true;
    return false;
}

int TinhTongChuSo(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n;
    do
    {
        cout << "Nhap vao so nguyen duong n co 4 chu so: ";
        cin >> n;
    } while (!KiemTraSoNguyenDuong(n));

    cout << "So nut cua " << n << " la: " << TinhTongChuSo(n) << endl;

    return 0;
}
