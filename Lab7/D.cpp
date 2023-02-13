#include <bits/stdc++.h>
using namespace std;
// void swap(vector<pair<pair<string,string>,double> > &v, int i,int j){
//     pair<pair<string,string>,double>  t = v[i];
//     v[i] = v[j];
//     v[j] = t;
// }
bool check(vector<pair<pair<string,string>,double> > &v, int i,int j, vector<pair<pair<string,string>,double> > &v1){
    if(v[i].second == v1[j].second){
        if(v[i].first.first == v1[j].first.first){
            return v[i].first.second < v1[j].first.second;
        }
        return v[i].first.first < v1[j].first.first;
    }
    return v[i].second < v1[j].second;
}
void Merge(vector<pair<pair<string,string>,double> > &v, int low, int mid, int high){

    int n1 = mid-low+1;
    int n2 = high - mid;
    // int a[n1], b[n2];
    vector<pair<pair<string,string>,double> > a;
    vector<pair<pair<string,string>,double> > b;
    for (int i = 0; i < n1; ++i)
    {
        // a[i] = v[low+i];
        a.push_back({{v[low+i].first.first, v[low+i].first.second},v[low+i].second});
    }
    for (int i = 0; i < n2; ++i)
    {
        // b[i] = v[mid+1+i];
        b.push_back({{v[mid+1+i].first.first, v[mid+1+i].first.second}, v[mid+1+i].second});
    }

    int i = 0, j = 0, k = low;
    while(i < n1 and j < n2){
        if(check(a,i,j,b)){
            v[k++] = a[i++];
        }else{
            v[k++] = b[j++];
        }
    }

    while(i < n1){
        v[k++] = a[i++];
    }
    while(j < n2){
        v[k++] = b[j++];
    }

}

void MergeSort(vector<pair<pair<string,string>,double> > &v, int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        MergeSort(v,low, mid);
        MergeSort(v,mid+1,high);
        Merge(v,low,mid,high);
    }
}



int main(){
    vector<pair<pair<string,string>,double> >  v;
    int n;cin >> n;
    double sum = 0;
    int sum1 = 0;
    for(int i = 0; i < n; i++){
        sum = 0, sum1 = 0;
        string a,b;cin >> a >> b;
        // string c = a + " " + b;
        int m;cin >> m;
        for(int j = 0; j < m; j++){
            string gpa;
            int x;
            cin >> gpa >> x;
            sum1+=x;
            if(gpa == "A+")sum+=(4.00 * x);
            else if(gpa == "A") sum+=(3.75 * x);
            else if(gpa == "B+") sum+=(3.50 * x);
            else if(gpa == "B") sum+=(3.00 * x);
            else if(gpa == "C+") sum+=(2.50 * x);
            else if(gpa == "C") sum+=(2.00 * x);
            else if(gpa == "D+") sum+=(1.50 * x);
            else if(gpa == "D") sum+=(1.00 * x);
            else sum+=(0.00 * x);
        }
        v.push_back(make_pair(make_pair(a,b), sum/sum1));
    }
    MergeSort(v,0,n-1);

    for(int i = 0; i < v.size(); i++){
        cout << v[i].first.first << " " << v[i].first.second << " ";
        cout << fixed << setprecision(3) << v[i].second << '\n';
    }
}
