class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> outDegree;
        vector<int> inDegree(numCourses, 0);
        
        for(auto course: prerequisites){
            inDegree[course[0]] += 1;
            if(course[0] == course[1])
                return false;
        
            outDegree[course[1]].push_back(course[0]);
        }
        // cout<<"vector : ";
        // for(auto i: inDegree){
        //     cout<<i<<"\t";
        // }
        // cout<<endl;
        
        for(int i=0; i<numCourses; i++){
            int index = -1;
            // cout<<"vector : ";
            // for(auto i: inDegree){
            //     cout<<i<<"\t";
            // }
            // cout<<endl;
            for(auto i = 0; i<inDegree.size(); i++){
                if(inDegree[i] == 0){
                    index = i; 
                    break;
                }
             }
            // cout<<index<<endl;
            if(index == -1)
                return false;
            inDegree[index] = -1;
            for(auto itr : outDegree[index])
                inDegree[itr]--;
        }
        return true;
    }
};