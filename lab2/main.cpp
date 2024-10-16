#include <iostream>
using namespace std;

int main() {
    cout << "p q r | (p or q) and (p or r)" << endl;
    cout << "-----------------------------" << endl;

    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                bool result = (p || q) && (p || r);

                cout << p << " " << q << " " << r << " | " << result << endl;
            }
        }
    }

    return 0;
}