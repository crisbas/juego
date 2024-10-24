#Documentación del Juego de Dados

## Descripción General
Este proyecto implementa un juego de mesa basado en dados donde los jugadores compiten por conquistar columnas en un tablero. El juego está implementado en C++ y utiliza una arquitectura orientada a objetos.

## Estructura del Proyecto

### Diagrama de Clases Principal

## Clases Principales

### 1. Clase Celda
Representa una celda individual en el tablero visual.

#### Atributos
- c_[4]: Array de caracteres que representa el contenido de la celda

#### Métodos Principales
- mostrar(): Muestra el contenido de la celda con formato
- actualizar(char simbolo): Actualiza el símbolo en la celda
- getSimbolo(): Obtiene el símbolo actual de la celda

### 2. Clase TableroVisual
Maneja la representación visual del tablero de juego.

#### Atributos
- guia[11]: Array que define el ancho de cada columna
- rotulo[11]: Array con las etiquetas de las columnas
- ptr: Matriz dinámica de celdas

#### Métodos Principales
- mostrar(): Renderiza el tablero completo
- actualizarTablero(int columna, int posicion, char simbolo): Actualiza una posición específica
- limpiarPosicion(int columna, int posicion): Limpia una posición específica
- getAlturaColumna(int columna): Obtiene la altura máxima de una columna
- getSimbolo(int columna, int posicion): Obtiene el símbolo en una posición específica

### 3. Clase Dado
Implementa la funcionalidad de los dados.

#### Métodos
- tirar(): Genera un número aleatorio entre 1 y 6

### 4. Clase Marcador
Representa un marcador en el juego.

#### Atributos
- columna: Columna donde está el marcador
- posicion: Posición actual en la columna
- activo: Estado de activación del marcador
- permanente: Indica si el marcador es permanente

### 5. Clase Jugador
Gestiona la información y acciones de cada jugador.

#### Atributos
- nombre: Nombre del jugador
- columnasGanadas: Vector de columnas conquistadas
- simbolo: Símbolo que representa al jugador
- marcadores: Vector de marcadores activos
- marcadoresPermanentes: Vector de marcadores permanentes

#### Métodos Principales
- ganarColumna(int columna): Registra una columna ganada
- tieneColumna(int columna): Verifica si el jugador tiene una columna
- columnasGanadasTotal(): Cuenta el total de columnas ganadas
- perderColumna(int columna): Elimina una columna ganada

### 6. Clase Tablero
Gestiona la lógica del tablero de juego.

#### Atributos
- columnas: Mapa que registra el estado de cada columna
- visualTablero: Instancia de TableroVisual
- marcadoresTemporales: Mapa de marcadores temporales

#### Métodos Principales
- puedeMoverse(): Verifica si son posibles movimientos
- moverMarcador(): Ejecuta el movimiento de un marcador
- limpiarMarcadoresTemporales(): Elimina marcadores temporales
- hacerMarcadoresPermanentes(): Convierte marcadores temporales en permanentes
- columnaCompleta(): Verifica si una columna está llena

### 7. Clase Juego
Clase principal que controla el flujo del juego.

#### Atributos
- jugadores: Vector de jugadores
- tablero: Instancia del tablero
- jugadorActual: Índice del jugador actual
- marcadoresActivos: Vector de marcadores activos

#### Métodos Principales
- turno(): Gestiona el turno de un jugador
- jugar(): Ejecuta el bucle principal del juego

## Flujo del Juego

1. *Inicialización*
   - Se crea el juego con el número de jugadores (1-3)
   - Cada jugador ingresa su nombre
   - Se asignan símbolos únicos (A, B, C)

2. *Turno de Jugador*
   - El jugador tira 4 dados
   - Elige una combinación de sumas
   - Puede mover marcadores existentes o crear nuevos
   - Decide continuar o finalizar su turno

3. *Condiciones de Victoria*
   - Un jugador gana al conquistar 3 columnas
   - Las columnas se conquistan al llenarlas completamente
   - Se pueden robar columnas de otros jugadores

## Consideraciones Técnicas

### Gestión de Memoria
- Se utiliza memoria dinámica para el tablero
- Implementación de destructor en TableroVisual
- Uso de contenedores STL para gestión automática de memoria

### Interfaz de Usuario
- Uso de códigos ANSI para colorear la salida
- Interfaz basada en consola
- Validación de entrada del usuario

### Características Especiales
- Sistema de marcadores temporales y permanentes
- Mecanismo de robo de columnas
- Múltiples opciones de combinación de dados

## Ejemplos de Uso

### Iniciar el Juego
cpp
Juego juego(3);  // Crear juego con 3 jugadores
juego.jugar();   // Iniciar el juego


### Tirar los Dados
cpp
int resultado = Dado::tirar();  // Obtener un número entre 1 y 6


### Mover un Marcador
cpp
Marcador marcador(7);  // Crear marcador en columna 7
tablero.moverMarcador(marcador, 'A', 1);  // Mover una posición


## Limitaciones y Posibles Mejoras

1. *Limitaciones Actuales*
   - Máximo 3 jugadores
   - Interfaz basada en consola
   - No hay persistencia de datos

2. *Mejoras Potenciales*
   - Implementar interfaz gráfica
   - Añadir sistema de guardado
   - Incluir más jugadores
   - Añadir variantes de reglas
   - Implementar sistema de ranking
