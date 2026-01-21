# Video Metadata - Problem 162

## 📺 YouTube (Plain Text + Links)

Title: LeetCode 162: Find Peak Element | Binary Search on Unsorted Data!

Description:
Binary search isn't just for sorted arrays! In this video, we use slope analysis to find a peak element in O(log N) time. 

Complexity Analysis
• Time: O(log N)
• Space: O(1)

Resources
📘 Algorithm Handbook (Full Breakdown):
https://scriptsledge.github.io/algorithm-handbook/problems/0162/

💡 Detailed Article (LeetCode):
https://leetcode.com/problems/find-peak-element/solutions/

#LeetCode #Algorithms #BinarySearch #Cpp #SoftwareEngineering #CodingInterview

---

## 📸 Meta (Facebook/Instagram - Plain Text Only)

**Caption:**
LeetCode 162: Find Peak Element | O(log N) Binary Search

Think binary search only works on sorted arrays? Think again! 🏔️

The Engineering Approach:
By comparing any element with its neighbor, we can determine if we're moving "uphill" or "downhill." Since the boundaries are -∞, we're guaranteed to find a peak if we just keep following the slope upward.

Complexity Analysis:
• Time: O(log N)
• Space: O(1)

Resources & Code:
Find the full breakdown here:
https://scriptsledge.github.io/algorithm-handbook/problems/0162/

#LeetCode #Algorithms #Engineering #BinarySearch #Cpp #Programming #Tech

## 📊 Engagement Poll

**Prompt:** Why does binary search work here?
Option 1: Array is sorted
Option 2: Slope Analysis
Option 3: Two Pointers
Option 4: Hash Map

---

## 💼 LinkedIn Post (Plain Text Only - No Markdown)

Counter-intuitive: Binary Search on an unsorted array.

In LeetCode 162 (Find Peak Element), we are tasked with finding a peak in O(log N) time. Usually, binary search requires sorted data, but here we use "Slope Analysis."

🔹 The Goal
Find any element that is strictly greater than its neighbors.

🔹 The Solution
We treat the array like a mountain range.

• If nums[mid] < nums[mid+1], we are on an uphill slope -> Peak is to the right.
• If nums[mid] > nums[mid+1], we are on a downhill slope -> Peak is at mid or to the left.

This allows us to eliminate half the array at each step, even without a globally sorted state.

Full Analysis & Code:
https://scriptsledge.github.io/algorithm-handbook/problems/0162/

#Algorithms #SystemsDesign #BinarySearch #Cpp #Engineering #Efficiency