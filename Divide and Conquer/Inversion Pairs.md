**Problem Description**

In stock market analysis, contrarian trading is a common investment strategy that aims to invest in the opposite direction of the prevailing market trend. Based on this investment strategy, financial analysts need to pay attention to moments when stock prices suddenly drop. To effectively track these situations, we define the concept of stock market inversion pairs, where an inversion pair is formed if the stock price on one day is higher than the stock price on a subsequent day.

Given an integer array *prices*, where each element represents the closing price of a stock on a particular day, design a program that uses a divide-and-conquer algorithm to calculate the total number of inversion pairs in the array.


**Example 1**

*Input:*
5
9 7 5 4 6

*Output:*
8

*Explanation:*
The inversion pairs in this example are: (9, 7), (9, 5), (9, 4), (9, 6), (7, 5), (7, 4), (7, 6), (5, 4)

**Solution**
```cpp
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
