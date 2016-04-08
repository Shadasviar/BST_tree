#pragma once


typedef enum {left_child, right_child, parent, last} node_name;

typedef struct node{
	struct node *family[last];
	double value;
  node_name role;  //role of this node for its parent (e.g. right_child)
} node;

node* create_node(double);

int add_node(node*, node_name, double value);
int set_value(node*, double value);
int delete_node(node*);
double get_value(node*);
int num_of_children(node*);
int add_leaf_in_BST_order(node*, double value);
int num_of_leafs(node*);

void print_values_in_deep(node*);
