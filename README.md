# Aplicativo Interactivo de Lógica y Algoritmos

Aplicativo de consola desarrollado en **C++** como parte de la prueba práctica de la asignatura Algoritmos y Lógica de Programación — Universidad Técnica de Ambato, FISEI, Carrera de Software. Período enero–julio 2026.

## Descripción

El programa presenta un menú interactivo con cuatro opciones:

1. **Operaciones básicas** — suma, resta, multiplicación y división con validación de divisor cero.
2. **Registro de notas** — ingreso de 5 notas en un arreglo; calcula promedio, nota mayor, nota menor, cantidad de aprobados y reprobados.
3. **Guardar resultados** — exporta los resultados al archivo `resultados/resultados.txt` con el nombre del estudiante, fecha y lenguaje utilizado.
4. **Salir** — finaliza la ejecución del programa.

## Estructura del repositorio

```
AplicativoInteractivo/
├── README.md
├── src/
│   └── aplicativo.cpp
├── resultados/
│   └── resultados.txt
└── capturas/
```

## Tecnologías

- C++17 — compilado con g++ (MinGW) / Visual Studio Community 2022

## Compilación y ejecución

```bash
g++ src/aplicativo.cpp -o aplicativo
./aplicativo
```

> **Nota:** asegúrese de que la carpeta `resultados/` exista en el directorio de ejecución para que el archivo `resultados.txt` se genere correctamente.

## Estudiante

**Edison Landeta** — Universidad Técnica de Ambato  
Docente: Ing. José Rubén Caiza Caizabuano, Mg.
