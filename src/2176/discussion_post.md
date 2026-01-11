# Count Equal and Divisible Pairs in an Array
<!-- C++ | O(N^2) Solution | Clean & Efficient -->

# Intuition
The problem asks for pairs of identical elements whose indices have a product divisible by $k$. Given the small constraints, we can efficiently group indices by value and check all pairs within each group.

# Approach
1. Group indices by their values using a hash map.
2. For each unique value, iterate through its list of indices.
3. For every pair of indices $(i, j)$ in the list, check if $(i \times j) \pmod k == 0$.
4. Return the total count.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/cNzBZds0BrQ)

# Complexity
*   **Time complexity:** $O(N^2)$
    In the worst case where all elements are the same, we check all $N(N-1)/2$ pairs.
*   **Space complexity:** $O(N)$
    To store the indices in the hash map.

# Code
```cpp
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> indices;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (indices.count(nums[i])) {
                for (int j : indices[nums[i]]) {
                    if ((i * j) % k == 0)
                        count++;
                }
            }
            indices[nums[i]].push_back(i);
        }

        return count;
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/2176/)