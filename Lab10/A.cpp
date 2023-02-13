#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int cnt = 0;
 
bool isValid(int i, int j, vector<vector<int>> &mat) {
    return (i >= 0 && i < mat.size()) && (j >= 0 && j < mat[0].size());
}
bool check(int n,int m, vector<vector<int>> &mat){
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 1)
                return false;
        }
    }
    return true;
}
 
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };
void bfs(vector<vector<int>> &mat)
{
    queue<pair<int,int> > Q;
 
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 2) {
                Q.push({i, j});
            }
        }
    }

    while (!Q.empty())
    {
        queue<pair<int,int> > q;
        swap(Q, q);
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                if (isValid(x + row[k], y + col[k], mat) &&
                    mat[x + row[k]][y + col[k]] == 1)
                {
                    mat[x + row[k]][y + col[k]] = -mat[x + row[k]][y + col[k]];
                    Q.push({x + row[k], y + col[k]});
                }
            }
        }
        cnt++;
    }
 
   

}
 
int main()
{
    int n,m;cin >> n >> m;
    vector<vector<int> > mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    if(n == 1 and m == 1 and mat[0][0] == 0){
        cout << 0;
        return 0;
    }
    bfs(mat);
    
    if(!check(n,m,mat))cout << -1;
    else cout << cnt-1;


   
    return 0;
}