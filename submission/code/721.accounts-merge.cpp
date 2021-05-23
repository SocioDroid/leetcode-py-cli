class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, set<string>> lists;
        map<string, string> email_name;
        for(auto account : accounts){
            for(int i=1; i< account.size(); i++){
                lists[account[1]].insert(account[i]);
                lists[account[i]].insert(account[1]);
                email_name[account[i]] = account[0];
            }
        }
        
    
        set<string> visited;
        vector<string> v;
        vector<vector<string>> result;
        
        for(auto itr : lists){
            if(visited.find(itr.first) != visited.end())
                continue;
            v.clear();
            queue<string> q;
            
            q.push(itr.first);
            v.push_back(email_name[itr.first]);

            while(!q.empty()){
                string mail = q.front();
                q.pop();
                
                if(visited.find(mail) != visited.end())
                    continue;
                visited.insert(mail);
                v.push_back(mail);
                
                for(auto it : lists[mail])
                    q.push(it);
            }    
            sort(v.begin()+1, v.end());
            // v.insert(0,email_name[v[0]]);
            result.push_back(v);
        }
        return result;
        
    }
};
//         for(auto itr : lists){
//             cout<<itr.first<<"->";
//             for(auto ls : itr.second)
//                 cout<<ls<<"->";
//             cout<<endl;
//         }