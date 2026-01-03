# 🏷️ LeetCode Submission Title
C++ | Kadane's Algorithm | O(N) Time | O(1) Space | Simple & Clean

# 🚀 Intuition
The problem asks for the contiguous subarray with the largest sum. A brute-force approach would check every possible subarray, taking $O(N^2)$ or $O(N^3)$. We need something faster.

Think of this as a "gambler's fallacy" or "financial streak":
*   If your current running sum becomes **negative**, it is a "burden."
*   Any future subarray would be better off **starting fresh** than carrying that negative debt.
*   Therefore, whenever our current sum drops below zero, we reset it to 0.

# 💡 Approach
This is the classic **Kadane's Algorithm**:
1.  Initialize `sum = 0` and `max_sum` to the first element (to handle all-negative arrays).
2.  Iterate through the array:
    *   Add the current number to `sum`.
    *   Update `max_sum` if the current `sum` is greater.
    *   **Crucial Step:** If `sum` becomes negative, reset `sum` to 0. We essentially discard the current subarray and start a new one from the next element.

# 🎥 Video Explanation
[**Watch the quick walkthrough on YouTube**](https://youtube.com/shorts/ujSbHn855So)

# 💻 Complexity
*   **Time complexity:** $$O(N)$$
    We traverse the array exactly once.
*   **Space complexity:** $$O(1)$$
    We only use two variables (`sum` and `max_sum`) regardless of the input size.

# 👨‍💻 Code
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int sum = 0;
        
        for (int num : nums) {
            sum += num;
            max_sum = max(max_sum, sum);
            if (sum < 0) {
                sum = 0; // Reset "debt"
            }
        }
        
        return max_sum;
    }
};
```

---
**Connect & Follow:**
*   📘 **Algorithm Handbook:** [Source Code & Docs](https://github.com/scriptsledge/algorithm-handbook/tree/main/src/0053)