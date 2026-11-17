bool isPalindrome(struct ListNode* head) {

    int count = 0;
    struct ListNode *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }


    struct ListNode *mid = head;
    for (int i = 0; i < count / 2; i++) {
        mid = mid->next;
    }


    struct ListNode *prevnode = NULL;
    struct ListNode *currentnode = mid;
    struct ListNode *nextnode = mid;
    while (nextnode != NULL) {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }

    struct ListNode *first = head;
    struct ListNode *second = prevnode;
    while (second != NULL) {
        if (first->val != second->val) {
            return false;
        }
        first = first->next;
        second = second->next;
    }

    return true;
}

