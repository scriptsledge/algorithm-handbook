#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    int expected1 = 4;
    if (sol.search(nums1, target1) == expected1) {
        cout << "Test Case 1 Passed!" << endl;
    } else {
        cout << "Test Case 1 Failed!" << endl;
    }

    // Test Case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    int expected2 = -1;
    if (sol.search(nums2, target2) == expected2) {
        cout << "Test Case 2 Passed!" << endl;
    } else {
        cout << "Test Case 2 Failed!" << endl;
    }

    // Test Case 3
    vector<int> nums3 = {1};
    int target3 = 0;
    int expected3 = -1;
    if (sol.search(nums3, target3) == expected3) {
        cout << "Test Case 3 Passed!" << endl;
    } else {
        cout << "Test Case 3 Failed!" << endl;
    }

    return 0;
}