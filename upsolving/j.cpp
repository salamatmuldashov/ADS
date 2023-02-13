#include <bits/stdc++.h>
using namespace std;
void binarySearch(int arr[], int size, int key)
{
    int l = 0;
    int r = size - 1;
    while (l <= r)
    {
        if (arr[l] + arr[r] == key)
        {
            cout << arr[l] << " " << arr[r] << '\n';
            return;
        }
        if (arr[l] + arr[r] < key)
        {
            l++;
        }else
        {
            r--;
        }
    
    }
}
int main(){
    int k;cin >> k;
    int n;cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    binarySearch(arr,n,k);
}
