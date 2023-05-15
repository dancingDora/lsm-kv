#pragma once

#include<cstdint>
#include<list>
#include<random>
#include<string>
#include <vector>

const unsigned int MAX_LEVEL = 8;

template<class T = std::string>
struct skipNode {
    unsigned long key;
    T val;
    std::vector<skipNode *> forwards;

    skipNode(int k, T v) : key(k), val(v) {
        for (int i = 0; i < MAX_LEVEL; i++)
            forwards.push_back(nullptr);
    }
};

class SkipList {
private:
    skipNode<> *head, *tail;
    unsigned int sz;
    std::default_random_engine random_engine;
    std::uniform_int_distribution<unsigned int> *random_int;

    unsigned int random_level();

public:
    SkipList();

    ~SkipList();

    unsigned int size() const;

    void put(uint64_t key, const std::string &s);

    std::string get(uint64_t key) const;

    bool del(uint64_t key);

    void reset();

    void scan(uint64_t key1, uint64_t key2, std::list<std::pair<uint64_t, std::string>> &list) const;
};