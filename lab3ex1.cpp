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

void insertNode(Node* p, int x){
    if (p == NULL){
     return;
    }
    Node* n = new Node();
    n->data = x;
    n->next = p->next;
    p->next = n;
}

void deleteList(){
    p = head;
    while(p!=NULL){
        head = p->next;
        delete p;
        p = head;
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

void orderInput(){
    cout<<"Add elements (ctrl + Z = stop)"<<endl;
    cin>>x;
    head->data = x;
    head->next = NULL;

    while(cin>>x){
        Node *p = head;
        if(x < head->data)
            pushNode(&head,x);
        else
            while(p != NULL){
                if(p->data <= x){
                        //cout<<"primif"<<endl;
                    if(p->next == NULL || p->next->data > x){
                        insertNode(p, x);
                        //print(head);
                       // cout<<endl;
                        break;
                    }
                }
                p = p->next;
            }
        }
    }

void deleteElement(){
    int ok=1, el;
    cout<<"Delete element equal to ";
    cin>>el;
    while(ok){
        if(head == NULL){
            cout<<"List is empty"<<endl;
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

int main()
{
    orderInput();
    print(head);

    cin.clear();

    deleteElement();
    print(head);


    deleteList();
    print(head);

    return 0;
}
