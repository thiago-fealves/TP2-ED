#ifndef UTILS
#define UTILS

class SimulationParameters {
  // Data must be public so other functions can access directly, there is no sensible information here
  public:
    // Attributes eta, gama, delta, alfa, beta and lambda, respectively
    static int capacity;
    static double velocity;
    static double interval;
    static double maxDistanceOrigin;
    static double maxDistanceDestination;
    static double efficiency;
    
    // Initialization
    static void getSimulationParameters();
    static void printParameters();
};

class Vector2D {
  public:
    // Attributes
    double x;
    double y;

    // Constructors
    Vector2D();
    Vector2D(double x, double y);

    // Operations
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(const int scalar) const;
    
    // Utility
    static double distance(Vector2D one, Vector2D two);
};



#endif

