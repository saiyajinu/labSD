#include <iostream>

using namespace std;

// prima litera din Nume sa fie intre A-E, F-J, K-O, P-T, U-Z;

struct Node{
    string nume;
    string prenume;
    Node* next;
};

Node* table[5];
Node *p = new Node();
Node *oldp = new Node();

void pushNode(int i, string nm, string prnm){
    if(table[i] == NULL){
        table[i] = new Node();
    }
    Node* n = new Node();
    n->nume = nm;
    n->prenume = prnm;
    n->next = table[i];
    table[i] = n;
}

void print(int i){
    p = table[i];
    if(p == NULL)
        cout<<"\tempty list\n";
    while(p != NULL){
        cout<<'\t'<<p->nume<<" "<<p->prenume<<endl;
        p = p->next;
    }
    cout<<endl;
}

void input(){
    cout<<"Add students (ctrl + Z = stop)"<<endl;
    string x, y;
    cout<<"First name: ";
    while(cin>>x){
        cout<<"Last name: ";cin>>y;
        if(x[0] < 'E'){
            pushNode(0,x,y);
        }
        else if(x[0] < 'J'){
            pushNode(1,x,y);
        }
        else if(x[0] < 'O'){
            pushNode(2,x,y);
        }
        else if(x[0] < 'T'){
            pushNode(3,x,y);
        }
        else if(x[0] < 'Z'){
            pushNode(4,x,y);
        }
        cout<<"\nFirst name: ";
    }
}

int getListNumber(string x){
    if(x[0] < 'E'){
            return 0;
        }
        else if(x[0] < 'J'){
            return 1;
        }
        else if(x[0] < 'O'){
            return 2;
        }
        else if(x[0] < 'T'){
            return 3;
        }
        else if(x[0] < 'Z'){
            return 4;
        }
}

void deleteStudent(string x, string y){
    int ok = 1;
    int i = getListNumber(x);
    //cout<<table[i]->nume;
    while(ok == 1){
        if(table[i] == NULL){
            cout<<"Student doesn't exist - list is empty!\n";
            ok = 0;
        }
        p = table[i];
        oldp = NULL;
        while(p != NULL && x != p->nume){
            oldp = p;
            p = p->next;
        }
        if(p == NULL){
            cout<<"Student doesn't exist!\n";
            ok = 0;
        }
        else{
            if(oldp != NULL){
                oldp->next = p->next;
                delete p;}
            else{
                table[i] = p->next;
                delete p;}
            cout<<"Student has been deleted"<<endl;
            ok = 0;
        }
    }
}

void findStudent(string x, string y){
    int ok = 1;
    int i = getListNumber(x);
    while(ok == 1){
        if(table[i] == NULL){
            cout<<"Student doesn't exist - list is empty!\n";
            ok = 0;
        }
        p = table[i];
        oldp = NULL;
        while(p != NULL && x != p->nume){
            oldp = p;
            p = p->next;
        }
        if(p == NULL){
            cout<<"Student doesn't exist!\n";
            ok = 0;
        }
        else{
            cout<<"Student has been found!\n";
            ok = 0;
        }
    }
}


int main()
{
    pushNode(0,"Andrei","David");
    pushNode(1,"Faresh","Andi");
    pushNode(2,"K","Bogdan");
    pushNode(3,"Popescu","Mihai");
    pushNode(3,"Protopop","Radu");
    input();
    cin.clear();
    for(int i = 0; i < 5; i++){
        if(i == 0){cout<<"A-E:"<<endl;}
        if(i == 1){cout<<"F-J:"<<endl;}
        if(i == 2){cout<<"K-O:"<<endl;}
        if(i == 3){cout<<"P-T:"<<endl;}
        if(i == 4){cout<<"U-Z:"<<endl;}
        print(i);
    }
    cout<<endl;
    string x, y;
    cout<<"Delete Student\nFirst Name: ";
    cin>>x;
    cout<<"Last Name: ";
    cin>>y;
    cout<<endl;
    deleteStudent(x,y);
    cout<<endl;
    cout<<endl;

    for(int i = 0; i < 5; i++){
        if(i == 0){cout<<"A-E:"<<endl;}
        if(i == 1){cout<<"F-J:"<<endl;}
        if(i == 2){cout<<"K-O:"<<endl;}
        if(i == 3){cout<<"P-T:"<<endl;}
        if(i == 4){cout<<"U-Z:"<<endl;}
        print(i);
    }

    cout<<"Find Student\nFirst Name: ";
    cin>>x;
    cout<<"Last Name: ";
    cin>>y;
    cout<<endl;
    findStudent(x,y);
    cout<<endl;
    cout<<endl;


    return 0;
}
