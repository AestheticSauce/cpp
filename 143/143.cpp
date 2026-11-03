// 143Reorder List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
void reorderLIst(ListNode* head)
{

    //if we only have one node in the list then we just return the node itself
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    //if we have more than one node in the list, then we try to find the middle using fast and slow pointer method.
    ListNode* fast = head->next;
    ListNode* slow = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //splits up the linked list into two linked list
    ListNode* second = slow->next;
    slow->next = nullptr;

    //reverse the second half of the linked list 
    ListNode* prev = nullptr;
    while (second != nullptr)
    {
        ListNode* next = second->next;

        second->next = prev;

        prev = second;

        second = next;
    }

    //second before this point to null, we need it to point to the last item as its now the head of our second list
    second = prev;
    while (second != nullptr)
    {

        ListNode* temp = head->next;
        ListNode* temp2 = second->next;

        head->next = second;

        second->next = temp;

        head = temp;
        second = temp2;
    }

}
int main()
{

}
