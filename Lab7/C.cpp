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
	int n,m;cin >> n >> m;
	int arr[n], arr1[m];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int j = 0; j < m; j++){
		cin >> arr1[j];
	}
	if(n == 0 or m == 0) return 0;
	MergeSort(arr, 0, n-1);
	MergeSort(arr1, 0, m-1);

	for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr1[i] == arr[j]){
                cout << arr1[i] << " ";
                i++;
            }
        }
    }


}