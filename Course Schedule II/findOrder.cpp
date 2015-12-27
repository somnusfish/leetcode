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
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        
        vector<int> ret;
        for(int i=0; i<prerequisites.size(); i++){
            int v = prerequisites[i].first;
            int w = prerequisites[i].second;
            if(postNum[w] > postNum[v]){
                return ret;
            }
        }
        
        vector<pair<int,int>> postIndex;
        for(int i=0; i<postNum.size(); i++){
            postIndex.push_back(make_pair(postNum[i], i));
        }
        sort(postIndex.begin(), postIndex.end(), [](pair<int,int> a, pair<int, int> b){
            return a.first < b.first;
        });
        
        
        for(int i=0; i<postIndex.size(); i++){
            ret.push_back(postIndex[i].second);
        }
        return ret;
    }
};
