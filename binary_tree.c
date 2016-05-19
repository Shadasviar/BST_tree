/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 2; tab-width: 2 -*-  */
/*
 * binary_tree.c
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
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


int print_node_value(node*);
void write_tree_to_array(node*, type_name[], int*);
int is_less(type_name, type_name);
node* most_left(node*);
node* delete_node(node*);
int is_leaf(node*);

/*
 *Start of realization of the interface
 -----------------------------------------------------------------------------*/


node* create_node(type_name value){

  node *result =(node*)malloc(sizeof(*result));
  for(int i = 0; i < last; ++i){
		result->family[i] = NULL;
	}

	result->value = value;
  result->role = parent;

	return result;
}


int add_node(node *in_node, node_name name, type_name value){

  if(name < parent && in_node){
    in_node->family[name] = create_node(value);
    in_node->family[name]->family[parent] = in_node;
    in_node->family[name]->role = name;
  	return true;
  }
  else ;

	return false;
}


int set_value(node *in_node, type_name value){

  if(in_node){
    in_node->value = value;
    return true;
  }
  else ;
	
	return false;
}


type_name get_value(node *in_node){
  return in_node ? in_node->value : (type_name)0;
}


node* delete_node_by_key(node **in_node, type_name value){
  node* res = find(*in_node, value);
  if( ! res) return *in_node;
  if(res == get_head(*in_node)){
    *in_node = delete_node(res);
    return *in_node;
  }
  return delete_node(res);
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


int add_leaf_in_BST_order(node *in_node, type_name value){

  if(in_node){

    if(is_less(value, in_node->value)){
      if(! in_node->family[left_child]){
        add_node(in_node, left_child, value);
        return true;
      }
      else add_leaf_in_BST_order(in_node->family[left_child], value);
    }
    else{
    	if(!in_node->family[right_child]){
      	add_node(in_node, right_child, value);
        return true;
      }
    	else add_leaf_in_BST_order(in_node->family[right_child], value);
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


void delete_recursive(node *in_node){
	
	if(in_node && num_of_children(in_node) == 0){
    if(in_node->family[parent]) in_node->family[parent]->family[in_node->role] = NULL;
    free(in_node);
  }

  else
	if(in_node){
    if(in_node->family[left_child]){
			delete_recursive(in_node->family[left_child]);
		}
    if(in_node->family[right_child]){
			delete_recursive(in_node->family[right_child]);
		}
		delete_recursive(in_node);
  }

	else ;
}


int sort_array_by_tree(type_name array[], int size){
	
	node *head = ((size > 0) ? create_node(array[0]) : NULL);
	for(int i = 1; i < size; ++i){
  	add_leaf_in_BST_order(head, array[i]);
  }

	int index = 0;
	write_tree_to_array(head, array, &index);

	delete_recursive(head);
	return true;
	
}


node* get_head(node *in_node){
  if(in_node->family[parent]) return get_head(in_node->family[parent]);
  return in_node;
}


node* find(node *in_node, type_name val){
  if( ! in_node) return NULL;
  if(is_less(val, in_node->value)) return find(in_node->family[left_child], val);
  else if(is_less(in_node->value, val)) return find(in_node->family[right_child], val);
  else return in_node;
}


/*
 * End of realization of the interface
 -----------------------------------------------------------------------------*/

int is_less(type_name a, type_name b){
  return a < b;
}


int print_node_value(node *in_node){
  return printf("%.2lf \n", get_value(in_node));
}


void write_tree_to_array(node *in_node, type_name array[], int *i_current){
	if(in_node && num_of_children(in_node) == 0){
    array[(*i_current)++] = get_value(in_node);
  }

  else
	if(in_node){
    if(in_node->family[left_child]){
			write_tree_to_array(in_node->family[left_child], array, i_current);
		}
    array[(*i_current)++] = get_value(in_node);
    if(in_node->family[right_child]){
			write_tree_to_array(in_node->family[right_child], array, i_current);
		}
  }

	else ;
}


node* most_left(node *in_node){
  if( ! in_node) return NULL;
  if(in_node->family[left_child]){
    return most_left(in_node->family[left_child]);
  }
  return in_node;
}


node* delete_node(node *in_node){
  if(! in_node) return NULL;
  else{
      
    if(is_leaf(in_node)){
      if(in_node->role < parent) in_node->family[parent]->family[in_node->role] = NULL;
      free(in_node);
      in_node = NULL;
      return NULL;
    }
    else{
      node *tmp = NULL;
      
      if(in_node->family[right_child] && in_node->family[left_child]){
        tmp = most_left(in_node->family[right_child]);
        node *newnode = create_node(tmp->value);
        if(in_node->role < parent) in_node->family[parent]->family[in_node->role] = newnode;
        memcpy(newnode->family, in_node->family, sizeof(*(newnode->family))*last);
        newnode->role = in_node->role;
        newnode->family[right_child] = delete_node_by_key(&in_node->family[right_child], tmp->value);      
        free(in_node);
        in_node = NULL;
        return newnode;
      }
      else{
        int child = 0;
        while( ! in_node->family[child]) ++child;
        tmp = in_node->family[child];
        if(in_node->role < parent) in_node->family[parent]->family[in_node->role] = tmp;
        tmp->family[parent] = in_node->family[parent];
        tmp->role = in_node->role;
        free(in_node);
        in_node = NULL;
        return tmp;
      }
      
    }
  }
}


int is_leaf(node *in_node){
  return ( ! (in_node->family[left_child] || in_node->family[right_child]));
}
