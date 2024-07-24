/*
Problem Description
Given n circular plates with varying radii, you need to place them in a rectangular container such that all plates touch the bottom of the container. The objective is to find the minimum length of the container required to fit all plates. Use a backtracking algorithm to find the optimal arrangement and return the result rounded to two decimal places.

Example 1
Input:
3
1 2 1
Output:
7.66

Example 2
Input:
4
2 4 1 1
Output:
13.83
*/

#include <iostream>
using namespace std;
#include "vector"
#include "string"
#include "math.h"
#include "float.h"

double minlen=DBL_MAX;
vector<int> best;
void compute(int n,vector<double>& r,vector<double>& x,vector<int>& record){
    //
    double low=0,high=0;
    for(int i=0;i<n;i++){//
        if(x[record[i]]-r[record[i]] < low)
            low = x[record[i]]-r[record[i]];
        if(x[record[i]]+r[record[i]] > high)
            high = x[record[i]]+r[record[i]];
    }
    if(high-low<minlen){
        minlen=high-low;// update minlen
        best=record;  // record minimum value
    }
//    cout<<high-low<<endl;
}

double center(vector<double>& r,vector<double>& x,vector<int>& record){// Calculate the center coordinates of the circle
    double x_max=0;
    for(int j=0;j<record.size()-1;j++){ 
        double x_value=x[record[j]]+2.0*sqrt(r[record[record.size()-1]]*r[record[j]]);
        if(x_value>x_max)  
            x_max=x_value;
    }
    return x_max;
}

void backtracing(vector<double>& r,int n,vector<bool>& visit,vector<double>& x,vector<int>& record)
{
    if(record.size()==n){//
        compute(n,r,x,record);
    }
    else{
        for(int i=0;i<n;i++){
            if(!visit[i])
            {
                visit[i]=true;
                record.push_back(i);
                double center_x = center(r,x,record);//
                x[i] = center_x;
                backtracing(r,n,visit,x,record);//dfs
                x[i] = 0.0;
                record.pop_back();
                visit[i]=false;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;//
    vector<double> r(n,0.0);
    for(int i=0;i<n;i++){
        cin>>r[i];//
    }
    vector<bool> visit(n,false);
    vector<double> x(n,0.0);
    vector<int> record;
    backtracing(r,n,visit,x,record);
    // output
    printf("%.2f",minlen);
}
