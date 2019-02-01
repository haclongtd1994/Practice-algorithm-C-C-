/*
 * Linked_list_1.cxx
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
int n;
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
Node *creatNode(int x){
	Node *p = new Node;
	if(p==NULL) exit(1);
	p->next = NULL;
	p->data = x;
	return p;
}
bool isEmpty(List l){
	if(l.head == NULL) return true;
	return false;
}
void addHead(List &l, int x){
	Node *p = creatNode(x);
	if(isEmpty(l)) l.head = l.tail = p;
	else{
		 p->next = l.head;
		 l.head = p;
	}
}
void addTail(List &l, int x){
	Node *p = creatNode(x);
	if(isEmpty(l))  addHead(l,x);
	else{
		l.tail->next = p;
		l.tail = p;
	}
}
Node *search(List l, int k){
	Node *p = l.head;
	while(p!=NULL){
		if(p->data == k) return p;
		else p = p->next;
	}
	return NULL;
}
void addMid(List &l, int x, int k){
	Node *p = search(l,k);
	if(p!=NULL){
		Node *q = creatNode(x);
		Node *r = p->next;
		p->next = q;
		q->next = r;
	}
}
void addAtk(List &l, int x, int k){
	if(isEmpty(l) || k<=1) addHead(l,x);
	else if(k>=n) addTail(l,x);
	else{
		Node *p = creatNode(x);
		Node *q = new Node;
		Node *w = new Node;
		Node *r = l.head;
		int dem=0;
		while(r!=NULL){
			dem++;
			q=r;
			if(dem==k) break;
			else r = r->next;
		}
		w = l.head;
		while(w->next != q)	w = w->next;
		w->next = p;
		p->next = r;
		
	}
}
void nhap(List &l){
	cout<<"\nNhap so phan tu ban dau cua list: ";cin>>n;
	for(int i=1;i<=n;i++)	addTail(l,i);
}
void xuat(List l){
	Node *p = l.head;
	while(p!=NULL){
		cout<<" "<<p->data;
		p = p->next;
	}
}


void menu(){
	List l;
	Init(l);
	nhap(l);
	xuat(l);
	int k,x,lc;
	do{
		cout<<"\n________MENU_________\n1_Chen Dau. \n2_Chen cuoi."0
			<<"\n3_Chen sau vi tri node data = x. \n4_chen sau vi tri bat ky."
			<<"\n5_Xuat thong tin List. \n0_Thoat.\n_Vui long chon ?";
		cin>>lc;
		switch(lc){
			case 0:	break;
			case 1: cout<<"\nNhap x: ";cin>>x;addHead(l,x);n++;break;
			case 2: cout<<"\nNhap x: ";cin>>x;addTail(l,x);n++;break;
			case 3: cout<<"\nNhap x, k: ";cin>>x>>k;addMid(l,x,k);n++;break;
			case 4: cout<<"\nNhap x, vi tri k: ";cin>>x>>k;addAtk(l,x,k);n++;break;
			case 5: xuat(l);break;
		}
	}while(lc!=0);
}


int main(int argc, char **argv)
{
	menu();
	return 0;
}

