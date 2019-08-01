#include <vector>
#include <algorithm>

#include <simulation/simulation.hpp>

World::World(const std::string &file_location)
{
  // do things
}

void World::timestep(const Seconds &time)
{
  const auto advance_time_step = [time](auto &particle) {
    particle.timestep(time);
  };

  for (int i = 0; i < 10000; ++i) {
    std::for_each(begin(particles), end(particles), advance_time_step);
  }
}


