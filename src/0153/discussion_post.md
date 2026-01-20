# C++ | O(log N) | Binary Search | Step-by-Step Visualization

# Intuition
The array is sorted but rotated, which means it consists of two sorted subarrays. The minimum element is the pivot point where the rotation happened. Since it's derived from a sorted array, we can use Binary Search to find this element in logarithmic time.

# Approach
1. Use two pointers, `low` and `high`, to perform binary search.
2. At each step, calculate `mid`.
3. Check if the right half `[mid, high]` is sorted by comparing `nums[mid]` and `nums[high]`.
4. If it is sorted, `nums[mid]` is a candidate for the minimum. Store it and search the left half.
5. If it is not sorted, the left half `[low, mid]` must be sorted. `nums[low]` is a candidate for the minimum. Store it and search the right half.
6. Continue until `low > high`.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/vkfP6mTvT_0)

# Complexity
*   **Time complexity:** $O(\log N)$
    Binary search reduces the search space by half each time.
*   **Space complexity:** $O(1)$
    Only a constant amount of extra space is used.

# Code
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int minEle = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= nums[high]) {
                minEle = min(nums[mid], minEle);
                high = mid - 1;
            } else {
                minEle = min(minEle, nums[low]);
                low = mid + 1;
            }
        }
        return minEle;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0153/)