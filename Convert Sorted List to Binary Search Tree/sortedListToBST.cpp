/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToSubBST(vector<int>& nums, int start, int end){
        if(start>end){
            return NULL;
        }
        int middle = (start+end)/2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = sortedArrayToSubBST(nums,start, middle-1);
        root->right = sortedArrayToSubBST(nums, middle+1, end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode* p = head;
        while(p){
            nums.push_back(p->val);
            p = p->next;
        }
        return sortedArrayToSubBST(nums, 0, nums.size()-1);
    }
};
