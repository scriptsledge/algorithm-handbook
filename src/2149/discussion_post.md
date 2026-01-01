# 🚀 Intuition
The problem requires alternating positive and negative numbers while **preserving their relative order**. This constraint suggests that we cannot swap elements arbitrarily in-place without complex rotation logic. The most direct and stable approach is to construct a new array where we place elements into their pre-determined positions.

# 💡 Approach
Since the result array must alternate `[+, -, +, -, ...]`:
*   **Positive** numbers will always occupy indices `0, 2, 4, ...`
*   **Negative** numbers will always occupy indices `1, 3, 5, ...`

We can solve this in a single pass using the **Two-Pointer** technique:
1.  Initialize `pos` at `0` and `neg` at `1`.
2.  Iterate through the input array `nums`.
3.  If the number is positive, place it at `ans[pos]` and increment `pos` by 2.
4.  If the number is negative, place it at `ans[neg]` and increment `neg` by 2.

This ensures stability and $O(N)$ efficiency.

# 🎥 Video Explanation
[**Watch the quick walkthrough on YouTube**](https://youtube.com/shorts/c-BjOSH3xms)

# 💻 Complexity
*   **Time complexity:** $$O(N)$$
    We traverse the array exactly once.
*   **Space complexity:** $$O(N)$$
    Used for the result array. (Note: an in-place $O(1)$ space solution that preserves order is significantly more complex and slower due to array shifting).

# 👨‍💻 Code
```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int posIndex = 0, negIndex = 1;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                ans[posIndex] = nums[i];
                posIndex += 2;
            } else {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;
    }
};
```

---
**Connect & Follow:**
*   📘 **Algorithm Handbook:** [Source Code & Docs](https://github.com/scriptsledge/algorithm-handbook/tree/main/src/2149)
*   💡 **LeetCode Solution:** [View on LeetCode](https://leetcode.com/problems/rearrange-array-elements-by-sign/solutions/7455816/c-on-time-two-pointers-clean-intuitive-s-xsav)
