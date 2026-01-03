#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int binary_search(vector<int>& arr, int target, int low, int high) {
        if (high < low) {
            return -1;
        }
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) {
            return binary_search(arr, target, low, mid - 1);
        }
        return binary_search(arr, target, mid + 1, high);
    }
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        return binary_search(nums, target, low, high);
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int result1 = sol.search(nums1, target1);
    cout << "Test Case 1: " << (result1 == 4 ? "Passed" : "Failed") << " (Expected 4, Got " << result1 << ")" << endl;

    // Test Case 2
    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    int result2 = sol.search(nums2, target2);
    cout << "Test Case 2: " << (result2 == -1 ? "Passed" : "Failed") << " (Expected -1, Got " << result2 << ")" << endl;

    return 0;
}