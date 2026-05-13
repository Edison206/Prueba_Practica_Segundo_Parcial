// ============================================================
//  Aplicativo Interactivo de Logica y Algoritmos
//  Asignatura : Algoritmos y Logica de Programacion
//  Estudiante : Edison Landeta
//  Docente    : Ing. Jose Ruben Caiza Caizabuano, Mg.
//  Universidad: Universidad Tecnica de Ambato - FISEI
//  Periodo    : Enero 2026 - Julio 2026
// ============================================================

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

// ---------- Nomina del curso ----------
const int TOTAL_ESTUDIANTES = 39;
string nomina[TOTAL_ESTUDIANTES] = {
    "Acosta Hanna",
    "Andrade Hugo",
    "Atiencia Josue",
    "Balarrezo Diego",
    "Barrionuevo Sol",
    "Bedoya Juan",
    "Bravo Samuel",
    "Cajiao Paulo",
    "Calvopina Brandon",
    "Castelo Katherine",
    "Chacha Victor",
    "Chiluiza Steed",
    "Dominguez Daniel",
    "Freire Alan",
    "Gualle Abisag",
    "Guaman Alexander",
    "Guanga Sebastian",
    "Guanotoa Karla",
    "Landeta Edison",
    "Lara Karen",
    "Loor Jhon",
    "Lopez Washington",
    "Miranda Imanol",
    "Monar Jhair",
    "Muyulema Mateo",
    "Narvaez Antonella",
    "Nunez Bryan",
    "Pilco Mario",
    "Pomaquero Katherine",
    "Quevedo Gina",
    "Rivadeneira Matias",
    "Rocha Carolina",
    "Sanchez Isaac",
    "Segovia Joseph",
    "Supe Joan",
    "Toapanta Matias",
    "Verdesoto Kevin",
    "Villacres Alejandro",
    "Viteri Shantal"
};

int main() {

    // ---------- Declaracion de variables ----------
    int    opcion;
    double num1, num2;
    double notas[5];
    double suma, promedio, mayor, menor;
    int    aprobados, reprobados;
    string nombre;
    bool   hayNotas = false;

    suma = 0; promedio = 0; mayor = 0; menor = 0;
    aprobados = 0; reprobados = 0;

    // ---------- Nombre del estudiante ----------
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre);

    // ---------- Menu principal ----------
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Operaciones basicas\n";
        cout << "2. Registro de notas\n";
        cout << "3. Guardar resultados\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        // ------ Opcion 1: operaciones matematicas ------
        case 1:
            cout << "Ingrese el primer numero: ";
            cin >> num1;
            cout << "Ingrese el segundo numero: ";
            cin >> num2;

            cout << "\n--- Resultados ---\n";
            cout << "Suma:            " << num1 + num2 << "\n";
            cout << "Resta:           " << num1 - num2 << "\n";
            cout << "Multiplicacion:  " << num1 * num2 << "\n";

            if (num2 != 0)
                cout << "Division:        " << num1 / num2 << "\n";
            else
                cout << "Division:        Error - division entre cero no permitida\n";
            break;

        // ------ Opcion 2: registro de notas ------
        case 2:
            for (int i = 0; i < 5; i++) {
                cout << "Ingrese la nota " << i + 1 << ": ";
                cin >> notas[i];
            }

            suma       = 0;
            mayor      = notas[0];
            menor      = notas[0];
            aprobados  = 0;
            reprobados = 0;

            for (int i = 0; i < 5; i++) {
                suma += notas[i];
                if (notas[i] > mayor)  mayor = notas[i];
                if (notas[i] < menor)  menor = notas[i];
                if (notas[i] >= 7)     aprobados++;
                else                   reprobados++;
            }

            promedio = suma / 5.0;
            hayNotas = true;

            cout << "\n--- Resultados de notas ---\n";
            cout << "Promedio:   " << promedio   << "\n";
            cout << "Nota mayor: " << mayor      << "\n";
            cout << "Nota menor: " << menor      << "\n";
            cout << "Aprobados:  " << aprobados  << "\n";
            cout << "Reprobados: " << reprobados << "\n";
            break;

        // ------ Opcion 3: guardar en archivo ------
        case 3: {
            time_t t  = time(0);
            tm*    lt = localtime(&t);
            char   fecha[20];
            strftime(fecha, sizeof(fecha), "%d/%m/%Y", lt);

            ofstream archivo("resultados/resultados.txt");
            if (archivo.is_open()) {

                // Datos del estudiante y resultados
                archivo << "Estudiante: " << nombre << "\n";
                archivo << "Fecha:      " << fecha  << "\n";
                archivo << "Lenguaje:   C++"        << "\n";

                if (hayNotas) {
                    archivo << "Promedio:   " << promedio   << "\n";
                    archivo << "Nota mayor: " << mayor      << "\n";
                    archivo << "Nota menor: " << menor      << "\n";
                    archivo << "Aprobados:  " << aprobados  << "\n";
                    archivo << "Reprobados: " << reprobados << "\n";
                } else {
                    archivo << "(No se registraron notas en esta sesion)\n";
                }

                // Nomina completa del curso
                archivo << "\n";
                archivo << "============================================================\n";
                archivo << "NOMINA DEL CURSO - ALGORITMOS Y LOGICA DE PROGRAMACION\n";
                archivo << "Universidad Tecnica de Ambato | FISEI | Carrera de Software\n";
                archivo << "Periodo: Enero 2026 - Julio 2026\n";
                archivo << "============================================================\n\n";

                for (int i = 0; i < TOTAL_ESTUDIANTES; i++) {
                    if (i + 1 < 10) archivo << " ";
                    archivo << i + 1 << ". " << nomina[i] << "\n";
                }

                archivo.close();
                cout << "Resultados guardados correctamente en resultados/resultados.txt\n";
            } else {
                cout << "Error: no se pudo abrir el archivo. "
                     << "Verifique que la carpeta /resultados exista.\n";
            }
            break;
        }

        // ------ Opcion 4: salir ------
        case 4:
            cout << "Fin del programa. Hasta pronto.\n";
            break;

        default:
            cout << "Opcion invalida, intente de nuevo.\n";
        }

    } while (opcion != 4);

    return 0;
}
