#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
char arr[N];
int partition(char arr[], int low, int high){
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
void quickSort(char arr[], int low, int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int n;cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    char k;cin >> k;
    arr[n] = k;
    n++;
    quickSort(arr, 0, n-1);
    if(arr[n-1] == k){
        cout << arr[0];
        return 0;
    }
    else{
        for(int i = 0; i < n-1; i++){
            if((arr[i] != arr[i+1]) and arr[i] == k){
                cout << arr[i+1];
                break;
            }
        }
    }

    

    
    
   
    

}