# 1295. Find Numbers with Even Number of Digits

## Problem Description

Given an array `nums` of integers, return how many of them contain an **even number of digits**.

### Examples

**Example 1:**
```text
Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
```

**Example 2:**
```text
Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
```

### Constraints
*   `1 <= nums.length <= 500`
*   `1 <= nums[i] <= 10^5`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

To determine if a number has an even number of digits, we can check its value against ranges:
- 2 digits: $10 \le \text{num} \le 99$
- 4 digits: $1000 \le \text{num} \le 9999$
- 6 digits: $100000$ (since the maximum value is $10^5$)

Alternatively, we could convert the number to a string or use $\lfloor \log_{10}(\text{num}) \rfloor + 1$ to count digits. Given the constraints ($1 \le \text{num} \le 10^5$), checking ranges is efficient.

### Code

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto num : nums) {
            if ((num > 9 && num < 100) || (num > 999 && num < 10000) || num == 100000) {
                count++;
            }
        }
        return count;
    }
};
```