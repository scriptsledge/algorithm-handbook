#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<int> prefixMax(n, 0), suffixMax(n, 0);
        prefixMax[0] = nums[0];

        // Compute prefix max
        for (int i = 1; i < n; i++)
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);

        // Compute suffix max
        suffixMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffixMax[i] = max(suffixMax[i + 1], nums[i]);

        long long maxValue = 0;

        // Iterate through j to find max (prefixMax[i] - nums[j]) * suffixMax[k]
        for (int j = 1; j < n - 1; j++) {
            long long left = prefixMax[j - 1] - (long long)nums[j];
            long long right = suffixMax[j + 1];
            maxValue = max(maxValue, left * right);
        }

        return maxValue;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {12, 6, 1, 2, 7};
    cout << "Test Case 1: " << (sol.maximumTripletValue(nums1) == 77 ? "Passed" : "Failed") << endl;

    // Test Case 2
    vector<int> nums2 = {1, 10, 3, 4, 19};
    cout << "Test Case 2: " << (sol.maximumTripletValue(nums2) == 133 ? "Passed" : "Failed") << endl;

    // Test Case 3
    vector<int> nums3 = {1, 2, 3};
    cout << "Test Case 3: " << (sol.maximumTripletValue(nums3) == 0 ? "Passed" : "Failed") << endl;

    return 0;
}