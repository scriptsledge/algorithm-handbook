#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            auto lb =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto ub =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            count += ub - lb;
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {0, 1, 7, 4, 4, 5};
    int lower1 = 3, upper1 = 6;
    cout << "Test Case 1: " << (sol.countFairPairs(nums1, lower1, upper1) == 6 ? "Passed" : "Failed") << endl;

    // Example 2
    vector<int> nums2 = {1, 7, 9, 2, 5};
    int lower2 = 11, upper2 = 11;
    cout << "Test Case 2: " << (sol.countFairPairs(nums2, lower2, upper2) == 1 ? "Passed" : "Failed") << endl;

    return 0;
}