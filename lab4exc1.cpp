#include <iostream>

using namespace std;

struct Node{
    int data;
    int prio;
    Node *next;
};

Node *frontt = new Node();
Node *p = new Node();
Node *rear = new Node();
int x, prio;

void insertNode(int x, int prio){
    if (p == NULL){
     return;
    }
    Node* n = new Node();
    n->data = x;
    n->prio = prio;
    n->next = NULL;
    rear->next = n;
    rear = n;
}

void input(){
    cout<<"Add elements (ctrl + Z = stop)"<<endl;
    cin>>x;
    cout<<"priority = "; cin>>prio;
    frontt->data = x;
    frontt->prio = prio;
    frontt->next = rear;
    cin>>x;
    cout<<"priority = "; cin>>prio;
    rear->data = x;
    rear->prio = prio;
    rear->next = NULL;

    while(cin>>x){
        cout<<"priority = "; cin>>prio;
        insertNode(x, prio);
    }
}

void print(){
    if(frontt == NULL)
        cout<<"empty queue";
    p = frontt;
    while(p != NULL){
        cout<<p->data<<"("<<p->prio<<") ";
       // cout<<p->next->data;
        p = p->next;
       // cout<<rear->data;
    }
    cout<<endl;
}

int main()
{
    input();
    print();

    return 0;
}
