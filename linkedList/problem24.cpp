#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* cur = head;
        ListNode* next = head->next;
        ListNode* prev = nullptr;
        head = next;

        while(cur != nullptr & next != nullptr) {
            cur->next = next->next;
            next->next = cur;
            if(prev != nullptr) prev->next = next;
            
                
            if(cur->next == nullptr || cur->next->next == nullptr) break;
            prev = cur;
            cur = cur->next;
            next = cur->next;
        }

        return head;
    }
};