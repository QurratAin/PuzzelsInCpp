#include "RomanToInteger.h"

int RomanToIntegerI::romanToInt(string s)
{
    int integer_number = 0;
    int letter_index = 0;

    while (letter_index < size(s)) {
        if ((s[letter_index] == 'I' && (s[letter_index + 1] == 'V' or s[letter_index + 1] == 'X')) ||
            (s[letter_index] == 'X' && (s[letter_index + 1] == 'L' or s[letter_index + 1] == 'C')) ||
            (s[letter_index] == 'C' && (s[letter_index + 1] == 'D' or s[letter_index + 1] == 'M'))) {
            integer_number += (symbol_map[s[letter_index + 1]] - symbol_map[s[letter_index]]);
            letter_index++;
        }
        else {
            integer_number += symbol_map[s[letter_index]];
        }
        letter_index++;
    }
    return integer_number;
}

int RomanToIntegerII::romanToInt(string s)
{
    int integer_number = 0;
    int letter_index = 0, cur_num = 0, next_num = 0;

    while (letter_index < size(s)) {
        cur_num = symbol_map[s[letter_index]];
        next_num = symbol_map[s[letter_index + 1]];
        if (next_num <= cur_num) {
            integer_number += cur_num;
        }
        else {
            integer_number -= cur_num;
        }
        ++letter_index;
    }
    return integer_number;
}
