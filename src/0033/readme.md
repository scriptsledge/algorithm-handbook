# 0033. Search in Rotated Sorted Array

## Problem Description

There is an integer array `nums` sorted in ascending order (with distinct values).

Prior to being passed to your function, `nums` is possibly left rotated at an unknown index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (0-indexed). For example, `[0,1,2,4,5,6,7]` might be left rotated by 3 indices and become `[4,5,6,7,0,1,2]`.

Given the array `nums` after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or `-1` if it is not in `nums`.

You must write an algorithm with $O(\log n)$ runtime complexity.

### Examples

**Example 1:**
- **Input:** `nums = [4,5,6,7,0,1,2]`, `target = 0`
- **Output:** `4`

**Example 2:**
- **Input:** `nums = [4,5,6,7,0,1,2]`, `target = 3`
- **Output:** `-1`

**Example 3:**
- **Input:** `nums = [1]`, `target = 0`
- **Output:** `-1`

### Constraints

- `1 <= nums.length <= 5000`
- $-10^4 <= nums[i] <= 10^4$
- All values of `nums` are unique.
- `nums` is an ascending array that is possibly rotated.
- $-10^4 <= target <= 10^4$

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

The problem asks for an $O(\log n)$ search in a rotated sorted array. Since it's a search in a sorted (but rotated) array, we can use a modified Binary Search.

1.  Initialize `left = 0` and `right = nums.size() - 1`.
2.  While `left <= right`:
    -   Calculate `mid = left + (right - left) / 2`.
    -   If `nums[mid] == target`, return `mid`.
    -   Check which half is sorted:
        -   **Case 1: Left half `[left...mid]` is sorted (`nums[left] <= nums[mid]`)**
            -   Check if `target` lies within this sorted range: `target >= nums[left] && target < nums[mid]`.
            -   If yes, move `right = mid - 1`.
            -   Otherwise, `target` must be in the right half, so move `left = mid + 1`.
        -   **Case 2: Right half `[mid...right]` is sorted**
            -   Check if `target` lies within this sorted range: `target > nums[mid] && target <= nums[right]`.
            -   If yes, move `left = mid + 1`.
            -   Otherwise, `target` must be in the left half, so move `right = mid - 1`.
3.  If the loop finishes without finding the target, return `-1`.

### Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
```