#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> digitSumFreq;

        for (int num = 1; num <= n; num++) {
            int sum = 0, temp = num;

            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            digitSumFreq[sum]++;
        }

        int maxGroupSize = 0;
        for (auto& entry : digitSumFreq) {
            maxGroupSize = max(maxGroupSize, entry.second);
        }

        int maxGroups = 0;
        for (auto& entry : digitSumFreq) {
            if (entry.second == maxGroupSize)
                maxGroups++;
        }

        return maxGroups;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    if (sol.countLargestGroup(13) == 4) {
        cout << "Test Case 1 Passed!" << endl;
    } else {
        cout << "Test Case 1 Failed!" << endl;
    }

    // Example 2
    if (sol.countLargestGroup(2) == 2) {
        cout << "Test Case 2 Passed!" << endl;
    } else {
        cout << "Test Case 2 Failed!" << endl;
    }

    return 0;
}