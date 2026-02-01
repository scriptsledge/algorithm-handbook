# 3423. Maximum Difference Between Adjacent Elements in a Circular Array

## Problem Description

Given a circular array `nums`, find the maximum absolute difference between adjacent elements.

Note: In a circular array, the first and last elements are adjacent.

### Examples

**Example 1:**
- **Input:** `nums = [1,2,4]`
- **Output:** `3`
- **Explanation:** Because `nums` is circular, `nums[0]` and `nums[2]` are adjacent. They have the maximum absolute difference of `|4 - 1| = 3`.

**Example 2:**
- **Input:** `nums = [-5,-10,-5]`
- **Output:** `5`
- **Explanation:** The adjacent elements `nums[0]` and `nums[1]` have the maximum absolute difference of `|-5 - (-10)| = 5`.

### Constraints

- `2 <= nums.length <= 100`
- `-100 <= nums[i] <= 100`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We can iterate through the array and calculate the absolute difference between each element and its next neighbor. Since the array is circular, the next neighbor of the last element is the first element. This can be handled using the modulo operator `(i + 1) % n`.

### Code

```cpp
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDistance = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int nextIndex = (i + 1) % n;
            maxDistance = max(maxDistance, abs(nums[i] - nums[nextIndex]));
        }
        
        return maxDistance;
    }
};
```