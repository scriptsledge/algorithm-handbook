# 🏷️ LeetCode Submission Title
C++ | Two Pointers (Reverse) | O(M+N) Time | O(1) Space

# Intuition
The problem asks us to merge two sorted arrays into `nums1`, which has enough space at the end to hold `nums2`.

A naive approach would be to insert elements from `nums2` into `nums1` and shift the rest, but that would be $O(N \cdot M)$.
We could copy `nums2` into `nums1` and then sort, but that costs $O((M+N) \log (M+N))$.

The constraint is doing this **in-place** efficiently.
Since the "empty" space is at the *end* of `nums1`, why not fill the array from the *back*? This avoids overwriting elements we haven't processed yet.

# Approach
1.  **Initialize Pointers:**
    *   `p1` points to the last valid element of `nums1` (`m - 1`).
    *   `p2` points to the last element of `nums2` (`n - 1`).
    *   `p` points to the last index of the merged array (`m + n - 1`).

2.  **Reverse Merge:**
    *   Compare `nums1[p1]` and `nums2[p2]`.
    *   Place the larger element at `nums1[p]` and decrement the corresponding pointer.
    *   Repeat until one of the arrays is exhausted.

3.  **Cleanup:**
    *   If `nums2` still has elements left (because they were smaller than everything in `nums1`), copy them into the remaining spots in `nums1`.
    *   If `nums1` has elements left, we don't need to do anything—they are already in their correct sorted position.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/MSFm9bfnE0c)

# Complexity
*   **Time complexity:** $$O(M + N)$$
    We process each element exactly once.
*   **Space complexity:** $$O(1)$$
    We modify `nums1` in-place without using extra auxiliary space.

# Code
```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p--] = nums1[p1--];
            } else {
                nums1[p--] = nums2[p2--];
            }
        }
        
        while (p2 >= 0) {
            nums1[p--] = nums2[p2--];
        }
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0088/)