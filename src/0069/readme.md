# 69. Sqrt(x)

## Problem Description

Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

### Examples

**Example 1:**
```text
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
```

**Example 2:**
```text
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```

### Constraints
*   `0 <= x <= 2^31 - 1`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use **Binary Search** to find the largest integer $k$ such that $k^2 \le x$. The range for our search is $[0, x]$.

1. Initialize `low = 0` and `high = x`.
2. While `low <= high`:
    * Calculate `mid = low + (high - low) / 2`.
    * If `mid * mid <= x`, then `mid` could be the answer, but there might be a larger one. Move right: `low = mid + 1`.
    * Else, `mid` is too large. Move left: `high = mid - 1`.
3. Return `high` as it will hold the largest integer whose square is less than or equal to `x`.

*Note: Use `long long` for the calculation of `mid * mid` to prevent integer overflow.*

### Code

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (1LL * mid * mid <= x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};
```