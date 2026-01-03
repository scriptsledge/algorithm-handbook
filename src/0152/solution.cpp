#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;
        int fwd = 1, bwd = 1;

        for (int i = 0; i < n; i++) {
            fwd *= nums[i];
            bwd *= nums[n - 1 - i];

            maxProd = max({maxProd, fwd, bwd});

            // If we encounter a zero, reset the running product to 1
            // Zero essentially splits the array into subarrays
            if (fwd == 0) fwd = 1;
            if (bwd == 0) bwd = 1;
        }

        return maxProd;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Test Case 1: " << (sol.maxProduct(nums1) == 6 ? "Passed" : "Failed") << endl;

    // Example 2
    vector<int> nums2 = {-2, 0, -1};
    cout << "Test Case 2: " << (sol.maxProduct(nums2) == 0 ? "Passed" : "Failed") << endl;

    // Example 3: Edge case with single negative
    vector<int> nums3 = {-2};
    cout << "Test Case 3: " << (sol.maxProduct(nums3) == -2 ? "Passed" : "Failed") << endl;
    
    // Example 4: Double negative
    vector<int> nums4 = {-2, -3, 7};
    cout << "Test Case 4: " << (sol.maxProduct(nums4) == 42 ? "Passed" : "Failed") << endl;

    return 0;
}