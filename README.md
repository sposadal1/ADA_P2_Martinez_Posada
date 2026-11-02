# Práctica 2: Multiplicación rápida de enteros


## Integrantes
- Juan Daniel Martinez Fernandez
- Samuel Posada Londoño

## Estructura del Repositorio
- `src/`: Código fuente (`main.cpp`, `operaciones.cpp`, `utils.cpp`).
- `include/`: Archivos de cabecera (`operaciones.h`, `utils.h`).
- `Makefile`: Script para la compilación automatizada del proyecto.
- `tiempos.csv`: Archivo de salida con los resultados del benchmark generado durante la ejecución.

## Requisitos
- Compilador de C++ (ej. `g++` o `MinGW-w64` en Windows).
- Utilidad `make` instalada en el sistema.

## Instrucciones de Compilación y Ejecución

Para compilar y probar el código, abre una terminal en la carpeta raíz del repositorio (donde se encuentra el archivo `Makefile`) y sigue estos pasos:

### 1. Compilación
Para compilar el proyecto completo, ejecuta:
```bash
make
```
Esto compilará los archivos de la carpeta `src/` y generará un ejecutable llamado `main.exe` en el directorio principal.

Si necesitas limpiar los archivos binarios compilados (`.o`) y el ejecutable antiguo, ejecuta:
```bash
make clean
```

### 2. Ejecución
Para iniciar el programa, ejecuta el siguiente comando en la terminal:
```bash
./main.exe
```

Al ejecutarse, el programa realizará dos acciones automáticas:
1. **Validaciones Obligatorias:** Probará ambos algoritmos contra casos de borde (números de 1 dígito, ceros intercalados, longitudes impares, ceros a la izquierda y productos de 250 dígitos) e imprimirá por consola si pasaron o fallaron.
2. **Benchmark Oficial:** Medirá y comparará los tiempos de ejecución de ambos algoritmos para tamaños desde 2 hasta 4096 dígitos, mostrará el resumen en la consola y guardará los resultados detallados en el archivo `tiempos.csv`.
