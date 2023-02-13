#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v1;
#define mp make_pair
int cnt = 0;
struct maxheap
{
private:
    int size;
    vector<int> v;
public:
    maxheap(){
        size = 0;
    }
    void insert(int val){
        v.push_back(val);
        size++;
        shiftup(size-1);
    }

    void shiftup(int i){
        if(i > 0){
            int parent = (i-1)/2;
            if(v[i] > v[parent]){
                swap(v[i],v[parent]);
                shiftup(parent);
            }
        }
    }

    void shiftdown(int i){
        int l = (i*2)+1; // 
        int r = (i*2)+2;
        int maxpos = i;
        if(l < size and v[maxpos] < v[l]) maxpos = l;
        if(r < size and v[maxpos] < v[r]) maxpos = r;

        if(i != maxpos){
            swap(v[i],v[maxpos]);
            shiftdown(maxpos);
        }
    }

    int extractMax(){
        int maxNum = v[0];
        v[0] = v[v.size()-1];
        v.pop_back();
        size--;
        shiftdown(0);
        return maxNum;
    }

    // void answer(){
    //     for(int i = 1; i < v.size(); i+=2){
    //         v1.push_back(make_pair(v[i],v[i+1]));
    //     }
    //     int cnt = 0;

    //     vector<pair<int,int> > ::iterator it;
    //     for(it = v1.begin(); it!= v1.end(); it++){
    //         if(it->second > it->first)cnt++;
    //     }
    //     cout << cnt << '\n';
    // }

    int answer1(int i){
        if(i < v.size()){
        int l = (2*i) + 1;
        int r = (2*i) + 2;
        if(l < v.size() and r < v.size()){
            if(v[l] < v[r])cnt++;
        }
        answer1(l);
        answer1(r);

    
        }
        return cnt;
    }

    void print(){
        for(int i = 0; i < v.size();i++){
            cout << v[i] << " ";
        }
    }

};

int main(){
    maxheap* hp = new maxheap();
    int n;cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        hp->insert(x);
    }   
    // hp->print();
    cout << hp->answer1(0);

    
    
    

}