#include "../header/yachtsystem.h"
#include <stdexcept>

using namespace Coruh::Yachtsystem;

double Yachtsystem::add(double a, double b) {
  return a + b;
}

double Yachtsystem::subtract(double a, double b) {
  return a - b;
}

double Yachtsystem::multiply(double a, double b) {
  return a * b;
}

double Yachtsystem::divide(double a, double b) {
  if (b == 0) {
    throw std::invalid_argument("Division by zero is not allowed.");
  }

  return a / b;
}
