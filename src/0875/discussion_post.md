# O(N log M) Binary Search | Answer Space | Overflow Handling

# Intuition
The problem asks for the minimum eating speed $k$. The time required to eat all bananas is inversely proportional to $k$. This monotonic property suggests we can binary search for the optimal $k$ in the range $[1, \max(\text{piles})]$.

# Approach
1. Set `low = 1` and `high = max(piles)`.
2. Binary search for $k$:
   - For a given `mid` speed, calculate the total hours needed.
   - Use `(pile + mid - 1) / mid` for integer ceiling division.
   - Accumulate hours in `long long` to prevent overflow.
   - If total hours $\le h$, this speed is valid; try slower (`high = mid - 1`).
   - Otherwise, speed is too slow; try faster (`low = mid + 1`).
3. Return `low`.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/Aejd-PzcCLs)

# Complexity
*   **Time complexity:** $O(N \log M)$ where $M$ is the max pile size.
*   **Space complexity:** $O(1)$

# Code
```cpp
class Solution {
public:
    long long rqTimeF(vector<int>& arr, int k) {
        long long rqTime = 0;
        for (int i = 0; i < arr.size(); i++) {
            rqTime += ((long long)arr[i] + k - 1) / k;
        }
        return rqTime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (rqTimeF(piles, mid) <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0875/)

```