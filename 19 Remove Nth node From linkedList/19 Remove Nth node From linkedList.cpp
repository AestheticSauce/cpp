#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    ListNode*ptr = head;
    ListNode* temp = head;
    int size = 0;
    int stop = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
        size++;
        
    }

    stop = size - n ;
    for(int i = 0; i < stop-1;i++)
    {
        ptr = ptr->next;
    }
    if (n == 1 && n!= size) 
    {
        ptr->next = nullptr;
    }
    else if(n == size)
    {

        ptr = ptr->next;
        head = ptr;
    }
    else 
    {
        ptr->next = ptr->next->next;
    }
    return head;
}
int main()
{
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    //for (int i = 1; i <= 3; i++) 
    //{
    //    curr->next = new ListNode(i);
    //    curr = curr->next;
    //}
    ListNode *res  = removeNthFromEnd(head, 1);
    while(res != nullptr)
    {
        std::cout << res->val << std::endl;
        res = res->next;
    }
    
}
