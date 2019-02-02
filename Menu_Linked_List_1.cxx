/*
 * Menu_Linked_List_1.cxx
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
int n=0;

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
bool isEmpty(List l){
	if(l.head == NULL) return true;
	return false;
}
Node *createNode(int x){
	Node *p = new Node;
	if(p==NULL) exit(1);
	p->data = x;
	p->next = NULL;
	return p;
}
void addHead(List &l, int x){
	Node *p = createNode(x);
	if(isEmpty(l)) l.head = l.tail =p;
	else{
		p->next = l.head;
		l.head = p;
	}
}
void addTail(List &l, int x){
	Node *p = createNode(x);
	if(isEmpty(l)) addHead(l,x);
	else{
		l.tail->next = p;
		l.tail = p;
		
	}
}

void nhap(List &l){
	int dl,x;
	do{
		cout<<"Vui long nhap so luong phan tu: ";cin>>x;
	}while(x>50);
	for(int i=1;i<=x;i++){
		cout<<"Nhap vao du lieu thu "<<i<<": ";cin>>dl;
		addTail(l,dl);
	}
}
void xuat(List l){
	Node *p = l.head;
	cout<<"Du lieu xuat ra:";
	while(p!=NULL){
		cout<<" "<<p->data;
		p = p->next;
	}
}
Node *search(List l, int x){
	Node *p = l.head;
	while(p!=NULL){
		if(p->data == x) return p;
		p = p->next;
	}
	return NULL;
}
void addMid(List &l, int x, int k){
	Node *p = search(l,k);
	if(p!=NULL){
		Node *r = createNode(x);
		r->next = p->next;
		p->next = r;
	}
	else{
		cout<<"Data not found ...\n";
	}
}
void addAtk(List &l, int x, int k){
	if(isEmpty(l)||k<=1)	addHead(l,x);
	else if(k>=10)			addTail(l,x);
	else{
		int dem=0;
		Node *p = l.head;
		while(p!=NULL){
			if(dem==k) break;
			dem++;
			p = p->next;
		}
		Node *r = createNode(x);
		r->next = p->next;
		p->next = r;
	}
}
void menu()
{
	List l;
	Init(l);
	nhap(l);
	xuat(l);
	int k,x,lc;
	do{
		cout<<"\nSelect che do cua menu linked list: \n1__Them du lieu vao node dau."
			<<"\n2__Them vao sau node cuoi.\n3__Them du lieu x sau node co du lieu k."
			<<"\n4__Them du lieu vao vi tri bat ky.\n5__Xuat ket qua cac du lieu trong node.\n"
			<<"\n0__Exit menu\n\n";
		cin>>lc;
		switch(lc){
			case 0: cout<<"Exiting ....";break;
			case 1: cout<<"Nhap x: ";cin>>x;addHead(l,x);n++;break;
			case 2: cout<<"Nhap x: ";cin>>x;addTail(l,x);n++;break;
			case 3: cout<<"Nhap x, k: ";cin>>x>>k;addMid(l,x,k);n++;break;
			case 4: cout<<"Nhap x, k: ";cin>>x>>k;addAtk(l,x,k);n++;break;
			case 5: xuat(l);break;
		}
	}while(lc!=0);
}
int main(int argc, char **argv)
{
	cout<<"________MENU_______LINKED______LIST______"<<endl;
	menu();
	return 0;
}

