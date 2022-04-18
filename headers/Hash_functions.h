//
// Created by mikhalinho on 16.04.22.
//

#ifndef HASHTABLE_HASH_FUNCTIONS_H
#define HASHTABLE_HASH_FUNCTIONS_H

inline size_t best_hash(const simple_string& key) {
    return 1;
}

inline size_t first_sym_hash(const simple_string& key) {
    return (size_t) key.get_data()[0];
}

inline size_t len_hash(const simple_string& key) {
    return key.get_size();
}

inline size_t sum_hash(const simple_string& key) {
    size_t sum = 0;
    size_t str_size = key.get_size();
    for (int i = 0; i < str_size; i++)
        sum += key[i];

    return sum;
}

template<typename data_type>
data_type Rol(data_type number) {
    return number << 1 | ((number & (1 << (sizeof(number) - 1))) >> (sizeof(number)-1));
}

inline size_t shift_hash(const simple_string& key) {
    size_t hash = 0;
    size_t str_size = key.get_size();

    for (int i = 0; i < str_size; i++)
        hash = Rol(hash) ^ key[i];

    return hash;
}

inline size_t my_hash(const simple_string& key) {
    size_t hash = 0;
    size_t str_size = key.get_size();

    for (int i = 0; i < str_size; ++i) {
        hash += (hash << 13) ^ (hash >> 19);
        hash -= key[(i * 2) % (int) str_size];
    }

    return hash;
}

inline size_t ull_hash(const simple_string& key) {
    return *key.data;
}

#endif //HASHTABLE_HASH_FUNCTIONS_H
