#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *slow= head, *fast= head;
        while(fast->next && fast->next->next){
            slow= slow->next;
            fast= fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Linked list WITH a cycle (3 -> 2 -> 0 -> -4 -> points back to 2)
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next;

    cout << "Test Case 1 (Cycle expected): " 
         << (sol.hasCycle(head1) ? "True (Cycle found)" : "False (No cycle)") << endl;

    // Test Case 2: Linked list WITHOUT a cycle (1 -> 2)
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    cout << "Test Case 2 (No cycle expected): " 
         << (sol.hasCycle(head2) ? "True (Cycle found)" : "False (No cycle)") << endl;

    head1->next->next->next->next = nullptr; 

    auto deleteList = [](ListNode* head) {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    };

    deleteList(head1);
    deleteList(head2);

    return 0;
}