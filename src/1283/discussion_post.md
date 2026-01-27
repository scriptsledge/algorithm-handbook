# 🏷️ Smallest Divisor | Binary Search on Answer | O(N log(max_val))

# Intuition
The problem asks for the *smallest* divisor that satisfies a condition. Notice the monotonicity:
- As the **divisor increases**, the **sum decreases**.
- As the **divisor decreases**, the **sum increases**.

This property is a classic hint for **Binary Search on the Answer**. Instead of searching through the array, we search through the range of possible divisors.

# Approach
1.  **Identify Search Range:** 
    *   Minimum divisor: `1` (results in the largest possible sum).
    *   Maximum divisor: `max(nums)` (results in the smallest possible sum, which is `nums.length`).
2.  **Binary Search:**
    *   Calculate `mid` divisor.
    *   Compute the sum of `ceil(nums[i] / mid)`.
    *   If `sum <= threshold`: This divisor works! But there might be a smaller one. Store it and search the left half.
    *   If `sum > threshold`: This divisor is too small (the sum is too high). Search the right half.
3.  **Ceil Division:** Use the formula `(a + b - 1) / b` to compute `ceil(a / b)` efficiently without floating-point math.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/Shj_IYAHxXk)

# Complexity
*   **Time complexity:** $$O(N \log(\max(\text{nums})))$$ 
    Where $N$ is the number of elements in `nums`. We perform binary search over the range $[1, 10^6]$, and for each step, we iterate through the array.
*   **Space complexity:** $$O(1)$$
    We only use a few variables for the search.

# Code
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

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/1283/)