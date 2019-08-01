#include <iostream>
#include <simulation/simulation.hpp>


int main(const int argc, const char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <inputfilename>\n";
    exit(EXIT_FAILURE);
  }

  // take first parameter and treat it as the input filename
  World world{std::string{argv[1]}};
}


