/*
 * binary_tree.h
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

#pragma once
#include "fractions.h"
#include <stdio.h>


typedef fraction type_name;
typedef enum {left_child, right_child, parent, last} node_name;

typedef struct node{
  struct node *family[last];
  type_name value;
  node_name role;  //role of this node for its parent (e.g. right_child)
} node;

node* create_node(type_name);

int add_node(node*, node_name, type_name value);
int set_value(node*, type_name value);
node* delete_node_by_key(node**, type_name);
node* get_head(node*);
node* find(node*, type_name);
void delete_recursive(node*);
type_name get_value(node*);
int num_of_children(node*);
int add_leaf_in_BST_order(node*, type_name value);
int num_of_leafs(node*);
int sort_array_by_tree(type_name[], int);

void print_values_in_deep(node*);

void write_to_file(FILE *filename, node*);
node* read_file(FILE*);

