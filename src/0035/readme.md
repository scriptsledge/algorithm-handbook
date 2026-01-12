# 0035. Search Insert Position

## Problem Description

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

### Examples

**Example 1:**
Input: nums = [1,3,5,6], target = 5
Output: 2

**Example 2:**
Input: nums = [1,3,5,6], target = 2
Output: 1

**Example 3:**
Input: nums = [1,3,5,6], target = 7
Output: 4

### Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` contains distinct values sorted in ascending order.
- `-10^4 <= target <= 10^4`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use binary search to find the insertion point in $O(\log n)$ time. The insertion point is the index of the first element in the sorted array that is greater than or equal to the target.

1. Initialize `low = 0`, `high = nums.size() - 1`, and `pos = nums.size()`.
2. While `low <= high`:
    - Calculate `mid`.
    - If `nums[mid] >= target`, we've found a potential insertion point. Update `pos = mid` and search the left half (`high = mid - 1`) to see if there's a smaller index that also satisfies the condition.
    - If `nums[mid] < target`, the insertion point must be in the right half (`low = mid + 1`).
3. Return `pos`.

### Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int pos = nums.size();
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] >= target) {
                pos = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return pos;
    }
};
```