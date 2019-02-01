/*
 * Dequy.cxx
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
int temp[20];
int kq=0;

void xuat(int kq){
	cout<<"Ket qua cua bai toan sum of: "<<kq<<endl;
}

//tinh tong cua cac tich a*(i+2)
void Dequy(int n,int a){
	if(n==0){
		for(int i=1;i<=20;i++){
			if(temp[i]!='\0')		kq += temp[i];
		}
		xuat(kq/2);
	}
	else{ 
		temp[n]=(a*(n+2));
		Dequy(n-1,a);
	}
}

int main(int argc, char **argv)
{
	int a=0,n=0;
	cout<<"Vi du dung de quy\n";
	do{
		cout<<"Nhap vao bien a\n";
		cin>>a;
	}while(a<=1);
	do{
		cout<<"Nhap vao so luong n\n";
		cin>>n;
	}while(n<=1||n>20);
	Dequy(n,a);
	return 0;
}

