#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int result = 0;
        
        for (int x : answers) {
            count[x]++;
        }
        
        for (auto& [y, x] : count) {
            // Ceiling division: (x + y) / (y + 1)
            // Each group of (y + 1) rabbits can have the same color.
            // If x rabbits say there are y others of the same color,
            // they form groups of size (y + 1).
            result += ((x + y) / (y + 1)) * (y + 1);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> answers1 = {1, 1, 2};
    cout << "Test Case 1: " << (sol.numRabbits(answers1) == 5 ? "Passed" : "Failed") << endl;

    // Example 2
    vector<int> answers2 = {10, 10, 10};
    cout << "Test Case 2: " << (sol.numRabbits(answers2) == 11 ? "Passed" : "Failed") << endl;

    return 0;
}