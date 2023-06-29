class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n,0);
        // vector<int,vector<int>> v(n);
        map<int,vector<int>> v;
        for(auto i:prerequisites)
        {
            indegree[i[0]]++;
            // v[i[1]].push_back(i[0]);
            v[i[1]].push_back(i[0]);
            
        }
        
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:v[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        
        if(topo.size()==n)
        {
            return true;
        }
        
        return false;
    }
};