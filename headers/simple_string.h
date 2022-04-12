//
// Created by mikhalinho on 11.04.2022.
//

#ifndef HASHTABLE_SIMPLE_STRING_H
#define HASHTABLE_SIMPLE_STRING_H


#include <cstring>
#include <cstdio>

class simple_string;

/*!
 * @brief compares 2 simple strings
 * @param s1
 * @param s2
 * @return {s1 > s2 => 1}, {s1 == s2 => 0}, {s1 < s2 => -1}
 */
int sscmp(simple_string s1, simple_string s2);


size_t Size_of_file(FILE* name_of_file);

char* text_from_file(FILE* file_name, size_t size_of_file);


class simple_string {
public:
    simple_string() = default;
    explicit simple_string (char* src);
    explicit simple_string (FILE* src);
    explicit simple_string (const char* src);

    //simple_string& operator=(const simple_string& cpu) = delete;
    simple_string(const simple_string&)                = delete;

    friend simple_string& operator<<(simple_string& sstr, const char* str);
    friend bool operator==(const simple_string& s1, const simple_string& s2) { return !strcmp(s1.data, s2.data); }

    const char* get_data() const;

    ~simple_string() { delete[] data; }
private:
    char* data = nullptr;
    size_t size = 0;
};


#endif //HASHTABLE_SIMPLE_STRING_H
