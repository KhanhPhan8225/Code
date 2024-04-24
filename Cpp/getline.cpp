#include <iostream>
using namespace std;

int main(){
    string name, address;
    cin >> name >> address;
    cout << "Name: " << name << endl;
    cout << "Address: " << address;
    return 0;
}

// getline()
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, address;
    getline(cin, name);
    getline(cin, address);
    cout << "Name: " << name << endl;
    cout << "Address: " << address;
    return 0;
}