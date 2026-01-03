# 56. Merge Intervals

## Problem Description

Given an array of `intervals` where `intervals[i] = [start_i, end_i]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.

### Examples

**Example 1:**
```text
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
```

**Example 2:**
```text
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

### Constraints
*   `1 <= intervals.length <= 10^4`
*   `intervals[i].length == 2`
*   `0 <= start_i <= end_i <= 10^4`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use a **Sort & Sweep** approach:
1.  **Sort** the intervals by start time.
2.  **Iterate** through the sorted intervals and maintain a `lastStart` and `lastEnd`.
3.  If the current interval starts before the previous one ends (`currentStart <= lastEnd`), they overlap. We merge them by extending `lastEnd`.
4.  If they don't overlap, we save the previous interval and start a new one.

This runs in $O(N \log N)$ time due to sorting.

### Code

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        int lastStart = intervals[0][0];
        int lastEnd = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];
            
            if (currentStart <= lastEnd) {
                lastEnd = max(lastEnd, currentEnd);
            } else {
                result.push_back({lastStart, lastEnd});
                lastStart = currentStart;
                lastEnd = currentEnd;
            }
        }
        
        result.push_back({lastStart, lastEnd});
        
        return result;
    }
};
```