#include <iostream>
#include <string.h>

using namespace std;

struct node{
    char* data;
    node* left;
    node* right;
};

node* root = NULL;

node* newNode(char* data){
    node* aux = new node;
    aux->data = new char[strlen(data)+1];
    strcpy(aux->data, data);
    aux->left = NULL;
    aux->right = NULL;
    return aux;
}

node* insertNode(node* root, char* data){
    node* newnode = newNode(data);
    node* p = root;
    node* p1 = NULL;

    while(p != NULL){
        p1 = p;
        if(strcmp(data, p->data) > 0)
            p = p->left;
        else
            p = p->right;
    }

    if(p1 == NULL)
        p1 = newnode;
    else if(strcmp(data, p1->data) > 0)
        p1->left = newnode;
    else
        p1->right = newnode;
    return p1;
}

void readSRD(node* root)
{
    if(root == NULL)
        return;
    else {
        readSRD(root->left);
        cout<<root->data<<" ";
        readSRD(root->right);
    }
}

int main()
{
    char str[100];
    char* tok;
    cout<<"Input string: ";
    cin.get(str, 100);
    tok = strtok(str, " ");
    root = insertNode(root, tok);
    tok = strtok(NULL, " ");
    while(tok != NULL){
        insertNode(root, tok);
        tok = strtok(NULL, " ");
    }
    readSRD(root);

    return 0;
}
