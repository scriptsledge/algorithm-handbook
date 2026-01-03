# 88. Merge Sorted Array

## Problem Description

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

**Merge** `nums1` and `nums2` into a single array sorted in **non-decreasing order**.

The final sorted array should not be returned by the function, but instead be stored inside the array `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.

### Examples

**Example 1:**
```text
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
```

**Example 2:**
```text
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
```

**Example 3:**
```text
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
```

### Constraints
*   `nums1.length == m + n`
*   `nums2.length == n`
*   `0 <= m, n <= 200`
*   `1 <= m + n <= 200`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use a **Reverse Two-Pointer** approach. 

Since `nums1` has a buffer at the end, we can fill the final sorted array from **right to left**.
1. Compare the largest elements from `nums1` and `nums2`.
2. Place the larger one at the end of the buffer.
3. Decrement pointers and repeat.

This avoids the need to shift elements ($O(N^2)$) or allocate new memory ($O(N)$).

### Code

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p--] = nums1[p1--];
            } else {
                nums1[p--] = nums2[p2--];
            }
        }
        
        while (p2 >= 0) {
            nums1[p--] = nums2[p2--];
        }
    }
};
```