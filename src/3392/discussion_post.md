# 3392. Count Subarrays of Length Three With a Condition
<!-- C++ | O(N) | Simple Window Check -->

# Intuition
The problem requires checking every window of size 3 in the array. Given the small constraints, a single pass is sufficient.

# Approach
1.  Iterate through the array from `0` to `n-3`.
2.  For each window `(first, second, third)`, check if `2 * (first + third) == second`. 
3.  Using multiplication instead of division by 2 avoids potential floating-point precision issues and correctly handles odd middle numbers (since half of an odd number would not be an integer).

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/mqfaMGXhPJY)

# Complexity
*   **Time complexity:** $$O(N)$$
*   **Space complexity:** $$O(1)$$

# Code
```cpp
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i <= (int)nums.size() - 3; ++i) {
            if (2 * (nums[i] + nums[i+2]) == nums[i+1]) {
                count++;
            }
        }
        return count;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/3392/)