#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> orderedMap;

    orderedMap[1] = "Ek";
    orderedMap[2] = "Do";
    orderedMap[3] = "Teen";

    std::cout << "Pehle ordered map:\n";
    for (const auto& pair : orderedMap) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    // Key aur value modify karne ka example
    for (auto& pair : orderedMap) {
        if (pair.first == 2) {
            pair.first = 4; // Key ko modify kiya
            pair.second = "Chaar"; // Value ko modify kiya
        }
    }

    std::cout << "\nModified ordered map:\n";
    for (const auto& pair : orderedMap) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
