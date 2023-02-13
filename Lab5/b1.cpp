#include <bits/stdc++.h>
using namespace std;
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

    void print(){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << '\n';
    }
    
    int answer(){
        while(size > 1){
            int a = extractMax();
            int b = extractMax();
            if(a!=b) this->insert(a-b);
        }
        if(size == 1) return v.front();
        return 0;

        
    }
};

int main(){
    maxheap* hp = new maxheap();
    int n;cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        hp->insert(x);
    }

    // cout << hp->answer();
    hp->print();




}