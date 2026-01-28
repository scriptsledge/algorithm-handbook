# O(N) Solution | Three Pointers (Dutch National Flag) | One Pass

# Intuition
The problem asks to sort an array of 0s, 1s, and 2s in-place. A simple two-pass approach could count the occurrences of each color and then overwrite the array. However, we can do it in one pass using three pointers.

# Approach
We maintain three pointers:
1. `left`: Next position for `0`.
2. `right`: Next position for `2`.
3. `i`: Current element being scanned.

As we iterate:
- If we see `0`, we swap it with the `left` pointer and move both forward.
- If we see `2`, we swap it with the `right` pointer and move the `right` pointer backward. We don't move `i` because the new element at `i` needs to be checked.
- If we see `1`, we just move `i` forward.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/Dq-waygVwz0)

# Complexity
*   **Time complexity:** $$O(N)$$
    We traverse the array once.
*   **Space complexity:** $$O(1)$$
    Constant extra space used for pointers.

# Code
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int i = 0;
        
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            } else {
                i++;
            }
        }
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0075/)