#include <string>
#include <vector>

#include "input.h"

void parta(const std::vector<std::string>&);
void partb(const std::vector<std::string>&);

extern std::filesystem::path filename;

int main(int argc, char** argv) {
    auto lines = aoc23cpp::FileLines(filename);
    parta(lines);
    partb(lines);
}