# 🏷️ LeetCode Submission Title
C++ | Unordered Set | O(N) Time | O(N) Space | Simple & Intuitive

# Intuition
The problem allows us to reduce elements strictly greater than a value $h$ to $h$, but only if all elements currently greater than $h$ are identical. This is a "top-down" reduction constraint. 

Effectively, this means we can only eliminate the current maximum unique value in the array by setting it to a value equal to (or greater than) the next largest unique value. To reach the target $k$, we must perform one operation for every unique value that exists between the maximum element and $k$.

# Approach
1.  **Check Feasibility:** Iterate through the array. If any number $n < k$, return $-1$.
2.  **Count Unique Targets:** For every number $n > k$, add it to an `unordered_set`. The set will automatically handle duplicates, leaving us with only the unique values that need to be processed.
3.  **Result:** The number of operations is simply the size of the set.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/nh-EGn7PdYg)

# Complexity
*   **Time complexity:** $$O(N)$$
    We traverse the array once to populate the set. Set insertions are $O(1)$ on average.
*   **Space complexity:** $$O(N)$$
    In the worst case, all elements are unique and greater than $k$, requiring $O(N)$ space in the set.

# Code
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> aboveK;

        for (int n : nums) {
            if (n < k) return -1;
            if (n > k) aboveK.insert(n);
        }

        return aboveK.size();
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/3375/)