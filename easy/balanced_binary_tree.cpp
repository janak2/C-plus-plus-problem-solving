/**
  *Q.Given a binary tree, determine if it is height-balanced. 
     For this problem, a height-balanced binary tree is defined as a binary tree in which 
     the depth of the two subtrees of every node never differ by more than 1.
  *
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
 
#define INBALANCE -1
class Solution_better {
public:
    bool isBalanced(TreeNode* root) {
        return getLevel(root)!=INBALANCE;
    }
private:
    int getLevel(TreeNode* node){
        if(node==NULL){
            return 0;  
        } 
        
        int leftLevel=getLevel(node->left);
        if(leftLevel==INBALANCE) {
            return INBALANCE;
        }
        int rightLevel=getLevel(node->right);
        if(rightLevel==INBALANCE){
            return INBALANCE;
        }
        if(abs(leftLevel-rightLevel)<2){
            return max(leftLevel,rightLevel)+1;
        }
        
        return INBALANCE;
    }
};

class Solution_mine {
public:
    map<TreeNode*,int> m;
   
    int depth(TreeNode* root, map<TreeNode*,int>& m)
    {
        if(root==NULL)return 0;
        if(m.count(root)>0)return m[root];
        m[root] = 1+ max(depth(root->left,m),depth(root->right,m));
        return m[root];
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        if(abs(depth(root->left,m)-depth(root->right,m))<2)
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        else return false;
    }
};
