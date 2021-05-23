class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> outDegree;
        vector<int> inDegree(numCourses, 0);
        vector<int> result;
        
        for(auto course: prerequisites){
            inDegree[course[0]] += 1;
            if(course[0] == course[1])
                return {};
        
            outDegree[course[1]].push_back(course[0]);
        }
       
        
        for(int i=0; i<numCourses; i++){
            int index = -1;
            for(auto i = 0; i<inDegree.size(); i++){
                if(inDegree[i] == 0){
                    index = i; 
                    break;
                }
             }
            if(index == -1)
                return {};
            inDegree[index] = -1;
            result.push_back(index);
            for(auto itr : outDegree[index])
                inDegree[itr]--;
        }
        return result;
    }
};