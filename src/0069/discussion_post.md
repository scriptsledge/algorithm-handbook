# O(log X) Binary Search | Prevent Overflow | Concise C++

# Intuition
The square root of $x$ is the largest integer $k$ such that $k^2 \le x$. Since $k^2$ is monotonically increasing, we can use binary search to find this value efficiently.

# Approach
1. Set `low = 0` and `high = x`.
2. Perform binary search in the range $[0, x]$.
3. Use `1LL * mid * mid` to avoid integer overflow during comparison.
4. If `mid * mid <= x`, move `low` to `mid + 1` to search for a larger value.
5. Otherwise, move `high` to `mid - 1`.
6. Return `high` as the result.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/e4VhcH_7DWE)

# Complexity
*   **Time complexity:** $O(\log X)$
*   **Space complexity:** $O(1)$

# Code
```cpp
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (1LL * mid * mid <= x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0069/)