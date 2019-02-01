/*
 * Thap_Ha_Noi.cxx
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


void chuyen(int n, char a, char b){
	cout<<"Chuyen dia thu "<<n<<" tu coc "<<a<<" sang coc "<<b<<endl;
}

void thaphanoi(int n, char a, char b, char c){
	if(n==1)	chuyen(n,a,c);
	else{
		thaphanoi(n-1,a,c,b);
		chuyen(n,a,c);
		thaphanoi(n-1,b,a,c);
	}
}

int main(int argc, char **argv)
{
	int n=0;
	cout<<"Bai toan thap ha noi"<<endl;
	char a='A', b='B', c='C';
	do{
		cout<<"Nhap vao so luong dia"<<endl;
		cin>>n;
	}while(n>8);
	thaphanoi(n, a,b,c);
	return 0;
}

