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
    ~Node(){
        if(next != NULL){
            // cout<<"~Node"<<data<<endl;
            delete next;
            next = NULL;
        }
    }
};

class List{
    Node* head;
    Node* tail;
    public:
    List(){
        head = NULL;
        tail = NULL;
    }
    ~List(){
        if(head != NULL){
            // cout<<"~List"<<endl;
            delete head;
            head = NULL;
        }
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

    void insert_Middle(int val,int pos){
        Node* newNode = new Node(val);
        Node* prev = head;
        for(int i = 0; i < pos - 1; i++){
            if(prev == NULL){
                cout<<"Position is INVALID"<<endl;
                return;
            }
            prev = prev->next;
        } 
        newNode->next = prev->next;
        prev->next = newNode;
    }

    void pop_Front(){
        if(head == NULL){
            cout<<"LinkedList is Empty";
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

    }
    void pop_Back(){
        if(head == NULL){
            cout<<"LinkedList is Empty";
            return;
        }
        Node* temp = head;
        while(temp->next->next !=  NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;

    }

    int searchItr(int key){
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    void printList(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data;
            temp = temp->next;
            cout<<" ";
        }
        cout<<endl;
    }

// SEARCH RECURSIVELY :-

    int helper(Node* h,int key){
        if(h == NULL){
            return -1;
        }
        if(h->data == key){
            return 0;
        }
        int idx = helper(h->next,key);
        if(idx == -1){
            return -1;
        }
        return idx + 1;
    }
    int searchRec(int key){
        return helper(head,key);
    }

    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    int getSize(){
        int sz = 0;
        Node* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            sz++;
        }
        return sz;
    }
    void removeNth(int n){
        int size = getSize();
        Node* prev = head;
        for(int i = 1; i < (size - n); i++){
            prev = prev->next; 
        }
        Node* toDel = prev->next;
        cout<<"deleted element is: "<<toDel->data<<endl;
        prev->next = prev->next->next;
    }
    
};


int main(){
    int key = 0;
    List ll;
    ll.push_Front(3);
    ll.push_Front(2);
    ll.push_Front(1);
    ll.push_Back(4);
    ll.push_Back(5);
    // ll.insert_Middle(200,3);
    ll.printList();
    // ll.pop_Front();
    // ll.pop_Back();
    // cout<<"After pop data from head and tail"<<endl;
    // ll.printList();
    // cout<<"Enter the element to be search: ";
    // cin>>key;
    // cout<<ll.searchRec(key)<<endl;
    // cout<<"Linked List in Reverse Order:"<<endl;
    // ll.reverse();
    // ll.printList();
    ll.removeNth(4);
    ll.printList();
    return 0;
}