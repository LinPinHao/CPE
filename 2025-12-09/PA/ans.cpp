#include <iostream>
using namespace std;
int main() {
    int n;
    while (cin >> n && n >= 0) {
        cout << 1 + n * (n+1) / 2 << endl;
    }
}