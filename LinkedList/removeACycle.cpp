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
    void print_LL(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data;
            temp = temp->next;
            cout<<" ";
        }
        cout<<"NULL";
    }
};
void remove_Cycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            cout<<"Cycle exists."<<endl;
            isCycle = true;
            break;
        }
    }
        if(!isCycle){
            cout<<"Cycle doesn't exists."<<endl;
        }
    

    slow == fast;
    if(slow == fast){
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else{
        Node* prev = fast;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
    }

} 

int main(){
List ll;
ll.push_Front(4);
ll.push_Front(3);
ll.push_Front(2);
ll.push_Front(1);
ll.tail->next = ll.head;
remove_Cycle(ll.head);
ll.print_LL();
}