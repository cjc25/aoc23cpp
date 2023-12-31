#include "input.h"

#include <filesystem>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

#include "absl/strings/str_split.h"

namespace aoc23cpp {

std::vector<std::string> FileLines(const std::filesystem::path &filename) {
  std::ifstream in_stream(filename);
  std::istreambuf_iterator begin(in_stream);
  std::string input(begin, {});

  return absl::StrSplit(input, "\n");
}

} // namespace aoc23cpp