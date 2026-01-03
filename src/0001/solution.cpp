#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash_map.find(complement) != hash_map.end()) {
                return {hash_map[complement], i};
            }
            hash_map[nums[i]] = i;
        }
        return {};
    }
};

void printVector(const vector<int>& res) {
    cout << "[";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i < res.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    cout << "Test Case 1: ";
    printVector(sol.twoSum(nums1, target1)); // Expected: [0,1]

    // Example 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    cout << "Test Case 2: ";
    printVector(sol.twoSum(nums2, target2)); // Expected: [1,2]

    // Example 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    cout << "Test Case 3: ";
    printVector(sol.twoSum(nums3, target3)); // Expected: [0,1]

    return 0;
}