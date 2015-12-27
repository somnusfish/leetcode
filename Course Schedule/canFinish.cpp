class Solution {
public:
    void explore(vector<vector<int>> &prerequistes, vector<bool> &visited, vector<int> &postNum, int &myclock, int curNode){
        if(visited[curNode]){
            return;
        }
        visited[curNode] = true;
        for(int i=0; i<prerequistes[curNode].size(); i++){
            explore(prerequistes, visited, postNum, myclock, prerequistes[curNode][i]);
        }
        myclock++;
        postNum[curNode] = myclock;
        return;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<vector<int>> requist(numCourses);
        vector<int> postNum(numCourses, 0);
        int myclock = 0;
        for(int i=0; i<prerequisites.size(); i++){
            int v = prerequisites[i].first;
            int w = prerequisites[i].second;
            requist[v].push_back(w);
        }
        for(int i=0; i<numCourses; i++){
            explore(requist, visited, postNum, myclock, i);
        }
        
        for(int i=0; i<prerequisites.size(); i++){
            int v = prerequisites[i].first;
            int w = prerequisites[i].second;
            if(postNum[w] > postNum[v]){
                return false;
            }
        }
        return true;
    }
};
