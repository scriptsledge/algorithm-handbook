# 🚀 Intuition
The problem asks for the maximum value of `(nums[i] - nums[j]) * nums[k]` where `i < j < k`. A brute-force approach would check every triplet, taking $O(N^3)$ time, which is too slow for $N=10^5$. 

We need to optimize the selection of `i` and `k` for a fixed `j`. To maximize the expression `(nums[i] - nums[j]) * nums[k]`, we want:
1.  `nums[i]` to be as **large** as possible (where `i < j`).
2.  `nums[k]` to be as **large** as possible (where `k > j`).

This suggests that for any middle element `nums[j]`, we just need to know the maximum value to its left (`prefixMax`) and the maximum value to its right (`suffixMax`).

# 💡 Approach
1.  **Precompute Prefix Max:** Create an array `prefixMax` where `prefixMax[i]` stores the maximum value in `nums[0...i]`. This allows us to instantly retrieve the maximum possible `nums[i]` for any `j` by looking at `prefixMax[j-1]`.
2.  **Precompute Suffix Max:** Create an array `suffixMax` where `suffixMax[i]` stores the maximum value in `nums[i...n-1]`. This allows us to instantly retrieve the maximum possible `nums[k]` for any `j` by looking at `suffixMax[j+1]`.
3.  **Iterate and Calculate:** Loop through every possible middle index `j` from `1` to `n-2`.
    *   Calculate `current_value = (prefixMax[j-1] - nums[j]) * suffixMax[j+1]`.
    *   Update our global `maxValue`.
4.  **Handle Negatives:** Since the problem requires returning 0 if the maximum triplet value is negative, initialize `maxValue` to 0.

# 🎥 Video Explanation
[**Watch the quick walkthrough on YouTube**](https://youtube.com/shorts/TRbzjm3yej0)

# 💻 Complexity
*   **Time complexity:** $$O(N)$$
    We traverse the array three times (prefix, suffix, and final calculation), which is linear.
*   **Space complexity:** $$O(N)$$
    We use two auxiliary arrays (`prefixMax` and `suffixMax`) of size $N$.

# 👨‍💻 Code
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

---
**Connect & Follow:**
*   📘 **Algorithm Handbook:** [Source Code & Docs](https://github.com/scriptsledge/algorithm-handbook/tree/main/src/2874)