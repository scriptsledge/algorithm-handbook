# 1. Two Sum

## Problem Description

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

### Examples

**Example 1:**
```text
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
```

**Example 2:**
```text
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

### Constraints
*   `2 <= nums.length <= 10^4`
*   `-10^9 <= nums[i] <= 10^9`
*   `-10^9 <= target <= 10^9`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use a **Hash Map** to store values and their indices as we iterate through the array. 

For each element, we calculate the `complement` needed to reach the `target`. If the `complement` is already in the map, we return the pair of indices. Otherwise, we add the current element to the map.

This achieves a linear $O(N)$ time complexity.

### Code

```cpp
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
```