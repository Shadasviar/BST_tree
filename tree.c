#include "binary_tree.h"
#include <stdio.h>

int main(){
    int size;
    puts("Enter size of array");
    scanf("%d", &size);
    double array[size];

    for(int i = 0; i < size; ++i){
        scanf("%lf", &array[i]);
    }

    node *head = (size > 0) ? create_node(array[0]) : NULL;
    for(int i = 1; i < size; ++i){
        add_leaf_in_BST_order(head, array[i]);
    }

    print_values_in_deep(head);
	return 0;
}
