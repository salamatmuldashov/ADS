#include <bits/stdc++.h>
using namespace std;
bool canSplit(int a[], long long mid,int n, int x){
    long long subarray = 0;
    long long curSum = 0;
    for (int i = 0; i < n; i++)
    {
        curSum+=a[i];
        if (curSum > mid)
        {
            subarray++;
            curSum = a[i];
        }
        
    }
    return subarray + 1 <= x;
    
}
int main(){
    int n,m;cin >> n >> m;
    int a[1000001];
    long long l,r;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] > l) l = a[i];
        r+=a[i];
    }
    long long res = r;
    while (l <= r)
    {
       long long mid = l + (r-l) / 2;
       if (canSplit(a,mid,n,m))
       {
        res = mid;
        r = mid - 1;
       }else l = mid + 1;
       
    }

    cout << res;
    
    
}