# 1482. Minimum Number of Days to Make m Bouquets

## Problem Description

You are given an integer array `bloomDay`, an integer `m` and an integer `k`.

You want to make `m` bouquets. To make a bouquet, you need to use `k` **adjacent** flowers from the garden.

The garden consists of `n` flowers, the `i`-th flower will bloom in the `bloomDay[i]` and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make `m` bouquets from the garden. If it is impossible to make `m` bouquets return `-1`.

### Examples

**Example 1:**
```text
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
```

**Example 2:**
```text
Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
```

**Example 3:**
```text
Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
```

### Constraints
*   `bloomDay.length == n`
*   `1 <= n <= 10^5`
*   `1 <= bloomDay[i] <= 10^9`
*   `1 <= m <= 10^6`
*   `1 <= k <= n`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

This is a **Binary Search on Answer** problem. We need to find the minimum number of days $D$ such that we can form $m$ bouquets of $k$ adjacent flowers.

1.  **Impossibility Check:** If $m \times k > n$, it's impossible to form the bouquets regardless of the days waited. Return `-1`.
2.  **Search Space:** The minimum possible day is `min(bloomDay)` and the maximum is `max(bloomDay)`.
3.  **Binary Search:**
    *   Pick `mid` days.
    *   Check if it's possible to form `m` bouquets using only flowers that bloom within `mid` days.
    *   To check: Iterate through `bloomDay`, count adjacent flowers that bloomed. If count reaches `k`, form a bouquet and reset count.
    *   If possible: `ans = mid`, try fewer days (`high = mid - 1`).
    *   If not possible: Need more days (`low = mid + 1`).

### Code

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