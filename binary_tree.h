#pragma once


typedef double type_name;
typedef enum {left_child, right_child, parent, last} node_name;

typedef struct node{
	struct node *family[last];
	type_name value;
  node_name role;  //role of this node for its parent (e.g. right_child)
} node;

node* create_node(type_name);

int add_node(node*, node_name, type_name value);
int set_value(node*, type_name value);
node* delete_node_by_key(node*, type_name);
node* get_head(node*);
node* find(node*, type_name);
void delete_recursive(node*);
type_name get_value(node*);
int num_of_children(node*);
int add_leaf_in_BST_order(node*, type_name value);
int num_of_leafs(node*);
int sort_array_by_tree(type_name[], int);

void print_values_in_deep(node*);

