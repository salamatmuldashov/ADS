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
int binarySearchReverse(int arr[], int x, int size){
    int l = 0;
    int r = size - 1;
    while (l <= r)
    {  
        int mid = l + (r-l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if(arr[mid] < x){
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
        
        
    }
    return -1;
    
}

int main(){
    int n;cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int a,b;cin >> a >> b;
    int arr1[a][b];
    for (int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++){
            cin >> arr1[i][j];
        }
    }

    
    for (int i = 0; i < n; i++)
    {
        int x,y; bool pass = false;
        for(int j = 0; j < a;j++){
            if (j % 2 == 1)
            {
                x = binarySearch(arr1[j],arr[i],b);
                y = j;
            }
            else
            {
                x = binarySearchReverse(arr1[j],arr[i],b);
                y = j;
            }
            if(x != -1){
            cout << y << " " << x << "\n";
            pass = true;
            break;
            }
        }
        if(pass == false)
        cout << -1 << "\n";
    }
    
    
    
}