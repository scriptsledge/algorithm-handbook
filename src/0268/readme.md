# 268. Missing Number

## Problem Description

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array*.

### Examples

**Example 1:**
```text
Input: nums = [3,0,1]
Output: 2
```

**Example 2:**
```text
Input: nums = [0,1]
Output: 2
```

### Constraints
*   `n == nums.length`
*   `1 <= n <= 10^4`
*   `0 <= nums[i] <= n`
*   All the numbers of `nums` are **unique**.

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use the **Gauss Summation** formula to find the missing number in $O(N)$ time with $O(1)$ space.

1.  Calculate the sum of all numbers from $0$ to $n$ using $\frac{n(n+1)}{2}$.
2.  Calculate the actual sum of the numbers in the array.
3.  The difference between the expected sum and the actual sum is the missing number.

### Code

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }
};
```