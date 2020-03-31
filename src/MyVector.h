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
  MyVector operator+(const MyVector& a)
  {
    return MyVector(a.x + this->x, a.y + this->y);
  }
  MyVector operator-(const MyVector& a)
  {
    return MyVector(this->x - a.x, this->y - a.y);
  }
  double dotProduct(const MyVector& a, const MyVector& b)
  {
    return a.x*b.x + a.y*b.y;
  }
 private:
  double x;
  double y;
};
