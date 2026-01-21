#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[mid + 1])
                low = mid + 1;
            else
                high = mid;
        }
        
        return low;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 2, 3, 1};
    int res1 = sol.findPeakElement(nums1);
    cout << "Test Case 1: " << (res1 == 2 ? "Passed" : "Failed") << " (Expected 2, Got " << res1 << ")" << endl;

    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    int res2 = sol.findPeakElement(nums2);
    // Multiple peaks possible, but 1 or 5 are valid.
    cout << "Test Case 2: " << (res2 == 1 || res2 == 5 ? "Passed" : "Failed") << " (Expected 1 or 5, Got " << res2 << ")" << endl;

    return 0;
}