# O(N) Solution | Two Pointers | Step-by-Step Explanation

# Intuition
When we are given the head of a singly linked list, we cannot directly access the middle element like an array because linked lists do not support indexing. So the key challenge is to **find the middle node using traversal**.

A straightforward idea would be to:
1. Traverse the list to find its length.
2. Traverse again up to `length / 2` to reach the middle.

However, this requires **two passes** over the list.

To optimize this, we can observe that if:
* One pointer moves **one step at a time**, and
* Another pointer moves **two steps at a time**,

then when the faster pointer reaches the end of the list, the slower pointer will naturally be positioned at the **middle node**.

This insight allows us to find the middle in **a single traversal**.

# Approach
1. Initialize two pointers:
   * `slow` starting at the head
   * `fast` also starting at the head
2. Move:
   * `slow` one node forward (`slow = slow->next`)
   * `fast` two nodes forward (`fast = fast->next->next`) in each iteration
3. Continue this process while `fast` and `fast->next` are not `nullptr`.
4. When the loop ends:
   * `fast` has reached the end of the list
   * `slow` is pointing to the middle node
5. In case of an even number of nodes, this method naturally returns the **second middle node**, as required by the problem.
6. Return the node pointed to by `slow`.

# Video Explanation
[**Watch the breakdown on YouTube**](https://youtube.com/shorts/x5RD2a8DKG4)

# Complexity
*   **Time complexity:** $O(N)$
    The list is traversed only once.
*   **Space complexity:** $O(1)$
    No extra data structures are used; only two pointers are maintained.

# Code
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

---
**Algorithm Handbook:**
[Full Analysis & Code](https://scriptsledge.github.io/algorithm-handbook/problems/0876/)
