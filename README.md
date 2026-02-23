# arduino-rfid-system
# RFID Access / Identification System (Arduino)

Proyecto académico en Arduino para lectura e identificación mediante tecnología **RFID**.

El sistema detecta tarjetas o tags RFID, lee su identificador y ejecuta una acción asociada (En nustro caso se emplearon para posicionamiento).

---

## Qué hace el proyecto

- Inicializa el módulo RFID
- Detecta tarjetas/tags cercanos
- Lee el UID (identificador) del tag
- Compara el UID con valores permitidos (según la lógica implementada)
- Ejecuta una acción o muestra el resultado por serie / pantalla / actuador

---

## Objetivo del proyecto

Este proyecto está orientado a practicar:

- Comunicación con periféricos en Arduino
- Lectura de tags RFID
- Validación de identificadores
- Diseño de sistemas simples de control de acceso
- Integración hardware-software

---

## Componentes usados

- Arduino
- Módulo RFID
- Tags / tarjetas RFID

---

## Conceptos trabajados

- Identificación por radiofrecuencia (RFID)
- Lectura de UID
- Lógica de validación
- Programación embebida en Arduino/C++

---

## Archivo principal

- `RFID.ino`

---

## Cómo ejecutar

1. Abrir `RFID.ino` en el **Arduino IDE**
2. Instalar la librería del módulo RFID
3. Conectar el módulo RFID a la placa (SPI)
4. Seleccionar placa y puerto
5. Subir el programa
6. Acercar un tag/tarjeta RFID y observar la salida

---





## Autor

Proyecto realizado por **Marcos** como práctica universitaria.
