/***
 * 给定一个二叉树，返回它的中序 遍历。使用迭代
 * ***/
#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while(cur!=nullptr || !stack.empty()){
            if(cur != nullptr){
                stack.push(cur);
                cur = cur->left;
            }
            else{
                cur = stack.top();
                stack.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }

        }
        return res;
        
    }
};