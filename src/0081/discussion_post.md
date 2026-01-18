# 81. Search in Rotated Sorted Array II
<!-- C++ | O(N) Worst Case | Binary Search -->

# Intuition
The problem is a variation of searching in a rotated sorted array. The key challenge is handling duplicates, which can make it ambiguous to determine which half of the array is sorted.

# Approach
We use a modified binary search.
1.  Check if `nums[mid]` is the target.
2.  Handle the duplicate case `nums[left] == nums[mid] == nums[right]` by shrinking the search window (`left++`, `right--`). This is the only scenario that degrades the time complexity.
3.  Identify the sorted half (either left or right) and check if the target lies within that range to adjust pointers accordingly.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/HcrrB-Xtg8Q)

# Complexity
*   **Time complexity:** $$O(\log N)$$ average, $$O(N)$$ worst case.
    The worst case occurs when all elements are duplicates, requiring linear scanning.
*   **Space complexity:** $$O(1)$$
    We use constant extra space.

# Code
```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};
```

---

**Algorithm Handbook:**

[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0081/)



**LeetCode Solution:**

[Read the Post](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/solutions/7504755/c-on-worst-case-binary-search-81-search-qcaie)
