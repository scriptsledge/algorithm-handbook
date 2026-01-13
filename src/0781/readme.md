# 781. Rabbits in Forest

## Problem Description

There is a forest with an unknown number of rabbits. We asked `n` rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array `answers` where `answers[i]` is the answer of the `i`-th rabbit.

Given the array `answers`, return the minimum number of rabbits that could be in the forest.

### Examples

**Example 1:**
- **Input:** `answers = [1,1,2]`
- **Output:** `5`
- **Explanation:**
  The two rabbits that answered "1" could both be the same color, say red.
  The rabbit that answered "2" can't be red or the answers would be inconsistent.
  Say the rabbit that answered "2" was blue.
  Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
  The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

**Example 2:**
- **Input:** `answers = [10,10,10]`
- **Output:** `11`

### Constraints

- `1 <= answers.length <= 1000`
- `0 <= answers[i] < 1000`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

If a rabbit says there are `y` other rabbits with the same color, then there must be `y + 1` rabbits of that color in total.

1. We count how many rabbits gave the same answer `y`. Let this count be `x`.
2. A single color can accommodate at most `y + 1` rabbits.
3. Therefore, the `x` rabbits that answered `y` must belong to at least `ceil(x / (y + 1))` different colors.
4. Each of these colors must have exactly `y + 1` rabbits to minimize the total count.
5. Total rabbits for answer `y` is `ceil(x / (y + 1)) * (y + 1)`.

In integer arithmetic, `ceil(x / (y + 1))` can be written as `(x + y) / (y + 1)`.

### Code

```cpp
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int result = 0;
        
        for (int x : answers) {
            count[x]++;
        }
        
        for (auto& [y, x] : count) {
            result += ((x + y) / (y + 1)) * (y + 1);
        }
        
        return result;
    }
};
```