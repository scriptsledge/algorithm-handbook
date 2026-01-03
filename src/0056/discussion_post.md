# 🏷️ LeetCode Submission Title
C++ | Sorting & Merging | O(N log N) | Clean & Easy to Understand

# 🚀 Intuition
The core problem is handling intervals that might arrive in any order. If we process intervals randomly, checking for overlaps becomes complex ($O(N^2)$).

However, if we **sort** the intervals by their start time, an important property emerges:
*   Overlapping intervals will always be adjacent to each other in the sorted list.
*   We only need to compare the "current" interval with the "next" one.

# 💡 Approach
1.  **Sort:** First, sort the intervals based on their start times. This costs $O(N \log N)$ but simplifies the logic to a single pass.
2.  **Iterate & Merge:**
    *   Initialize `lastStart` and `lastEnd` with the first interval.
    *   Iterate through the rest of the intervals.
    *   **Overlap Condition:** If `currentStart <= lastEnd`, it means the current interval starts before the previous one ends. We merge them by updating `lastEnd = max(lastEnd, currentEnd)`.
    *   **No Overlap:** If `currentStart > lastEnd`, the previous interval is "complete". Push it to the result and start tracking the new interval (`lastStart`, `lastEnd`).
3.  **Finalize:** Don't forget to push the last merged interval after the loop finishes.

# 🎥 Video Explanation
[**Watch the quick walkthrough on YouTube**](https://youtube.com/shorts/FkppnZQVxyk)

# 💻 Complexity
*   **Time complexity:** $$O(N \log N)$$
    Dominated by the sorting step. The subsequent linear scan is $O(N)$.
*   **Space complexity:** $$O(N)$$
    In the worst case (no overlaps), we store all intervals in the `result` vector. If we ignore the return container, auxiliary space is $O(\log N)$ for sorting stack depth.

# 👨‍💻 Code
```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        
        // 1. Sort by start time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        int lastStart = intervals[0][0];
        int lastEnd = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];
            
            // 2. Overlap: Extend the end time
            if (currentStart <= lastEnd) {
                lastEnd = max(lastEnd, currentEnd);
            } 
            // 3. No Overlap: Push previous and start new
            else {
                result.push_back({lastStart, lastEnd});
                lastStart = currentStart;
                lastEnd = currentEnd;
            }
        }
        
        // 4. Push the final interval
        result.push_back({lastStart, lastEnd});
        
        return result;
    }
};
```

---

**Connect & Follow:**

*   📘 **Algorithm Handbook:** [Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0056/)
