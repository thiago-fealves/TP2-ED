#include "utils.hpp"
#include <iostream>

// Initializing parameters
int SimulationParameters::capacity = 0;
double SimulationParameters::velocity = 0.0;
double SimulationParameters::interval = 0.0;
double SimulationParameters::maxDistanceOrigin = 0.0;
double SimulationParameters::maxDistanceDestination = 0.0;
double SimulationParameters::eficiency = 0.0;

// Parameters Input
void SimulationParameters::getSimulationParameters(){
  std::cin >> capacity >> velocity >> interval >> maxDistanceOrigin >> maxDistanceDestination >> eficiency;
}
void SimulationParameters::printParameters(){
  std::cout << capacity << " " << velocity << " " << interval; 
  std::cout << " " << maxDistanceOrigin << " " << maxDistanceDestination << " " << eficiency << std::endl; 
}

// Vector2D
Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

Vector2D Vector2D::operator+(const Vector2D& other) const {
  return Vector2D(this->x + other.x, this->y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
  return Vector2D(this->x - other.x, this->y - other.y);
}

Vector2D Vector2D::operator*(const int scalar) const {
  return Vector2D(this->x * scalar, this->y * scalar);
}
