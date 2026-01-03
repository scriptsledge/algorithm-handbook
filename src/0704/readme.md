# 0704. Binary Search

## Problem Description

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with $O(\log n)$ runtime complexity.

### Examples

**Example 1:**

**Input:** `nums = [-1,0,3,5,9,12]`, `target = 9`
**Output:** `4`
**Explanation:** `9` exists in `nums` and its index is `4`

**Example 2:**

**Input:** `nums = [-1,0,3,5,9,12]`, `target = 2`
**Output:** `-1`
**Explanation:** `2` does not exist in `nums` so return `-1`

### Constraints

*   `1 <= nums.length <= 10^4`
*   `-10^4 < nums[i], target < 10^4`
*   All the integers in `nums` are unique.
*   `nums` is sorted in ascending order.

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use the standard **Binary Search** algorithm to find the target in a sorted array. Binary search works by repeatedly dividing the search interval in half.

1.  Compare the target value with the middle element of the array.
2.  If the target value matches the middle element, its index is returned.
3.  If the target value is less than the middle element, the search continues in the lower half.
4.  If the target value is greater than the middle element, the search continues in the upper half.

In this implementation, we use a recursive approach.

### Code

```cpp
class Solution {
private:
    int binary_search(vector<int>& arr, int target, int low, int high) {
        if (high < low) {
            return -1;
        }
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) {
            return binary_search(arr, target, low, mid - 1);
        }
        return binary_search(arr, target, mid + 1, high);
    }
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        return binary_search(nums, target, low, high);
    }
};
```