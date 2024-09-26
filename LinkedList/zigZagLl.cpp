#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
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

    void pushFront(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
        newNode->next = head;
        head = newNode;
        }
    }

};

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast != NULL && fast->next != NULL){
        
        prev = slow ;
        slow = slow->next;
        fast = fast->next->next;
    }
        if(prev != NULL){
            prev->next = NULL;
        }
    
    return slow;
}

Node* zigZag(Node* head){
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    // Alternate merging:-

    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = right;
    while(left != NULL && right != NULL){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;

      tail = nextLeft ? nextLeft : right; // Update tail
        left = nextLeft;
        right = nextRight;
    }
    if(right != NULL){
        tail->next = right;
    }
    return head;
}

int main(){
    List ll;
    ll.pushFront(5);
    ll.pushFront(4);
    ll.pushFront(3);
    ll.pushFront(2);
    ll.pushFront(1);
    printLL(ll.head);
    ll.head = zigZag(ll.head);
    printLL(ll.head);
    return 0;
}
