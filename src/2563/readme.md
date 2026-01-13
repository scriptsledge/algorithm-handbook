# 2563. Count the Number of Fair Pairs

## Problem Description

Given a 0-indexed integer array `nums` of size `n` and two integers `lower` and `upper`, return the number of fair pairs.

A pair `(i, j)` is fair if:
- `0 <= i < j < n`, and
- `lower <= nums[i] + nums[j] <= upper`

### Examples

**Example 1:**
- **Input:** `nums = [0,1,7,4,4,5]`, `lower = 3`, `upper = 6`
- **Output:** `6`
- **Explanation:** There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

**Example 2:**
- **Input:** `nums = [1,7,9,2,5]`, `lower = 11`, `upper = 11`
- **Output:** `1`
- **Explanation:** There is a single fair pair: (2,3).

### Constraints

- `1 <= nums.length <= 10^5`
- `nums.length == n`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= lower <= upper <= 10^9`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

The problem asks for the number of pairs `(i, j)` such that `0 <= i < j < n` and `lower <= nums[i] + nums[j] <= upper`.

1. **Sorting**: First, we sort the array `nums`. Sorting does not change the set of possible sums of pairs, and it allows us to use binary search.
2. **Binary Search**: For each element `nums[i]`, we need to find the number of elements `nums[j]` (where `j > i`) such that:
   - `nums[j] >= lower - nums[i]`
   - `nums[j] <= upper - nums[i]`
3. We can use `std::lower_bound` to find the first element that is at least `lower - nums[i]` and `std::upper_bound` to find the first element that is strictly greater than `upper - nums[i]`.
4. The number of such elements is the distance between these two iterators.

### Code

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