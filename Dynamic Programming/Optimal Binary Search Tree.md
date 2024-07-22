**Problem Description**

Given a dataset \( S = [x_1, x_2, ..., x_n] \) containing \( n \) elements (with \( x_0 = negative infinity \) and \( x_{n+1} = positive infinity \) by default), and an associated access probability distribution \( P = [a_0, b_1, a_1, b_2, ..., b_n, a_n] \) containing \( 2n+1 \) elements.

Here, \( b_i \) represents the probability of accessing element \( x_i \), and \( a_i \) represents the probability of accessing the interval \((x_i, x_{i+1})\).

Using dynamic programming, construct the optimal binary search tree (BST) and determine the minimum average number of comparisons (rounded to two decimal places).

**Example 1**

*Input:*

5

0.04 0.1 0.02 0.3 0.02 0.1 0.05 0.2 0.06 0.1 0.01

*Output:*

2.04

**Example 2**

*Input*  
3

0.1 0.35 0.2 0.05 0.1 0.15 0.05

*Output*  
1.85

**Solution**
```cpp
#include<iostream>
#include "vector"
using namespace std;

int main() {
    int n;
    cin >> n; 
    vector<float> a(n + 2,0.0);  // Probability of intervals
    vector<float> b(n + 2,0.0);  // Probability of elements
    vector<vector<float>> m(n+3,vector<float>(n+3,0.0));
    vector<vector<float>> w(n+2,vector<float>(n+2,0.0));
    cin >> a[0];   
    b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++) {
            w[i][j] = a[i - 1];
            for (int q = i; q <= j; q++) {
                w[i][j] = w[i][j] + b[q] + a[q];
            }
        }
    }
    
    for (int i = 1; i <= n+1; i++) {
        m[i][i - 1] = 0;
    }
    
    for (int t = 1; t <= n; t++)
    {
        for (int i = 1; i <= n-t+1; i++)
        {
            int j = i + t - 1;
            float min_ij = 0;
            for (int k = i; k <= j; k++)  
            {
                if (k == i) {
                    min_ij = m[i + 1][j];
                }
                float tmp = m[i][k - 1] + m[k + 1][j];
                if (min_ij > tmp) {
                    min_ij = tmp;
                }
            }
            m[i][j] = min_ij + w[i][j];
        }
    }
    cout << m[1][n];
}
