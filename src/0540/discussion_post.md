# O(log N) Binary Search | Even-Index Pattern | Clean C++

# Intuition
In a sorted array where all elements except one appear twice, the pairs follow a predictable index pattern. Before the single element, pairs start at even indices. After it, they start at odd indices. Binary search can exploit this pattern break.

# Approach
1. Use binary search pointers `low` and `high`.
2. Calculate `mid` and adjust it to always be an even index (`mid -= mid % 2`).
3. Compare `nums[mid]` with `nums[mid + 1]`.
4. If they match, the single element is to the right (`low = mid + 2`).
5. If they don't match, it's to the left or at `mid` (`high = mid`).
6. Return `nums[low]`.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/KUj96Ovg6bU)

# Complexity
*   **Time complexity:** $O(\log N)$
*   **Space complexity:** $O(1)$

# Code
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 1) mid--;
            if (nums[mid] == nums[mid + 1]) low = mid + 2;
            else high = mid;
        }
        return nums[low];
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0540/)