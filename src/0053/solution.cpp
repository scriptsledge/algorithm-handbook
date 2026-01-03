#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int sum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            max_sum = max(max_sum, sum);
            if (sum < 0) {
                sum = 0; // Reset sum when it becomes negative
            }
        }
        
        return max_sum;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Test Case 1: " << (sol.maxSubArray(nums1) == 6 ? "Passed" : "Failed") << endl;

    // Test Case 2
    vector<int> nums2 = {1};
    cout << "Test Case 2: " << (sol.maxSubArray(nums2) == 1 ? "Passed" : "Failed") << endl;

    // Test Case 3
    vector<int> nums3 = {5,4,-1,7,8};
    cout << "Test Case 3: " << (sol.maxSubArray(nums3) == 23 ? "Passed" : "Failed") << endl;

    return 0;
}