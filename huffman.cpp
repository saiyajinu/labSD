#include <iostream>

using namespace std;


struct Node{
    char letter;
    int priority;
    Node* next;
    Node* left;
    Node* right;

};

Node *head = new Node();
Node *p = new Node();
Node *auxp = new Node();

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

Node* newNode(Node* p){
    Node* n = new Node();
    n->letter = p->letter;
    n->priority = p->priority;
    n->left = p->left;
    n->right = p->right;
    return n;
}

void Huff(Node** head){
    while(qSize() > 1){
        Node* aux;
        aux = new Node();
        aux->letter = '*';
        aux->priority = (*head)->priority + (*head)->next->priority;
        aux->left = newNode(*head);
        aux->right = newNode((*head)->next);



        deleteFirst();
        deleteFirst();

        p = (*head);
       if((*head) !=NULL){
            if( aux->priority < (*head)->priority){
                aux->next = (*head);
                (*head) = aux;
            }
            else
                while (p!=NULL){
                    if(aux->priority >= p->priority)
                        if(p->next == NULL || p->next->priority > aux->priority)
                        {
                                aux->next = p->next;
                                p->next = aux;
                            break;
                        }
                    p = p->next;
                }
       }
        else{
            aux->next = (*head);
                (*head) = aux;
        }
    }
}

void writeSRD(Node* head){
    if(head == NULL)
        return;
    else {
        writeSRD(head->left);
        cout<<head->letter<<" ";
        writeSRD(head->right);
    }
}

struct HuffMatrix{
    char letter;
    string encoding;
}codes[54];

int it;
string code = "";

string matrixLetterCode(char letter){
    int i;
    for( i = 0; i < it; i++){
        if (codes[i].letter == letter)
         break;
    }
    return codes[i].encoding;
}

void writeHuffCode(Node* head){
    if(head == NULL)
        return;
    else{
        if(head->letter != '*'){
            codes[it].letter = head->letter;
            codes[it].encoding = code;
            ++it;
            return;
        }

        code += '0';
        writeHuffCode(head->left);
        code.pop_back();

        code += '1';
        writeHuffCode(head->right);
        code.pop_back();
    }
}

void encodeWord(string &encoding){
    char in;
    cout<<"Encode word (ctrl + Z at the end)"<<endl;
    while(cin>>in){
        encoding+=matrixLetterCode(in);
   }
}

void decodeWord(string decode){
    int i;
    p = head;
    for(i = 0; i<decode.size(); i++){
            if(p != NULL){
                if(decode[i] == '0')
                    p = p->left;
                else p = p->right;

                if(p->letter != '*'){
                    cout<<p->letter;
                    p = head;
                }
            }
            else{
                cout<<"\nwrong input to decode";
                break;
            }
        }
    }

int main() {
    input();
    cin.clear();
    cout<<endl;
    print(head);

//    cout<<endl;
//    cout<<"queue initial size: "<<qSize()<<endl;
//    cout<<endl;

    Huff(&head);

//    print(head);
//    cout<<endl;
//    cout<<head->priority<<endl;
//    cout<<head->left->priority<<endl;
//    cout<<head->right->priority<<endl;

//    writeSRD(head);
//    cout<<endl;

    writeHuffCode(head);

    for(int i = 0; i < it; i++){
        cout<<codes[i].letter<<' '<<codes[i].encoding<<endl;
    }
    string encoding="";
    encodeWord(encoding);
    cin.clear();

    cout<<endl;
    cout<<encoding;
    cout<<endl;

    string decode;
    cout<<"String to decode: ";
    cin>>decode;
    decodeWord(decode);




    return 0;
}
