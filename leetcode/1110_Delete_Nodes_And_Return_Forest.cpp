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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ret;
        if(root == NULL) return ret;
        unordered_set<int> S;
        unordered_set<TreeNode*> visit;
        
        for(int i = 0; i < to_delete.size(); i ++){
            S.insert(to_delete[i]);
        }
        
        queue<TreeNode*> Q; Q.push(root);
        queue<TreeNode*> parent; parent.push(NULL);
        queue<int> dir; dir.push(0);// 0; 1 - left; 2 - right;
        while(!Q.empty()){
            TreeNode* p = Q.front();Q.pop();
            TreeNode* pp = parent.front(); parent.pop();
            int d = dir.front(); dir.pop();
            if(visit.find(p) != visit.end()) continue;
            visit.insert(p);
            TreeNode* left = p->left;
            TreeNode* right = p->right;
            if(S.find(p->val) != S.end()){
                // need to delete from parent
                if(pp != NULL){
                    if(d == 1){
                        pp->left = NULL;
                    }
                    else if(d == 2){
                        pp->right = NULL;
                    }
                }
                // add its children
                if(left != NULL){
                    Q.push(left); parent.push(NULL);dir.push(0);
                }
                if(right != NULL){
                    Q.push(right); parent.push(NULL);dir.push(0);
                }
            }
            else{
                // a root may add to ret
                if(pp != NULL){
                    // parent in it, no need to add to ret
                    
                }
                else{
                    // parent not in, need to add in ret;
                    ret.push_back(p);
                }
                
                if(left != NULL){
                    Q.push(left);parent.push(p);dir.push(1);
                }
                if(right != NULL){
                    Q.push(right); parent.push(p);dir.push(2);
                }
            }
        }
        return ret;
        
    }
};