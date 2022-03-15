
#include <iostream>
#include <vector>

using namespace std;

//initialize matrix to -1
vector <vector<int>> t(30,vector<int>(30,-1));

int knapsack(int wt[], int val[], int size, int w){
    
    if (w==0 || size ==0)           return 0;
           ///  Check if already in matrix or not
    if (t[size][w] != -1)              return t[size][w];
    if (w>=wt[size-1]){

                 /// Add in matrix while return
        return t[size][w] = max(val[size-1] + knapsack(wt, val,size-1,w-wt[size-1]),
                            knapsack(wt,val,size-1,w));
    }
    else
        return (knapsack(wt,val,size-1,w));
    
}
int main()
{
    int wt[] = {3,3,5,2};
    int val[] = {4,3,6,8};
    int size = 4;
    int w=6;
    cout<<knapsack(wt,val,size,w);

    return 0;
}
