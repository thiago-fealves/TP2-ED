#include "utils.hpp"
#include <iostream>
#include <ostream>

void SimulationParameters::getSimulationParameters(){
  std::cin >> capacidade >> velocidade >> intervalo >> distanciaOrigem >> distanciaDestino >> eficiencia;
}
void SimulationParameters::printParameters(){
  std::cout << capacidade << " " << velocidade << " " << intervalo; 
  std::cout << " " << distanciaOrigem << " " << distanciaDestino << " " << eficiencia << std::endl; 
}
