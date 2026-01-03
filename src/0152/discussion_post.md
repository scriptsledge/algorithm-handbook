# 🏷️ LeetCode Submission Title
C++ | Two-Pass Solution | O(N) Time | O(1) Space | Simplest Approach

# Intuition
The "Maximum Product Subarray" is tricky because of **negative numbers**. A single negative number flips a large positive product into a large negative one. However, another negative number can flip it back to positive.

Unlike "Maximum Sum Subarray" (Kadane's), we can't just drop negative prefixes.

**Key Observation:**
If there are no zeros, the maximum product subarray **must** start from either the very beginning or the very end of the array.
*   **Even number of negatives:** The entire array product is positive.
*   **Odd number of negatives:** One negative number splits the array. We either take the prefix before it or the suffix after it.

**Zeros** act as "reset" buttons, splitting the problem into smaller subarrays.

# Approach
Instead of tracking min/max dynamic programming states (which is the standard approach), we can simplify this using a **Two-Pass Algorithm**:

1.  **Forward Pass:** Calculate running products from left to right. Keep track of the maximum. Reset to 1 if we hit a zero.
2.  **Backward Pass:** Calculate running products from right to left. Keep track of the maximum. Reset to 1 if we hit a zero.
3.  The result is the maximum value found in either pass.

This covers all cases: prefixes, suffixes, and subarrays split by zeros.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/OI1irq3hDjE)

# Complexity
*   **Time complexity:** $$O(N)$$
    We iterate through the array once (calculating both forward and backward simultaneously).
*   **Space complexity:** $$O(1)$$
    We only use a few integer variables.

# Code
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

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0152/)