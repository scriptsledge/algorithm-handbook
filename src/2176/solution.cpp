#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> indices;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (indices.count(nums[i])) {
                for (int j : indices[nums[i]]) {
                    if ((i * j) % k == 0)
                        count++;
                }
            }
            indices[nums[i]].push_back(i);
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {3, 1, 2, 2, 2, 1, 3};
    int k1 = 2;
    cout << "Test Case 1: " << sol.countPairs(nums1, k1) << " (Expected: 4)" << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 3, 4};
    int k2 = 1;
    cout << "Test Case 2: " << sol.countPairs(nums2, k2) << " (Expected: 0)" << endl;

    return 0;
}