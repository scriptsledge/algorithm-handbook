# 0075. Sort Colors

## Problem Description

Given an array `nums` with `n` objects colored red, white, or blue, sort them **in-place** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

### Examples

**Example 1:**
- **Input:** `nums = [2,0,2,1,1,0]`
- **Output:** `[0,0,1,1,2,2]`

**Example 2:**
- **Input:** `nums = [2,0,1]`
- **Output:** `[0,1,2]`

### Constraints
- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is either `0`, `1`, or `2`.

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use a one-pass algorithm with three pointers (Dutch National Flag algorithm):
- `left` tracks the boundary of 0s.
- `right` tracks the boundary of 2s.
- `i` iterates through the array.

### Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int i = 0;
        
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            } else {
                i++;
            }
        }
    }
};
```