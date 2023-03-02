#include <vector>
#include <iostream>
#include <sys/time.h>
//#include "kdTree.hpp"
#include "naiveTree.hpp"

typedef struct extend_t{
    unsigned node_id;
    bool target_reached;
} extend_t;

class rrt {
public:
	rrt();
	~rrt();

    //kdTree tree;
    naiveTree tree;
    std::vector<int> plan(float q_start[], float q_target[]);

private:
    static const unsigned max_nodes = 5e4;
    unsigned collision_nodes;

    float q_step_size;
    float target_p;

    extend_t extend(float target[]);
    bool in_collision(float q_point[]);

};