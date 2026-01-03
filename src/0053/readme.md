# 53. Maximum Subarray

## Problem Description

Given an integer array `nums`, find the **subarray** with the largest sum, and return *its sum*.

### Examples

**Example 1:**
```text
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```

**Example 2:**
```text
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
```

**Example 3:**
```text
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

### Constraints
*   `1 <= nums.length <= 10^5`
*   `-10^4 <= nums[i] <= 10^4`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

We use **Kadane's Algorithm** (Greedy Approach).

The core idea is to maintain a `current_sum` as we iterate through the array. 
*   If `current_sum` is positive, it contributes to future subarrays.
*   If `current_sum` becomes negative, it is a liability. We reset `current_sum` to 0, effectively starting a new subarray from the next element.

This allows us to find the maximum sum in a single pass ($O(N)$).

### Code

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int sum = 0;
        
        for (int num : nums) {
            sum += num;
            max_sum = max(max_sum, sum);
            if (sum < 0) {
                sum = 0; // Reset sum when it becomes negative
            }
        }
        
        return max_sum;
    }
};
```