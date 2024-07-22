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
