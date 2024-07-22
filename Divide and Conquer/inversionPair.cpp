#include<iostream>
#include<vector>
using namespace std;

int res=0;
void mergeSort(vector<int>& nums,int leftL,int leftR,int rightL,int rightR)
{
    int i=leftL,j=rightL;
    vector<int> temp;
    while(i<=leftR&&j<=rightR)
    {
        if(nums[i]>nums[j])
        {
            res+=leftR-i+1;
            temp.push_back(nums[j]);
            j++;
        }
        else
        {
            temp.push_back(nums[i]);
            i++;
        }
    }
    while(j<=rightR)
    {
        temp.push_back(nums[j++]);
    }
    while(i<=leftR)
    {
        temp.push_back(nums[i++]);
    }
    for(i=leftL;i<=rightR;i++)
        nums[i]=temp[i-leftL];
}
void getRP(vector<int>& nums,int L,int R)
{
    if(L>=R)
        return ;
    int mid=L+(R-L)/2;
    getRP(nums,L,mid);
    getRP(nums,mid+1,R);
    mergeSort(nums,L,mid,mid+1,R);
}

int main() {
    int n;
    cin>>n;
    int x;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++) {
        cin>>x;
        nums[i]=x;
    }
    getRP(nums,0,nums.size()-1);
    cout<<res<<endl;
}
