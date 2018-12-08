/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head= (struct ListNode*)malloc(sizeof(struct ListNode));
        //cout<<head->val<<" "<<head->next<<" ";
        
        
           if(l1==NULL)
               return l2;
           if(l2==NULL)
               return l1;
        
            
            ListNode* l3 = head;
            while(l1!=NULL && l2!=NULL)
            { 

                    if( l1->val + l2->val < 10 )
                    {

                        l3->val = l1->val + l2->val;
                        
                        if(l1->next==NULL && l2->next==NULL)
                            l3->next=NULL;
                        else
                        {
                            ListNode* temp= (struct ListNode*)malloc(sizeof(struct ListNode));
                            l3->next=temp;
                            l3=l3->next;
                        }

                    }
                    else
                    {
                        l3->val = (l1->val + l2->val)%10;
                        
                        if(l1->next==NULL && l2->next==NULL)
                        {
                        
                             ListNode* temp= (struct ListNode*)malloc(sizeof(struct ListNode));
                             l3->next=temp;
                             l3=l3->next;
                             l3->val=1;
                             l3->next=NULL;
                            
                        }
                        else
                        {
                            ++(l1->next->val);
                            ListNode* temp= (struct ListNode*)malloc(sizeof(struct ListNode));
                            l3->next=temp;
                            l3=l3->next;
                        }
                    }
                    l1=l1->next;
                    l2=l2->next;
               
            }
  
            
        return head;
    }
};
