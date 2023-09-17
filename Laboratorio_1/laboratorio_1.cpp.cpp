#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>
using namespace std;

double DistanciaEuclidiana(const vector<double>& punto1, const vector<double>& punto2) {
    double distancia = 0.0;
    for (int i = 0; i < punto1.size(); ++i) {
        //elevamos al cuadrado la resta de dos coordenadas
        distancia = distancia+ pow(punto1[i] - punto2[i], 2);
    }
    //sacamos la raíz cuadrada de la suma de las coordenadas
    return sqrt(distancia);
}

int main() {
    const int num_puntos = 100;  // número de puntos a generar
    const int dimension = 5000;     // dimensión de los puntos

    random_device rd;
    mt19937 gen(rd());

    // distribución de los puntos entre 0 y 1
    uniform_real_distribution<double> dis(0.0, 1.0);

    // se crea un vector y se almacenarán los puntos aleatorios
    vector<vector<double>> puntos(num_puntos, vector<double>(dimension, 0.0));

    for (int i = 0; i < num_puntos; ++i) {
        for (int j = 0; j < dimension; ++j) {
            puntos[i][j] = dis(gen);
        }
    }

    ofstream outFile("distancias.txt");
    // Calcular y guardamos las distancias euclidianas
    for (int i = 0; i < num_puntos; ++i) {
        for (int j = i + 1; j < num_puntos; ++j) {
            double distancia = DistanciaEuclidiana(puntos[i], puntos[j]);
            outFile << distancia << "\n";
        }
    }

    return 0;
}








