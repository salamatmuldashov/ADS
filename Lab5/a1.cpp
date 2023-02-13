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
        if(i > 0){
            int parent = (i - 1) / 2;
            if(v[i] < v[parent]){
                swap(v[i], v[parent]);
                shiftup(parent);
            }
        }
    }

    void shiftdown(int i ){
        int l = (i*2) + 1;
        int r = (i*2) + 2;
        int cur = i;

        if(l < size and v[cur] > v[l]) cur = l;
        if(r < size and v[cur] > v[r]) cur = r;


        if(cur != i){
            swap(v[cur], v[i]);
            shiftdown(cur);
        }
    }

    long long extractMin(){
        long long maxNum = v[0];
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

    long long answer1(){
        while(size >1){
        long long a = extractMin();
        long long b = extractMin();
         sum += (a+b);
        //  cout << a << " " << b << '\n';
        insert(a+b);
        
        }
        return sum;
    }


  
    
  

   
};

int main(){
    heap* hp = new heap();
    int n;cin >> n;
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        hp->insert(x);
    }
    cout << hp->answer1();
    // int q;cin >> q;
    // while(q--){
    //     int x,y;cin >> x >> y;
    //     hp->answer(x,y);

    // }
    // hp->print();

}
  