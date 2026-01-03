# 3375. Minimum Operations to Make Array Values Equal to K

## Problem Description

You are given an integer array `nums` and an integer `k`.

An integer `h` is called **valid** if all values in the array that are strictly greater than `h` are identical.

You are allowed to perform the following operation on `nums`:
1. Select an integer `h` that is **valid** for the current values in `nums`.
2. For each index `i` where `nums[i] > h`, set `nums[i]` to `h`.

Return the **minimum number of operations** required to make every element in `nums` equal to `k`. If it is impossible, return `-1`.

### Examples

**Example 1:**
```text
Input: nums = [5,2,5,4,5], k = 2
Output: 2
```

**Example 2:**
```text
Input: nums = [2,1,2], k = 2
Output: -1
```

### Constraints
*   `1 <= nums.length <= 100`
*   `1 <= nums[i] <= 100`
*   `1 <= k <= 100`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use an **Unordered Set** to count unique values strictly greater than $k$. 

The "valid $h$" constraint means we can only reduce the largest elements if they are all identical. This forces us to reduce the array one unique value at a time. Therefore, the number of operations is equal to the count of unique values that need to be "stepped down" to reach $k$.
### Code

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> aboveK;

        for (int n : nums) {
            if (n < k) return -1;
            if (n > k) aboveK.insert(n);
        }

        return aboveK.size();
    }
};
```