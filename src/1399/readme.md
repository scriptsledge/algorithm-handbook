# 1399. Count Largest Group

## Problem Description

You are given an integer `n`.

We need to group the numbers from `1` to `n` according to the sum of its digits. For example, the numbers `14` and `5` belong to the same group, whereas `13` and `3` belong to different groups.

Return the number of groups that have the largest size, i.e. the maximum number of elements.

### Examples

**Example 1:**

Input: `n = 13`
Output: `4`
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.

**Example 2:**

Input: `n = 2`
Output: `2`
Explanation: There are 2 groups [1], [2] of size 1.

### Constraints

- `1 <= n <= 10^4`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

1. Iterate through all numbers from `1` to `n`.
2. For each number, calculate the sum of its digits.
3. Use a hash map (or a frequency array) to store the count of numbers for each digit sum.
4. Find the maximum frequency among all digit sums.
5. Count how many digit sums have this maximum frequency.
6. Return the count.

### Code

```cpp
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> digitSumFreq;

        for (int num = 1; num <= n; num++) {
            int sum = 0, temp = num;

            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            digitSumFreq[sum]++;
        }

        int maxGroupSize = 0;
        for (auto& entry : digitSumFreq) {
            maxGroupSize = max(maxGroupSize, entry.second);
        }

        int maxGroups = 0;
        for (auto& entry : digitSumFreq) {
            if (entry.second == maxGroupSize)
                maxGroups++;
        }

        return maxGroups;
    }
};
```