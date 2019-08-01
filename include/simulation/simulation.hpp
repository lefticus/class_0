#ifndef POSITION_HPP
#define POSITION_HPP

#include <string>
#include <vector>


struct Meters {
  double meter{0};
};

struct Position {
  Meters x;
  Meters y;
};

struct MetersPerSecond {
  double value{0};
};

struct Velocity {
  MetersPerSecond x;
  MetersPerSecond y;
};

struct Seconds {
  double seconds{0};
};

struct Temperature {
  double k{0};
};

// inline is required here to prevent a multiple-definition
// of this function error when the code is linked
inline Meters operator*(const MetersPerSecond &mps, const Seconds &seconds) {
  return Meters{mps.value * seconds.seconds};
}

inline Position operator*(const Velocity &speed, const Seconds &seconds) {
  return Position{speed.x * seconds, speed.y * seconds};
}

inline Meters &operator+=(Meters &lhs, const Meters &rhs) {
  lhs.meter += rhs.meter;
  return lhs;
}

inline Position &operator+=(Position &initial, const Position &offset) {
  initial.x += offset.x;
  initial.y += offset.y;
  return initial;
}

struct Particle {
  Position pos;
  Velocity velocity;
  Temperature temp;

  void timestep(const Seconds &time) { pos += velocity * time; }
};

struct World {
  World(const std::string &filename);

  void timestep(const Seconds &time);
  std::vector<Particle> particles;

};

#endif

