#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int size = intervals.size();
        
        // Handle empty or single interval case
        if (size <= 1) {
            return intervals;
        }
        
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        // Initialize with first interval
        int lastStart = intervals[0][0];
        int lastEnd = intervals[0][1];
        
        for (int i = 1; i < size; i++) {
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];
            
            // If overlap, merge by updating the end time
            if (currentStart <= lastEnd) {
                // Take the maximum end time
                lastEnd = max(lastEnd, currentEnd);
            } else {
                // No overlap, add the previous merged interval to result
                result.push_back({lastStart, lastEnd});
                
                // Start a new merged interval
                lastStart = currentStart;
                lastEnd = currentEnd;
            }
        }
        
        // Don't forget to add the last interval
        result.push_back({lastStart, lastEnd});
        
        return result;
    }
};

void printIntervals(const vector<vector<int>>& intervals) {
    cout << "[";
    for (size_t i = 0; i < intervals.size(); ++i) {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i < intervals.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    cout << "Test Case 1: ";
    printIntervals(sol.merge(intervals1)); // Expected: [[1,6],[8,10],[15,18]]

    // Example 2
    vector<vector<int>> intervals2 = {{1,4},{4,5}};
    cout << "Test Case 2: ";
    printIntervals(sol.merge(intervals2)); // Expected: [[1,5]]

    // Example 3
    vector<vector<int>> intervals3 = {{4,7},{1,4}};
    cout << "Test Case 3: ";
    printIntervals(sol.merge(intervals3)); // Expected: [[1,7]]

    return 0;
}