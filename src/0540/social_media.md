# Video Metadata - Problem 540

## 📺 YouTube (Plain Text + Links)

Title: LeetCode 540: Single Element in a Sorted Array | Binary Search Optimization

Description:
Can you find the unique element in a sorted array in O(log N) time? We dive into the "Even-Index Pattern" that makes binary search the perfect tool for this problem.

Complexity Analysis
• Time: O(log N)
• Space: O(1)

Resources
📘 Algorithm Handbook (Full Breakdown):
https://scriptsledge.github.io/algorithm-handbook/problems/0540/

💡 Detailed Article (LeetCode):
https://leetcode.com/problems/single-element-in-a-sorted-array/solutions/7511594/olog-n-binary-search-even-index-pattern-4c8r5

#LeetCode #Algorithms #BinarySearch #Cpp #SoftwareEngineering #CodingInterview

---

## 📸 Meta (Facebook/Instagram - Plain Text Only)

**Caption:**
LeetCode 540: Single Element in a Sorted Array | O(log N) Binary Search

The key to solving this in logarithmic time is identifying the pattern shift. In this array, pairs always start at even indices—until the single element appears and shifts everything!

The Engineering Approach:
By forcing our binary search to always check even indices, we can determine exactly which side of the array the unique element resides in.

Complexity Analysis:
• Time: O(log N)
• Space: O(1)

Resources & Code:
Find the full breakdown here:
https://scriptsledge.github.io/algorithm-handbook/problems/0540/

#LeetCode #Algorithms #Engineering #BinarySearch #Cpp #Programming #Tech

## 📊 Engagement Poll

**Prompt:** What's the trick to O(log N) here?
Option 1: Index Parity
Option 2: XOR Sum
Option 3: Two Pointers
Option 4: Frequency Map

---

## 💼 LinkedIn Post (Plain Text Only - No Markdown)

Efficiency is about finding the right pattern.

In LeetCode 540 (Single Element in a Sorted Array), the naive O(N) approach is trivial. But the requirement for O(log N) time and O(1) space forces us to look deeper.

🔹 The Goal
Find the only non-duplicate element in a sorted array where every other element appears twice.

🔹 The Solution
Binary search is the answer, but with a twist: Index Parity.

• Before the unique element, pairs start at EVEN indices (0, 2, 4...).
• After it, they start at ODD indices (1, 3, 5...).

By checking if nums[mid] == nums[mid+1] at an even mid, we can discard half the array in each step.

Full Analysis & Code:
https://scriptsledge.github.io/algorithm-handbook/problems/0540/

#Algorithms #SystemsDesign #BinarySearch #Cpp #Engineering #Efficiency