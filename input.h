#ifndef _AOC23CPP_INPUT_H_
#define _AOC23CPP_INPUT_H_

#include <filesystem>
#include <string>
#include <vector>

namespace aoc23cpp {

std::vector<std::string> FileLines(const std::filesystem::path &filename);

} // namespace aoc23cpp

#endif // _AOC23CPP_INPUT_H_