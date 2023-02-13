#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j <= high-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}
void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int n,m;cin >> n >> m;
    int arr[n], arr1[m];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < m; i++){
        cin >> arr1[i];
    }
    if(n == 0 or m == 0){
        return 0;
    }
    quickSort(arr,0,n-1);    // 4 5 9
    quickSort(arr1,0,m-1);   // 1 2 3 4 9
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr1[i] == arr[j]){
                cout << arr1[i] << " ";
                i++;
            }
        }
    }
    

}