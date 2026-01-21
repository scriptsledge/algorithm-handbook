#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            // Ensure mid is even to compare with the next element
            if (mid % 2 == 1) {
                mid--;
            }
            
            // If pair is correct, the single element is in the right half
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                // Otherwise, it's in the left half (including mid)
                high = mid;
            }
        }
        
        return nums[low];
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int res1 = sol.singleNonDuplicate(nums1);
    cout << "Test Case 1: " << (res1 == 2 ? "Passed" : "Failed") << " (Expected 2, Got " << res1 << ")" << endl;

    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    int res2 = sol.singleNonDuplicate(nums2);
    cout << "Test Case 2: " << (res2 == 10 ? "Passed" : "Failed") << " (Expected 10, Got " << res2 << ")" << endl;

    return 0;
}