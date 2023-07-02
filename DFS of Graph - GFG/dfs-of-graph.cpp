//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  
   void dfs(int n,int V,vector<int> adj[],vector<int>&vis,vector<int>&ans)
   {
       vis[n]=1;
       for(auto it:adj[n])
       {
           if(!vis[it])
           {
               ans.push_back(it);
               vis[it]=1;
               dfs(it,V,adj,vis,ans);
           }
       }
   }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0),ans;
        ans.push_back(0);
        vis[0]=1;
        for(int i=0;i<V;i++)
        {
            vis[i]=1;
            for(auto it:adj[i])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    ans.push_back(it);
                    dfs(it,V,adj,vis,ans);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends