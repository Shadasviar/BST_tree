#include "binary_tree.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>


int print_node_value(node*);


/*
 *Start of realization of the interface
 -----------------------------------------------------------------------------*/


node* create_node(double value){

  node *result =(node*)malloc(sizeof(node));
  for(int i = 0; i < last; ++i){
		result->family[i] = NULL;
	}

	result->value = value;
  result->role = parent;

	return result;
}


int add_node(node *in_node, node_name name, double value){

  if(name < parent && in_node){
    in_node->family[name] = create_node(value);
    in_node->family[name]->family[parent] = in_node;
    in_node->family[name]->role = name;
  	return true;
  }
  else ;

	return false;
}


int set_value(node *in_node, double value){

  if(in_node){
    in_node->value = value;
    return true;
  }
  else ;
	
	return false;
}


double get_value(node *in_node){
  return in_node ? in_node->value : NAN;
}


int delete_node(node *in_node){
  if(in_node && num_of_children(in_node) == 0){
    in_node->family[parent]->family[in_node->role] = NULL;
    free(in_node);
    return true;
  }
  else return false;
}


int num_of_children(node *in_node){
  int result = 0;
  for(int i = 0; i < parent; ++i){
    if(in_node->family[i]) ++result;
  }
  return result;
}


void print_values_in_deep(node *in_node){

	if(in_node && num_of_children(in_node) == 0){
    print_node_value(in_node);
  }

  else
	if(in_node){
    if(in_node->family[left_child]){
			print_values_in_deep(in_node->family[left_child]);
		}
    print_node_value(in_node);
    if(in_node->family[right_child]){
			print_values_in_deep(in_node->family[right_child]);
		}
  }

	else ;

}


int add_leaf_in_BST_order(node *in_node, double value){

  if(in_node){

    if(value > in_node->value){
      if(!in_node->family[right_child]){
        add_node(in_node, right_child, value);
        return true;
      }
      else add_leaf_in_BST_order(in_node->family[right_child], value);
    }
    else{
    	if(!in_node->family[left_child]){
      	add_node(in_node, left_child, value);
        return true;
      }
    	else add_leaf_in_BST_order(in_node->family[left_child], value);
    }

  }

	return false;
}


int num_of_leafs(node *in_node){
	int result = 0;

	if(in_node && num_of_children(in_node) == 0) ++result;
  else
	if(in_node){
    if(in_node->family[left_child]){
			result += num_of_leafs(in_node->family[left_child]);
		}
    if(in_node->family[right_child]){
			result += num_of_leafs(in_node->family[right_child]);
		}
  }

	else ;

	return result;

}



/*
 * End of realization of the interface
 -----------------------------------------------------------------------------*/


int print_node_value(node *in_node){
  return printf("%.2lf \n", get_value(in_node));
}
