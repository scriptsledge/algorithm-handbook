# 🏷️ C++ | Recursive Binary Search | O(log N) | Clean & Efficient

# Intuition
The problem asks for an efficient search in a sorted array. Binary Search is the classic algorithm for this, leveraging the sorted property to eliminate half of the search space at each step.

# Approach
We implement Binary Search using a recursive helper function:
1.  Define a range `[low, high]` (initially `[0, n-1]`).
2.  Calculate the middle index: `mid = low + (high - low) / 2`.
3.  Compare `nums[mid]` with `target`:
    *   If `nums[mid] == target`, we found the index.
    *   If `nums[mid] > target`, search in the left half `[low, mid-1]`.
    *   If `nums[mid] < target`, search in the right half `[mid+1, high]`.
4.  Base case: If `high < low`, the target is not present.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/woWmBQDRbfY)

# Complexity
*   **Time complexity:** $O(\log N)$
    Each recursive call halves the search space.
*   **Space complexity:** $O(\log N)$
    Due to the recursion stack. (Note: Iterative binary search would be $O(1)$).

# Code
```cpp
class Solution {
private:
    int binary_search(vector<int>& arr, int target, int low, int high) {
        if (high < low) {
            return -1;
        }
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) {
            return binary_search(arr, target, low, mid - 1);
        }
        return binary_search(arr, target, mid + 1, high);
    }
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        return binary_search(nums, target, low, high);
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0704/)