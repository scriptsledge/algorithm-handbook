#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Use 1LL to avoid overflow during multiplication
            if (1LL * mid * mid <= x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};

int main() {
    Solution sol;
    
    int x1 = 4;
    int res1 = sol.mySqrt(x1);
    cout << "Test Case 1: " << (res1 == 2 ? "Passed" : "Failed") << " (Expected 2, Got " << res1 << ")" << endl;

    int x2 = 8;
    int res2 = sol.mySqrt(x2);
    cout << "Test Case 2: " << (res2 == 2 ? "Passed" : "Failed") << " (Expected 2, Got " << res2 << ")" << endl;

    int x3 = 0;
    int res3 = sol.mySqrt(x3);
    cout << "Test Case 3: " << (res3 == 0 ? "Passed" : "Failed") << " (Expected 0, Got " << res3 << ")" << endl;

    return 0;
}