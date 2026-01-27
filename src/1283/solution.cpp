#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Helper function to check if a given divisor is valid according to the threshold.
     * sum(ceil(nums[i] / divisor)) <= threshold
     */
    bool isValid(vector<int>& nums, int threshold, int divisor) {
        int sum = 0;
        for (auto num : nums) {
            // Efficient way to calculate ceil(num / divisor)
            sum += ((num + divisor - 1) / divisor);
            if (sum > threshold)
                return false;
        }
        return sum <= threshold;
    }

    /**
     * Binary search for the smallest divisor.
     * The range for the divisor is [1, max(nums)].
     */
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(nums, threshold, mid)) {
                result = mid;
                high = mid - 1; // Try smaller divisor
            } else {
                low = mid + 1; // Need a larger divisor to decrease the sum
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 5, 9};
    int threshold1 = 6;
    cout << "Test Case 1: " << (sol.smallestDivisor(nums1, threshold1) == 5 ? "Passed" : "Failed") << " (Expected 5)" << endl;

    // Example 2
    vector<int> nums2 = {44, 22, 33, 11, 1};
    int threshold2 = 5;
    cout << "Test Case 2: " << (sol.smallestDivisor(nums2, threshold2) == 44 ? "Passed" : "Failed") << " (Expected 44)" << endl;

    return 0;
}