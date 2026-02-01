#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDistance = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int nextIndex = (i + 1) % n;
            maxDistance = max(maxDistance, abs(nums[i] - nums[nextIndex]));
        }
        
        return maxDistance;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 4};
    cout << "Test Case 1: " << sol.maxAdjacentDistance(nums1) << " (Expected: 3)" << endl;

    // Example 2
    vector<int> nums2 = {-5, -10, -5};
    cout << "Test Case 2: " << sol.maxAdjacentDistance(nums2) << " (Expected: 5)" << endl;

    return 0;
}