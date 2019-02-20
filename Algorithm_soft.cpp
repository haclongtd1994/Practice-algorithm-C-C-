#include<iostream>
using namespace std;
int arr[10]={10,50,20,65,4,52,42,58,75,50};
int arr2[10]={45,6453,56,124,4,578,245,354,214,354};
typedef void (*Function_Sort)(int arr[], int low, int high);
struct Data{
	int *arr;
	Function_Sort function;
};

////////////////////////////////////Function Public///////////////////////////////////////
void swap(int &a, int &b){
	int t=a;
	a=b;
	b=t;
}
/////////////////////////////////////////BUBBLE SORT//////////////////////////////////////
int bubble_sort(int arr[]){
	for(int i=0;i<10;i++){
		for(int j=9;j>i;j--){
			if(arr[j-1]>arr[j]){
				swap(arr[j-1],arr[j]);
			}
		}
	}
}
/////////////////////////////////////////QUICK SORT//////////////////////////////////////
int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int left = low;
	int right = high - 1;
	while(1){
		while(left<=right&&arr[left]<pivot) left++;
		while(right>=left&&arr[right]>pivot) right--;
		if(left>=right)	break;
		swap(arr[left],arr[right]);
		left++;
		right--;
	}
	swap(arr[left],arr[high]);
	return left;
}
void quick_sort(int arr[],int low, int high){
	if(low<high){
		int pi = partition(arr,low,high);
		quick_sort(arr,low,pi-1);
		quick_sort(arr,pi+1,high);
	}
}
/////////////////////////////////////////MERGE SORT//////////////////////////////////////
void merge(int arr[], int l,int m, int r){
	int i,j,k;
	int n1 = m - l +1;
	int n2 = r - m;
	int L[n1], R[n2];
	for(i=0;i<n1;i++)
		L[i] = arr[l+i];
	for(j=0;j<n2;j++)
		R[j] = arr[m+1+j];
	i=j=0;k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k] = L[i];
		i++;k++;
	}
	while(j<n2){
		arr[k] = R[j];
		j++;k++;
	}
}
void merge_sort(int arr[], int l, int r){
	if(l<r){
		int m = l + (r-l)/2;
		merge_sort(arr,l,m);	//phan chia phan ben trai
		merge_sort(arr,m+1,r);	//phia chia phan ben phai
		merge(arr,l,m,r);			//ghep lai	
	}
}


void printarr(int arr[]){
	for(int i=0;i<10;i++)
		cout<<"Number "<<i+1<<": "<<arr[i]<<endl;
}

void menu(Data &dulieu){
	int n=0;
	do{
		cout<<"Menu Select: \n1__Bubble sort\n2__Merge sort\n3__Quick sort\n4__Print Arr\n5__Test Function Pointer\n0__quit\n";
		cin>>n;
		switch(n){
			case 1:		bubble_sort(arr);
						break;
			case 2:		merge_sort(arr,0,9);
						break;
			case 3:		quick_sort(arr,0,9);
						break;
			case 4:		printarr(arr);
						break;
			case 5:		dulieu.function(dulieu.arr,0,9);
						printarr(dulieu.arr);
						break;
		}
	}while(n!=0);
}

int main(){
	cout<<"Algorithm sort\n";
	Data dulieu;
	dulieu.arr = arr2;
	dulieu.function = merge_sort;
	menu(dulieu);
	return 0;
}

