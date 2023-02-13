#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
int n,q;
int a[1000001];
typedef long long ll;
int binarySearch(int l, int r, int x){
    while (l <= r)
    {
        int mid = l + (r-l) / 2;
        if(a[mid] <= x and a[mid+1] > x)return mid+1;
        if(a[mid] <= x and a[mid+1] <= x) l = mid+1;
        if(a[mid] > x and a[mid+1] > x) r = mid;
    }
    return 0;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    cin >> q;
    while (q--)
    {
        int p;cin >> p;
        if (p >= a[n-1])
        {
            int sum = 0;
            for(int i = 0; i < n;i++){
                sum+=a[i];
            }

            cout << n << " " << sum << '\n';
        }
        else if (p < a[0])
        {
            cout << 0 << " " <<  0 << '\n';
        }
        else
        {
            int x = binarySearch(0,n-1,p);
            int sum = 0;
            for (int i = 0; i < x; i++)
            {
                sum+=a[i];
            }
            cout << x << " " << sum << "\n";
            x = 0;
        }
        
        
        
    }
    
    
    
}