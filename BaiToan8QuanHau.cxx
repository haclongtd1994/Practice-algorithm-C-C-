/*
 * BaiToan8QuanHau.cxx
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
#include <cmath>
using namespace std;

int a[9];

void xuat(int n){
	for(int i=1;i<=n;i++)	cout<<" "<<a[i];
	cout<<endl;
}

bool OK(int x2, int y2){
	for(int i=1;i<x2;i++){
		if(a[i]==y2||abs(i-x2)==abs(a[i]-y2)) return false;
	}
	return true;
}

void Try(int i, int n){
	for(int j=1;j<=n;j++){
		if(OK(i,j)){
			a[i] = j;
			if(i==n) xuat(n);
			Try(i+1,n);
		}
	}
}

int main(int argc, char **argv)
{
	cout<<"Bai toan 8 quan hau"<<endl;
	int n=8;
	Try(1,n);
	return 0;
}

