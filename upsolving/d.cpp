#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;cin >> n;
	ll cnt = 0;
	for(int i = 2; i*i <=n; i++){
		if(n % i == 0){
			cnt++;
			while (n % i == 0)
			{
				n/=i;
			}
			
		}
	}
	if(n>1) cnt++;

	cout << cnt << '\n';
}



