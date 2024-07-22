**Problem Description**

You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

- Create a root node whose value is the maximum value in nums.
- Recursively build the left subtree on the subarray prefix to the left of the maximum value.
- Recursively build the right subtree on the subarray suffix to the right of the maximum value.

Return the maximum binary tree built from nums.



**Example 1**

*Input:* nums = [3,2,1,6,0,5]  

*Output:* [6,3,5,null,2,0,null,null,1]

*Explanation:* The recursive calls are as follow:

- The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
    - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
        - Empty array, so no child.
        - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
            - Empty array, so no child.
            - Only one element, so child is a node with value 1.
    - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
        - Only one element, so child is a node with value 0.
        - Empty array, so no child.

**Solution**
```cpp
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* create(vector<int>& nums,int L,int R)
{
    if(L>R)
        return nullptr;
    int maxval=nums[L];
    int index=L;
    for(int i=L;i<=R;i++)
    {
        if(nums[i]>maxval)
        {
            maxval=nums[i];
            index=i;
        }
    }
    TreeNode *root=new TreeNode(maxval);
    root->left=create(nums,L,index-1);
    root->right=create(nums,index+1,R);
    return root;
}

void levelOrder(TreeNode* root)
{
    // create a queue
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())  
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode *cur = q.front();
            q.pop();   
            cout<<cur->val<<" ";
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
    }
}
int main() {
    vector<int> nums;
    int x;
    while(cin>>x)    // get input from typing, end with Enter.
    {
        nums.push_back(x);
        if(getchar()=='\n')
            break;
    }
    TreeNode *root=create(nums,0,nums.size()-1);
    levelOrder(root);
}
