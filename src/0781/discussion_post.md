# Rabbits in Forest
<!-- C++ | O(N) Time | O(N) Space | Greedy + Math -->

# Intuition
The key is to group rabbits of the same color. If a rabbit says $y$ others have the same color, that color has $y+1$ spots. We want to minimize the total count by filling these spots with other rabbits who also answered $y$.

# Approach
1. Count the frequency of each answer $y$ in the `answers` array.
2. For each answer $y$, calculate how many groups of size $y+1$ are needed to accommodate all rabbits that gave that answer.
3. The number of groups is $\lceil \text{count} / (y+1) \rceil$.
4. Multiply the number of groups by $(y+1)$ to get the total rabbits for that specific answer.
5. Sum these totals for all unique answers.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/jQ0bGl53uM4)

# Complexity
*   **Time complexity:** $O(N)$
*   **Space complexity:** $O(N)$

# Code
```cpp
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int result = 0;
        
        for (int x : answers) {
            count[x]++;
        }
        
        for (auto& [y, x] : count) {
            result += ((x + y) / (y + 1)) * (y + 1);
        }
        
        return result;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0781/)