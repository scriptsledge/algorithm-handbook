# 876. Middle of the Linked List

## Problem Description

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

### Examples

**Example 1:**
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

**Example 2:**
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

### Constraints

- The number of nodes in the list is in the range [1, 100].
- 1 <= Node.val <= 100

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Intuition

When we are given the head of a singly linked list, we cannot directly access the middle element like an array because linked lists do not support indexing. So the key challenge is to **find the middle node using traversal**.

A straightforward idea would be to traverse the list twice: once to find the length and once to reach the midpoint. However, by using two pointers moving at different speeds (one step vs two steps), we can find the middle node in a single pass.

### Approach

1.  Initialize `slow` and `fast` pointers at the `head`.
2.  Move `slow` one step and `fast` two steps in each iteration.
3.  Continue while `fast` and `fast->next` are not `nullptr`.
4.  Return `slow`, which will be at the middle node when the loop terminates.

### Code

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
```
