#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast= head, *slow= head;
        while(fast && fast->next){
            slow= slow->next;
            fast= fast->next->next;
            if(slow==fast){
                ListNode *p= head, *q= fast;
                while(p!=q){
                    p= p->next;
                    q= q->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};

int main() {
    // linked list: 3 -> 2 -> 0 -> -4
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    
    // point the last node (-4) back to the second node (2)
    head->next->next->next->next = head->next;

    Solution sol;
    ListNode *cycleStart = sol.detectCycle(head);

    if (cycleStart != nullptr) {
        std::cout << "Cycle detected! The cycle begins at node with value: " << cycleStart->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    return 0;
}