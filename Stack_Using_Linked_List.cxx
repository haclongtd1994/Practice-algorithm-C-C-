/*
 * Stack_Using_Linked_List.cxx
 * 
 * Copyright 2019 PhanThanhHung <phanthanhhung@phanthanhhung-Inspiron-3543>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};
struct List{
	Node *tail;
	Node *head;
};
void Init(List &l){
	l.head = l.tail = NULL;
}
bool isEmpty(List l){
	bool temp;
	(l.head==NULL)?		temp=true:false;
	return temp;
}
Node *createNode(int x){
	Node *p = new Node;
	if(p==NULL) exit(1);
	p->data = x;
	p->next = NULL;
	return p;
}
void push(List &l, int x){
	Node *p = createNode(x);
	if(isEmpty(l))	l.head = l.tail = p;
	else{
		p->next = l.head;
		l.head = p;
	}
}
void pop(List &l){
	if(isEmpty(l))	exit(1);
	else{
		Node *p = l.head;
		l.head = l.head->next;
		delete p;
	}
}
void nhap(List &l){
	int n=0,x=0;
	cout<<"\nInput number stack: ";cin>>n;
	for(int i =1;i<=n;i++){
		cout<<"Stack "<<i<<": ";cin>>x;
		push(l,x);
	}
}
void xuat(List l){
	cout<<"\n==============================OutPut=================\n";
	Node *p = l.head;
	while(p!=NULL){
		cout<<p->data<<endl;
		p = p->next;
	}
}
void menu(){
	List l;
	Init(l);
	nhap(l);
	xuat(l);
	
	push(l,100);
	xuat(l);
	pop(l);
	xuat(l);
	pop(l);
	xuat(l);
	
}
int main(int argc, char **argv)
{
	cout<<"Linked List to create Stack\n";
	menu();
	return 0;
}

