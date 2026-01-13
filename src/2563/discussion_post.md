# Count the Number of Fair Pairs
<!-- C++ | O(N log N) Solution | Sorting + Binary Search -->

# Intuition
The problem asks to find pairs with a sum in a specific range. Brute force is too slow. Sorting allows us to use binary search to efficiently find the range of valid partners for each number.

# Approach
1. Sort the input array.
2. For each element `nums[i]`, use binary search (`lower_bound` and `upper_bound`) to find the range of elements `nums[j]` (where `j > i`) that satisfy the condition `lower <= nums[i] + nums[j] <= upper`.
3. The count of such elements is the difference between the two binary search iterators.
4. Total complexity is $O(N \log N)$.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/v0hsuMQVeBk)

# Complexity
*   **Time complexity:** $O(N \log N)$
    *   Sorting takes $O(N \log N)$.
    *   Iterating through the array with binary search takes $O(N \log N)$.
*   **Space complexity:** $O(1)$
    *   We use constant extra space (ignoring sorting overhead).

# Code
```cpp
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            auto lb =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto ub =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            count += ub - lb;
        }
        return count;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/2563/)