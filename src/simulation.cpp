#include <vector>
#include <simulation.hpp>
#include <algorithm>

int main(const int argc, const char *[]) {
  const auto advance_time_step = [](auto &particle) {
    particle.timestep(Seconds{0.1});
  };

  std::vector<Particle> world;
  for (int i = 0; i < 10000; ++i) {
    std::for_each(begin(world), end(world), advance_time_step);
  }
}
