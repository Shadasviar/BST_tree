/*
 * tree.c
 * Copyright (C) Uladzislau Harbuz 2016 
 * 
 * This file is part of BST_tree.
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

void print_array(type_name[], int);
void init_array_by_rand(type_name[], int, int, int);
void bubbleSortTable(type_name t[], int s);

int main(){

		clock_t start, stop;
    int size;
    puts("Enter size of array");
    scanf("%d", &size);
    type_name array2[size];
    type_name array1[size];
  
	init_array_by_rand(array1, size, 1, 5);
	init_array_by_rand(array2, size, 1, 10);

	print_array(array1, size);
	print_array(array2, size);

  
  node *head = create_node(array1[0]);
  for(int i = 1; i < size; ++i){
    add_leaf_in_BST_order(head, array1[i]);
  }

  print_values_in_deep(head);
  puts("");

  delete_node_by_key(&head, set_complex(3,4));
  print_values_in_deep(head);
  puts("");

  delete_node_by_key(&head, set_complex(1,2));
  print_values_in_deep(head);
  puts("");

  
	start = clock();
    sort_array_by_tree(array1, size);
	stop = clock();
	printf("time 1 is: %f\n", (float)(stop-start)/CLOCKS_PER_SEC);
  print_array(array1, size);

  /*
  FILE *file = fopen("fdf", "w");
  write_to_file(file, head);
  fclose(file);
  
	print_array(array1, size);
	print_array(array2, size);

  file = fopen("fdf", "r");
  node *n = read_file(file);
  fclose(file);
  */

  //print_values_in_deep(n);

	return 0;
}


void print_array(type_name array[], int size){
	printf("{");
	for(int i = 0; i < size; ++i){
		print_complex(array[i]);
	}
	printf("}\n");
}


void init_array_by_rand(type_name array[], int size, int down, int up){
	srand((double)time(NULL));
	for(int i = 0; i < size; ++i){
		array[i] = set_complex(((rand() % (up-down+1)) + down), ((rand() % (up-down+1)) + down));
	}
}

