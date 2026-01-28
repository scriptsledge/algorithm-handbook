#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int i = 0;
        
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            } else {
                i++;
            }
        }
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums1);
    vector<int> expected1 = {0, 0, 1, 1, 2, 2};
    if (nums1 == expected1) {
        cout << "Test Case 1 Passed" << endl;
    } else {
        cout << "Test Case 1 Failed" << endl;
    }

    vector<int> nums2 = {2, 0, 1};
    sol.sortColors(nums2);
    vector<int> expected2 = {0, 1, 2};
    if (nums2 == expected2) {
        cout << "Test Case 2 Passed" << endl;
    } else {
        cout << "Test Case 2 Failed" << endl;
    }

    return 0;
}