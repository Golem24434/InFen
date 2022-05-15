#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> object_symbol_T =   
                            {255, 255, 255, 255, 255, 
                            0, 0, 255, 0, 0,
                            0, 0, 255, 0, 0,
                            0, 0, 255, 0, 0,
                            0, 0, 255, 0, 0};
vector<int> object_symbol_plus =   
                            {0, 0, 255, 0, 0, 
                            0, 0, 255, 0, 0,
                            255, 255, 255, 255, 255,
                            0, 0, 255, 0, 0,
                            0, 0, 255, 0, 0};
vector<int> object_symbol_minus =   
                            {0, 0, 0, 0, 0, 
                            0, 0, 0, 0, 0,
                            255, 255, 255, 255, 255,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0};
vector<int> object_symbol_P =   
                            {255, 255, 0, 0, 0, 
                            255, 0, 255, 0, 0,
                            255, 255, 0, 0, 0,
                            255, 0, 0, 0, 0,
                            255, 0, 0, 0, 0};
vector<int> object_symbol_L =   
                            {255, 0, 0, 0, 0, 
                            255, 0, 0, 0, 0,
                            255, 0, 0, 0, 0,
                            255, 0, 0, 0, 0,
                            255, 255, 255, 255, 255};
vector<vector<int>> objects = {object_symbol_T, object_symbol_plus, object_symbol_minus, object_symbol_P, object_symbol_L};
int definition_of_objects(std::vector<int> input_object) {
    int temp_difference = 6375;
    int difference = 0;
    int temp_index = 0;
    for (int i = 0;i < objects.size(); i++) {
        vector<int> temp = objects[i];
        for (int j = 0;j < 25; ++j) {
            difference += abs(input_object[j] - temp[j]);
        }
        if (difference < temp_difference) {
            temp_index = i;
            temp_difference = difference;
        }
        difference = 0;
    }
    return temp_index;
}

int main(void) {
    vector<int> object_symbol_L_ex =   
                            {200, 1, 0, 0, 0, 
                            200, 20, 0, 0, 0,
                            200, 1, 0, 0, 0,
                            200, 1, 30, 23, 40,
                            200, 200, 200, 200, 200};
    int index = definition_of_objects(object_symbol_L_ex);
    cout << index;
	return 0;
}