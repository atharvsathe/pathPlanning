#include <climits>
#include <algorithm>
#include <deque>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

const unsigned k = 2;

typedef struct Node{
    float point[k];
    unsigned parent_id;
} Node;

class naiveTree {
public:
	naiveTree(unsigned cap);
	~naiveTree();

    unsigned get_tree_size() {return size;}
    Node get_node(unsigned node_id) {return node_list[node_id];}
    unsigned get_parent(unsigned child_id) {return get_node(child_id).parent_id;}
    float* get_point(unsigned node_id) {return &node_list[node_id].point[0];}
    

    unsigned insert_new_node(float point[], unsigned parent);
    unsigned get_nearest_node(float point[]);

    float euclidean_distance(float point1[], float point2[]);

private:
    Node *node_list;
    unsigned size;
    	
};