#include <string>
#include <unordered_map>
using namespace std;

class UndergroundSystem {
private:
    struct Viaje {
        string estacion;
        int tiempo;
    };

    struct Estadistica {
        long long tiempoTotal;
        int cantidad;
    };

    unordered_map<int, Viaje> pasajeros;
    unordered_map<string, Estadistica> rutas;

    string crearRuta(string inicio, string destino) {
        return inicio + "->" + destino;
    }

public:
    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
        pasajeros[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        Viaje viaje = pasajeros[id];
        int duracion = t - viaje.tiempo;

        string ruta = crearRuta(viaje.estacion, stationName);

        if (rutas.find(ruta) == rutas.end()) {
            rutas[ruta] = {duracion, 1};
        } else {
            rutas[ruta].tiempoTotal += duracion;
            rutas[ruta].cantidad++;
        }

        pasajeros.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string ruta = crearRuta(startStation, endStation);
        Estadistica estadistica = rutas[ruta];

        return static_cast<double>(estadistica.tiempoTotal)
               / estadistica.cantidad;
    }
};
