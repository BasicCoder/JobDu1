#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAX 10010

struct Node{
	int val;
	int ori;
	int sorted;
};

Node nodes[MAX];

bool cmp1(const Node &n1, const Node &n2){
	return n1.val < n2.val;
}

bool cmp2(const Node &n1, const Node &n2){
	return n1.ori < n2.ori;
}

int n;
int main(){
	int i;
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; ++i){
			scanf("%d", &nodes[i].val);
			nodes[i].ori = i;
		}

		sort(nodes, nodes+ n, cmp1);

		nodes[0].sorted = 1;
		for(i = 0; i < n -1; ++i){
			if(nodes[i].val == nodes[i+1].val){
				nodes[i+1].sorted = nodes[i].sorted;
			}else{
				nodes[i+1].sorted = nodes[i].sorted +1;
			}
		}

		sort(nodes, nodes +n, cmp2);

		for(i =0; i <n; ++i){
			printf("%d", nodes[i].sorted);
			if(i == n -1)
				printf("\n");
			else
				printf(" ");
		}
			
	}
	return 0;
}