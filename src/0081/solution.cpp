#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {2,5,6,0,0,1,2};
    int target1 = 0;
    bool expected1 = true;
    bool result1 = sol.search(nums1, target1);
    
    // Test Case 2
    vector<int> nums2 = {2,5,6,0,0,1,2};
    int target2 = 3;
    bool expected2 = false;
    bool result2 = sol.search(nums2, target2);

    if (result1 == expected1 && result2 == expected2) {
        cout << "Test passed!" << endl;
    } else {
        cout << "Test failed!" << endl;
        cout << "Test 1: " << result1 << " (Expected: " << expected1 << ")" << endl;
        cout << "Test 2: " << result2 << " (Expected: " << expected2 << ")" << endl;
    }

    return 0;
}