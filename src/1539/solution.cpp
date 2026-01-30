#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: 1539. Kth Missing Positive Number
 * Approach: Binary Search (O(log N))
 * The number of missing elements before index `mid` is `arr[mid] - (mid + 1)`.
 * We use binary search to find the smallest index `left` such that the number
 * of missing elements before it is greater than or equal to `k`.
 */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // arr[mid] - (mid + 1) gives the number of missing integers before arr[mid]
            int missingCount = arr[mid] - mid - 1;
            
            if (missingCount < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // After the loop, `left` is the insertion point where the missing kth element would be.
        // The answer is `left + k`. 
        // Logic: arr[right] + (k - missing_before_right)
        // = arr[right] + k - (arr[right] - right - 1)
        // = right + 1 + k
        // Since the loop ends with left = right + 1, we return left + k.
        return left + k;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;
    cout << "Test Case 1: " << (sol.findKthPositive(arr1, k1) == 9 ? "Passed" : "Failed") << " (Expected 9)" << endl;

    // Test Case 2
    vector<int> arr2 = {1, 2, 3, 4};
    int k2 = 2;
    cout << "Test Case 2: " << (sol.findKthPositive(arr2, k2) == 6 ? "Passed" : "Failed") << " (Expected 6)" << endl;

    return 0;
}