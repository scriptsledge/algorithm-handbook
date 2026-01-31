# O(N) Solution | Bitwise Optimization | Step-by-Step Analysis

## Problem Statement

Given a string `s` consisting of lowercase English letters, find the maximum difference `diff = a1 - a2` where:
- `a1` has an odd frequency in the string
- `a2` has an even frequency in the string

**Constraints:**
- `3 <= s.length <= 100`
- `s` consists only of lowercase English letters
- At least one character has odd frequency and one has even frequency

## Initial Approach and Analysis

The problem requires tracking character frequencies and identifying the maximum odd frequency and minimum even frequency. My initial approach involved:

1. Count frequency of each character
2. Separate frequencies into odd and even categories
3. Find maximum among odd frequencies and minimum among even frequencies
4. Return their difference

## Implementation Evolution

### First Implementation Issues

My initial logic contained flaws in how the minimum value was initialized and updated:

```cpp
// Problematic logic
if (a2 == 0)
    a2 = freq;
a2 = min(a2, freq); // Always executes, negating above check
```

This pattern incorrectly handled the initialization. The second assignment always executed, effectively ignoring the initialization check.

### Refinement Process

**Issue 1: Incorrect Min/Max Tracking**
- Problem: Separate initialization checks followed by unconditional updates.
- Solution: Initialize with `INT_MAX` and `INT_MIN` (or 0) and use combined condition checks.

**Issue 2: Data Structure Overhead**
- Problem: Using `std::map` or `std::unordered_map` adds unnecessary hashing and dynamic allocation overhead.
- Solution: Use a fixed-size `vector` or array of size 26.

**Issue 3: Suboptimal Operations**
- Problem: Frequent use of `min/max` functions and modulo `%` operators.
- Solution: Direct comparisons and bitwise parity checking.

## Technical Design Decisions

### Data Structure Selection

**Array vs Hash Map Trade-off:**
- **Array (Vector):** O(26) = O(1) space, cache-friendly, no hashing overhead.
- **Hash Map:** O(k) space, dynamic sizing but higher constant factor time complexity.

Given the constraint of lowercase English letters only, a fixed-size array provides optimal performance.

### Bitwise Optimization

**Parity Check Enhancement:**
```cpp
// Standard modulo operation
if (freq % 2 != 0)

// Bitwise operation
if (freq & 1)
```

Bitwise AND operation is generally more efficient than modulo for parity checking.

## Complexity Analysis

### Time Complexity: O(N)
- Character frequency counting: O(N)
- Frequency array traversal: O(26) = O(1)
- Overall: O(N)

### Space Complexity: O(1)
- Fixed-size frequency array: O(26) = O(1)
- No additional data structures scale with input size.

## Final Optimized Solution

```cpp
class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        
        // Count character frequencies
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        
        // Find maximum odd and minimum even frequencies
        for (int f : freq) {
            if (f > 0) {
                if (f & 1) {
                    if (f > maxOdd) maxOdd = f;
                } else {
                    if (f < minEven) minEven = f;
                }
            }
        }
        
        return maxOdd - minEven;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/3442/)
