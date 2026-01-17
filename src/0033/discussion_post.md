# 0033. Search in Rotated Sorted Array
<!-- C++ | O(log N) Solution | Modified Binary Search -->

# Intuition
The key insight for this problem is that even after rotation, at least one half of the array (either `[left, mid]` or `[mid, right]`) will always be sorted. We can use this property to perform a Binary Search by checking if the target falls within the sorted half.

# Approach
1.  Initialize `left` and `right` pointers to the start and end of the array.
2.  While `left <= right`:
    -   Calculate `mid`.
    -   If `nums[mid]` is the target, return `mid`.
    -   Check if the left half `[left, mid]` is sorted (`nums[left] <= nums[mid]`).
        -   If sorted, check if `target` is within `[nums[left], nums[mid])`. If so, search left; otherwise, search right.
    -   Otherwise, the right half `[mid, right]` must be sorted.
        -   Check if `target` is within `(nums[mid], nums[right]]`. If so, search right; otherwise, search left.
3.  If not found, return -1.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/ea-sqI523rY)

# Complexity
*   **Time complexity:** $O(\log N)$
    - Binary search halves the search space at each step.
*   **Space complexity:** $O(1)$
    - Constant extra space is used.

# Code
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0033/)