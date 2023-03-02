#include "naiveTree.hpp"

naiveTree::naiveTree(unsigned cap) {
    node_list = (Node *) malloc(sizeof(Node) * cap);
    size = 0;
}

naiveTree::~naiveTree() {
    free(node_list);
}

// PUBLIC FUNCTIONS
unsigned naiveTree::insert_new_node(float point[], unsigned parent) {
    unsigned current_node = size;
    node_list[current_node].parent_id = parent;
    for (unsigned i = 0; i < k; i++)
        node_list[current_node].point[i] = point[i];
    
    size++;
    return current_node;
}

unsigned naiveTree::get_nearest_node(float point[]) {
    float distance = std::numeric_limits<float>::max();
    unsigned nearest_node  = UINT_MAX;

    for (unsigned this_node = 0; this_node < size; this_node++) {
        float* this_point = get_point(this_node);
        float point_actual[2];
        point_actual[0] = this_point[0];
        point_actual[1] = this_point[1];

        float this_distance = euclidean_distance(point_actual, point);
        if (this_distance < distance) {
            distance = this_distance;
            nearest_node = this_node;
        }
    }
    return nearest_node;
}


float naiveTree::euclidean_distance(float point1[], float point2[]) {
    float total = 0;
    for (unsigned i = 0; i < k; i++) {
        total += pow(point1[i] - point2[i], 2);
    }
    return sqrt(total);
}
