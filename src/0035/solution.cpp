#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int pos = nums.size();
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] >= target) {
                pos = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return pos;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << "Test Case 1: " << (sol.searchInsert(nums1, target1) == 2 ? "Passed" : "Failed") << endl;

    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << "Test Case 2: " << (sol.searchInsert(nums2, target2) == 1 ? "Passed" : "Failed") << endl;

    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << "Test Case 3: " << (sol.searchInsert(nums3, target3) == 4 ? "Passed" : "Failed") << endl;

    return 0;
}