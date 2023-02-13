#include <bits/stdc++.h>
using namespace std;
void swap(vector<pair<pair<string,string>,double> > &v, int i,int j){
    pair<pair<string,string>,double>  t = v[i];
    v[i] = v[j];
    v[j] = t;
}
bool check(vector<pair<pair<string,string>,double> > &v, int i,int j){
    if(v[i].second == v[j].second){
        if(v[i].first.first == v[j].first.first){
            return v[i].first.second < v[j].first.second;
        }
        return v[i].first.first < v[j].first.first;
    }
    return v[i].second < v[j].second;
}

int partition(vector<pair<pair<string,string>,double> > &v, int low, int high){
    int pivot = high;
    int i = (low-1);
    for(int j = low; j <= high-1; j++){
        if(check(v, j, pivot)){
            i++;
            swap(v, i, j);
        }
    }
    swap(v, i+1, high);
    return i+1;
}

void quickSort(vector<pair<pair<string,string>,double> >  &v, int low, int high){
    if(low < high){
        int pi = partition(v, low, high);
        quickSort(v, low, pi-1);
        quickSort(v, pi+1, high);
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
    quickSort(v, 0, v.size()-1);
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first.first << " " << v[i].first.second << " ";
        cout << fixed << setprecision(3) << v[i].second << '\n';
    }
}