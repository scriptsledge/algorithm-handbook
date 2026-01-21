#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto num : nums) {
            if ((num > 9 && num < 100) || (num > 999 && num < 10000) || num == 100000) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {12, 345, 2, 6, 7896};
    cout << "Test Case 1: " << (sol.findNumbers(nums1) == 2 ? "Passed" : "Failed") << " (Expected 2, Got " << sol.findNumbers(nums1) << ")" << endl;

    vector<int> nums2 = {555, 901, 482, 1771};
    cout << "Test Case 2: " << (sol.findNumbers(nums2) == 1 ? "Passed" : "Failed") << " (Expected 1, Got " << sol.findNumbers(nums2) << ")" << endl;

    return 0;
}