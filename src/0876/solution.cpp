#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list from a given node
void printLinkedList(ListNode* node) {
    cout << "[";
    while (node != nullptr) {
        cout << node->val;
        if (node->next != nullptr) cout << ",";
        node = node->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> vals1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createLinkedList(vals1);
    cout << "Test Case 1: ";
    printLinkedList(sol.middleNode(head1)); // Expected: [3,4,5]

    // Test Case 2
    vector<int> vals2 = {1, 2, 3, 4, 5, 6};
    ListNode* head2 = createLinkedList(vals2);
    cout << "Test Case 2: ";
    printLinkedList(sol.middleNode(head2)); // Expected: [4,5,6]

    return 0;
}