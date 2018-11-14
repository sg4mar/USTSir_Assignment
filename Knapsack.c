#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int maximum(int a, int b);
int knapsack(int W, int weight[], int value[], int n);

int main() 
{ 
	int value[] = {50,60,200, 1000, 170}; 
	int weight[] = {10, 20,40, 30}; 
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


