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

node *LCA(node* root, int k1, int k2)
{
    if (root == NULL) return NULL;

    if (root->data > k1 && root->data > k2)
        return LCA(root->left, k1, k2);


    if (root->data < k1 && root->data < k2)
        return LCA(root->right, k1, k2);

    return root;
}

int main()
{
    input();

    cin.clear();

    int k1, k2;
    cout<<"Values for LCA:\nk1 = ";cin>>k1;
    cout<<"k2 = ";cin>>k2;
    node* lcarez = LCA(root, k1, k2);
    cout<<"LCA of the two values is "<<lcarez->data;

    return 0;
}
