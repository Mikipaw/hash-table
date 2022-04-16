//
// Created by mikhalinho on 16.04.22.
//

#ifndef HASHTABLE_HASH_FUNCTIONS_H
#define HASHTABLE_HASH_FUNCTIONS_H

size_t best_hash(const simple_string& key) {
    return 1;
}

size_t first_sym_hash(const simple_string& key) {
    return key.get_data()[0];
}

size_t len_hash(const simple_string& key) {
    return key.get_size();
}

size_t sum_hash(const simple_string& key) {
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

size_t worst_hash(const simple_string& key) {
    size_t hash = 0;
    size_t str_size = key.get_size();

    for (int i = 0; i < str_size; i++)
        hash = Rol(hash) ^ key[i];

    return hash;
}

size_t ly_hash(const simple_string& key) {
    size_t hash = 0;
    size_t str_size = key.get_size();

    for (int i = 0; i < str_size; i++)
        hash = (hash * 1664525) + (unsigned char)(key[i]) + 1013904223;

    return hash;
}

size_t rot_13(const simple_string& key) {
    size_t hash = 0;
    size_t str_size = key.get_size();

    for (int i = 0; i < str_size; ++i) {
        hash += (unsigned char) key[i];
        hash -= (hash << 13) | (hash >> 19);
    }

    return hash;
}


#endif //HASHTABLE_HASH_FUNCTIONS_H
