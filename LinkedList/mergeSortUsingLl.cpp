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
            cout<<temp->data<<" -> ";
            temp = temp->next;
        } 
        cout<<"NULL\n";
    }

Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast != NULL && fast->next !=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev != NULL){
        prev->next = NULL;
    }
    return slow;
}

Node* merge(Node* left, Node* right){
    List ans;
    Node* i = left;
    Node* j = right;
    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_Back(i->data);
            i = i->next;
        }
        else{
            ans.push_Back(j->data);
            j = j->next;
        }
    }
    while(i != NULL){
            ans.push_Back(i->data);
            i = i->next;
        }
    while(j != NULL){
            ans.push_Back(j->data);
            j = j->next;
        }    
    
    return ans.head;
}

Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* rightHead = splitAtMid(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);
    return merge(left, right);
}

int main(){
    List ll;
    ll.push_Front(1);
    ll.push_Front(2);
    ll.push_Front(3);
    ll.push_Front(4);
    ll.push_Front(5);
    print_LL(ll.head);
    ll.head = mergeSort(ll.head);
    print_LL(ll.head);
    return 0;
}