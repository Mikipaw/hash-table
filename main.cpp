#include <cstdio>

#include "headers/unordered_map.h"
#include "headers/Hash_functions.h"


int main() {
    puts("Hello, world!\n");

    mp5::unordered_map ump(first_sym_hash, 127);

    ump.insert(simple_string("Hello"));
    ump.insert(simple_string("Darkness"));
    ump.insert(simple_string("My"));
    ump.insert(simple_string("Old"));
    ump.insert(simple_string("Friend"));
    ump.insert(simple_string("I"));
    ump.insert(simple_string("Cant"));
    ump.insert(simple_string("Hold"));
    ump.insert(simple_string("Myy"));
    ump.insert(simple_string("Fire"));
    ump.insert(simple_string("Again"));

    ump.dump();

    return 0;
}
