# O(N log D) Binary Search | Answer Space | Clean C++

# Intuition
The problem asks for the minimum number of days to form $m$ bouquets of $k$ adjacent flowers. Since waiting longer only increases the number of available flowers, the condition is monotonic. This allows us to binary search on the number of days.

# Approach
1. Handle the edge case: If $m \times k > n$, return -1.
2. Define the search space for days: `low = min_element`, `high = max_element`.
3. Binary search for the minimum days:
   - For a given `mid` day, count how many bouquets can be formed using adjacent bloomed flowers.
   - If bouquets $\ge m$, it's possible; try a smaller number of days (`high = mid - 1`).
   - Otherwise, we need more days (`low = mid + 1`).
4. Return the minimum valid day found.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/K6E2-lh9lfk)

# Complexity
*   **Time complexity:** $O(N \log D)$ where $D$ is the range of bloom days.
*   **Space complexity:** $O(1)$

# Code
```cpp
class Solution {
public:
    bool isPosible(vector<int>& arr, int m, int k, int day) {
        int cnt = 0, bouquet = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) cnt++;
            else {
                bouquet += (cnt / k);
                cnt = 0;
            }
        }
        bouquet += (cnt / k);
        return bouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL * m * k > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPosible(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/1482/)

```