#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds the maximum difference between nums[i] and nums[j] such that i < j and nums[i] < nums[j].
     * 
     * The approach maintains the minimum value seen so far as we iterate through the array.
     * For each element, if it's greater than the minimum seen so far, we calculate the difference
     * and update the maximum difference. If it's smaller, we update the minimum.
     * 
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     * 
     * @param nums 0-indexed integer array
     * @return Maximum difference or -1 if no such pair exists
     */
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1;

        int minSoFar = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > minSoFar) {
                maxDiff = max(maxDiff, nums[i] - minSoFar);
            } else {
                minSoFar = nums[i];
            }
        }

        return maxDiff;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {7, 1, 5, 4};
    cout << "Test 1: " << (sol.maximumDifference(nums1) == 4 ? "Passed" : "Failed") << " (Expected 4)" << endl;

    // Example 2
    vector<int> nums2 = {9, 4, 3, 2};
    cout << "Test 2: " << (sol.maximumDifference(nums2) == -1 ? "Passed" : "Failed") << " (Expected -1)" << endl;

    // Example 3
    vector<int> nums3 = {1, 5, 2, 10};
    cout << "Test 3: " << (sol.maximumDifference(nums3) == 9 ? "Passed" : "Failed") << " (Expected 9)" << endl;

    return 0;
}