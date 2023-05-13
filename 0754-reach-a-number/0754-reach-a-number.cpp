class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int x=0;
        int i=1;
        int prev=0;
        int ans=0;
        while(x<target)
        {
            x+=i;
            if(x==target)
            {
                ans=i;
                break;
            }
            
            if(x>target)
            {
                if(!(x-target&1))
                {
                    ans=i;
                    break;
                }
                
                else
                {
                    x+=(i+1);
                    if(x-target&1)
                    {
                        ans=i+2;
                        break;
                    }
                    
                    else
                    {
                        ans=i+1;
                        break;
                    }
                }
            }
            
            prev=x;
            i++;
        }
        
        return ans;
    }
};