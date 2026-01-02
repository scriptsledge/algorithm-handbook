# 2874. Maximum Value of an Ordered Triplet II

## Problem Description

You are given a 0-indexed integer array `nums`.

Return the **maximum value** over all triplets of indices `(i, j, k)` such that `i < j < k`. If all such triplets have a negative value, return `0`.

The value of a triplet of indices `(i, j, k)` is equal to `(nums[i] - nums[j]) * nums[k]`.

### Examples

**Example 1:**
```text
Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77.
```

**Example 2:**
```text
Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
```

**Example 3:**
```text
Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
```

### Constraints
*   `3 <= nums.length <= 10^5`
*   `1 <= nums[i] <= 10^6`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

The problem asks us to maximize `(nums[i] - nums[j]) * nums[k]` with the constraint `i < j < k`. A naive approach would be to iterate through all possible triplets, which would take $O(N^3)$ time. Given the constraint $N \le 10^5$, we need an $O(N)$ approach.

By fixing the middle element `nums[j]`, the problem reduces to finding the maximum `nums[i]` to the left of `j` and the maximum `nums[k]` to the right of `j`. If we can access these maximums in $O(1)$ time, we can solve the entire problem in $O(N)$.

We use **Prefix Max** and **Suffix Max** arrays:
1.  **Prefix Max:** Create an array `prefixMax` where `prefixMax[i]` is the maximum value in `nums[0...i]`.
2.  **Suffix Max:** Create an array `suffixMax` where `suffixMax[i]` is the maximum value in `nums[i...n-1]`.
3.  **Iterate:** For each index `j` from `1` to `n-2`:
    *   The max value to the left is `prefixMax[j-1]`.
    *   The max value to the right is `suffixMax[j+1]`.
    *   Calculate the triplet value: `(prefixMax[j-1] - nums[j]) * suffixMax[j+1]`.
    *   Update the global maximum.

### Code

```cpp
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<int> prefixMax(n, 0), suffixMax(n, 0);
        prefixMax[0] = nums[0];

        // Compute prefix max
        for (int i = 1; i < n; i++)
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);

        // Compute suffix max
        suffixMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffixMax[i] = max(suffixMax[i + 1], nums[i]);

        long long maxValue = 0;

        // Iterate through j to find max (prefixMax[i] - nums[j]) * suffixMax[k]
        for (int j = 1; j < n - 1; j++) {
            long long left = prefixMax[j - 1] - (long long)nums[j];
            long long right = suffixMax[j + 1];
            maxValue = max(maxValue, left * right);
        }

        return maxValue;
    }
};
```
