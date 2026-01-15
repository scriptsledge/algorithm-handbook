# 1399. Count Largest Group | Frequency Map of Digit Sums
<!-- C++ | O(N log N) Solution | Clean & Efficient -->

# Intuition
The problem asks to group numbers by their digit sums. Since the range of $n$ is small (up to $10^4$), the maximum digit sum is also small (36 for 9999). This suggests using a frequency map to count how many numbers fall into each digit sum group.

# Approach
1. Iterate from 1 to $n$.
2. For each number, compute the sum of its digits.
3. Increment the frequency of that digit sum in a map or array.
4. Find the maximum frequency in the map.
5. Count how many groups have this maximum frequency.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/7WDydCn4TvI)

# Complexity
*   **Time complexity:** $$O(N \log_{10} N)$$
    Iterating from 1 to $N$, and for each number calculating digit sum.
*   **Space complexity:** $$O(\text{max\_digit\_sum})$$
    Storing counts for each possible digit sum (max 36 for $N=10^4$).

# Code
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

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/1399/)

```