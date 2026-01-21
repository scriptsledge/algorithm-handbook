# O(N) Range-Based Solution | Clean & Efficient

# Intuition
The goal is to count numbers with an even number of digits. Given that the values are at most $10^5$, we can pre-identify the ranges that contain an even number of digits (10-99, 1000-9999, 100000) and check each number against these ranges.

# Approach
1. Initialize a counter.
2. For each number in the input:
   - If it's between 10 and 99 (2 digits), increment counter.
   - If it's between 1000 and 9999 (4 digits), increment counter.
   - If it's exactly 100000 (6 digits), increment counter.
3. Return the counter.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/aqOEOBKOtvw)

# Complexity
*   **Time complexity:** $O(N)$
    - We iterate through the array once.
*   **Space complexity:** $O(1)$
    - We only use a constant amount of extra space.

# Code
```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto num : nums) {
            if ((num > 9 && num < 100) || (num > 999 && num < 10000) || num == 100000) {
                count++;
            }
        }
        return count;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/1295/)