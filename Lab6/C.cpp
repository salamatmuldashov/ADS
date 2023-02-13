#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5;
int arr[N];
int mn = INT_MAX;
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
    int n;cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    // for(int i = 0; i < n;i++){
    //     cout << arr[i] << " ";    // -3916237 -362060 -357920 -20 30 6246457
    // }

    for(int i = 0; i < n-1; i++){
        mn = min(mn, abs(arr[i]- arr[i+1]));
    }
    for(int i = 0; i < n-1; i++){
        if(abs(arr[i]- arr[i+1]) == mn){
            cout << arr[i] << " " << arr[i+1] << " ";
        }
    }
    cout << '\n';
    
    

}