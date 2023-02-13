#include <bits/stdc++.h>
using namespace std;

void Merge(int[],int,int,int);
void MergeSort(int arr[], int low, int high){
	if(low < high){
		int mid = (low+high)/2;
		MergeSort(arr,low, mid);
		MergeSort(arr,mid+1,high);
		Merge(arr,low,mid,high);
	}
}

void Merge(int arr[], int low, int mid, int high){
	int n1 = mid-low+1;
	int n2 = high - mid;
	int a[n1], b[n2];

	for (int i = 0; i < n1; ++i)
	{
		a[i] = arr[low+i];
	}
	for (int i = 0; i < n2; ++i)
	{
		b[i] = arr[mid+1+i];
	}

	int i = 0, j = 0, k = low;
	while(i < n1 and j < n2){
		if(a[i] < b[j]){
			arr[k++] = a[i++];
		}else{
			arr[k++] = b[j++];
		}
	}

	while(i < n1){
		arr[k++] = a[i++];
	}
	while(j < n2){
		arr[k++] = b[j++];
	}

}
int main(){
	int n;cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int m;cin >> m;
	int arr1[m];
	for (int i = 0; i < m; ++i)
	{
		cin >> arr1[i];
	}
	int arr2[n+m];
	for (int i = 0; i < n; ++i)
	{
		arr2[i] = arr[i];
	}
	for (int i = n; i < n+m; ++i)
	{
		arr2[i] = arr1[i-n];
	}
	
	MergeSort(arr2, 0, (n+m)-1);
	for(int i = 0; i < n+m; i++){
		cout << arr2[i] <<  " ";
	}

}