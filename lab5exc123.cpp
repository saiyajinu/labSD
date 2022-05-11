#include <iostream>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* root = NULL;

node* newNode(int data){
    node* aux = new node;
    aux->data = data;
    aux->left = NULL;
    aux->right = NULL;
    return aux;
}

node* insertNode(node* root, int data){
    node* newnode = newNode(data);
    node* p = root;
    node* p1 = NULL;

    while(p != NULL){
        p1 = p;
        if(data < p->data)
            p = p->left;
        else
            p = p->right;
    }

    if(p1 == NULL)
        p1 = newnode;
    else if(data < p1->data)
        p1->left = newnode;
    else
        p1->right = newnode;
    return p1;
}

void input(){
    int x;
    cout<<"Add nodes (ctrl + Z = stop)"<<endl;
    cout<<"Node value: ";cin>>x;
    root = insertNode(root, x);

    cout<<"Node value: ";
    while (cin>>x){
            insertNode(root, x);
            cout<<"Node value: ";
    }
}

void readRSD(node* root){
    if(root == NULL)
        return;
    else{
        cout<<root->data<<" ";
        readRSD(root->right);
        readRSD(root->left);
    }
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

void readSDR(node* root){
    if(root == NULL)
        return;
    else{
        readSDR(root->left);
        readSDR(root->right);
        cout<<root->data<<" ";
    }
}

node* deleteNode(node* root, int data){
    if(root == NULL)
        return root;

    if(data < root->data)
        root->left = deleteNode(root->left, data);
    else if(data > root->data)
        root->right = deleteNode(root->right, data);
    else{
        if(root->left == NULL and root->right == NULL)
            return NULL;
        else if(root->left == NULL){
            node* aux = root->right;
            delete root;
            return aux;
        }
        else if(root->right == NULL){
            node* aux = root->left;
            delete root;
            return aux;
        }
    }
}
void readBetweenValues(node *root, int k1, int k2){
    if(root == NULL)
        return;
    if(k1 < root->data)
        readBetweenValues(root->left, k1, k2);
    if ( k1 <= root->data && k2 >= root->data )
        cout<<root->data<<" ";
    readBetweenValues(root->right, k1, k2);
}


int main()
{
    input();

    cin.clear();

    readRSD(root);
    cout<<endl;

    readSRD(root);
    cout<<endl;

    readSDR(root);
    cout<<endl;

    int del;
    cout<<"Node to delete: ";
    cin>>del;
    deleteNode(root, del);
    cout<<endl;

    readSRD(root);
    cout<<endl;

    int k1, k2;
    cout<<"Search between two nodes";
    cout<<endl;
    cout<<"k1 = ";
    cin>>k1;
    cout<<"k2 = ";
    cin>>k2;
    readBetweenValues(root, k1, k2);

    return 0;
}

