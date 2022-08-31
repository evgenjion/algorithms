// 1. lower_bound делается на отсортированном массиве.
// 2. По сути lower_bound это индекс, куда бы вставилось наше число
//
// Пример:
//  0   1   2   3        // индексы
// {10, 20, 30, 40}      // vector
//
// lower_bound для числа 25 будет 2. То есть если бы вставляли в этот массив это число,
// то место ему в индексе 2, а остальное надо сдвинуть. (Для числа 20 было бы 1, так как (20 < 20 == false))
//

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

        auto start = v.begin();
        auto end = v.end();

        auto low = std::lower_bound(start, end, n);

        // *low same as "low - v.begin()"
        if (*low == n)
          cout << "Yes " << (low - start + 1) << endl;
        else
          cout << "No " << (low - start + 1) << endl;
    }

    return 0;
}
