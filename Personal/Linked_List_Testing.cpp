#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Customizable Solution class for practicing LeetCode problems
class Solution {
public:
    // Function to remove the Nth node from the end of the list
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);  // Dummy node to handle edge cases
        ListNode* l = dummy;
        ListNode* r = dummy;

        // Move r forward by n+1 positions
        for (int i = 0; i <= n; ++i) {
            r = r->next;
        }

        // Move both l and r until r reaches the end
        while (r != nullptr) {
            l = l->next;
            r = r->next;
        }

        // Remove the nth node from the end
        l->next = l->next->next;

        return dummy->next;  // Return the new head, skipping the dummy node
    }

    // Function to create a linked list from a vector of values
    ListNode* createList(const vector<int>& values) {
        if (values.empty()) return nullptr;
        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        for (size_t i = 1; i < values.size(); ++i) {
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        return head;
    }

    // Function to print the linked list
    void printList(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->val;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

// Example of using the Solution class
int main() {
    Solution solution;
    
    // Customize this part for your own test cases
    vector<int> values = {1, 2, 3, 4, 5};  // List to create
    int n = 2;  // Node to remove from the end

    ListNode* head = solution.createList(values);
    cout << "Original List: ";
    solution.printList(head);

    head = solution.removeNthFromEnd(head, n);
    cout << "Modified List after removing " << n << "th node from end: ";
    solution.printList(head);

    return 0;
}





        // ListNode* dummy = new ListNode(0, head);
        // ListNode* first = dummy;
        // ListNode* second = dummy;
        
        // // Move first pointer n+1 steps ahead
        // for (int i = 0; i <= n; i++) {
        //     first = first->next;
        // }

        // // Move first to the end, maintaining the gap
        // while (first != nullptr) {
        //     first = first->next;
        //     second = second->next;
        // }

        // // Skip the desired node
        // second->next = second->next->next;

        // // Return the head of the modified list
        // return dummy->next;
