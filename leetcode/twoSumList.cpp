struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool pre;
        pre = false;
        ListNode *pAdd = new ListNode(0);
        ListNode *pTmp = pAdd;
        while(1)
        {
            if(l1 != NULL && l2 != NULL)
            {
                int sum = l1->val + l2->val + static_cast<int>(pre);
                pTmp->val = sum % 10;
                pre = static_cast<bool>(sum / 10);
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 != NULL || l2 != NULL)
            {
                int sum = (l1 != NULL?l1->val:l2->val) + static_cast<int>(pre);
                pTmp->val = sum % 10;
                pre = static_cast<bool>(sum / 10);
                if(l1 != NULL)
                    l1 = l1->next;
                else if(l2 != NULL)
                    l2 = l2->next;
            }
            if(l1 == NULL && l2 == NULL)
            {
                if(pre == 0)
                {
                    break;
                }
                else
                {
                    pTmp->next = new ListNode(0);
                    pTmp = pTmp->next;
                    pTmp->val = static_cast<int>(pre);
                    break;
                }
            }
            pTmp->next = new ListNode(0);
            pTmp = pTmp->next;
        }
        return pAdd;
    }
};
