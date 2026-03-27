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

    searchResult recursive(Node* start, const std::string& item);

private:
    // Path reconstruction for parent map output
    std::vector<Node*> reconstructPath(
        std::unordered_map<Node*, Node*>& parent,
        Node* start,
        Node* target);

    // Recursive helper function for queue expansion
    Node* recursiveHelper(
        std::queue<Node*>& frontier,
        std::unordered_set<Node*>& visited,
        std::unordered_map<Node*, Node*> parent,
        const std::string& item,
        int verticesVisited
        );
};

#endif //PROJECT2_BFS_H
