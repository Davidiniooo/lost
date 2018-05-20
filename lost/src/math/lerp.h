namespace lost::math {

double lerp(double t, double a, double b) {
  return (1 - t) * a + t * b;
}

} // namespace lsot::math