#include <filesystem>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "absl/log/check.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_split.h"

std::filesystem::path filename = "inputs/day2.txt";

using svpair = std::pair<std::string_view, std::string_view>;

bool game_is_good(std::string_view gamestr) {
  for (auto round : absl::StrSplit(gamestr, "; ")) {
    for (auto cuberesult : absl::StrSplit(round, ", ")) {
      svpair val = absl::StrSplit(cuberesult, " ");
      int cubect;
      CHECK(absl::SimpleAtoi(val.first, &cubect));
      if ((val.second == "red" && cubect > 12) ||
          (val.second == "green" && cubect > 13) ||
          (val.second == "blue" && cubect > 14)) {
        return false;
        ;
      }
    }
  }
  return true;
}

void parta(const std::vector<std::string> &lines) {
  int idsum = 0;
  for (std::string_view line : lines) {
    svpair gamesplit = absl::StrSplit(line, ": ");
    if (game_is_good(gamesplit.second)) {
      svpair g2 = absl::StrSplit(gamesplit.first, " ");
      int gameno;
      CHECK(absl::SimpleAtoi(g2.second, &gameno));
      idsum += gameno;
    }
  }
  std::cout << idsum << '\n';
}

int gamepower(std::string_view rounds) {
  std::vector<int> cubemins(3);
  for (auto round : absl::StrSplit(rounds, "; ")) {
    for (auto cuberesult : absl::StrSplit(round, ", ")) {
      svpair cubeval = absl::StrSplit(cuberesult, " ");
      int cubect;
      CHECK(absl::SimpleAtoi(cubeval.first, &cubect));
      int i = 0;
      if (cubeval.second == "green") {
        i = 1;
      }
      if (cubeval.second == "blue") {
        i = 2;
      }
      cubemins[i] = std::max(cubemins[i], cubect);
    }
  }
  return std::reduce(cubemins.begin(), cubemins.end(), 1, std::multiplies<>());
}

void partb(const std::vector<std::string> &lines) {
  int power = 0;
  for (std::string_view line : lines) {
    svpair gamesplit = absl::StrSplit(line, ": ");
    power += gamepower(gamesplit.second);
  }
  std::cout << power << '\n';
}