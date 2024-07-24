/*
Problem Description
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order and output them in lexicographical order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Example 1
Input: 
4
1 2
3
3
Output: 
0 1 3 
0 2 3 
Explanation: 
There are two paths from node 0 to node 3:
Path 0 -> 1 -> 3
Path 0 -> 2 -> 3
Both paths are output in lexicographical order.
*/

#include <iostream>
using namespace std;
#include "vector"
#include "algorithm"
#include "string"
#include "sstream"

void backtracking(vector<vector<int>>& graph, int index, vector<int>& record, vector<vector<int>>& results, int n,vector<bool>& visit) {
    if (index == graph.size() - 1) {
        results.push_back(record);
        return;
    }
    for (int i = 0; i < n; i++) {
        if(graph[index][i]==1){  // index -> i
            record.push_back(i);
            visit[i]=true;
            backtracking(graph, i, record, results,n,visit); // dfs
            visit[i]= false;
            record.pop_back();
        }
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph,int n,vector<bool>& visit) {
    vector<vector<int>> results;
    vector<int> record = {0};
    backtracking(graph, 0, record, results,n,visit);
    return results;
}
int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<bool> visit(n, false); 
    int x;
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin,str);
        if(str.empty())
        {
            continue;
        }
        else
        {
            istringstream iss(str); // use 'istringstream' to cope with streaming input
            int num;
            while (iss >> num) { 
                graph[i][num] = 1;
            }
        }
    }
    // lexicographical order
    vector<vector<int>> paths = allPathsSourceTarget(graph, n, visit);
    for (int i = 0; i < paths.size(); ++i) {
        for (int j = 0; j < paths[i].size(); ++j) {
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }
}
