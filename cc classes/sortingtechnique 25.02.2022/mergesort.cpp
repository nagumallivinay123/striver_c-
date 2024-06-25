#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 1;
int a[N];
 
 
// L = l ..... mid || R = mid+1 ...... r
void merge(int l, int mid, int r){
 
	int left_size = mid - l + 1;
 
	int right_size = r - (mid+1) + 1;	// r - mid
 
	int L[left_size+1];
	int R[right_size+1];

 
	for(int i = 0;i<left_size;i++){
		L[i] = a[i + l];
	}
	for(int i =0;i<right_size;i++){
		R[i] = a[mid + 1 + i];
	}
 
	L[left_size] = INT_MAX;
	R[right_size] = INT_MAX;
 
	int left_index = 0;
	int right_index = 0;
 
	for(int i = l;i<=r;i++){
 
		if(L[left_index]<R[right_index]){
			a[i] = L[left_index];
			left_index++;
		}
		else{
			a[i] = R[right_index];
			right_index++;
		}
 
	}
 
}
 
void merge_sort(int l,int r){
	if(l==r)
		return;
 
	int mid = (l + r) / 2;
 
	merge_sort(l,mid); 
 
	merge_sort(mid+1,r);
 
 
	merge(l,mid,r);
 
 
}
 
int main()
{
	int n;
	cin>>n;
 
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
 
	merge_sort(0,n-1);
 
	for(int i =0;i<n;i++){
		cout<<a[i]<<" ";
	}
 
}