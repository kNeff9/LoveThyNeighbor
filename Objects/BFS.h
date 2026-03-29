//
// Created by Avery Reynolds on 3/26/26.
//

#ifndef PROJECT2_BFS_H
#define PROJECT2_BFS_H

#include "Node.h"
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>

struct searchResult {
    bool found = false;
    std::vector<Node*> path;
    Node* target = nullptr;
    int verticesTraversed = 0;
    double runtime_ms = 0.0;
};

class BFS {
public:
    searchResult iterative(Node* start, const std::string& item);


    // Path reconstruction for parent map output
    std::vector<Node*> reconstructPath(
        std::unordered_map<Node*, Node*>& parent,
        Node* start,
        Node* target);
};

#endif //PROJECT2_BFS_H