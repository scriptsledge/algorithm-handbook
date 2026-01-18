# 3392. Count Subarrays of Length Three With a Condition

## Problem Description

Given an integer array `nums`, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.

### Examples

**Example 1:**
Input: `nums = [1,2,1,4,1]`
Output: `1`
Explanation: Only the subarray `[1,4,1]` contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.

**Example 2:**
Input: `nums = [1,1,1]`
Output: `0`
Explanation: `[1,1,1]` is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.

### Constraints
*   `3 <= nums.length <= 100`
*   `-100 <= nums[i] <= 100`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We iterate through the array from index `0` to `n-3`. For each index `i`, we check the subarray of length 3: `[nums[i], nums[i+1], nums[i+2]]`.
The condition is `nums[i] + nums[i+2] == nums[i+1] / 2`.
To avoid floating-point issues, we can rewrite the condition as `2 * (nums[i] + nums[i+2]) == nums[i+1]`.

### Code

```cpp
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i <= (int)nums.size() - 3; ++i) {
            if (2 * (nums[i] + nums[i+2]) == nums[i+1]) {
                count++;
            }
        }
        return count;
    }
};
```