#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN 1

enum { MINIMIZE, MAXIMIZE };

typedef struct __Item {
	char *name;
	int size;
	int price;
} Item;

int solve(int limit, const Item *items, int n_items, int target, int initial_value, int display_table);
int solveMax(int limit, const Item *items, int n_items, int display_table);
int solveMin(int limit, const Item *items, int n_items, int initial_value, int display_table);
void printSolve(int limit, const Item *items, int *item, int *value, int target);
void printTableHead(int limit);
void printTableBody(int *value, int limit, int *item, int target);

int main(void) {
	Item items[]={
		{"plum", 4, 4500},
		{"apple", 5, 5700},
		{"orange", 2, 2250},
		{"strawberry", 1, 1100},
		{"melon", 6, 6700},
		{"cherry", 4, 4300}
	};
	int limit = 8;
	int n_items = 6;
	int v;
	
	printf("Input Limit: ");
	scanf("%d", &limit);

	// 最大値を初期値として使う
	v = solveMax(limit, items, n_items, 0);
	v = solveMin(limit, items, n_items, v, 1);
}
//
int solve(int limit, const Item *items, int n_items, int target, int initial_value, int display_table){
    int s, i, t;
    int *value = (int *)calloc(limit+1, sizeof(int));
    int *item = (int *)calloc(limit+1, sizeof(int));

    for(s=0; s<=limit; s++){
        value[s] = -initial_value;
        item[s] = -1;
    }
    value[0] = 0;

    if(display_table == 1)
        printTableHead(limit);

    for(i=0; i<n_items; i++){
        for(t=items[i].size; t<=limit; t++){
            int p = t - items[i].size;
            int newvalue;
            if(target == MAXIMIZE)
                newvalue = value[p] + items[i].price;
            else
                newvalue = value[p] + items[i].price*(-1);
            if(newvalue > value[t]){
                value[t] = newvalue;
                item[t] = i;
            }
        }
        if(display_table == 1){
            if(target == MAXIMIZE)
                printTableBody(value, limit, item, MAXIMIZE);
            else
                printTableBody(value, limit, item, MINIMIZE);
        }
    }
    if(display_table == 1){
        if(target == MAXIMIZE)
            printSolve(limit, items, item, value, MAXIMIZE);
        else
            printSolve(limit, items, item, value, MINIMIZE);
    }

    return (value[limit]);
}


int solveMax(int limit, const Item *items, int n_items, int initial_value){
    int display_table=0;
    return(solve(limit, items, n_items, MAXIMIZE, initial_value, display_table));
}

int solveMin(int limit, const Item *items, int n_items, int initial_value, int display_table){
    return(solve(limit, items, n_items, MINIMIZE,initial_value, display_table));
}


// 最適解表示用
void printSolve(int limit, const Item *items, int *item, int *value, int target) {
	int s, v;
	
	printf("     Items|  Price\n");
	printf("----------+-------\n");
	for(s = limit; s >= MIN; s = s - items[item[s]].size) {
		printf("%10s|%7ld\n", items[item[s]].name, items[item[s]].price);
	}
	printf("----------+-------\n");
	v = value[limit];
	if (target == MINIMIZE) v = -v;
	printf("     Total|%7ld\n", v);
}

// テーブル表示用
void printTableHead(int limit) {
	int j;
	
	for (j = 1; j <= limit; j++) {
		printf("%7d|", j);
	}
	printf("\n");
	for (j = 1; j <= limit; j++) {
		printf("=======+");
	}
	printf("\n");
}

void printTableBody(int *value, int limit, int *item, int target) {
	int j, v;
	
	for (j = 1; j <= limit; j++) {
		v = value[j];
		if (target == MINIMIZE) v = -v;
		printf("%7d|", v);
	}
	printf("\n");
	for (j = 1; j <= limit; j++) {
		if (item[j] >= 0)
			printf("%7d|", item[j]);
		else
			printf("      -|");
	}
	printf("\n");
	for (j = 1; j <= limit; j++) {
		printf("-------+");
	}
	printf("\n");
}
