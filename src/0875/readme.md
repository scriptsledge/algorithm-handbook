# 875. Koko Eating Bananas

## Problem Description

Koko loves to eat bananas. There are `n` piles of bananas, the `i`-th pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer `k` such that she can eat all the bananas within `h` hours.

### Examples

**Example 1:**
```text
Input: piles = [3,6,7,11], h = 8
Output: 4
```

**Example 2:**
```text
Input: piles = [30,11,23,4,20], h = 5
Output: 30
```

**Example 3:**
```text
Input: piles = [30,11,23,4,20], h = 6
Output: 23
```

### Constraints
*   `1 <= piles.length <= 10^4`
*   `piles.length <= h <= 10^9`
*   `1 <= piles[i] <= 10^9`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We are looking for the minimum speed $k$ in the range $[1, \max(\text{piles})]$. Since the time taken to eat all bananas decreases as $k$ increases, we can use **Binary Search** on the answer.

1.  **Range:** The minimum speed is 1, and the maximum speed needed is the size of the largest pile (since she can't eat more than one pile per hour anyway).
2.  **Binary Search:**
    *   Find the middle speed `mid`.
    *   Calculate the total hours `rqTime` needed to eat all piles at speed `mid`.
    *   If `rqTime <= h`, it means she can finish at this speed. Try to find a slower speed by setting `high = mid - 1`.
    *   If `rqTime > h`, it means she is eating too slowly. Increase the speed by setting `low = mid + 1`.
3.  The search converges to the minimum speed `low`.

### Code

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