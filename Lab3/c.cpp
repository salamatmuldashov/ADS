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
int binarySearch1(int arr[], int l, int r, int size){
    int cnt = 0;
    

}

int main(){
    int n,q;cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    while (q--)
    {
        int cnt = 0;
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2; // 1 2 3 5 8 13 21
        // 1 5 13 21
        if (l1 > l2)
        {
            
        }
        else
        {
        
        }
        
        

    }
    
    
}