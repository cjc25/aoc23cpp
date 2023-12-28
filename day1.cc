#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string_view>
#include <vector>

#include "absl/strings/match.h"
#include "absl/strings/str_split.h"

int to_digit(char c) {
  switch (c) {
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    return c - '0';
    break;
  default:
    return 0;
    break;
  }
}

void parta(std::string_view input) {
  std::vector<std::string_view> lines = absl::StrSplit(input, "\n");
  int running = 0;
  for (auto line : lines) {
    int first = 0;
    int last = 0;
    for (int i = 0; i < line.size(); ++i) {
      if (int v = to_digit(line[i]); v != 0) {
        first = v;
        break;
      }
    }
    for (int i = line.size(); i > 0; --i) {
      if (int v = to_digit(line[i - 1]); v != 0) {
        last = v;
        break;
      }
    }
    running += (10 * first) + last;
  }
  std::cout << running << '\n';
}

int to_digit(std::string_view in) {
  if (absl::StartsWith(in, "one") || absl::StartsWith(in, "1")) {
    return 1;
  }
  if (absl::StartsWith(in, "two") || absl::StartsWith(in, "2")) {
    return 2;
  }
  if (absl::StartsWith(in, "three") || absl::StartsWith(in, "3")) {
    return 3;
  }
  if (absl::StartsWith(in, "four") || absl::StartsWith(in, "4")) {
    return 4;
  }
  if (absl::StartsWith(in, "five") || absl::StartsWith(in, "5")) {
    return 5;
  }
  if (absl::StartsWith(in, "six") || absl::StartsWith(in, "6")) {
    return 6;
  }
  if (absl::StartsWith(in, "seven") || absl::StartsWith(in, "7")) {
    return 7;
  }
  if (absl::StartsWith(in, "eight") || absl::StartsWith(in, "8")) {
    return 8;
  }
  if (absl::StartsWith(in, "nine") || absl::StartsWith(in, "9")) {
    return 9;
  }
  return 0;
}

void partb(std::string_view input) {
  std::vector<std::string_view> lines = absl::StrSplit(input, "\n");
  int running = 0;
  for (auto line : lines) {
    int first = 0;
    int last = 0;
    for (int i = 0; i < line.size(); ++i) {
      std::string_view sub = line.substr(i);
      if (int v = to_digit(sub); v != 0) {
        first = v;
        break;
      }
    }
    for (int i = line.size(); i > 0; --i) {
      std::string_view sub = line.substr(i - 1);
      if (int v = to_digit(sub); v != 0) {
        last = v;
        break;
      }
    }
    running += (10 * first) + last;
  }

  std::cout << running << '\n';
}

int main(int argc, char **argv) {
  std::filesystem::path in = "inputs/day1.txt";
  std::ifstream in_stream(in);
  std::istreambuf_iterator begin(in_stream);
  std::string input(begin, {});

  parta(input);
  partb(input);
}