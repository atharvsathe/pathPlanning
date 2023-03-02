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
    unsigned left;
    unsigned right;
    short axis;
    bool active;    
} Node;

class kdTree {
public:
	kdTree(unsigned cap);
	~kdTree();

    unsigned get_tree_size();
    Node get_node(unsigned node_id);
    unsigned get_parent(unsigned child_id);
    float* get_point(unsigned node_id);
    void deactivate_node(unsigned node_id);
    

    unsigned insert_new_node(float point[], unsigned parent);
    unsigned get_nearest_node(float point[]);

    float euclidean_distance(float point1[], float point2[]);
    
    
private:
Node *node_list;
    unsigned size, next_identifier;
    
    std::map <unsigned, unsigned> parent_map;

    unsigned insert_node(float point[]);
    unsigned new_node(float point[], short axis);
    

	
};