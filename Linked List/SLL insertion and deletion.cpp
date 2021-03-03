//making linked list
#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
    int data;
    struct node* next;
};

//for inserting we need position,value of node and Head.

struct node* Insert_Node(struct node* head,int item,int position){
    //allocate new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    //check either this space is valid
    if(newNode == NULL){
        cout << "Memory Error hai Bro!" << endl;
        return head;
    }
    
    newNode->data = item;

    //insertion at begining
    if(position == 1){
        newNode->next = head;
        head = newNode;
    }

    else{
        int i = 1;
        struct node* front = head;
        struct node* back = NULL;
        while(i<position && front!=NULL){
            back = front;
            front = front->next;
            i++;
        }
        //now front point to pos node and back point to one node behind of front
        back->next = newNode;
        newNode->next = front;
    }
    return head;
}


//for deletion we need head and position
struct node* Delete_Node(struct node* head,int position){
    if(head == NULL){
        cout << "list is empty!" << endl;
        return head;
    }
    
    if(position == 1){
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int i = 1;
    //goto one node back from position
    struct node* temp = head;
    while(temp!=NULL && i<position-1){
        temp = temp->next;
        i++;
    }

    //for corner case checking
    if(temp==NULL || temp->next==NULL){
        cout << "Are yaar itna to node hi nahi hai!" << endl;
        return head;
    }

    struct node* use = temp->next;
    temp->next = temp->next->next;
    free(use);
    return head;
}

void print_List(struct node* var){
    while(var!=NULL){
        cout << var->data << " ";
        var = var->next;
    }
}

int length_of_List(struct node* var){
    int count = 0;
    while(var!=NULL){
        count++;
        var = var->next;
    }
    return count;
}

int main(){
    struct node* head = NULL;
    head = Insert_Node(head,10,1);
    head = Insert_Node(head,20,1);
    head = Insert_Node(head,30,2);
    head = Insert_Node(head,40,3);
    print_List(head);
    cout << endl << "Length of Linked List is = " << length_of_List(head) << endl;
    head = Delete_Node(head,3);
    print_List(head);
    head = Delete_Node(head,5);//for corner case checking
    return 0;
}