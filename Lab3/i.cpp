#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int x, int size){
    int l = 0;
    int r = size - 1;
    while (l <= r)
    {
        int mid = l+ (r-l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] < x)
        {
            l = mid+1;
        }else
        {
            r = mid-1;
        }
    
    }

    return -1;
    
}

int main(){
    int n;cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k; cin >> k;
    int x = binarySearch(a,k,n);
    if (x != -1)
    {
        cout << "Yes";
    }
    else cout << "No";
    
    
}