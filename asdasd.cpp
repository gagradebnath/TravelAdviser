// C++ recursive function to 
// solve tower of hanoi puzzle 
#include <bits/stdc++.h> 
using namespace std; 

void towerOfHanoi(int n, char from_rod,char aux_rod ,char to_rod) 
{ 
	if (n == 0) { 
		return; 
	} 
	towerOfHanoi(n - 1, from_rod, to_rod, aux_rod); 
	cout  << n << " " << from_rod 
		<< " " << to_rod << endl; 
	towerOfHanoi(n - 1, aux_rod, from_rod,to_rod); 
} 

// Driver code 
int main() 
{ 
	int N = 5; 

	// A, B and C are names of rods 
	towerOfHanoi(N, 'A', 'B', 'C'); 
	return 0; 
} 

// This is code is contributed by rathbhupendra
