#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {3, 2, 3};
    if (sol.majorityElement(nums1) == 3) {
        cout << "Test Case 1 Passed!" << endl;
    } else {
        cout << "Test Case 1 Failed!" << endl;
    }

    // Example 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    if (sol.majorityElement(nums2) == 2) {
        cout << "Test Case 2 Passed!" << endl;
    } else {
        cout << "Test Case 2 Failed!" << endl;
    }

    return 0;
}