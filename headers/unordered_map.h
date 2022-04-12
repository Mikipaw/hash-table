//
// Created by mikhalinho on 11.04.2022.
//

#ifndef HASHTABLE_UNORDERED_MAP_H
#define HASHTABLE_UNORDERED_MAP_H


#include <cstdio>
#include <vector>

#include "List.h"

using std::vector;

namespace mp5 {

    class unordered_map {
        public:

        void rehash();
        void reserve(size_t capacity);

        explicit unordered_map(size_t(*hash_func) (const char *));

        void verificator() const;

        void insert(List_elem elem);
        void insert(const simple_string& key);
        bool remove(const simple_string& key);
        const simple_string* find(const simple_string& key) const;

        ~unordered_map() = default;

        private:
            List elements;
            vector<List>::iterator array;

            size_t (*hash_func)(const simple_string&);
    };
}


#endif //HASHTABLE_UNORDERED_MAP_H
