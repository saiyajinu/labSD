#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head = new Node();
Node *p = new Node();

void pushNode(int x){
    Node* n = new Node();
    n->data = x;
    n->next = head;
    head = n;
}

void popNode(int &popres){
    Node* temp;
    if(head == NULL)
        return;
    else{
        temp = head;
        popres = temp->data;
        head = head->next;
        delete temp;
    }
}

int popres;
int frec[20];
int arr[20];
int n;
int ok = 1;

int main()
{
    cout<<"n = ";cin>>n;
    cout<<"vectorul alaturat = ";
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n && ok == 1; i++){
        pushNode(arr[i]);
        frec[arr[i]]++;
        if (frec[arr[i]] == 2){
            popNode(popres);
            popNode(popres);
            if (popres != arr[i])
                ok=0;
        }
    }

    if(ok == 1)
        cout<<"valid";
    else
        cout<<"invalid";
    return 0;
}
