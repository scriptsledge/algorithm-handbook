# 540. Single Element in a Sorted Array

## Problem Description

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in $O(\log n)$ time and $O(1)$ space.

### Examples

**Example 1:**
```text
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
```

**Example 2:**
```text
Input: nums = [3,3,7,7,10,11,11]
Output: 10
```

### Constraints
*   `1 <= nums.length <= 10^5`
*   `0 <= nums[i] <= 10^5`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use **Binary Search** to achieve $O(\log n)$ time complexity. 

The key observation is that before the single element, pairs start at even indices ($i, i+1$ where $i$ is even). After the single element, pairs start at odd indices ($i, i+1$ where $i$ is odd).

1. Initialize `low = 0` and `high = n - 1`.
2. While `low < high`:
    * Calculate `mid`.
    * Ensure `mid` is even (if `mid` is odd, decrement it).
    * Compare `nums[mid]` with `nums[mid + 1]`.
    * If they are equal, the single element must be to the right, so `low = mid + 2`.
    * Otherwise, it's to the left (or is `mid`), so `high = mid`.
3. Return `nums[low]`.

### Code

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                high = mid;
            }
        }
        
        return nums[low];
    }
};
```