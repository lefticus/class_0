#include <iostream>
#include <array>
#include <numeric>

int main(const int argc, const char *argv[])
{
  constexpr std::array<int, 5> data{34, 12, 19, 102, 4};

  const auto sum = std::accumulate(begin(data), end(data), 0.0);

  if (argc > 5) {
    std::cout << " That's a lot of arguments\n";
  }

  if (argc == 4) {
    std::cout << "exactly 4\n";
  }

  std::cout << "Sum: " << sum << '\n';
  std::cout << "Average: " << (sum / double(data.size())) << '\n';
}
