# 🏷️ LeetCode Submission Title
C++ | Gauss Summation | O(N) Time | O(1) Space | Simple & Mathematical

# Intuition
The problem asks us to find a single missing number in a known range $[0, n]$. 

Instead of searching for the number or using extra memory (like a Hash Set), we can treat this as a **checksum** problem. We know exactly what the sum of all numbers from $0$ to $n$ *should* be. By comparing that "Expected Sum" with the "Actual Sum" of the array, the difference must be the missing value.

# Approach
1.  **Calculate Expected Sum:** Use the Gauss Summation formula: $\text{Sum} = \frac{n(n+1)}{2}$.
2.  **Calculate Actual Sum:** Traverse the array once and sum all elements.
3.  **Find the Difference:** The missing number is simply `expectedSum - actualSum`.

This approach is optimal because it requires only a single pass and no auxiliary data structures.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/xcK5Nmbe8EY)

# Complexity
*   **Time complexity:** $$O(N)$$
    We traverse the array exactly once to calculate the sum.
*   **Space complexity:** $$O(1)$$
    We only store two integer variables (`expectedSum` and `actualSum`).

# Code
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

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0268/)