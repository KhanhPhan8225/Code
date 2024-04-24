#include <iostream> 
using namespace std;

int main() {
    int x, y, z;
    cout << "Nhap 3 so nguyen: ";
    cin >> x >> y >> z;
    if (x > y and x > z) {
        cout << x;
    } else if (y > x && y > z) {
        cout << y;
    } else {
        cout << z;
    }
    return 0;
}