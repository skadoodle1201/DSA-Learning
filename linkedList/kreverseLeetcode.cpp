 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* kreverse(ListNode* head, int n){
            if(!head){
                return head;
            }
            ListNode * next, * curr , * prev;
            prev = next = NULL;
            curr = head;
            int k = 0;
            ListNode * temp = head;
            int l = 0;
            while(temp){
                temp = temp->next;
                l++;
            }
            if(l<n) return head;
            while(curr and k < n){
                next = curr -> next;
                curr->next = prev;
                prev = curr;
                curr = next;
                k++;
            }

            if(next!=NULL)
                head->next = kreverse(next, n);
            return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {

    }
};
