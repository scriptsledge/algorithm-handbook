# 🏷️ LeetCode Submission Title
C++ | Hash Map | O(N) Time | O(N) Space | Clean & Efficient

# Intuition
The "Two Sum" problem is the quintessential introduction to the power of Hash Maps. 

A naive approach would be to check every pair of numbers ($O(N^2)$). However, we can reframe the problem: for every number `x` we encounter, we are looking for its **complement** (`target - x`) that we might have seen earlier in the array. 

By storing seen numbers and their indices in a Hash Map, we can perform this "look-back" in $O(1)$ average time.

# Approach
1.  **Initialize a Hash Map:** Store the value as the key and its index as the value.
2.  **Single Pass:** Iterate through the array once.
    *   Calculate the `complement = target - nums[i]`.
    *   Check if the `complement` exists in the Hash Map.
    *   **Match Found:** If it exists, we found our pair. Return the current index and the stored index.
    *   **No Match:** Store the current number and its index in the map and continue.

This "One-Pass Hash Map" approach is optimal for time complexity.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/vuQXdeAL43A)

# Complexity
*   **Time complexity:** $$O(N)$$
    We traverse the list containing $N$ elements only once. Each lookup in the table costs only $O(1)$ time.
*   **Space complexity:** $$O(N)$$
    In the worst case, we store all $N$ elements in the hash map.

# Code
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash_map.find(complement) != hash_map.end()) {
                return {hash_map[complement], i};
            }
            hash_map[nums[i]] = i;
        }
        return {};
    }
};
```

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0001/)