#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <array>

using std::cout;
using std::cin;
using std::endl;


int main() {
    int size;
    cin >> size;

    std::vector<int> v;
    v.reserve(size);

    for (int i = 0; i < size; i++) {
        int t;
        cin >> t;

        v.push_back(t);
    }

    int q;
    cin >> q;

    // Q queries
    for (auto j = 0; j < q; j++) {
        int n;
        cin >> n;

        bool found = false;

        for (auto it = v.begin(); it < v.end(); it++) {
            if (*it == n) {
                cout << "Yes " << (it - v.begin() + 1) << endl;
                found = true;
                break;
            }
        }

        if (found) continue;

        auto low = std::lower_bound(v.begin(), v.end(), n);
        cout << "No " << (low - v.begin() + 1) << endl;
    }

    return 0;
}
