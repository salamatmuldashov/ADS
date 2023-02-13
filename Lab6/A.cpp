#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
char arr[N], arr1[N];
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
    int x = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i = 0; i < n; i++){
        if(arr[i] == 'a' or arr[i] == 'e' or arr[i] == 'i' or arr[i] == 'o' or arr[i] == 'u'){
            arr1[x] = arr[i];
            x++;
        }
    }
    for(int i = 0; i < x; i++){
        cout << arr1[i];
    }

    for(int i = 0; i < n; i++){
        if(arr[i] == 'a' or arr[i] == 'e' or arr[i] == 'i' or arr[i] == 'o' or arr[i] == 'u'){
            continue;
        }else cout << arr[i];
    }
    cout << '\n';

}
