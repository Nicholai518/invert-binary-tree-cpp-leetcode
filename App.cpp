#include <iostream>
using namespace std;


  struct TreeNode 
  {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        // nothing to invert
        if (root == NULL) {
            return root;
        }

        // traverse left side
        TreeNode* left = invertTree(root->left);

        // traverse right side
        TreeNode* right = invertTree(root->right);

        // swap
        root->right = left;
        root->left = right;

        // return
        return root;
    }
};

 TreeNode printTree(TreeNode* root) 
 {
    if (root == NULL) 
    {
        return NULL;
    }
    else 
    {
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
    return NULL;
}

int main()
{
    Solution solution;

    TreeNode one(1);
    TreeNode three(3);
    TreeNode two(2, &one, &three);

    TreeNode six(6);
    TreeNode nine(9);
    TreeNode seven(7, &six, &nine);

    TreeNode root(4, &two, &seven);

    TreeNode *example_one = solution.invertTree(&root);

    cout << "Example One : ";
    printTree(example_one);

	return 0;
}
