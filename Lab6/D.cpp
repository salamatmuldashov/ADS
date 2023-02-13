#include <bits/stdc++.h>
using namespace std;
bool comparator(int a[], int b[]){
    if(a[2] > b[2]){
        return false;
    }
    else if (a[2] == b[2])
    {
        if(a[1] > b[1]){
            return false;
        }
        else if (a[1] == b[1])
        {
            if(a[0] > b[0]){
                return false;
            }
        }
        
    }
    return true;
    
}

int partition(int a[][3], int low, int high){
    int pivot = high;
    int i = low - 1;
    for(int j = low; j <= high-1; j++){
        if(!comparator(a[j], a[pivot])){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i + 1;
}

void quickSort(int a[][3], int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

int main(){
    int n;cin >> n;
    int a[n][3];
    for(int i = 0; i < n;i++){
        string s;cin >> s;
        string s1 = s.substr(0,2);
        string s2 = s.substr(3,2);
        string s3 = s.substr(6,4);
        int x1 = stoi(s1);
        int x2 = stoi(s2);
        int x3 = stoi(s3);
        a[i][0] = x1;
        a[i][1] = x2;
        a[i][2] = x3;
    }
    quickSort(a, 0, n-1);
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < 3; j++){
            if(a[i][j] < 10) cout << 0;
            if(j == 2)cout << a[i][j];
            else cout << a[i][j] << "-";
        }
        cout << '\n';
    }

}