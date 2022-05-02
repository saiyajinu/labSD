#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

};

class Queue{
public:
    Node *ffront, *rear;
    Queue(){
        ffront = rear = NULL;
    }

    void insertQ (int val){
        Node* p = new Node();
        p->data = val;
        p->next = NULL;
        if (rear == NULL)
            ffront = p;
        else
            rear->next = p;
        rear = p;
    }

    void leaveQ(){
        if (ffront == NULL)
            return;
        else{
        Node* p = ffront;
        ffront = ffront->next;

        if(ffront == NULL)
            rear = NULL;

        delete p;
        }
    }
};




int main()
{
    Queue c1, c2, c3;
    //int x[20];
    int ok = 1;
    int n;
    int last;
    last = 1;
    n = 9;
    int x[9] = {3, 6, 9, 2 ,4, 7, 1, 8, 5};
//    cout<<"cate trenuri sunt: ";cin>>n;
//    cout<<"ordinea trenurilor: ";
//    for(int i = 0; i < n; i++){
//        cin>>x[i];
//    }
    for(int i = 0; i < n; i++){
        if(c1.rear == NULL){
            c1.insertQ(x[i]);
            cout<<"Se pune trenul "<<x[i]<<" pe sina 1"<<endl;
            continue;
        }
        if(c1.rear != NULL){
            if(x[i] > (c1.rear)->data){
                c1.insertQ(x[i]);
                cout<<"Se pune trenul "<<x[i]<<" pe sina 1"<<endl;
                continue;
                }
            }

        if(c2.rear == NULL){
            c2.insertQ(x[i]);
            cout<<"Se pune trenul "<<x[i]<<" pe sina 2"<<endl;
            continue;
        }
        if(c2.rear != NULL){
            if(x[i] > (c2.rear)->data){
                c2.insertQ(x[i]);
                cout<<"Se pune trenul "<<x[i]<<" pe sina 2"<<endl;
                continue;
                }
            }

        if(c3.rear == NULL){
            c3.insertQ(x[i]);
            cout<<"Se pune trenul "<<x[i]<<" pe sina 3"<<endl;
            continue;
        }
        if(c3.rear != NULL){
            if(x[i] > (c3.rear)->data){
                c3.insertQ(x[i]);
                cout<<"Se pune trenul "<<x[i]<<" pe sina 3"<<endl;
                continue;
                }
            }
        ok = 0;

    }

    if ( ok == 0){
        cout<<"Nu exista strategie de ordonare a trenurilor";
    }
    else
    while(last <= n){
        if(c1.ffront != NULL && c1.ffront->data == last){
            c1.leaveQ();
            cout<<"Trenul "<<last<<" de pe sina 1 pe sina finala"<<endl;
            last ++;
        }
        if(c2.ffront != NULL &&c2.ffront->data == last){
            c2.leaveQ();
            cout<<"Trenul "<<last<<" de pe sina 2 pe sina finala"<<endl;
            last ++;
        }
        if(c3.ffront != NULL && c3.ffront->data == last){
            c3.leaveQ();
            cout<<"Trenul "<<last<<" de pe sina 3 pe sina finala"<<endl;
            last ++;
        }
    }


    return 0;
}
