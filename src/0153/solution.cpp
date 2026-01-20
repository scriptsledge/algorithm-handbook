#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int minEle = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= nums[high]) {
                minEle = min(nums[mid], minEle);
                high = mid - 1;
            } else {
                minEle = min(minEle, nums[low]);
                low = mid + 1;
            }
        }
        return minEle;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Test 1: " << (sol.findMin(nums1) == 1 ? "Passed" : "Failed") << " (Expected 1, Got " << sol.findMin(nums1) << ")" << endl;

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 2: " << (sol.findMin(nums2) == 0 ? "Passed" : "Failed") << " (Expected 0, Got " << sol.findMin(nums2) << ")" << endl;

    vector<int> nums3 = {11, 13, 15, 17};
    cout << "Test 3: " << (sol.findMin(nums3) == 11 ? "Passed" : "Failed") << " (Expected 11, Got " << sol.findMin(nums3) << ")" << endl;

    return 0;
}