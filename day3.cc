#include <cctype>
#include <filesystem>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

std::filesystem::path filename = "inputs/day3.txt";

using ipair = std::pair<int, int>;

struct num_and_adjs {
  int num;
  std::set<ipair> adjs;
};

std::vector<num_and_adjs> gather_nums(const std::vector<std::string> &lines) {
  std::vector<num_and_adjs> num_options;
  for (int row = 0; row < lines.size(); ++row) {
    int running_num = 0;
    std::set<ipair> adjacencies;
    for (int col = 0; col < lines[row].size(); ++col) {
      char c = lines[row][col];
      if (std::isdigit(c)) {
        running_num *= 10;
        running_num += (c - '0');
        for (int r : {row - 1, row, row + 1}) {
          for (int c : {col - 1, col, col + 1}) {
            if (r != row || c != col) {
              // For multi-digit numbers we count the digits themselves as
              // adjacencies. That's fine: they can't also be symbols!
              adjacencies.insert({r, c});
            }
          }
        }
        continue;
      }

      // not a digit - end a running sum if any
      if (running_num != 0) {
        // end of a number
        num_options.push_back(
            {.num = running_num, .adjs = std::move(adjacencies)});
        adjacencies.clear();
        running_num = 0;
      }
    }

    // end of a line - end a running sum if any
    if (running_num != 0) {
      // end of a number
      num_options.push_back(
          {.num = running_num, .adjs = std::move(adjacencies)});
      adjacencies.clear();
      running_num = 0;
    }
  }
  return num_options;
}

void parta(const std::vector<std::string> &lines) {
  std::vector<num_and_adjs> num_options = gather_nums(lines);
  std::set<ipair> symbols;
  for (int row = 0; row < lines.size(); ++row) {
    for (int col = 0; col < lines[row].size(); ++col) {
      char c = lines[row][col];

      // not a digit or a . - is a symbol
      if (!(std::isdigit(c) || c == '.')) {
        symbols.insert({row, col});
      }
    }
  }

  // For each num, if any of its adjacencies is a symbol, count it.
  int sum = 0;
  for (const auto &[n, adjs] : num_options) {
    if (std::any_of(adjs.begin(), adjs.end(), [&symbols](const auto &rc) {
          return symbols.contains(rc);
        })) {
      sum += n;
    }
  }

  std::cout << sum << '\n';
}

void partb(const std::vector<std::string> &lines) {
  std::vector<num_and_adjs> num_options = gather_nums(lines);
  std::set<ipair> gear_locs;
  for (int row = 0; row < lines.size(); ++row) {
    for (int col = 0; col < lines[row].size(); ++col) {
      char c = lines[row][col];
      // * - a gear
      if (c == '*') {
        gear_locs.insert({row, col});
      }
    }
  }

  // For each num, find the gears it is next to.
  std::map<ipair, std::vector<int>> gear_nums;
  for (const auto &[n, adjs] : num_options) {
    for (const auto &adj : adjs) {
      if (gear_locs.contains(adj)) {
        gear_nums[adj].push_back(n);
      }
    }
  }

  int gear = 0;
  for (const auto &[g, ns] : gear_nums) {
    if (ns.size() == 2) {
      gear += (ns[0] * ns[1]);
    }
  }

  std::cout << gear << '\n';
}