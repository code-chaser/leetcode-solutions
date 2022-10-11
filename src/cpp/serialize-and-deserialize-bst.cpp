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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        s="";
        func1(root, s);
        return s;
    }
    void func1(TreeNode *n, string &s)
    {
        if(!n)
        {
            s+="$,";
            return;
        }
        s+=to_string(n->val);
        s+=",";
        func1(n->left, s);
        func1(n->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i;
        i=0;
        return func2(data, i);
    }
    TreeNode *func2(string &s, int &i)
    {
        string n;
        n="";
        while(s[i]!=',')
        {
            n+=s[i];
            i++;
        }
        i++;
        if(n=="$")
            return NULL;
        TreeNode *root=new TreeNode(stoi(n));
        root->left=func2(s, i);
        root->right=func2(s, i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;