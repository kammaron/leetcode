/*************************************************************************
	> File Name: 297.cpp
	> Author: kamma
	> Mail: kammaron@163.com 
	> Created Time: 三  6/ 7 20:35:23 2017
 ************************************************************************/

#include<iostream>
#include<sstream>
using namespace std;
struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int i): left(NULL),right(NULL),val(i){}
	~TreeNode(){}
};
class Codec {
public:
    void preorder(TreeNode* root, string& s)
    {
        if(!root) return;
        s += to_string(root->val);
		s.push_back(',');
        if(root->left) preorder(root->left,s);
        else s += "NULL,";
        if(root->right) preorder(root->right,s);
        else s+= "NULL,";
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
		s += '[';
        preorder(root,s);
		s.back() =']';
        return s;
    }
	TreeNode* construct_tree(istringstream& in)
	{	
		string s;
		in >> s;
		if(s == "NULL") return NULL;
		else
		{
			istringstream is(s);
			int a;
			is >> a;
			TreeNode* root = new TreeNode(a);
			root->left = construct_tree(in);
			root->right = construct_tree(in);
			return root;
		}
	}
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		for(auto& i:data)
		{
			if(i =='[' || i == ']' || i==',')
				i = ' ';
		}
		istringstream in(data);
		return construct_tree(in);
    }
};
int main()
{
	TreeNode* root = new TreeNode(0);
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(50);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n2->right = n4;
	n4->left = n5;
	Codec c;
	string tree = c.serialize(root);
	cout << tree << endl;
	delete root;
	delete  n1;
	delete  n2;
	delete  n3;
	delete  n4;
	delete  n5;
	root = c.deserialize(tree);
	cout << c.serialize(root) << endl;
}

