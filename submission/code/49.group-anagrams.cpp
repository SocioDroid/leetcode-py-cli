class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(int i=0; i<strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        int c=0;
        for (auto i = m.begin(); i != m.end(); i++, c++)
        {
            vector<string> temp;
            for(int j=0; j<i->second.size(); j++){
                temp.push_back(i->second[j]);
                cout<<i->second[j]<<"\t";
            }
            res.push_back(temp);
            cout<<endl;
        }
        return res;
    }
};