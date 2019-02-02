/*
 * BT_Linked_List_1.cxx
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
Node *createNode(int x){
	Node *p = new Node;
	if(p==NULL)	exit(1);
	p->data = x;
	p->next = NULL;
	return p;
}
bool isEmpty(List l){
	if(l.head==NULL)	return true;
	return false;
}
void addHead(List &l, int x){
	Node *p = createNode(x);
	if(isEmpty(l))	l.head = l.tail = p;
	else{
		p->next = l.head;
		l.head = p;
	}
}
void addTail(List &l, int x){
	Node *p = createNode(x);
	if(isEmpty(l))	addHead(l,x);
	else {
		l.tail->next = p;
		l.tail = p;
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
	Node *p = search(l, k);
	if(p!=NULL){
		Node *q = createNode(x);
		Node *r = p->next;
		p->next = q;
		q->next = r;
	}
}
void addAtk(List &l, int x, int k){
	int dem=0;
	if(isEmpty(l)||n<=1) addHead(l,x);
	else if(k>=n)	addTail(l,x);
	else{
		Node *p = createNode(x);
		Node *w = new Node;
		Node *temp_1 = l.head;
		while(temp_1!=NULL){
			dem++;
			if(dem==k) 	break;
			else temp_1 = temp_1->next;
		}
		w = temp_1;
		temp_1->next = p;
		temp_1->next = w;
	}
}
void nhap(List &l){
	cout<<"Nhap vao so phan tu dau tien cua mang\n";cin>>n;
	for(int i=1;i<=n;i++) addTail(l,i);
}
void xuat(List l){
	Node *p = l.head;
	while(p!=NULL){
		cout<<" Data "<<p->data;
		p = p->next;
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
		cout<<"\n______SELECT________\n1__Chen vao dau node.\n2__Chen vao cuoi node."
			<<"\n3__Chen vao vi tri co data la k gia tri = x.\n4__Chen vao vi tri bat ky."
			<<"\n5__Liet ke danh sach cac node.\n0__Thoat chuong trinh.\n";
		cin>>lc;
		switch(lc){
			case 0: cout<<"Chuong trinh ket thuc\n";break;
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
	cout<<"Menu linked list________"<<endl;
	menu();
	return 0;
}

