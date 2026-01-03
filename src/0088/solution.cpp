#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        
        // Compare elements from the back and fill nums1 from the end
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p--] = nums1[p1--];
            } else {
                nums1[p--] = nums2[p2--];
            }
        }
        
        // If nums2 still has elements, copy them (nums1 elements are already in place)
        while (p2 >= 0) {
            nums1[p--] = nums2[p2--];
        }
    }
};

void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1_1 = {1,2,3,0,0,0};
    vector<int> nums2_1 = {2,5,6};
    sol.merge(nums1_1, 3, nums2_1, 3);
    cout << "Test Case 1: ";
    printVector(nums1_1); // Expected: [1,2,2,3,5,6]

    // Example 2
    vector<int> nums1_2 = {1};
    vector<int> nums2_2 = {};
    sol.merge(nums1_2, 1, nums2_2, 0);
    cout << "Test Case 2: ";
    printVector(nums1_2); // Expected: [1]

    // Example 3
    vector<int> nums1_3 = {0};
    vector<int> nums2_3 = {1};
    sol.merge(nums1_3, 0, nums2_3, 1);
    cout << "Test Case 3: ";
    printVector(nums1_3); // Expected: [1]

    return 0;
}