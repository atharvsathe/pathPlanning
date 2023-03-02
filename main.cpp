#include <iostream>
#include <fstream>
#include "rrt.hpp"
//#include "kdTree.hpp"

int main() {
    rrt tree;

    // MAP 1
    //float q_start[2] = {-4.5, -4.5};
    //float q_target[2] = {4.5, -4.5};

    //{-0.62533496, -4.99586416}; {-1.99421696, 3.66343596};
    // RRT : Sampled 3099 with: 1380 collision nodes in 0.067 secs.Path Size: 366
    // RRT : Sampled 3339 with: 10885 collision nodes in 0.467 secs. Path Size: 408    
    
    // {-3.9876, 4.332}; {1.6633, 0.99886};
    // RRT : Sampled 15445 with: 8652 collision nodes in 0.925 secs. Path Size: 719
    // RRT : Sampled 2540 with: 11768 collision nodes in 0.185 secs.Path Size: 705

    // {0.046, -4.387}; {4.998, -3.785};
    // RRT : Sampled 84761 with: 25149 collision nodes in 47.809 secs. Path Size: 767
    // RRT : Sampled 10578 with: 25360 collision nodes in 6.567 secs.Path Size: 777
    
    // {-2.34, -2.876}; {1.567, -0.86};
    // RRT : Sampled 21203 with: 9601 collision nodes in 2.19 secs. Path Size: 329
    // RRT : Sampled 905 with: 4641 collision nodes in 0.023 secs. Path Size: 328

    // {1.567, 3.521}; {4.832, 4.198};
    // RRT : Sampled 22213 with: 10534 collision nodes in 2.24 secs.Path Size: 148
    // RRT : Sampled 2785 with: 10985 collision nodes in 0.258 secs.Path Size: 160

    // {-3.197, 4.112}; {2.776, 4.91};
    // RRT : Sampled 58781 with: 18843 collision nodes in 21.609 secs.Path Size: 834
    // RRT : Sampled 10462 with: 29806 collision nodes in 5.217 secs.Path Size: 846
   
    

    // MAP 2
    //float q_start[2] = {-4.5, 0};
    //float q_target[2] = {4.5, 0};

    // {-4.368, -3.117}; {-1.987, 2.952};
    // RRT : Sampled 13322 with: 6283 collision nodes in 0.78 secs.Path Size: 432
    // RRT : Sampled 985 with: 2363 collision nodes in 0.057 secs. Path Size: 46

    // {4.886, -3.991}; {0.562, 1.532};
    // RRT : Sampled 42807 with: 13624 collision nodes in 11.141 secs.Path Size: 383
    // RRT : Sampled 5298 with: 9900 collision nodes in 1.754 secs.Path Size: 311

    // {-2.553, -4.013}; {-0.942, 3.776};
    // RRT : Sampled 4078 with: 1240 collision nodes in 0.133 secs. Path Size: 359
    // RRT : Sampled 1315 with: 3222 collision nodes in 0.096 secs. Path Size: 386
    
    // {-4.883, 3.861}; {4.011, -4.818};
    // RRT : Sampled 20588 with: 7087 collision nodes in 2.410 secs.Path Size: 598
    // RRT : Sampled 2401 with: 4421 collision nodes in 0.357 secs.Path Size: 598

    // {-0.332, 0.514}; {-3.998, 1.871};
    // RRT : Sampled 43199 with: 11235 collision nodes in 13.237 secs. Path Size: 319
    // RRT : Sampled 6830 with: 6905 collision nodes in 1.489 secs. Path Size: 326

    // {-2.998, 4.117}; {3.675, 4.491};
    // RRT : Sampled 25446 with: 7078 collision nodes in 4.368 secs. Path Size: 525
    // RRT : Sampled 3188 with: 6044 collision nodes in 0.623 secs.Path Size: 553

    float q_start[2] = {-4.5, -4.5};
    float q_target[2] = {4.5, -4.5};

    std::vector<int> path;
    path = tree.plan(q_start, q_target);

    std::ofstream path_file;
    path_file.open ("path.txt");
    for (unsigned i = 0; i < path.size() - 1; i++) {
        float *current_point = tree.tree.get_point(path[i]);
        path_file << current_point[0] << " " << current_point[1] << "\n";
    }
    path_file.close();

    std::ofstream points_file;
    points_file.open ("points.txt");
    unsigned size = tree.tree.get_tree_size();

    for (unsigned i = 0; i < size; i++) {
        float* point = tree.tree.get_point(i);
        points_file << point[0] << " " << point[1] << "\n";
    }
    points_file.close();


    return 0;
}