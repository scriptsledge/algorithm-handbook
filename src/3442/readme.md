# 3442. Maximum Difference Between Even and Odd Frequency I

## Problem Description

You are given a string `s` consisting of lowercase English letters.

Your task is to find the maximum difference `diff = freq(a1) - freq(a2)` between the frequency of characters `a1` and `a2` in the string such that:
- `a1` has an **odd** frequency in the string.
- `a2` has an **even** frequency in the string.

Return this maximum difference.

### Examples

**Example 1:**
```text
Input: s = "aaaaabbc"
Output: 3
Explanation:
The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
The maximum difference is 5 - 2 = 3.
```

**Example 2:**
```text
Input: s = "abcabcab"
Output: 1
Explanation:
The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
The maximum difference is 3 - 2 = 1.
```

### Constraints
- `3 <= s.length <= 100`
- `s` consists only of lowercase English letters.
- `s` contains at least one character with an odd frequency and one with an even frequency.

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

1.  **Count Frequencies:** Use a frequency array of size 26 to count the occurrences of each character in the string `s`.
2.  **Find Extremes:**
    -   Iterate through the frequency array.
    -   Keep track of the **maximum odd frequency** found so far.
    -   Keep track of the **minimum even frequency** found so far.
3.  **Calculate Difference:** The result is `maxOdd - minEven`.

This approach works because we want to maximize the difference `freq(odd) - freq(even)`. To do this, we should pick the largest possible odd frequency and the smallest possible even frequency.

### Code

```cpp
class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        for (int f : freq) {
            if (f > 0) {
                if (f % 2 != 0) {
                    maxOdd = max(maxOdd, f);
                } else {
                    minEven = min(minEven, f);
                }
            }
        }

        return maxOdd - minEven;
    }
};
```