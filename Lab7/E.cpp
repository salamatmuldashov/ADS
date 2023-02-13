#include <bits/stdc++.h>
using namespace std;
// void swap(vector<pair<pair<string,string>,double> > &v, int i,int j){
//     pair<pair<string,string>,double>  t = v[i];
//     v[i] = v[j];
//     v[j] = t;
// }
bool check(vector<pair<int, vector<int> > > &v, int i,int j, vector<pair<int, vector<int> > > &v1){
	if (v[i].first > v1[j].first) return true;

    if(v[i].first == v1[j].first){
    	for(int k = 0; k < v[i].second.size(); k++){
    		if(v[i].second[k] != v1[j].second[k]){
    			return v[i].second[k] < v1[j].second[k];
    		}
    	}
    	return false;
    }
    

    return false;
}
void Merge(vector<pair<int, vector<int> > > &v, int low, int mid, int high){

    int n1 = mid-low+1;
    int n2 = high - mid;
    // int a[n1], b[n2];
    vector<pair<int, vector<int> > > a;
    vector<pair<int, vector<int> > > b;
    for (int i = 0; i < n1; ++i)
    {
        // a[i] = v[low+i];
    	a.push_back({v[low+i].first, v[low+i].second});
    }
    for (int i = 0; i < n2; ++i)
    {
        // b[i] = v[mid+1+i];
    	b.push_back({v[mid+1+i].first, v[mid+1+i].second});
    }

    int i = 0, j = 0, k = low;
    while(i < n1 and j < n2){
        if((check(a,i,j,b))){
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

void MergeSort(vector<pair<int, vector<int> > > &v, int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        MergeSort(v,low, mid);
        MergeSort(v,mid+1,high);
        Merge(v,low,mid,high);
    }
}



int main(){
    int n,m;cin >> n >> m;
    vector<pair<int, vector<int> > > v;
    for(int i = 0; i < n; i++){
    	int sum = 0;
    	vector<int> v1;
    	for(int j = 0; j < m; j++){
    		int x;cin >> x;
    		sum+=x;
    		v1.push_back(x);
    	}
    	v.push_back({sum, v1});
    }

    MergeSort(v, 0, n-1);

    for(int i = 0; i < v.size(); i++){
    	for(int j = 0; j < v[i].second.size(); j++){
    		cout << v[i].second[j] << " ";
    	}
    	cout << '\n';
    }


}
