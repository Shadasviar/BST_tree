/*
 * tree.c
 * Copyright (C) Uladzislau Harbuz 2016 
 * 
 * BST_tree is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * BST_tree is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
    double array2[size];
    double array1[] = {1,4,2,5,1,3};
	//init_array_by_rand(array1, size, 0, 5);
	init_array_by_rand(array2, size, 0, 10);

	print_array(array1, size);
	print_array(array2, size);

  node *head = create_node(array1[0]);
  for(int i = 1; i < size; ++i){
    add_leaf_in_BST_order(head, array1[i]);
  }
  print_values_in_deep(head);

  delete_node_by_key(&head, 1);
  puts("");
  print_values_in_deep(head);

  delete_node_by_key(&head, 3);
  puts("");
  print_values_in_deep(head);

	start = clock();
    sort_array_by_tree(array1, size);
	stop = clock();
	printf("time 1 is: %f\n", (float)(stop-start)/CLOCKS_PER_SEC);

	start = clock();
    bubbleSortTable(array2, size);
	stop = clock();
	printf("time 2 is: %f\n", (float)(stop-start)/CLOCKS_PER_SEC);

	print_array(array1, size);
	print_array(array2, size);

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
