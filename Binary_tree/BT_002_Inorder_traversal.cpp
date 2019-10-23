//
// Created by LiuXing on 2019/10/23.
// LeetCode #94
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};


class solution{
public:
    // recursive version
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        recursion(root, res);
        return res;
    }

private:
    void recursion(TreeNode *root, vector<int>& res){
        if (!root)
            return;
        recursion(root->left, res);
        res.push_back(root->val);
        recursion(root->right, res);
        return;
    }


    // non-recursive version
public:
    vector<int> inorderTraversal2(TreeNode *root){
        vector<int> res;
        stack<TreeNode*> s;
        if(!root)
            return res;
        s.push(root);
        while(!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            if(cur->left == NULL && cur->right == NULL) {
                res.push_back(cur->val);
                continue;
            }
            if (cur->right) {
                s.push(cur->right);
                cur->right = NULL;
            }
            s.push(cur);
            if (cur->left) {
                s.push(cur->left);
                cur->left = NULL;
            }
        }
        return res;
    }
}
