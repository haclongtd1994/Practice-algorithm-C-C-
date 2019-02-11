/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};
struct List{
    Node *head;
    Node *tail;
};
void Init(List &l){
    l.head = l.tail = NULL;
}
Node *createNode(int x){
    Node *p = new Node;
    if(p==NULL) exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}
bool isEmpty(List l){
    if(l.head == NULL)  return true;
    else return false;
}
void addHead(List &l, int x){
    Node *p = createNode(x);
    if(isEmpty(l))  l.head = l.tail = p;
    else{
        p->next = l.head;
        l.head = p;
        l.tail->next = l.head;
    }
}
void nhap(List &l){
    int n,k;
    cout<<"Number of sll: ";cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Data of "<<i+1<<": ";cin>>k;
        addHead(l,k);
    }
}
Node *search(List l, int x){
    Node *p = l.head;
    do{
        if(p->data == x) return p;
        p = p->next;
    }while(p!=l.head);
    return NULL;
}
void xuat(List l){
    cout<<"\nData typed: \n";
    int sl=1;
    Node *p = l.head;
    do{
        cout<<"Data "<<sl<<": "<<p->data<<endl;
        sl++;
        p = p->next;
    }while(p!=l.head);
}
void addMid(List &l, int x, int k){
    Node *p = search(l,k);
    if(p!=NULL){
        Node *q = createNode(x);
        q->next = p->next;
        p->next = q;
    }
}
void menu(){
    List l;
    Init(l);
    nhap(l);
    xuat(l);
    addMid(l,10,3);
    xuat(l);
}

int main()
{
    cout<<"Hello to circle linked list\n";
    menu();
    return 0;
}
