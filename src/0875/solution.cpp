#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    // Helper function to calculate hours needed at speed k
    long long rqTimeF(vector<int>& arr, int k) {
        long long rqTime = 0;
        for (int i = 0; i < arr.size(); i++) {
            // Round up the time needed for each pile
            rqTime += ((long long)arr[i] + k - 1) / k;
        }
        return rqTime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long rqTime = rqTimeF(piles, mid);

            if (rqTime <= h) {
                high = mid - 1;  // Try slower speed
            } else {
                low = mid + 1;  // Need faster speed
            }
        }

        return low;  // Minimum speed where she finishes in h hours
    }
};

int main() {
    Solution sol;
    
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    int res1 = sol.minEatingSpeed(piles1, h1);
    cout << "Test Case 1: " << (res1 == 4 ? "Passed" : "Failed") << " (Expected 4, Got " << res1 << ")" << endl;

    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    int res2 = sol.minEatingSpeed(piles2, h2);
    cout << "Test Case 2: " << (res2 == 30 ? "Passed" : "Failed") << " (Expected 30, Got " << res2 << ")" << endl;

    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;
    int res3 = sol.minEatingSpeed(piles3, h3);
    cout << "Test Case 3: " << (res3 == 23 ? "Passed" : "Failed") << " (Expected 23, Got " << res3 << ")" << endl;

    return 0;
}