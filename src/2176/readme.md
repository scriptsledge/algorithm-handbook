# 2176. Count Equal and Divisible Pairs in an Array

## Problem Description

Given a **0-indexed** integer array `nums` of length `n` and an integer `k`, return *the number of pairs `(i, j)` where `0 <= i < j < n`, such that `nums[i] == nums[j]` and `(i * j)` is divisible by `k`*.

### Examples

**Example 1:**
```text
Input: nums = [3,1,2,2,2,1,3], k = 2
Output: 4
Explanation:
There are 4 pairs that meet all the requirements:
- nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
- nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
- nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
- nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
```

**Example 2:**
```text
Input: nums = [1,2,3,4], k = 1
Output: 0
Explanation: Since no value in nums is repeated, there are no pairs (i,j) that meet all the requirements.
```

### Constraints
*   `1 <= nums.length <= 100`
*   `1 <= nums[i], k <= 100`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We iterate through the array and use a hash map to store the indices of each number we've encountered so far. For each number at index `i`, we check all previously stored indices `j` of the same number. If `(i * j) % k == 0`, we increment our count.

Given the small constraints ($N \le 100$), this $O(N^2)$ approach in the worst case (when all elements are the same) is perfectly acceptable.

### Code

```cpp
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
```