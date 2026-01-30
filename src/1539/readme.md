# 1539. Kth Missing Positive Number

## Problem Description

Given an array `arr` of positive integers sorted in a strictly increasing order, and an integer `k`.

Return the *kth* positive integer that is missing from this array.

### Examples

**Example 1:**
- **Input:** `arr = [2,3,4,7,11], k = 5`
- **Output:** `9`
- **Explanation:** The missing positive integers are `[1,5,6,8,9,10,12,13,...]`. The 5th missing positive integer is 9.

**Example 2:**
- **Input:** `arr = [1,2,3,4], k = 2`
- **Output:** `6`
- **Explanation:** The missing positive integers are `[5,6,7,...]`. The 2nd missing positive integer is 6.

### Constraints

- `1 <= arr.length <= 1000`
- `1 <= arr[i] <= 1000`
- `1 <= k <= 1000`
- `arr[i] < arr[j]` for `1 <= i < j <= arr.length`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use **Binary Search** to achieve an $O(\log N)$ time complexity. 

1.  For any index `i`, the number of missing positive integers before `arr[i]` is given by `arr[i] - (i + 1)`.
2.  We search for the first index `left` such that the missing count is at least `k`.
3.  The result is then calculated as `left + k`.

### Code

```cpp
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] - mid - 1 < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left + k;
    }
};
```