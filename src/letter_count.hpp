#include <iostream>
#include <string>

using namespace std;

constexpr int N_CHARS = 26;

int char_to_index(char c) {
    return c - 'A';
}

char index_to_char(int index) {
    return static_cast<char>('A' + index);
}

void count(const string& line, int counts[]) {
    for (size_t i = 0; i < line.length(); i++) {
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

void print_counts(const int counts[], int size = N_CHARS) {
    for (int i = 0; i < size; ++i) {
        cout << index_to_char(i) << " " << counts[i] << endl;
    }
}
