#include<iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int data;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class List{
    public:
    Node* head;
    Node* tail;
    List(){
        head = NULL;
        tail = NULL;
    }
   
    void push_Front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    void push_Back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }

    }
};
 void print_LL(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data;
            temp = temp->next;
        } 
        cout<<"NULL\n";
    }
bool isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    
    if(slow==fast){
        cout<<"Cycle exists\n";
        return true;
    }
}
    
        cout<<"Cycle doesn't found";
        return false;
    }


int main(){
    List ll;
    ll.push_Front(4);
    ll.push_Front(3);
    ll.push_Front(2);
    ll.tail->next = ll.head;
    isCycle(ll.head);
    // print_LL();
}