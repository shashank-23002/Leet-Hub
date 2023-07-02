class Solution {

public:
    
    void bfs(int i,int j, vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int a=-1;a<=1;a++)
            {
                for(int b=-1;b<=1;b++)
                {
                    if((a==-1 && b==1) || (a==1 && b==-1) || a==b)
                    {
                        continue;
                    }
                    
                    if(row+a>=0 && row+a<n && col+b>=0 && col+b<m)
                    {
                        if(grid[row+a][col+b]=='1' && !vis[row+a][col+b])
                        {
                            q.push({row+a,col+b});
                            vis[row+a][col+b]=1;
                        }
                    
                    }
                }
            }
            
        }

    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int rows=grid.size();
        int col=grid[0].size();
        vector<vector<int>> vis(rows,vector<int> (col,0));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        
        return cnt;
    }
};