int getNthFromLast(Node *head, int n)
{
    struct Node* ptr1;
    struct Node* ptr2;
    ptr1 = head;
    ptr2 = head;
    int i = 1;
    while(i<n && ptr2!=NULL){
        ptr2 = ptr2->next;
        i++;
    }
    if(ptr2==NULL) return -1;
    while(ptr2->next!=NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1->data;
}

#include <iostream>
using namespace std;
int main() {
    cout<<"Hello World!";
}
