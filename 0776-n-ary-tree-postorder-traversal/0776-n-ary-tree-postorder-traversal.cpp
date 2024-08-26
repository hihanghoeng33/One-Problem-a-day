/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root){
            return {};
        }
    
        vector<int> hehe;
        dfsMethod(root, hehe);
        return hehe;

    }
private:
    void dfsMethod(Node* node, vector<int>& hehe){
        for(Node *child : node->children){
            dfsMethod(child, hehe);
        }
        hehe.push_back(node->val);
    }
};
