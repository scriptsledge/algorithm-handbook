#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> aboveK;

        for (int n : nums) {
            if (n < k) return -1;
            if (n > k) aboveK.insert(n);
        }

        return aboveK.size();
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {5, 2, 5, 4, 5};
    int k1 = 2;
    cout << "Test Case 1: " << (sol.minOperations(nums1, k1) == 2 ? "Passed" : "Failed") << endl;

    // Example 2
    vector<int> nums2 = {2, 1, 2};
    int k2 = 2;
    cout << "Test Case 2: " << (sol.minOperations(nums2, k2) == -1 ? "Passed" : "Failed") << endl;

    // Example 3
    vector<int> nums3 = {9, 7, 5, 3};
    int k3 = 1;
    cout << "Test Case 3: " << (sol.minOperations(nums3, k3) == 4 ? "Passed" : "Failed") << endl;

    return 0;
}