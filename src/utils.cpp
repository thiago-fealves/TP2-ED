#include "utils.hpp"
#include <iostream>
#include <ostream>

// Parameters
void SimulationParameters::getSimulationParameters(){
  std::cin >> capacity >> velocity >> interval >> distanceOrigin >> distanceDestination >> eficiency;
}
void SimulationParameters::printParameters(){
  std::cout << capacity << " " << velocity << " " << interval; 
  std::cout << " " << distanceOrigin << " " << distanceDestination << " " << eficiency << std::endl; 
}

// Vector2D
Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(int x, int y) : x(x), y(y) {}

Vector2D Vector2D::operator+(const Vector2D& other) const {
  return Vector2D(this->x + other.x, this->y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
  return Vector2D(this->x - other.x, this->y - other.y);
}

Vector2D Vector2D::operator*(const int scalar) const {
  return Vector2D(this->x * scalar, this->y * scalar);
}
