#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool func(vector<int>& b, int n, unordered_map<int, int>& map, int a, int mid) {
    int items = 0;
    for(auto entry: map) {
        if(entry.second >= mid) {
            items += entry.second / mid;
        }
    }
    return items >= a;
}

int main() {
    int a, n;
    cin >> a >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    unordered_map<int, int> map;
    int low = 1;
    int high = -1;
    for(int i: b) {
        map[i]++;
        high = max(high, map[i]);
    }
    int sol = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(func(b, n, map, a, mid)) {
            low = mid + 1;
            sol = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << sol << endl;
    return 0;
}

