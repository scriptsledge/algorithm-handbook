#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i <= (int)nums.size() - 3; ++i) {
            // Condition: nums[i] + nums[i+2] == nums[i+1] / 2.0
            // To avoid floating point, use: 2 * (nums[i] + nums[i+2]) == nums[i+1]
            if (2 * (nums[i] + nums[i+2]) == nums[i+1]) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 1, 4, 1};
    int expected1 = 1;
    int result1 = sol.countSubarrays(nums1);
    
    // Test Case 2
    vector<int> nums2 = {1, 1, 1};
    int expected2 = 0;
    int result2 = sol.countSubarrays(nums2);

    if (result1 == expected1 && result2 == expected2) {
        cout << "Test passed!" << endl;
    } else {
        cout << "Test failed!" << endl;
        cout << "Test 1: " << result1 << " (Expected: " << expected1 << ")" << endl;
        cout << "Test 2: " << result2 << " (Expected: " << expected2 << ")" << endl;
    }

    return 0;
}