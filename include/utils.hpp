#ifndef UTILS
#define UTILS

class SimulationParameters {
  // Data must be public so other functions can access directly, there is no sensible information here
  public:
    // Attributes eta, gama, delta, alfa, beta and lambda, respectively
    int capacidade;
    double velocidade;
    double intervalo;
    double distanciaOrigem;
    double distanciaDestino;
    double eficiencia;
    
    // Initialization
    void getSimulationParameters();
    void printParameters();
};

class Vector2D {
  public:
    // Attributes
    double x;
    double y;

    // Constructors
    Vector2D();
    Vector2D(int x, int y);

    // Operations
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(const int scalar) const;
};

#endif
