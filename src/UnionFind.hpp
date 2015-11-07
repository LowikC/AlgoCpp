#ifndef UnionFind_hpp
#define UnionFind_hpp

#include <vector>

class UnionFind {
public:
    UnionFind(const int n);

    void union_(const int i, const int j);

    int find(const int i);

    bool connected(const int i, const int j);

    int count();

private:
    int getRoot(const int x);
    void validate(const int x);
    std::vector<int> _parents;
    std::vector<int> _sizes;
    int _count;
};

#endif //UnionFind_hpp