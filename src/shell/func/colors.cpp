#include "colors.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";

enum ColorScheme {
    RANDOM_COLOR,
    RED_SCHEME,
    GREEN_SCHEME,
    YELLOW_SCHEME,
    BLUE_SCHEME,
    MAGENTA_SCHEME,
    CYAN_SCHEME,
    WHITE_SCHEME
};

bool useColors = true;
ColorScheme colorScheme = RANDOM_COLOR;

std::string getRandomColor() {
    const std::string colors[] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
    
    switch(colorScheme) {
        case RANDOM_COLOR:
            return colors[rand() % sizeof(colors)/sizeof(colors[0])];
        case RED_SCHEME:
            return RED;
        case GREEN_SCHEME:
            return GREEN;
        case YELLOW_SCHEME:
            return YELLOW;
        case BLUE_SCHEME:
            return BLUE;
        case MAGENTA_SCHEME:
            return MAGENTA;
        case CYAN_SCHEME:
            return CYAN;
        case WHITE_SCHEME:
            return WHITE;
        default:
            return "";
    }
}

void readConfigFile() {
    std::ifstream configFile("./config/config.conf");
    if(configFile.is_open()) {
        std::string line;
        while(getline(configFile, line)) {  
            if(line.find("$rainbow_colors") != std::string::npos) { 
                size_t pos = line.find('=');
                if(pos != std::string::npos) {
                    std::string value = line.substr(pos + 1);
                    if(value == "true") {
                        useColors = true;
                    } else if(value == "false") {
                        useColors = false;
                    }
                }
            }
            if(line.find("$color_scheme") != std::string::npos) {
                size_t pos = line.find('=');
                if(pos != std::string::npos) {
                    std::string value = line.substr(pos + 1);
                    if(value == "random") {
                        colorScheme = RANDOM_COLOR;
                    } else if(value == "red") {
                        colorScheme = RED_SCHEME;
                    } else if(value == "green") {
                        colorScheme = GREEN_SCHEME;
                    } else if(value == "yellow") {
                        colorScheme = YELLOW_SCHEME;
                    } else if(value == "blue") {
                        colorScheme = BLUE_SCHEME;
                    } else if(value == "magenta") {
                        colorScheme = MAGENTA_SCHEME;
                    } else if(value == "cyan") {
                        colorScheme = CYAN_SCHEME;
                    } else if(value == "white") {
                        colorScheme = WHITE_SCHEME;
                    } else {
                        colorScheme = RANDOM_COLOR; 
                    }
                }
            }
        }
        configFile.close();
    } else {
        std::cerr << "$Error, file config.conf not found" << std::endl;
    }
}

void printAsciiArt(const std::string& asciiArt) {
    for(char c : asciiArt) {
        if(useColors) {
            if(c == ' ') {
                std::cout << getRandomColor() << c << RESET;
            } else if(c == '\t') {
                std::cout << getRandomColor() << "    " << RESET;
            } else {
                std::cout << getRandomColor() << c << RESET;
            }
        } else {
            std::cout << c;
        }
    }
}