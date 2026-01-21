# O(log N) Binary Search | Slope Analysis | Visual Intuition

# Intuition
To find a peak element in $O(\log N)$ time, we need a way to discard half of the search space at each step. By comparing an element with its neighbor, we can determine the "slope" and move toward the peak.

# Approach
1. Use binary search pointers `low` and `high`.
2. Compare `nums[mid]` with `nums[mid + 1]`.
3. If `nums[mid]` is smaller, we are on an upward slope; move `low = mid + 1`.
4. Otherwise, we are on a downward slope or at a peak; move `high = mid`.
5. The convergence point `low` is a peak.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/__cbZP0ms3E)

# Complexity
*   **Time complexity:** $O(\log N)$
*   **Space complexity:** $O(1)$

# Code
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[mid + 1])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0162/)