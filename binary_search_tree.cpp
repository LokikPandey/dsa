#include<bits/stdc++.h>
using namespace std;

typedef struct tree{
    int val;
    struct tree * left, *right;
} tree;

void add(tree * root, int val)
{
    if(val<root->val)
    {
        if(root->left==NULL)
        {
            root->left = (tree *)malloc(sizeof(tree));
            root->left->val=val;
            root->left->left=NULL;
            root->left->right=NULL;
        }
        else add(root->left,val);
    }

    else if(val>root->val)
    {
        if(root->right==NULL)
        {
            root->right=(tree *)malloc(sizeof(tree));
            root->right->val=val;
            root->right->left=NULL;
            root->right->right=NULL;
        }
        else add(root->right,val);
    }
    else 
    {
        cout<<"wrong input"<<endl;
        return ;
    }

}
int main() {
    tree * root=(tree *)malloc(sizeof(root));
    cin>>root->val;
    root->left=NULL,root->right=NULL;

    cout<<"to input new nodes into the tree";
    int n;
    cout<<"Enter the number of nodes to input"<<endl;
    cin>>n;
    while(n--){
    int val;
    cin>>val;
    add(root,val);
    }

    queue<tree*> q;
    q.push(root);

    while(!q.empty())
    {
        auto i=q.front();
        q.pop();
        cout<<i->val<<" ";
        if(i->left) q.push(i->left);
        if(i->right) q.push(i->right);

    }

    return 0;
}