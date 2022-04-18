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

        //void rehash();                    probably doesn't need, because list is expanding automatically.
        //void reserve(size_t capacity);

        explicit unordered_map(size_t(*hash_function) (const simple_string&));

        unordered_map(size_t(*hash_function) (const simple_string&), size_t capacity);

        void dump();

        void insert(List_elem elem);
        void insert(const simple_string& key);
        bool remove(const simple_string& key);

        [[nodiscard]] simple_string*          find_ptr(const simple_string& key);
        [[nodiscard]] size_t                  find_pos(const simple_string& key) const;

        void               get_coll_num() const;

        const char* operator[](int    pos);
        const char* operator[](size_t pos);

        ~unordered_map() = default;

        private:
            List elements = List(CAPACITY);
            vector<size_t> array;

            size_t (*hash_func)(const simple_string&);

            size_t collisions_number    = 0;
            size_t actual_size          = 0;
    };
}


#endif //HASHTABLE_UNORDERED_MAP_H
