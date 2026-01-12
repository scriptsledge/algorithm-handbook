# 🏷️ 35. Search Insert Position
<!-- C++ | O(log N) Solution | Binary Search | Clean & Efficient -->

# Intuition
Since the array is sorted and we need $O(\log N)$ time complexity, binary search is the natural choice. We are looking for the smallest index `i` such that `nums[i] >= target`. If no such element exists, the insertion point is at the end of the array.

# Approach
1. Initialize `low = 0` and `high = nums.size() - 1`.
2. Initialize `pos = nums.size()` to handle the case where the target is greater than all elements.
3. Use a binary search loop:
   - Calculate `mid`.
   - If `nums[mid] >= target`, it means `mid` is a valid insertion position. We store it in `pos` and try to find an even smaller index in the left half (`high = mid - 1`).
   - If `nums[mid] < target`, we must look in the right half (`low = mid + 1`).
4. Return `pos`.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/4gcUIq43Hv4)

# Complexity
*   **Time complexity:** $O(\log N)$
    We halve the search space in each iteration of the binary search.
*   **Space complexity:** $O(1)$
    We only use a few integer variables.

# Code
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int pos = nums.size();
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] >= target) {
                pos = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return pos;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0035/)