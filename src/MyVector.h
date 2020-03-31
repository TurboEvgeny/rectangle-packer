// реализация двумерного вектора с операторами сложения,
// вычитания, скалярного произведения (все в прямоугольной ортогональной ск)
class MyVector
{
 public:
 MyVector():
  x(0.0),
  y(0.0)
  {}
 MyVector(double xArg, double yArg):
  x(xArg),
  y(yArg)
  {}
  friend MyVector operator+(const MyVector& lhs, const MyVector& rhs)
  {
    return MyVector(lhs.x + rhs.x, lhs.y + rhs.y);
  }
  friend MyVector operator-(const MyVector& lhs, const MyVector& rhs)
  {
    return MyVector(lhs.x - rhs.x, lhs.y - rhs.y);
  }
  double dotProduct(const MyVector& other)
  {
    return this->x * other.x + this->y * other.y;
  }
 private:
  double x;
  double y;
};
