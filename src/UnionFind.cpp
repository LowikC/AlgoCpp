#include "UnionFind.hpp"

UnionFind::UnionFind(const int n) :
    _parents(n),
    _sizes(n, 1),
    _count(n)
{
    for (int i = 0; i < n; i++) {
        _parents[i] = i;
    }
}

void UnionFind::union_(const int i, const int j) {
    validate(i);
    validate(j);
    int root_i = getRoot(i);
    int root_j = getRoot(j);

    if (root_i != root_j) {
        if (_sizes[root_i] < _sizes[root_j]) {
            _parents[root_i] = root_j;
        }
        else {
            _parents[root_j] = root_i;
        }
        _count--;
    }
}

void UnionFind::validate(const int x) {
    if (x < 0 || x > _parents.size()) {
        throw std::range_error("X must be between 0 and N");
    }
}

int UnionFind::getRoot(const int x) {
    int root = x;
    while (_parents[root] != root) {
        root = _parents[root];
    }

    // Path compression
    int p = x;
    while (_parents[p] != root) {
        int next = _parents[p];
        _parents[p] = root;
        p = next;
    }

    return root;
}


int UnionFind::find(const int i) {
    validate(i);
    return getRoot(i);
}

bool UnionFind::connected(const int i, const int j) {
    int root_i = find(i);
    int root_j = find(j);
    return (root_i == root_j);
}

int UnionFind::count() {
    return _count;
}
