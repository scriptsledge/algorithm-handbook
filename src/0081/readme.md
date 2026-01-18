# 81. Search in Rotated Sorted Array II

## Problem Description

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

### Examples

**Example 1:**

```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

**Example 2:**

```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

### Constraints

*   `1 <= nums.length <= 5000`
*   `-10^4 <= nums[i] <= 10^4`
*   `nums` is guaranteed to be rotated at some pivot.
*   `-10^4 <= target <= 10^4`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

The problem is a variation of binary search. Since the array is rotated and contains duplicates, we can't simply decide which half to discard based on `nums[left] <= nums[mid]` when `nums[left] == nums[mid]`.
When `nums[left] == nums[mid] == nums[right]`, we can't determine if the left or right half is sorted. In this case, we simply increment `left` and decrement `right` to shrink the search space (worst case O(N)).
Otherwise, if one half is sorted, we check if the target lies within that sorted half to decide where to move.

### Code

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};
```