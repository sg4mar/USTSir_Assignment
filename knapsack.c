#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int maximum(int a, int b);
int knapsack(int W, int weight[], int value[], int n);

int main() 
{ 
	int value[] = {50, 60, 200, 1000, 170}; 
	int weight[] = {10,35, 20,40, 30}; 
	int  W = 50; 
	int n;
        n = sizeof(value)/sizeof(value[0]); 
	printf("%d", knapsack(W, weight, value, n)); 

	return 0; 
} 

int maximum(int a, int b) {

	if(a > b){
		return a;
	}
	return b;

}

int knapsack(int W, int weight[], int value[], int n) 
{ 
	int i;
	int m;
	int K[n+1][W+1]; 


	for (i = 0; i <= n; i++) 
	{ 
		for (m = 0; m <= W; m++) 
		{ 
			if (i==0 || m==0)
				K[i][m] = 0;
 
			else if (weight[i-1] <= m) 
				K[i][m] = maximum(value[i-1] + K[i-1][m-weight[i-1]], K[i-1][m]); 

			else
				K[i][m] = K[i-1][m]; 
		} 
	} 

	return K[n][W]; 
} 

//Time Complexity: O(nW) where n is the number of items and W is the capacity of knapsack.
/*Procedure to Run Code in Vim Editor

1- Save the file as it is in home directory in Mint OS.
2- Open terminal and enter command vi knapsack.c.Exit then.
3- Compile it using command gcc knapsack.c
4- Enter Command ./a.out
5- Output is displayed for default value given(here).
*/






