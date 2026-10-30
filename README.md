# Práctica 2 — Multiplicación rápida de enteros: Karatsuba

## Asignatura
Análisis y Diseño de Algoritmos

## Descripción
Implementación y análisis comparativo de dos algoritmos de multiplicación de enteros de precisión arbitraria:

- Multiplicación clásica: Θ(n²).
- Algoritmo de Karatsuba: Θ(n^log₂3).

El proyecto utiliza representación decimal mediante cadenas de caracteres y aplica la estrategia de Divide y Vencerás.

## Integrantes
- Camila Garcia Ortiz

## Estructura del proyecto
- `src/`: implementaciones.
- `include/`: archivos de cabecera.
- `tests/`: pruebas de correctitud.
- `experiments/`: experimentos y mediciones.
- `docs/`: informe y figuras.

## Requisitos
- Compilador compatible con C++17.
- Python 3 (para generar las gráficas).

## Compilación
```bash
make
```

## Ejecución
```bash
./bin/practica2
```

## Ejecución de pruebas
```bash
make test
```

## Ejecución de experimentos
```bash
make benchmark
```

## Resultados
Los resultados experimentales se almacenan en `experiments/results.csv`.

## Informe
El informe completo se encuentra en `docs/informe.pdf`.

## Licencia y uso académico
Proyecto desarrollado con fines académicos para la asignatura Análisis y Diseño de Algoritmos.