#include <bits/stdc++.h>
using namespace std;
struct heap{
private:
    int size;
    vector<int> v;
    long long sum;
public:

    heap(){
        size = 0;
    }
    void insert(int value){
        v.push_back(value);
        size++;
        shiftup(size - 1);
    }

    void shiftup(int i){
        i--;
        if(i > 0){
            int parent = (i - 1) / 2;
            if(v[i] > v[parent]){
                swap(v[i], v[parent]);
                shiftup(parent);
            }
        }
    }

    void shiftdown(int i ){
        int l = (i*2) + 1;
        int r = (i*2) + 2;
        int cur = i;

        if(l < size and v[cur] < v[l]) cur = l;
        if(r < size and v[cur] < v[r]) cur = r;


        if(cur != i){
            swap(v[cur], v[i]);
            shiftdown(cur);
        }
    }

    long long extractMax(){
        int maxNum = v[0];
        v[0] = v[size-1];
        size = max(size-1,0);
        shiftdown(0);
        return maxNum;
    }

    void print(){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << '\n';
    }

    void answer(int index, int value){
        v[index-1]+=value;
        int num = v[index-1];
        shiftup(index-1);
        int j = this->getIndex(num);
        cout << j << '\n';
    }
    
    int getIndex(int val){
        for(int i = 0; i < v.size(); i++){
            if(v[i] == val){
                return i+1;
            }
        }
        return 0;
    }

    int getSize(){
        return size;
    }

    
    
};

int main(){
    heap* hp = new heap();
    int n;cin >> n;
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        hp->insert(x);
    }
    // if(hp->getSize() == 1){
    //     cout << hp->extractMax() << '\n';
    //     return 0;
    // }
    long long sum = 0;
    while(hp->getSize() > 1){
        long long a = hp->extractMax();
        long long b = hp->extractMax();
        long long result = a+b;
        sum+=result;
        hp->insert(result);
    }

    cout << sum << '\n';

    // int q;cin >> q;
    // while(q--){
    //     int x,y;cin >> x >> y;
    //     hp->answer(x,y);

    // }
    // hp->print();

}
  