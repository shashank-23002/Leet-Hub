class Solution {
public:
    
    void bfs(int sr, int sc,vector<vector<int>> &vis,vector<vector<int>>& image,int color)
    {
        int n=image.size();
        int m=image[0].size();
         queue<pair<int,int>> q;
         q.push({sr,sc});
        int c=image[sr][sc];
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=-1;i<n;i++)
            {
                for(int j=-1;j<m;j++)
                {
                    if((i==1 && j==0) || (i==-1 && j==0) || (i==0 && j==-1) || (i==0 && j==1))
                    {
                        if(row+i>=0 && row+i<n && col+j>=0 && col+j<m)
                        {
                            if(image[row+i][col+j]==c && !vis[row+i][col+j])
                            {
                                image[row+i][col+j]=color;
                                vis[row+i][col+j]=1;
                                q.push({row+i,col+j});
                            }
                        }
                    }
                }
            }
        }
        image[sr][sc]=color;
    }
    
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        vis[sr][sc]=1;
        // image[sr][sc]=color;
        bfs(sr,sc,vis,image,color);
        return image;
    }
};