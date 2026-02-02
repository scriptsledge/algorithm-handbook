# O(N) Solution | One Pass | Minimal Space | Step-by-Step Explanation

# 📌 Problem Summary
Find the maximum difference `nums[j] - nums[i]` such that:
- `0 <= i < j < n` (valid indices)
- `nums[i] < nums[j]` (strictly increasing)
- Return `-1` if no such pair exists.

# 🧠 Intuition
### Initial Idea: Two-Pointer Greediness
I first tried a two-pointer approach (start at both ends, move inward based on values). It failed because it skipped valid pairs. For example, in `[87,68,91,86,58,63,43,98,6,40]`, it incorrectly returned `92` (`98-6`) even though `6` comes *after* `98`.

### Key Insight: Track Minimum So Far
The problem’s hint asked:
> *Could you keep track of the minimum element visited while traversing?*

This led to the correct strategy:
> For each `j`, the best `i` is the smallest value before `j`.

# ✅ Approach
1.  **Track `minSoFar`**: The smallest value seen so far while iterating left-to-right.
2.  **Compute `maxDiff`**: At each step, if current value > `minSoFar`, update `maxDiff`.

### Why It Works
-   Ensures `i < j` by updating `minSoFar` before checking differences.
-   Only computes valid differences (`nums[i] < nums[j]`).

# 🧪 Test Cases
### Example 1: `[7,1,5,4]`
- Valid pairs: `1->5` (diff=4)
- **Output**: `4`

### Example 2: `[9,4,3,2]`
- No increasing pairs
- **Output**: `-1`

### Edge Case: All Equal Values `[5,5,5,5]`
- **Output**: `-1`

# 🔄 Design Trade-offs
| Approach | Time | Space | Notes |
| :--- | :--- | :--- | :--- |
| **Two-Pointer (Original)** | O(N) | O(1) | ❌ Incorrect logic |
| **Brute Force** | O(N^2) | O(1) | ✅ Simple, but slow |
| **Single-Pass Optimized** | O(N) | O(1) | ✅ Best balance |

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/RhvvEQWdrXY)

# Complexity
*   **Time complexity:** $$O(N)$$
    We traverse the array exactly once.
*   **Space complexity:** $$O(1)$$
    We only use a few variables to store the minimum seen so far and the maximum difference.

# Code
```cpp
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        // Initialize minSoFar with the first element
        int minSoFar = nums[0];
        // Default result if no valid pair is found
        int maxDiff = -1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > minSoFar) {
                // Found a larger element after minSoFar, calculate potential result
                maxDiff = max(maxDiff, nums[i] - minSoFar);
            } else {
                // Found a new minimum, update it for future pairs
                minSoFar = nums[i];
            }
        }

        return maxDiff;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/2016/)