/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;

        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        string direction;
        int commonPathLength = 0;

        while(commonPathLength < startPath.length() && 
                commonPathLength < destPath.length() && 
                startPath[commonPathLength] == destPath[commonPathLength]){
                    commonPathLength++;
                }

        for(int i = 0; i < startPath.length()-commonPathLength; i++){
            direction += "U";
        }

        for(int i = commonPathLength; i < destPath.length(); i++){
            direction += destPath[i];
        }

        return direction;
    }

    bool findPath(TreeNode* node, int target, string& path){
        if(node == NULL){
            return false;
        }

        if(node->val == target){
            return true;
        }

        path += "L";
        if(findPath(node->left, target, path)){
            return true;
        }
        path.pop_back();

        path += "R";
        if(findPath(node->right, target, path)){
            return true;
        }
        path.pop_back();

        return false;
    }
};