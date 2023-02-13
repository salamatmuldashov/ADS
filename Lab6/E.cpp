#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j <= high-1; j++){
        if(arr[j] > pivot){
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
    int arr[n][m];
    int arr1[m][n];
    int arr2[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }  
    }   
       
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            arr1[j][i] = arr[i][j];
        }
    }

    for(int j = 0; j < m; j++){
         quickSort(arr1[j], 0, n-1);
    }
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            arr2[i][j] = arr1[j][i];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout <<  arr2[i][j] << " ";
        }  
        cout << '\n';
    }  
    

      
     
     
   

   
    
    

}