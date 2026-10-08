#include <iostream>
#include <string>

using namespace std;

constexpr int N_CHARS = 26;

inline int char_to_index(char c) {
    return c - 'A';
}

inline char index_to_char(int index) {
    return static_cast<char>('A' + index);
}

inline void count(string& line, int counts[]) {
    for (int i = 0; i < line.length(); i++) {
        char c = line[i];
        if (c >= 'A' && c <= 'Z') {
            int index = char_to_index(c);
            counts[index]++;
        } else if (c >= 'a' && c <= 'z') {
            char upper_c = static_cast<char>(c - 'a' + 'A');
            int index = char_to_index(upper_c);
            counts[index]++;
        }
    }
}

inline void print_counts(const int counts[]) {
    for (int i = 0; i < N_CHARS; ++i) {
        cout << index_to_char(i) << " " << counts[i] << endl;
    }
}
