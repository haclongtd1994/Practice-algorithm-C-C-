/*
 * Queue_Linked_List.cxx
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
struct Queue{
	Node *head,*tail;
};
void Init(Queue &q){
	q.head = q.tail = NULL;
}
Node *createNode(int x){
	Node *q = new Node;
	if(q==NULL)		exit(1);
	q->data = x;
	q->next = NULL;
	return q;
}
bool isEmpty(Queue q){
	if(q.head==NULL)	return true;
	return false;
}
void push(Queue &q, int x){
	Node *p = createNode(x);
	if(isEmpty(q))	q.head = q.tail = p;
	else{
		q.tail->next = p;
		q.tail = p;
	}	
}
int pop(Queue &q){
	if(isEmpty(q))	exit(1);
	else{
		Node *temp = q.head;
		q.head = q.head->next;
		return temp->data;
		delete temp;
	}
	return 0;
}
int top(Queue q){
	if(q.head){
		return q.head->data;
	}
	return 0;
}
void nhap(Queue &q){
	int n=0,x=0;
	cout<<"Nhap cac du lieu input\n";
	cout<<"So luong phan tu: ";cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Phan tu thu "<<i+1<<": ";cin>>x;
		push(q,x);
	}
}
void xuat(Queue q){
	Node *p = q.head;
	cout<<endl;
	while(p!=NULL){
		cout<<" "<<p->data;
		p = p->next;
	}
}
void menu(){
	Queue q;
	Init(q);
	nhap(q);
	xuat(q);
	top(q);
	push(q,10);
	xuat(q);
	top(q);
	pop(q);
	xuat(q);
	top(q);
}
int main(int argc, char **argv)
{
	cout<<"..........................Lap ne mot danh sach Queue.................\n";
	menu();
	return 0;
}

