#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // Gauss Summation Formula: Sum of first n numbers = n * (n + 1) / 2
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {3, 0, 1};
    cout << "Test Case 1: " << (sol.missingNumber(nums1) == 2 ? "Passed" : "Failed") << endl;

    // Example 2
    vector<int> nums2 = {0, 1};
    cout << "Test Case 2: " << (sol.missingNumber(nums2) == 2 ? "Passed" : "Failed") << endl;

    // Example 3
    vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "Test Case 3: " << (sol.missingNumber(nums3) == 8 ? "Passed" : "Failed") << endl;

    return 0;
}