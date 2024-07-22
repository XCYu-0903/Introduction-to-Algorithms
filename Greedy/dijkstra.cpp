/*
Problem Description
Given a set of customers \( A = \{1, 2, 3, ..., n\} \), where each customer \( i \) has a service time \( t_i \) and a desired completion time \( d_i \), the goal is to minimize the maximum delay for any customer. The delay for a customer \( i \) is defined as the difference between the service completion time and \( d_i \), if the completion time exceeds \( d_i \). If the service completes on or before \( d_i \), there is no delay.
You need to schedule the services such that the maximum delay across all customers is minimized. The service schedule is represented as a function \( f : A \to \mathbb{N} \), where \( f(i) \) denotes the start time of customer \( i \)'s service. The maximum delay is the maximum of all individual delays.
Use a greedy algorithm to find the scheduling that minimizes the maximum delay. Output the minimum possible maximum delay.

Example 1
Input:
5
5 10
8 12
4 15
10 11
3 20
Output:
12
*/

#include <iostream>
using namespace std;
#include "vector"
#include "algorithm"
#include "unordered_set"

int findNear(vector<int>& pre,vector<int>& dist,unordered_set<int>& st)
{
    int minitem=INT_MAX, temp;
    for(int i=1;i<int(pre.size());i++)
    {
        if(st.find(i)!=st.end() && pre[i]!=-1 && dist[i]<minitem)
        {
            minitem=dist[i];
            temp=i;
        }
    }
    return temp;
}

void dijkstra(vector<vector<int>>& matrix,int n,vector<int>& pre,vector<int>& dist,unordered_set<int>& st)
{
    while(!st.empty())  
    {
        
        int t= findNear(pre,dist,st);
        st.erase(t);
        
        for(int j=0;j<n;j++)  
        {
            
            if(matrix[t][j]!=-1 && (dist[j]==-1 || dist[t]+matrix[t][j]<dist[j]))
            {
                dist[j]=dist[t]+matrix[t][j]; 
                pre[j]=t;
                st.insert(j);
            }
        }
    }
}
int main()
{
    int n,m;  
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(n,-1));  
    int i,j,k;
    for(int z=0;z<m;z++)
    {
        cin>>i>>j>>k;  
        matrix[i][j]=k;  
    }
    for(int z=0;z<n;z++)
    {
        matrix[z][z]=0;  
    }
    unordered_set<int> st;
    vector<int> pre(n,0); 
    vector<int> dist(n,0); 
    for(j=0;j<n;j++)  
    {
        dist[j]=matrix[0][j];
        if(dist[j]!=-1 && dist[j]!=0) 
        {
            pre[j]=0;
            st.insert(j);  
        }
    }
    pre[0]=-1;   
    dijkstra(matrix,n,pre,dist,st);  
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=dist[i];
    cout<<sum<<endl;
}
