#include <iostream>
#include <vector>
#include <stack>
#include "algorithm"

using namespace std;

bool check_empty(const vector<pair<int, int>> &origin) {
    for (pair<int, int> i: origin) {
        if (i.second != 0) return false;
    }
    return true;
}

bool my_comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    vector<pair<int, int>> origin_array;
    vector<int> result;

    result.push_back(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        origin_array.emplace_back(i + 1, tmp);
    }

    while (!check_empty(origin_array)) {
        sort(origin_array.begin(), origin_array.end(), my_comp);
        if (origin_array[1].second == 0) break;

        if (result[result.size() - 1] != origin_array[0].first ||
            origin_array.size() == 1) {
            result.push_back(origin_array[0].first);
            origin_array[0].second--;
        } else {
            result.push_back(origin_array[1].first);
            origin_array[1].second--;
        }
    }

    while (origin_array[0].second != 0) {
        result.push_back(origin_array[0].first);
        origin_array[0].second--;
    }

    for (int i : result) {
        if (i != 0) cout << i << " ";
    }

    return 0;
}
