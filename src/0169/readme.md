# 169. Majority Element

## Problem Description

Given an array `nums` of size `n`, return the majority element.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

### Examples

**Example 1:**

Input: `nums = [3,2,3]`
Output: `3`

**Example 2:**

Input: `nums = [2,2,1,1,1,2,2]`
Output: `2`

### Constraints

- `n == nums.length`
- `1 <= n <= 5 * 10^4`
- `-10^9 <= nums[i] <= 10^9`
- The input is generated such that a majority element will exist in the array.

### Follow-up
Could you solve the problem in linear time and in `O(1)` space?

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use the **Boyer-Moore Voting Algorithm**, which is an optimal strategy to find the majority element in $O(N)$ time and $O(1)$ space.

1.  Initialize a `candidate` and a `count` = 0.
2.  Iterate through the array:
    *   If `count` is 0, set the current number as the `candidate`.
    *   If the current number is the same as `candidate`, increment `count`.
    *   Otherwise, decrement `count`.
3.  The final `candidate` is the majority element (guaranteed by the problem statement).

### Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};
```