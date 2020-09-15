#include <iostream>
#include <string>
#include <math.h> 
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

struct point
{
    int x;
    int y;
};

struct queueNode
{
    point pt;
    int obj;
    int dist;
};

int isvalid(int x, int y, int r, int c){
    return (x>=0 && x<r && y>=0 && y<c);
}

int xmove[] = {-1,0,0,1};
int ymove[] = {0,-1,1,0};

int BFS(vector<vector<int>> &dp, point start, point end, int n, int m){
    if (!dp[start.x][start.y] || !dp[end.x][end.y])
        return -1;
    
    vec2d(visited,bool,n,m,false);

    visited[start.x][start.y] = true;

    queue<queueNode> q;
    queueNode s = {start,0,0};
    q.push(s);

    while(!q.empty()){
        queueNode curr = q.front();
        point pt = curr.pt;

        cout << pt.x << " " << pt.y << " " << curr.dist << endl;
        if (pt.x == end.x && pt.y == end.y)
            return curr.dist;
        
        q.pop();

        fr(i,0,3){
            int xpos = pt.x + xmove[i];
            int ypos = pt.y + ymove[i];

            if (isvalid(xpos,ypos,n,m) && !visited[xpos][ypos]){
                visited[xpos][ypos] = true;
                queueNode Adjcell;
                if (dp[xpos][ypos] == 0){
                    Adjcell = {{xpos,ypos}, curr.obj+1, curr.obj+curr.dist+1};
                }
                else{
                    Adjcell = {{xpos,ypos}, curr.obj, curr.dist+1};
                }  
                q.push(Adjcell);
            }
        }
    }
    return -1;
}

void Compute(vector<string> &v, int n, int m){
    point start,end;
    vec2d(dp,int,n,m,0);

    fr(i,0,n-1){
        fr(j,0,n-1){
            if (v[i][j] == 'S'){
                start.x = i;
                start.y = j;
                dp[i][j] = 1;
            }
            else if (v[i][j] == 'G'){
                end.x = i;
                end.y = j;
                dp[i][j] = 1;
            }
            else if (v[i][j] == '#'){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = 1;
            }
        }
    }

    cout << BFS(dp,start,end,n,m);
    exit(0);
}

int main(int argc, char *argv[]) {
  int n, m;
  while (!cin.eof()) {
    cin >> n >> m;
    vector<string> v(n);
    for(int i=0;i<n;i++)
      cin >> v[i];

    Compute(v,n,m);
  }
  return 0;
}
