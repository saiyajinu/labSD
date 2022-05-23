#include <iostream>

using namespace std;


//Priority Queue
struct Node{
    char letter;
    int priority;
    Node* next;
    Node* left;
    Node* right;

};

Node *head = new Node();
Node *p = new Node();
Node *oldp = new Node();

void pushNode(Node** head, char x, int prio){
    Node* n = new Node();
    n->letter = x;
    n->priority = prio;
    n->next = (*head);
    n->right = NULL;
    n->left = NULL;
    *head = n;
}

void insertNode(Node* p, char x, int prio){
    if (p == NULL){
        return;
    }
    Node* n = new Node();
    n->letter = x;
    n->priority = prio;
    n->next = p->next;
    n->right = NULL;
    n->left = NULL;
    p->next = n;
}

void input(){
    char x;
    int prio;
    cout<<"Add letters (ctrl + Z = stop)"<<endl;
    cout<<"Letter: ";cin>>x;
    cout<<"Frequency: ";cin>>prio;
    head->letter = x;
    head->priority = prio;
    head->next = NULL;

    cout<<"Letter: ";
    while (cin>>x){
        cout<<"Frequency: ";cin>>prio;
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

        cout<<"Letter: ";
    }
}

void deleteFirst(){
    int ok = 1;
    if(head == NULL && head->next == NULL){
        ok = 0;
    }
    if(ok == 1){
        p = head;
    head = p->next;
    delete p;
    }
}

int qSize(){
    int k = 0;
    if(head == NULL)
        return 0;
    ++k;
    p = head;
    while(p->next != NULL){
        p = p->next;
        ++k;
    }
    return k;
}

void print(Node *node){
    if(node == NULL)
        cout<<"empty queue";
    while(node != NULL){
        cout<<node->letter<<"("<<node->priority<<")  ";
        node = node->next;
    }
    cout<<endl;
}

void Huff(){
    while(qSize() > 1){
        Node* aux;
        aux = new Node();
        aux->letter = '*';
        aux->priority = head->priority + head->next->priority;
        aux->left = new Node();
        aux->left = head;
        aux->right = new Node();
        aux->right = head->next;

        deleteFirst();
        deleteFirst();

        aux->next = head;
        head = aux;
    }
}

void readSRD(Node* head){
    if(head == NULL)
        return;
    else {
        readSRD(head->left);
        cout<<head->letter<<" ";
        readSRD(head->right);
    }
}

int main() {
    input();
    cout<<endl;
    print(head);
    cout<<endl;
    cout<<"queue initial size: "<<qSize();
    cout<<endl;
    Huff();
    print(head);
    cout<<endl;
    cout<<head->priority<<endl;
    cout<<head->left->priority<<endl;
    cout<<head->right->priority<<endl;

    //readSRD(head);

    return 0;
}
