# O(log N) Binary Search | Finding the Gap | Step-by-Step Explanation

# Intuition
The core idea is to determine how many positive integers are missing *before* any given index in the sorted array. If we know the count of missing numbers at each step, we can use binary search to pinpoint exactly where the $k^{th}$ missing number should reside.

# Approach
1.  **Count Missing Numbers:** For an element at `arr[i]`, if no numbers were missing, its value would be `i + 1` (since the array is 1-indexed for positive integers). Therefore, the number of missing integers before index `i` is `arr[i] - (i + 1)`.
2.  **Binary Search:** We search for the first index `left` where the number of missing integers is at least `k`.
    *   If `missingCount < k`, it means the $k^{th}$ missing number is further to the right.
    *   Otherwise, it's to the left or could be this index itself.
3.  **Final Calculation:** After the search, `left` is the smallest index such that the number of missing integers before it is $\ge k$. The $k^{th}$ missing number can be calculated as `left + k`.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/uubPI0vBlCU)

# Complexity
*   **Time complexity:** $O(\log N)$
    We are performing a binary search over the array of size $N$.
*   **Space complexity:** $O(1)$
    We only use a few variables for the search boundaries.

# Code
```cpp
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] - mid - 1 < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left + k;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/1539/)