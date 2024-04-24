#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    if (a > 0) {
        cout << "a is positive number";
    } else if (a < 0) {
        cout << "a is negative number";
    } else {
        cout << "a is equal to 0";
    }
    return 0;
}