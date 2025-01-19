/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next ==NULL || k==0)
        {
            return head;
        }

        ListNode* curr = head;
        int length = 1;

        while(curr -> next != NULL)
        {
            curr = curr -> next;
            length += 1;
        }

        curr -> next = head;

        k = k % length;

        for(int i=0;i<(length-k);i++)
        {
            curr=curr->next;
        }

        head = curr -> next;
        curr -> next = NULL;
        return head;
    }
};