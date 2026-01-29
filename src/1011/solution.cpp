#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper: Simulate shipping with given capacity
    bool canShip(vector<int>& weights, int days, int capacity) {
        int daysNeeded = 1;
        int currentWeight = 0;

        for (int w : weights) {
            if (currentWeight + w > capacity) {
                daysNeeded++;           // Start a new day
                currentWeight = w;
            } else {
                currentWeight += w;
            }
        }

        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());       // Min possible capacity
        int right = accumulate(weights.begin(), weights.end(), 0);     // Max possible capacity

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canShip(weights, days, mid)) {
                right = mid;       // Try smaller capacity
            } else {
                left = mid + 1;    // Increase capacity
            }
        }

        return left;
    }
};

int main() {
    Solution sol;
    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;
    cout << "Test Case 1: " << (sol.shipWithinDays(weights1, days1) == 15 ? "Passed" : "Failed") << " (Expected 15, Got " << sol.shipWithinDays(weights1, days1) << ")" << endl;

    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;
    cout << "Test Case 2: " << (sol.shipWithinDays(weights2, days2) == 6 ? "Passed" : "Failed") << " (Expected 6, Got " << sol.shipWithinDays(weights2, days2) << ")" << endl;

    vector<int> weights3 = {1, 2, 3, 1, 1};
    int days3 = 4;
    cout << "Test Case 3: " << (sol.shipWithinDays(weights3, days3) == 3 ? "Passed" : "Failed") << " (Expected 3, Got " << sol.shipWithinDays(weights3, days3) << ")" << endl;

    return 0;
}