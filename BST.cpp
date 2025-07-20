#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root,int val)
{
    if(root == NULL) return new Node(val);

    if(val < root->data)
    {
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }

    return root;
}

Node* buildBST(vector<int> arr)
{
    Node* root = NULL;

    for(int val : arr)
    {
        root = insert(root,val);
    }
    return root;
}

bool search(Node* root,int key)
{
    if(root == NULL) return false;
    if(root->data == key) return true;
    else if(root->data < key)
    {
        return search(root->right,key);
    }
    else{
        return search(root->left,key);
    }
}

Node* getInorderSuccessor(Node* root)
{
    while(root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root,int key)
{
    if(root == NULL) return NULL;

    if(key < root->data)
    {
        root->left = delNode(root->left,key);
    }
    else if(key > root->data)
    {
        root->right = delNode(root->right,key);
    }
    else{
        if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = delNode(root->right,IS->data);
        }
    }
    return root;
}

void inOrder(Node* root)
{
    if(root == NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    return;
}

int main()
{
    vector<int> arr = {3,2,1,5,6,4};

    Node* root = buildBST(arr);

    inOrder(root);  // should print: 1 2 3 4 5 6
    cout<<endl;

    cout<<search(root,5)<<endl;  // should print 1

    cout<<"After deletion: ";
    root = delNode(root,99);      // ✅ update the root
    inOrder(root);               // should print: 1 2 3 4 6
    cout<<endl;

    cout<<"After insertion: ";
    root = insert(root,8);
    inOrder(root);
    cout<<endl;

    return 0;
}
