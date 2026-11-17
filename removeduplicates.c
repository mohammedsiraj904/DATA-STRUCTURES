struct ListNode* deleteDuplicates(struct ListNode* head){

    if(head == NULL || head -> next == NULL)
        return head;
    

    struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    prehead -> val = -101;
    prehead -> next = head; 
    
    struct ListNode* curr = prehead; 
    
   
    while(curr -> next != NULL && curr -> next -> next != NULL)
    {
     
        if(curr -> next -> val == curr -> next -> next -> val)
        {
            struct ListNode* temp = curr -> next -> next;
            
            while(temp != NULL && curr -> next -> val == temp -> val)
            {
                struct ListNode* anthortemp = temp;
                temp = temp -> next;
                
                free(anthortemp); 
            }
            
            curr -> next = temp;
            
        }
        else 
        {
            curr = curr -> next;
        }
    }
    

    return prehead -> next;
}
