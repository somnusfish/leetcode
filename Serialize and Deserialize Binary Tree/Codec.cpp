/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    vector<TreeNode *> serializeLevel(vector<TreeNode*> &roots, vector<string> &level){
        vector<TreeNode *> ret;
        for(int i=0; i<roots.size(); i++){
            if(roots[i]){
                level.push_back(to_string(roots[i]->val));
                ret.push_back(roots[i]->left);
                ret.push_back(roots[i]->right);
            }
            else{
                level.push_back("null");
            }
        }
        return ret;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<TreeNode *> roots;
        vector<string> seri;
        roots.push_back(root);
        while(roots.size()){
            roots = serializeLevel(roots, seri);
        }
        string s;
        for(int i=0; i<seri.size(); i++){
            if(i!=(seri.size()-1)){
                s += seri[i];
                s += ",";
            }
            else{
                s += seri[i];
            }
        }
        return s;
    }

    vector<string> normal(string &data){
        vector<string> dataN;
        string temp = data;
        std::size_t pos = temp.find(',');
        while(pos != std::string::npos){
            dataN.push_back(temp.substr(0, pos));
            temp = temp.substr(pos+1);
            pos = temp.find(',');
        }
        dataN.push_back(temp);
        return dataN;
    }
    
    vector<TreeNode *> construct(vector<TreeNode*> roots, vector<string> &data, int &pos){
        vector<TreeNode *> ret;
        for(int i=0; i<roots.size(); i++){
            if(data[pos].compare("null")){
                //not null
                TreeNode * temp = new TreeNode(stoi(data[pos]));
                ret.push_back(temp);
                roots[i]->left = temp;
            }
            else{
                roots[i]->left = NULL;
            }
            pos++;
            if(data[pos].compare("null")){
                //not null
                TreeNode * temp = new TreeNode(stoi(data[pos]));
                ret.push_back(temp);
                roots[i]->right = temp;
            }
            else{
                roots[i]->right = NULL;
            }
            pos++;
        }
        return ret;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> dataN = normal(data);
        if(dataN.size() == 1){
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(dataN[0]));
        int pos = 1;
        vector<TreeNode *> roots;
        roots.push_back(root);
        while(roots.size()){
            roots = construct(roots, dataN, pos);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
