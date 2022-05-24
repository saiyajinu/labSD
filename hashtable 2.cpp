#include <iostream>

using namespace std;

struct Node{
    char letter;
    int k;
};

Node table[11];

void setNode(char letter, int k){
    int i = (k%11);
    if(table[i].k == 0){
        table[i].k = k;
        table[i].letter = letter;
        }
    else{
        int ok = 0;
        for(int index = i + 1; index<11 && ok == 0;index++){
            if(table[index].k == 0){
                table[index].k = k;
                table[index].letter = letter;
                ok = 1;
            }
        }
        for(int index = 0; index<i && ok == 0;index++){
            if(table[index].k == 0){
                table[index].k = k;
                table[index].letter = letter;
                ok = 1;
            }
        }
        if(ok == 0)
            cout<<"Table is full! Ctrl+Z to stop\n";

    }
}

void printTable(){
    for(int i = 0; i<11; i++){
        if(table[i].k != 0){
            cout<<table[i].letter<<' '<<table[i].k<<endl;
        }
        else cout<<"empty\n";
    }
}

void Input(){
    cout<<"Add nodes (ctrlZ)\n";
    char x;
    int y;
    cout<<"Letter: ";
    while(cin>>x){
        cout<<"Key: ";
        cin>>y;
        setNode(x, y);
        cout<<"Letter: ";
    }
}

int main()
{
    Input();
    printTable();
    return 0;
}
