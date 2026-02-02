# O(N) Solution | One Pass | Minimal Space | Step-by-Step Explanation

# Intuition
The problem asks for the maximum difference `nums[j] - nums[i]` where `i < j` and `nums[i] < nums[j]`. This is very similar to the "Best Time to Buy and Sell Stock" problem. To maximize the difference, we want to subtract the smallest possible value seen before the current element.

# Approach
1.  Initialize `minSoFar` with the first element of the array.
2.  Initialize `maxDiff` to `-1` to handle cases where no such pair exists.
3.  Iterate through the array starting from the second element:
    - If the current element `nums[i]` is greater than `minSoFar`, update `maxDiff` with `max(maxDiff, nums[i] - minSoFar)`.
    - If the current element is smaller than `minSoFar`, update `minSoFar` to `nums[i]`.
4.  Return `maxDiff`.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/RhvvEQWdrXY)

# Complexity
*   **Time complexity:** $O(N)$
    We traverse the array exactly once.
*   **Space complexity:** $O(1)$
    We only use a few variables to store the minimum seen so far and the maximum difference.

# Code
```cpp
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minSoFar = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > minSoFar) {
                maxDiff = max(maxDiff, nums[i] - minSoFar);
            } else {
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