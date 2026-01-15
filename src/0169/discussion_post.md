# 169. Majority Element | Boyer-Moore Voting Algorithm
<!-- C++ | O(N) Solution | O(1) Space -->

# Intuition
The problem asks for an element appearing more than $N/2$ times. Sorting or HashMaps work in $O(N \log N)$ or $O(N)$ space respectively. However, the optimal approach is to treat this as a "voting" process where the majority candidate survives cancellations.

# Approach
**Boyer-Moore Voting Algorithm**:
1.  Initialize `candidate` and `count = 0`.
2.  Iterate through `nums`:
    *   If `count == 0`, update `candidate = num`.
    *   If `num == candidate`, `count++`.
    *   Else `count--`.
3.  The final `candidate` is the answer.

This works because the majority element has more than $N/2$ occurrences, so even if it is cancelled out by every other element 1-to-1, it will still have counts remaining.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/2wR39Vnqzb4)

# Complexity
*   **Time complexity:** $$O(N)$$
    Single pass through the array.
*   **Space complexity:** $$O(1)$$
    Uses only two integer variables.

# Code
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0169/)