class Solution {
public:
    int findLength(ListNode* head){
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }

        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //one way is to count the length of list 
        //later delete that by doing k-n
        int len=findLength(head);
        cout<<len;
        if(len-n<=0){
            return head->next;
        }
        int step=len-n;
        ListNode* temp=head;
        while(step>1){
            temp=temp->next;
            step--;
        }
        if(temp->next!=NULL)
        temp->next=temp->next->next;
        
        return head;
    }
};