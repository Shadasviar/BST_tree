#include "binary_tree.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_array(double[], int);
void init_array_by_rand(double[], int, int, int);
void bubbleSortTable(double t[], int s);

int main(){

		clock_t start, stop;
    int size;
    puts("Enter size of array");
    scanf("%d", &size);
    double array1[size], array2[size];

	init_array_by_rand(array1, size, 0, 20);
	init_array_by_rand(array2, size, 0, 20);

	print_array(array1, size);
	print_array(array2, size);

	start = clock();
    sort_array_by_tree(array1, size);
	stop = clock();
	printf("time 1 is: %f\n", (float)(stop-start)/CLOCKS_PER_SEC);

	start = clock();
    sort_array_by_tree(array2, size);
	stop = clock();
	printf("time 2 is: %f\n", (float)(stop-start)/CLOCKS_PER_SEC);

	//print_array(array1, size);
	//print_array(array2, size);

	return 0;
}


void print_array(double array[], int size){
	printf("{");
	for(int i = 0; i < size; ++i){
		printf("%.0lf ", array[i]);
	}
	printf("}\n");
}


void init_array_by_rand(double array[], int size, int down, int up){
	srand((double)time(NULL));
	for(int i = 0; i < size; ++i){
		array[i] = ((rand() % (up-down+1)) + down);
	}
}


void bubbleSortTable(double t[], int s){
  int i, j, tmp;
  int trzeba = 1;

 // for(i = 0; i < s-1; i++){
 i = 0;
 while(trzeba){
    trzeba = 0;
    for(j = 0; j < s-1-i; j++){
      if(t[j] > t[j+1]){
        trzeba = 1;
        tmp = t[j];
        t[j] = t[j+1];
        t[j+1] = tmp;
      }
    }
    i++;
  }
}
