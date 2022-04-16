//
// Created by mikhalinho on 11.04.2022.
//

#include "headers/unordered_map.h"

#define default_val array.capacity() + 1
#define NEXT_CACHE elements.at(elements.at(cur_pos).next).cache


using namespace mp5;


unordered_map::unordered_map(size_t(*hash_function) (const simple_string&)) : hash_func(hash_function) {
    //array[0] = &elements;
    std::fill(array.begin(), array.end(), default_val);
}

unordered_map::unordered_map(size_t(*hash_function) (const simple_string&), size_t capacity) : hash_func(hash_function) {
    array = vector<size_t>(capacity);
    std::fill(array.begin(), array.end(), default_val);
    //elements = List(capacity);
    //array.reserve(capacity);
    //array[0] = &elements;
}

void unordered_map::insert(List_elem elem) {
    elem.cache = elem.cache % array.capacity();

    if (array[elem.cache] == default_val)
        array[elem.cache] = elements.Insert(elements.Get_tail(), elem.item, elem.cache);

    else {
        size_t cur_pos = array[elem.cache];

        while (sscmp(elem.item, elements[cur_pos].item) == 1 && elem.cache == NEXT_CACHE)
            cur_pos = elements[cur_pos].next;

        elements.Insert(array[elem.cache], elem.item, elem.cache);
    }
}

void unordered_map::insert(const simple_string& elem) {
    size_t cache = hash_func(elem) % array.capacity();

    if (array[cache] == default_val)
        array[cache] = elements.Insert(elements.Get_tail(), elem, cache);

    else {
        size_t cur_pos = array[cache];

        while (sscmp(elem, elements[cur_pos].item) == 1 && cache == NEXT_CACHE)
            cur_pos = elements[cur_pos].next;

        elements.Insert(array[cache], elem, cache);
    }
}


bool unordered_map::remove(const simple_string& key) {
    size_t cache = hash_func(key);

    if (array[cache] == default_val) return false;

    int cur_pos = array[cache];

    while (sscmp(key, elements[cur_pos].item) == 1 && cache == NEXT_CACHE) ++cur_pos;

    if (!sscmp(key, elements[cur_pos].item)) {              //strings are equal
        if (cur_pos == array[cache]) {
            if (elements[cur_pos].next != -1) array[cache] = elements[cur_pos].next;
            else array[cache] = default_val;
        }

        elements.Delete_elem(cur_pos);
        return true;
    }

    return false;
}

const simple_string* unordered_map::find_ptr(const simple_string& key) const {
    size_t cache = hash_func(key);

    if (array[cache] == default_val) return nullptr;

    int cur_pos = array[cache];

    while (sscmp(key, elements.at(cur_pos).item) == 1 && cache == NEXT_CACHE) ++cur_pos;

    if (!sscmp(key, elements.at(cur_pos).item)) return &elements.at(cur_pos).item;             //strings are equal

    return nullptr;
}

size_t unordered_map::find_pos(const simple_string& key) const {
    size_t cache = hash_func(key);

    if (array[cache] == default_val) return default_val;

    int cur_pos = array[cache];

    while (sscmp(key, elements.at(cur_pos).item) == 1 && cache == NEXT_CACHE) ++cur_pos;

    if (!sscmp(key, elements.at(cur_pos).item)) return cur_pos;             //strings are equal

    return default_val;
}

void unordered_map::dump() { elements.Dump(); }