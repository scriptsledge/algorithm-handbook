# O(N) Solution | Simple Iteration | Circular Array Handling

# Intuition
The problem asks for the maximum difference between adjacent elements in a circular array. This means we need to check all pairs $(nums[i], nums[i+1])$ as well as the pair $(nums[n-1], nums[0])$.

# Approach
1. Iterate through the array using a loop from $i = 0$ to $n-1$.
2. For each index $i$, find the next index using `(i + 1) % n`.
3. Calculate the absolute difference between `nums[i]` and `nums[nextIndex]`.
4. Keep track of the maximum difference found so far.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/OHz8XKLe1_E)

# Complexity
*   **Time complexity:** $O(N)$
    We iterate through the array once.
*   **Space complexity:** $O(1)$
    We only use a few variables to store the maximum distance and indices.

# Code
```cpp
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDistance = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int nextIndex = (i + 1) % n;
            maxDistance = max(maxDistance, abs(nums[i] - nums[nextIndex]));
        }
        
        return maxDistance;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/3423/)