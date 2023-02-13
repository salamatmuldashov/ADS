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

    int answer(int index, int val){
        v[index-1]+=val;
        int x = v[index-1];
        shiftup(index-1);

        return x;
    }

    int getIndex(int val){
        for(int i = 0; i < v.size(); i++){
            if(v[i] == val){
                return i+1;
            }
        }
        return -1;
    }
    
    
};

int main(){
    maxheap* hp = new maxheap();
    int n;cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        hp->insert(x);
    }   
    int q;cin >> q;
    while(q--){
        int x,y;cin >> x >> y;
        int z = hp->answer(x,y);
        cout << hp->getIndex(z) << "\n";

    }
    hp->print();

}