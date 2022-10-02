// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = NULL;
        int n = inorder.size();
        set<TreeNode *> s;
        stack<TreeNode *> st;
        for (int pre = 0, in = 0; pre < n;)
        {
            TreeNode *node = NULL;
            do
            {
                node = new TreeNode(preorder[pre]);
                if (root == NULL)
                {
                    root = node;
                }
                if (st.size() > 0)
                {
                    if (s.find(st.top()) != s.end())
                    {
                        s.erase(st.top());
                        st.top()->right = node;
                        st.pop();
                    }
                    else
                    {
                        st.top()->left = node;
                    }
                }
                st.push(node);
            } while (preorder[pre++] != inorder[in] && pre < n);

            node = NULL;
            while (st.size() > 0 && in < n &&
                   st.top()->val == inorder[in])
            {
                node = st.top();
                st.pop();
                in++;
            }

            if (node != NULL)
            {
                s.insert(node);
                st.push(node);
            }
        }
        return root;
    }
};