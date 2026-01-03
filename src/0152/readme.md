# 152. Maximum Product Subarray

## Problem Description

Given an integer array `nums`, find a **subarray** that has the largest product, and return *the product*.

### Examples

**Example 1:**
```text
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

**Example 2:**
```text
Input: nums = [-2,0,-1]
Output: 0
```

### Constraints
*   `1 <= nums.length <= 2 * 10^4`
*   `-10 <= nums[i] <= 10`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use a **Two-Pass (Forward & Backward)** approach.

Unlike sums, where we can greedily discard negative prefixes, products can flip signs. A negative prefix might become the maximum product if multiplied by another negative later.

However, the maximum product of a non-zero subarray must start at either the **beginning** or the **end** of that subarray (depending on the count of negative numbers).

1.  **Forward Pass:** Calculate running product from left to right.
2.  **Backward Pass:** Calculate running product from right to left.
3.  Reset the running product to 1 whenever a zero is encountered.

This ensures we find the maximum product in $O(N)$ time.

### Code

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;
        int fwd = 1, bwd = 1;

        for (int i = 0; i < n; i++) {
            fwd *= nums[i];
            bwd *= nums[n - 1 - i];

            maxProd = max({maxProd, fwd, bwd});

            if (fwd == 0) fwd = 1;
            if (bwd == 0) bwd = 1;
        }

        return maxProd;
    }
};
```