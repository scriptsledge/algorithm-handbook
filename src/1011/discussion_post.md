# O(N log S) Solution | Binary Search on Answer | Easy Simulation

# Intuition
The problem asks for the minimum capacity. If a capacity $C$ works, any capacity $> C$ also works. This monotonicity allows us to binary search for the minimum $C$.

# Approach
1.  **Define the range:** The minimum capacity must be at least the maximum package weight (so we can carry every package). The maximum capacity is the sum of all weights (to ship in 1 day).
2.  **Binary Search:** In each step, check if the current `mid` capacity is enough to ship within `days`.
3.  **Check Function:** Iterate through weights and greedily fill days. If the capacity is exceeded, increment the day count.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/blRWI_fNErM)

# Complexity
*   **Time complexity:** $O(N \log(\sum \text{weights}))$
    *   $N$ is the number of packages. The binary search range is the sum of weights.
*   **Space complexity:** $O(1)$
    *   No extra space used besides variables.

# Code
```cpp
class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int daysNeeded = 1, currentWeight = 0;
        for (int w : weights) {
            if (currentWeight + w > capacity) {
                daysNeeded++;
                currentWeight = w;
            } else {
                currentWeight += w;
            }
        }
        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/1011/)

```