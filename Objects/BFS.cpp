//
// Created by Avery Reynolds on 3/26/26.
//

#include "BFS.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <algorithm>

std::vector<Node *> BFS::reconstructPath(std::unordered_map<Node *, Node *> &parent, Node *start, Node *target) {
    std::vector<Node*> path;
    for (Node* cur = target; cur!= nullptr; cur = parent[cur]) {
        path.push_back(cur);
    }

    // Want output to be from start to target [start, ..., target]
    std::reverse(path.begin(), path.end());
    return path;
}

searchResult BFS::iterative(Node *start, const std::string &item) {
    searchResult result;
    auto startTime = std::chrono::high_resolution_clock::now();

    std::unordered_set<Node*> visited;
    std::queue<Node*> q;
    std::unordered_map<Node*, Node*> parent;

    visited.insert(start);
    q.push(start);
    parent[start] = nullptr;

    while (!q.empty()) {
        Node* u = q.front();
        q.pop();
        result.verticesTraversed++;

        for (Node* v : u->friends) {
            for (const std::string& owned : v->items) {
                if (owned == item) {
                    parent[v] = u;
                    result.found = true;
                    result.target = v;
                    result.path = reconstructPath(parent, start, v);

                    auto endTime = std::chrono::high_resolution_clock::now();
                    result.runtime_ms = std::chrono::duration<double, std::milli>(endTime - startTime).count();
                    return result;
                }
            }

            if (visited.find(v) == visited.end()) {
                visited.insert(v);
                parent[v] = u;
                q.push(v);
            }

        }
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    result.runtime_ms = std::chrono::duration<double, std::milli>(endTime - startTime).count();
    return result;
}

