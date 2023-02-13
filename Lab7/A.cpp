#include <bits/stdc++.h>
using namespace std;

void Merge(int[],int,int,int);
void MergeSort(int arr[], int low, int high){
	if(low < high){
		int mid = (low+high)/2;
		MergeSort(arr,low, mid);
		MergeSort(arr,mid+1,high);
		Merge(arr,low,mid,high);
	}
}

void Merge(int arr[], int low, int mid, int high){
	int n1 = mid-low+1;
	int n2 = high - mid;
	int a[n1], b[n2];

	for (int i = 0; i < n1; ++i)
	{
		a[i] = arr[low+i];
	}
	for (int i = 0; i < n2; ++i)
	{
		b[i] = arr[mid+1+i];
	}

	int i = 0, j = 0, k = low;
	while(i < n1 and j < n2){
		if(a[i] < b[j]){
			arr[k++] = a[i++];
		}else{
			arr[k++] = b[j++];
		}
	}

	while(i < n1){
		arr[k++] = a[i++];
	}
	while(j < n2){
		arr[k++] = b[j++];
	}

}

int main(){
	vector<vector<string> > v;
	int n;cin >> n;
	string s;
	for (int i = 0; i <= n; i++)
	{
		string t = "";
		vector<string> v1;
		getline(cin,s);
		if(i == 0) continue;
		for(int j = 0; j < s.size(); j++){
			if(s[j] == ' '){
				v1.push_back(t);
				t.clear();
				continue;
			}
			t+=s[j];
		}
		v1.push_back(t);
		v.push_back(v1);
	}
	
	vector<multimap<int,string> > v2;
	multimap<int,string> mp;
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[i].size(); j++){
			mp.insert(make_pair(v[i][j].size(), v[i][j]));
		}
		v2.push_back(mp);
		mp.clear();
	}
	for(int i = 0; i < v2.size(); i++){
		for(auto it = v2[i].begin(); it != v2[i].end(); it++){
			cout << it->second << " ";
		}
		cout << '\n';
	}

	
	



	
	return 0;
}