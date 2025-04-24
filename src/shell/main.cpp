#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "./func/design.hpp"
#include "./func/colors.hpp"
#include "./cmd/line.hpp"
#include "../dll_inject.hpp"

using namespace std;

int main() {
    srand(time(nullptr));

    readConfigFile(); //Work with colors (./src/func/colors.cpp)
    printDesign(); //print main design in terminal (./src/func/design.cpp)
    line(); //line for enter command (./src/cmd/line.cpp)

    return 0;
}
