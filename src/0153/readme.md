# 0153. Find Minimum in Rotated Sorted Array

## Problem Description

Suppose an array of length `n` sorted in ascending order is rotated between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:

- `[4,5,6,7,0,1,2]` if it was rotated 4 times.
- `[0,1,2,4,5,6,7]` if it was rotated 7 times.

Notice that rotating an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of unique elements, return the *minimum element* of this array.

You must write an algorithm that runs in `O(log n)` time.

### Examples

**Example 1:**
Input: `nums = [3,4,5,1,2]`
Output: `1`
Explanation: The original array was `[1,2,3,4,5]` rotated 3 times.

**Example 2:**
Input: `nums = [4,5,6,7,0,1,2]`
Output: `0`
Explanation: The original array was `[0,1,2,4,5,6,7]` and it was rotated 4 times.

**Example 3:**
Input: `nums = [11,13,15,17]`
Output: `11`
Explanation: The original array was `[11,13,15,17]` and it was rotated 4 times.

### Constraints

- `n == nums.length`
- `1 <= n <= 5000`
- `-5000 <= nums[i] <= 5000`
- All the integers of `nums` are unique.
- `nums` is sorted and rotated between `1` and `n` times.

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

The problem asks for an `O(log n)` solution, which strongly suggests using Binary Search. In a rotated sorted array, one half is always sorted.

1. Initialize `low = 0`, `high = n - 1`, and `minEle = INT_MAX`.
2. While `low <= high`:
    - Calculate `mid = low + (high - low) / 2`.
    - If the right half is sorted (`nums[mid] <= nums[high]`):
        - The minimum element in this sorted half is `nums[mid]`. Update `minEle` and eliminate the right half by setting `high = mid - 1`.
    - Else (the left half is sorted):
        - The minimum element in this sorted half is `nums[low]`. Update `minEle` and eliminate the left half by setting `low = mid + 1`.
3. Return `minEle`.

### Code

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int minEle = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= nums[high]) {
                minEle = min(nums[mid], minEle);
                high = mid - 1;
            } else {
                minEle = min(minEle, nums[low]);
                low = mid + 1;
            }
        }
        return minEle;
    }
};
```