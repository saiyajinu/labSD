#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head = new Node();
Node *p = new Node();
Node *oldp = new Node();
int x;

void pushNode(Node** head, int x){
    Node* n = new Node();
    n->data = x;
    n->next = (*head);
    *head = n;
}

void input(){
    cout<<"Add elements (ctrl + Z = stop)"<<endl;
    cin>>x;
    head->data = x;
    head->next = NULL;
    while(cin>>x){
        pushNode(&head, x);
    }
}

void print(Node *node){
    if(node == NULL)
        cout<<"empty list";
    while(node != NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

void deleteNode(Node *p){
    if ( p->next == NULL)
        p = NULL;
    else{
        p->data = p->next->data;
        p->next = p->next->next;
        delete p->next;
    }
}

int main()
{
    input();
    print(head);

    p = head;
    p = p->next;
    p = p->next;

    deleteNode(p);
    print(head);

    return 0;
}
