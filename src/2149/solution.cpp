#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        int positiveIndex = 0, negativeIndex = 1;
        vector<int> result(nums);

        for (int i = 0; i < size; i++) {
            if (nums[i] < 0) {
                result[negativeIndex] = nums[i];
                negativeIndex += 2;
            } else {
                result[positiveIndex] = nums[i];
                positiveIndex += 2;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> tests = {
        {3,1,-2,-5,2,-4},
        {-1,1}
    };

    for (auto& nums : tests) {
        cout << "Input: nums = [";
        for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << (i < nums.size() - 1 ? "," : "");
        cout << "]\n";
        
        vector<int> result = sol.rearrangeArray(nums);
        
        cout << "Output: [";
        for (size_t i = 0; i < result.size(); ++i) cout << result[i] << (i < result.size() - 1 ? "," : "");
        cout << "]\n\n";
    }
    return 0;
}
