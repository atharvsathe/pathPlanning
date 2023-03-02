#include "kdTree.hpp"

kdTree::kdTree(unsigned cap) {
    node_list = (Node *) malloc(sizeof(Node) * cap);
    size = 0;
    next_identifier = 0;
}

kdTree::~kdTree() {
    free(node_list);
}

// PUBLIC FUNCTIONS
unsigned kdTree::get_tree_size() {
    return size;
}

Node kdTree::get_node(unsigned node_id) {
    return node_list[node_id];
}
unsigned kdTree::get_parent(unsigned child_id) {
    return parent_map[child_id];
}

float* kdTree::get_point(unsigned node_id) {
    return node_list[node_id].point;
}

void kdTree::deactivate_node(unsigned node_id) {
    node_list[node_id].active = false;
}

unsigned kdTree::insert_new_node(float point[], unsigned parent) {
    unsigned node_id = insert_node(point);
    parent_map[node_id] = parent;
    return node_id;
}



unsigned kdTree::get_nearest_node(float point[]) {
    float distance = std::numeric_limits<float>::max();
    unsigned nearest_node  = UINT_MAX;

    for (unsigned this_node; this_node < size; this_node++) {
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

    /*unsigned nearest_node  = UINT_MAX;

    std::deque <int> stack_node;
    stack_node.push_front(0);
    std::deque <int> stack_look;

    while (stack_node.size() > 0 || stack_look.size() > 0) {
        int node_id = 0;
        bool look_node = true;

        if (stack_node.size() > 0) {
            look_node = false;
            node_id = stack_node.front();
            stack_node.pop_front();
        } else {
            node_id = stack_look.front();
            stack_look.pop_front();
        }


        short self_axis = node_list[node_id].axis;
        int self_right = node_list[node_id].right;
        int self_left = node_list[node_id].left;

        float self_point[k];
        for (unsigned i = 0 ;i < k; i++) {self_point[i] = node_list[node_id].point[i];}

        if (node_list[node_id].active == true) {
            float node_distance = euclidean_distance(self_point, point);
            if (nearest_node == UINT_MAX || distance > node_distance) {
                nearest_node = node_id;
                distance = node_distance;
            }
        }

        int side_node = self_right;
        int side_look = self_left;
        if(point[self_axis] < self_point[self_axis]) {
            side_node = self_left;
            side_look = self_right;
        } 

        if(side_node != UINT_MAX) {stack_node.push_back(side_node);}
        if(side_look != UINT_MAX) {stack_look.push_back(side_look);}
    }
    return nearest_node;*/
    
}
// PRIVATE FUNCIONS


unsigned kdTree::insert_node(float point[]) {
    return new_node(point, 0);
    /*bool is_left = false;
    int current_id = 0;
    Node* parent_node = NULL;
    short axis = 0;

    if (size == 0) {
        return new_node(point, 0);
    } else {
        while(true) {
            int next_id = 0;
            parent_node = &(node_list[current_id]);
            axis = parent_node->axis;

            if (point[axis] < parent_node->point[axis]) {
                next_id = parent_node->left;
                is_left = true;
            } else {next_id = parent_node->right;}

            if (next_id == UINT_MAX) {break;}
            current_id = next_id;
        }

        if(is_left) {parent_node->left = size;}
        else {parent_node->right = size;}

        return new_node(point, (axis + 1) % k);
    }*/
}

unsigned kdTree::new_node(float point[], short axis) {
    unsigned current_node = next_identifier;
    /*node_list[current_node].axis = axis;
    node_list[current_node].active = true;
    node_list[current_node].left = UINT_MAX;
    node_list[current_node].right = UINT_MAX;*/

    for (unsigned i = 0; i < k; i++)
        node_list[current_node].point[i] = point[i];

    next_identifier++;
    size++;

    return current_node;
}

float kdTree::euclidean_distance(float point1[], float point2[]) {
    float total = 0;
    for (unsigned i = 0; i < k; i++) {
        total += pow(point1[i] - point2[i], 2);
    }
    return sqrt(total);
}