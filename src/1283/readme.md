# 1283. Find the Smallest Divisor Given a Threshold

## Problem Description

Given an array of integers `nums` and an integer `threshold`, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the **smallest** divisor such that the result mentioned above is less than or equal to `threshold`.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: $7/3 = 3$ and $10/2 = 5$).

The test cases are generated so that there will be an answer.

### Examples

**Example 1:**
```text
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
```

**Example 2:**
```text
Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
```

### Constraints

*   `1 <= nums.length <= 5 * 10^4`
*   `1 <= nums[i] <= 10^6`
*   `nums.length <= threshold <= 10^6`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use **Binary Search on the Answer**. 

Since the sum of the division results is monotonically decreasing as the divisor increases, we can search for the smallest divisor in the range `[1, max(nums)]`.

1.  **Define Range:** The minimum possible divisor is `1`, and the maximum possible divisor needed is the maximum element in `nums` (which makes all quotients `1`, resulting in a sum equal to `nums.length`).
2.  **Binary Search:**
    *   Pick a `mid` divisor.
    *   Calculate the sum of `ceil(num / mid)` for all `num` in `nums`.
    *   If the `sum <= threshold`, then `mid` is a potential answer. We try to find a smaller one by moving the `high` pointer.
    *   Otherwise, the divisor is too small, so we move the `low` pointer.

### Code

```cpp
class Solution {
public:
    bool isValid(vector<int>& nums, int threshold, int divisor) {
        int sum = 0;
        for (auto num : nums) {
            sum += ((num + divisor - 1) / divisor);
            if (sum > threshold) return false;
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(nums, threshold, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};
```