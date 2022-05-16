#include <iostream>
#include <vector>

#include "../include/FEN_maker.hpp"

#define EMPTY_PLACE '0'

using namespace std;

string FEN_maker(vector <char> matrix) {
    string answer = "";
    for (int i = 0; i < 8; ++i) {
        int count = 0;
        for (int j = 0; j < 8; ++j) {
            if (matrix[i * 8 + j] == EMPTY_PLACE) {
                count++;
            } else {
                if (count != 0) {
                    answer.push_back((char)(count + 48));
                }
                answer.push_back(matrix[i * 8 + j]);
                count = 0;
            }
        }
        if (count != 0) {
            answer.push_back((char)(count + 48));
        }
        if (i != 7) {
            answer.push_back('/');
        }
    }
    answer.push_back(' ');
    answer.push_back('w');
    answer.push_back(' ');
    answer.push_back('-');
    answer.push_back(' ');
    answer.push_back('-');
    answer.push_back(' ');
    answer.push_back('0');
    answer.push_back(' ');
    answer.push_back('1');
    return answer;
}