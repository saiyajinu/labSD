#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int priority;
    Node* next;

};

Node *head = new Node();
Node *p = new Node();
Node *oldp = new Node();

void pushNode(Node** head, int x, int prio){
    Node* n = new Node();
    n->data = x;
    n->priority = prio;
    n->next = (*head);
    *head = n;
}

void insertNode(Node* p, int x, int prio){
    if (p == NULL){
     return;
    }
    Node* n = new Node();
    n->data = x;
    n->priority = prio;
    n->next = p->next;
    p->next = n;
}

void input(){
    int x, prio;
    cout<<"Add elements (ctrl + Z = stop)"<<endl;
    cout<<"Element value: ";cin>>x;
    cout<<"Element priority: ";cin>>prio;
    head->data = x;
    head->priority = prio;
    head->next = NULL;

    cout<<"Element value: ";
    while (cin>>x){
        cout<<"Element priority: ";cin>>prio;
        Node *p = head;

        if (prio < head->priority)
            pushNode(&head, x, prio);
        else
        while (p!=NULL){
            if(prio >= p->priority)
                if(p->next == NULL || p->next->priority > prio)
                {
                    insertNode(p, x, prio);
                    break;
                }
            p = p->next;
        }

        cout<<"Element value: ";
    }
}

void deleteElement(){
    int ok=1, el;
    cout<<"Delete element equal to ";
    cin>>el;
    while(ok){
        if(head == NULL){
            cout<<"Queue is empty"<<endl;
            ok = 0;
        }
        p = head;
        oldp = NULL;
        while(p != NULL && el != p->data){
            oldp = p;
            p = p->next;
        }
        if (p == NULL) {
            cout<<"Element doesn't exist"<<endl;
            ok = 0;
            }
        else{
            if(oldp != NULL){
                oldp->next = p->next;
                delete p;}
            else{
                head = p->next;
                delete p;}
            cout<<"Element has been deleted"<<endl;
            ok = 0;
        }
    }
}

void print(Node *node){
    if(node == NULL)
        cout<<"empty queue";
    while(node != NULL){
        cout<<node->data<<"("<<node->priority<<")  ";
        node = node->next;
    }
    cout<<endl;
}

void deleteQueue(){
    p = head;
    while(p!=NULL){
        head = p->next;
        delete p;
        p = head;
    }
}

int main()
{
    input();
    cout<<endl;
    print(head);
    cout<<endl;

    cin.clear();

    deleteElement();
    print(head);
    cout<<endl;

    cin.clear();

    deleteQueue();
    print(head);

    return 0;
}
