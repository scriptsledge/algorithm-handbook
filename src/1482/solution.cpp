#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPosible(vector<int>& arr, int m, int k, int day) {
        int n = arr.size();
        int cnt = 0;
        int bouquet = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                cnt++;
            } else {
                bouquet += (cnt / k);
                cnt = 0;
            }
        }
        bouquet += (cnt / k);
        return bouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // Optimization: if we don't have enough flowers at all
        if (1LL * m * k > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPosible(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    vector<int> bloomDay1 = {1, 10, 3, 10, 2};
    int m1 = 3, k1 = 1;
    int res1 = sol.minDays(bloomDay1, m1, k1);
    cout << "Test Case 1: " << (res1 == 3 ? "Passed" : "Failed") << " (Expected 3, Got " << res1 << ")" << endl;

    vector<int> bloomDay2 = {1, 10, 3, 10, 2};
    int m2 = 3, k2 = 2;
    int res2 = sol.minDays(bloomDay2, m2, k2);
    cout << "Test Case 2: " << (res2 == -1 ? "Passed" : "Failed") << " (Expected -1, Got " << res2 << ")" << endl;

    vector<int> bloomDay3 = {7, 7, 7, 7, 12, 7, 7};
    int m3 = 2, k3 = 3;
    int res3 = sol.minDays(bloomDay3, m3, k3);
    cout << "Test Case 3: " << (res3 == 12 ? "Passed" : "Failed") << " (Expected 12, Got " << res3 << ")" << endl;

    return 0;
}