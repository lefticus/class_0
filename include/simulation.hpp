struct Meter {
  double meter;
};

struct Position {
  Meter x;
  Meter y;
  Meter z;
};

struct Speed {
  double meterspersecondX;
};

struct Seconds {
  double seconds;
};

struct Temperature {
  double k;
};

Meter operator*(const Speed &speed, const Seconds &seconds) {
  return Meter{speed.meterspersecondX * seconds.seconds};
}

Meter &operator+=(Meter &lhs, const Meter &rhs) {
  lhs.meter += rhs.meter;
  return lhs;
}

struct Particle {
  Position pos;
  Speed speed;
  Temperature temp;

  void timestep(const Seconds time) { pos.x += speed * time; }
};


