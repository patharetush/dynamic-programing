/**
 * There are n stairs, a person standing at the bottom wants to reach the top.
 * The person can climb either 1 stair, 2 stairs or 3 stairs at a time.
 * Count the number of ways, the person can reach the top
 * 
 *
 * Discussion:
 * for n = 1, there is only one way to reach (1)
 * for n = 2, there are two ways to reach (1,1), (2)
 * for n = 3, there are four wys to reach (1,1,1), (1,2), (2,1), (3)
 * for n = 4, there are seven wys to reach (1,1,1,1), (1,1,2), (1,2,1), (1,3), (2,1,1), (2,2), (3,1)
 *
 * function will be
 * f(n) = f(n-1) + f(n-2) + f (n-3)
 * f(1) = 1
 * f(2) = 2
 * f(3) = 4
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_ways_recursive(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	return find_ways_recursive(n-1) + find_ways_recursive(n-2) + find_ways_recursive(n-3);
}

int find_ways_optimized(int n) {
	int *smap = (int*) malloc(sizeof(int) * n);
	memset(smap, 0, n);
	smap[0] = 1;
	smap[1] = 2;
	smap[2] = 4;
	for(int i = 3; i < n; i++) {
		smap[i]= smap[i-1] + smap[i-2] + smap[i-3];
	}

	return smap[n-1];
}

int main(int argc, char** argv) {
	int alg = atoi(argv[1]);
	int top = atoi(argv[2]);
	int ways = 0;
	switch(alg) {
		case 1:
			ways = find_ways_recursive(top);
			break;
		case 2:
		default:
			ways = find_ways_optimized(top);
			break;
	}

	printf("Number of ways to reach %d are %d\n", top, ways);
}
