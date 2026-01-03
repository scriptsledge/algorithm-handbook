# Video Metadata - Problem 0152

## 📺 YouTube (Plain Text + Links)

Title: LeetCode 152: Maximum Product Subarray | Two-Pass Solution | C++

Description:
Finding the maximum product is harder than finding the maximum sum because negative numbers flip the sign. In this video, we explore why standard Kadane's Algorithm fails and how a simple "Forward & Backward" sweep solves LeetCode 152 in O(N) time with O(1) space.

Complexity Analysis
• Time: O(N)
• Space: O(1)

Resources
📘 Algorithm Handbook (Full Breakdown):
https://scriptsledge.github.io/algorithm-handbook/problems/0152/

💡 Detailed Article (LeetCode):
https://leetcode.com/problems/maximum-product-subarray/solutions/7463331/c-two-pass-solution-on-time-o1-space-sim-x56m

#LeetCode #Algorithms #Cpp #DataStructures #SoftwareEngineering #CodingInterview

---

## 📸 Meta (Facebook/Instagram - Plain Text Only)

**Caption:**
LeetCode 152: Maximum Product Subarray | C++ Solution

The Engineering Approach:
Why can't we just use Kadane's Algorithm here?
Because in multiplication, a "bad" number (negative) can instantly become the "best" number if multiplied by another negative.

Instead of complex Dynamic Programming states, we use a simple property: The max product must start from either the beginning or the end of a non-zero block.

By scanning Forward and Backward, we catch every possibility in O(N).

Complexity Analysis:
• Time: O(N)
• Space: O(1)

Resources & Code:
Find the full breakdown here:
https://scriptsledge.github.io/algorithm-handbook/problems/0152/

## 📊 Engagement Poll

**Prompt:** Best strategy for Max Product Subarray?
- Option 1: Forward & Backward Pass
- Option 2: Track Min & Max (DP)
- Option 3: Brute Force O(N²)
- Option 4: Kadane's (Sum Variation)

#LeetCode #Algorithms #Cpp #DataStructures #SoftwareEngineering #CodingInterview #Programming #Tech

---

## 💼 LinkedIn Post (Plain Text Only - No Markdown)

Why does multiplication break Greedy Algorithms? 📉

In the "Maximum Sum" problem, a negative number is always bad. We discard it.
In the "Maximum Product" problem, a negative number is an opportunity. It flips the sign, potentially turning a large negative product into a massive positive one.

That is the core challenge of LeetCode 0152 (Maximum Product Subarray).

🔹 The Goal
Find the contiguous subarray with the largest product.

🔹 The Solution
We use a "Two-Pass Scan" approach to solve this in O(N) time.

• Pass 1 (Forward): Accumulate product. If we hit 0, reset. This catches max products starting from the left.
• Pass 2 (Backward): Accumulate product from the end. This catches max products starting from the right (handling odd counts of negatives).

This approach eliminates the need to maintain complex Min/Max states for Dynamic Programming.

Full Analysis & Code:
https://scriptsledge.github.io/algorithm-handbook/problems/0152/

🎥 Video Link:
https://youtube.com/shorts/OI1irq3hDjE

#Algorithms #SystemsDesign #Cpp #DataStructures #Engineering