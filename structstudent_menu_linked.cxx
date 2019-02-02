/*
 * structstudent_menu_linked
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
#include <string.h>
using namespace std;
int lc,insert,ndelete;

struct student{
	int age;
	char name[50];
};
struct Node{
	student data;
	Node *next;
};
struct List{
	Node *head;
	Node *tail;
};
bool isEmpty(List l){
	if(l.head == NULL)	return true;
	return false;
}
void Init(List &l){
	l.head = l.tail = NULL;
}
Node *createNode(student data){
	Node *p = new Node;
	if(p==NULL)	exit(1);
	p->data = data;
	p->next = NULL;
	return p;	
}
void addHead(List &l, student x){
	Node *p = createNode(x);
	if(isEmpty(l))	l.head = l.tail = p;
	else{
		p->next = l.head;
		l.head = p;
	}
}
void addTail(List &l, student x){
	Node *p = createNode(x);
	if(isEmpty(l))	addHead(l,x);
	else{
		l.tail->next = p;
		l.tail = p;
	}
}
Node *searchName(List l,student x){
	Node *p = l.head;
	while(p!=NULL){
		if(!strcmp(p->data.name,x.name)) return p;
		p = p->next;
	}
	return NULL;
}
Node *searchAge(List l,student x){
	Node *p = l.head;
	while(p!=NULL){
		if(p->data.age==x.age) return p;
		p = p->next;
	}
	return NULL;
}
Node *searchAgeName(List l,student x){
	Node *p = l.head;
	while(p!=NULL){
		if(!strcmp(p->data.name,x.name)&&p->data.age==x.age) return p;
		p = p->next;
	}
	return NULL;
}
void addMidAge(List &l, student x, student k){
	Node *p = searchAge(l,k);
	if(p!=NULL){
		Node *r = createNode(x);
		r->next = p->next;
		p->next = r;
	}
}
void addMidName(List &l, student x, student k){
	Node *p = searchName(l,k);
	if(p!=NULL){
		Node *r = createNode(x);
		r->next = p->next;
		p->next = r;
	}
}
void addMidAgeName(List &l, student x, student k){
	Node *p = searchAgeName(l,k);
	if(p!=NULL){
		Node *r = createNode(x);
		r->next = p->next;
		p->next = r;
	}
}
void delHead(List &l){
	if(isEmpty(l))		exit(1);
	else{
		Node *d = l.head;
		l.head = l.head->next;
		delete d;
	}
}
void delTail(List &l){
	if(isEmpty(l))		exit(1);
	else{
		Node *s = l.head;
		while(s->next != l.tail)	s = s->next;
		Node *d = l.tail;
		s->next = NULL;
		l.tail = s;
		delete d;
	}
}
void delMid(List &l, int pos){
	if(isEmpty(l))		exit(1);
	else{
		Node *p = l.head;
		int dem=0;
		while(p!=NULL){
			dem++;
			if(dem==pos)	break;
			p = p->next;
		}
		Node *t = p;
		t = t->next;
		p->next = t->next;
		delete t;
	}
}
void nhap(List &l){
	int sl;student dl;
	cout<<"Init Class First\nNumber of student want to create in your class\n";cin>>sl;
	for(int i=1;i<=sl;i++){
		cout<<"Name Student "<<i<<": ";cin>>dl.name;
		cout<<"Age Student "<<i<<": ";cin>>dl.age;
		addTail(l,dl);
	}
	cout<<"--------------------END_OF_INPUT----------------------------------\n";
}
void xuat(List l){
	int i=0;
	Node *p = l.head;
	cout<<"\n\n//////////////////////////////////////OUTPUT////////////////////////////////\n";
	while(p!=NULL){
		i++;
		cout<<"==========================STUDENT__"<<i<<"__DATA=================================\n";
		cout<<"Name of student "<<i<<": "<<p->data.name<<endl;
		cout<<"Age of student "<<i<<": "<<p->data.age<<endl;
		p = p->next;
	}
}
void menu(){
	List l;
	Init(l);
	nhap(l);
	xuat(l);
	student x,k;
	int pos;
	do{
		cout<<"==================Select Mode: =================\n1_____Insert\n2______Delete\n3______Display\n0_____exit\n";
		cin>>lc;
		switch(lc){
			case 0: break;
			case 1: 
					do{
						cout<<"==================Insert Mode: =================\n1_____Head\n2______Tail\n3______Age\n4______Name\n5______Age_N_Name\n6_____exit\n";
						cin>>insert;
						switch(insert){
							case 1: cout<<"Insert name and age: ";cin>>x.name>>x.age;addHead(l,x);break;
							case 2: cout<<"Insert name and age: ";cin>>x.name>>x.age;addTail(l,x);break;
							case 3: cout<<"Insert name, age and possition(age): ";cin>>x.name>>x.age>>k.age;addMidAge(l,x,k);break;
							case 4: cout<<"Insert name, age and possition(name): ";cin>>x.name>>x.age>>k.name;addMidName(l,x,k);break;
							case 5: cout<<"Insert name, age and possition(age&name): ";cin>>x.name>>x.age>>k.age>>k.name;addMidAgeName(l,x,k);break;
						}
					}while(insert!=6);
					break;
			case 2: 
					do{
						cout<<"==================Delete Mode: =================\n1_____Head\n2______Tail\n3______Possition\n4_____exit\n";
						cin>>ndelete;
						switch(ndelete){
							case 1: cout<<"Delete.................Head.......... ";delHead(l);break;
							case 2: cout<<"Delete.................Tail..........";delTail(l);break;
							case 3: cout<<"Delete.................Possiton..........";cin>>pos;delMid(l,pos-1);break;
						}
					}while(ndelete!=4);
					break;
			case 3: 
					xuat(l);
					break;
		}
	}while(lc!=0);
}
int main(int argc, char **argv)
{
	cout<<"                 _____Linked_List_With_Data_Student_____\n";
	menu();
	return 0;
}

