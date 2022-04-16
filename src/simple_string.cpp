//
// Created by mikhalinho on 11.04.2022.
//

#include "headers/simple_string.h"


simple_string::simple_string(char* src) {
    if (src == nullptr) {
        fprintf(stderr, "Your string is empty!\n");
        return;
    }
    size = strlen(src);
    data = new char[size + 1];
    strcpy(data, src);
}

simple_string::simple_string(const char* src) {
    if (src == nullptr) {
        fprintf(stderr, "Your string is empty!\n");
        throw 1;
    }
    size = strlen(src);
    data = new char[size + 1];
    strcpy(data, src);
}

simple_string::simple_string (FILE* src) : size(Size_of_file(src)),
                                           data(text_from_file(src, Size_of_file(src))) {};

size_t Size_of_file(FILE* name_of_file) {
    fseek(name_of_file, 0, SEEK_END);
    size_t size_of_file = ftell(name_of_file);
    fseek(name_of_file, 0, SEEK_SET);

    return size_of_file;
}

char* text_from_file(FILE* file_name, size_t size_of_file){
    char* result_string = new char[size_of_file + 1];
    fread(result_string, sizeof(char), size_of_file + 1, file_name);

    return result_string;
}

simple_string &operator<<(simple_string &sstr, const char *str) {
    size_t src_size = strlen(str);
    sstr.size += src_size + 1;

    auto new_data = new char [sstr.size];

    strcpy(new_data, sstr.data);
    new_data = strcat(new_data, str);

    delete[] sstr.data;
    sstr.data = new_data;

    return sstr;
}

char& simple_string::operator[](int index) {
    if (index >= size) {
        fprintf(stderr, "Array index out of bound, exiting...\n");
        throw std::out_of_range("Index out of range!\n");
    }

    return data[index];
}


char& simple_string::operator[](int index) const{
    if (index >= size) {
        fprintf(stderr, "Array index out of bound, exiting...\n");
        throw std::out_of_range("Index out of range!\n");
    }

    return data[index];
}

const char *simple_string::get_data() const { return data; }

size_t simple_string::get_size() const { return size; }

int sscmp(const simple_string& s1, const simple_string& s2) {
    int i = 0, j = 0;
    while(true) {
        while(!(isalpha(s1[i]) || s1[i] == '\0')) i++;
        while(!(isalpha(s2[j]) || s2[j] == '\0')) j++;

        if (s1[i] == '\0' &&
            s2[j] == '\0')
            return 0;

        if (s1[i] == s2[j]){
            i++;
            j++;
        }

        else
            return s1[i] - s2[j] / abs(s1[i] - s2[j]);
    }
}
