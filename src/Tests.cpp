//
// Created by mikhalinho on 16.04.22.
//

#include "headers/Tests.h"
#include <ctime>

int main_test() {
    long time = clock();
    mp5::unordered_map ump(crc_hash, CAPACITY);

    FILE* original_text = fopen(FILENAME,    "rb");

    if (original_text == nullptr) {
        fprintf(stderr, "Error opening file!\n");
        return 2;
    }

    size_t size_of_file = Size_of_file(original_text);
    assert(size_of_file != 0);

    int number_of_lines = 0;
    char* text = text_from_file(original_text, size_of_file, &number_of_lines);
    if (text == nullptr)        return 3;
    if (number_of_lines == 0)   return 4;
    printf("Number of lines in input text - %d\n", number_of_lines);

    simple_string *pointers = (simple_string *) calloc(number_of_lines + 1, sizeof(simple_string));
    pointers[0].data = text;

    Arrange_str_ptrs(pointers, number_of_lines, text);
    //pointers[number_of_lines-1].size = (int) (pointers[number_of_lines].string - pointers[number_of_lines-1].string);

    for (int i = 0; i < number_of_lines - 3; ++i) { ump.insert(pointers[i]); }

    //ump.dump();
    ump.get_coll_num();

    free(pointers);

    printf("Programm time = %.3f sec\n", float(clock() - time) / CLOCKS_PER_SEC);

    return ALL_OK;
}