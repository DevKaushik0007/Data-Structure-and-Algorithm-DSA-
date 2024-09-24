#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printList(list<int> ll){
    list<int>::iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout<<(*itr)<<" -> ";
    }
    cout<<" NULL "<<endl;
}

int main(){
    list<int> ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(5);
    ll.push_back(6);

    printList(ll);
    cout<<"head = "<<ll.front()<<"\n";
    cout<<"tail = "<<ll.back()<<"\n";
    return 0;
}