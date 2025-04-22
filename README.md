# Demo Aplicación MPU6050 + Matriz LED

Este proyecto implementa una aplicación embebida demostrativa que integra dos drivers desarrollados para los módulos **MPU6050** (sensor inercial) y **MAX7219** (matriz LED), con el objetivo de visualizar información inercial en tiempo real a través de una interfaz gráfica sencilla.

Esta aplicación fue diseñada como parte del **Trabajo Final Integrador** del posgrado en *Sistemas Embebidos*, en el marco de la materia **Protocolos de Comunicación en Sistemas Embebidos**.

---

## 🚀 Funcionalidad general

El sistema permite visualizar el estado de inclinación del dispositivo de forma gráfica en una matriz 8x8 controlada por SPI. Además, cuenta con distintos **modos de operación** que se pueden cambiar mediante un botón físico:

### 🧠 Modos disponibles

1. **Visualización por bloques (2x2)**
2. **Cambio de sensibilidad** mediante niveles: ±1g, ±0.5g, ±0.15g, ±0.05g
3. **Brillo proporcional a inclinación**
4. **Animación personalizada** (emoji o efecto)

---

## 🧱 Estructura del código

```
/Core
├─  src/
│     └──  main_app.c  ...     # Lógica de la aplicación (setup, run y modos)
└── inc/
     └──  main_app.h   ...    # API pública
```

La aplicación utiliza una arquitectura no bloqueante basada en `delay_t`, y gestiona el cambio de modos mediante una FSM simple con detección de flanco de botón.

---

## ⚙️ Requisitos y dependencias

- Microcontrolador STM32 (ej: NUCLEO-F446RE)
- Biblioteca HAL configurada con:
  - I2C (para MPU6050)
  - SPI (para MAX7219)
  - UART (opcional para logs)
- Drivers disponibles por separado:
  - [Driver MPU6050](https://github.com/AlejoGm/PCSE-Drivers/tree/main/mpu6050)
  - [Driver LED Matrix MAX7219](https://github.com/AlejoGm/PCSE-Drivers/tree/main/LedMatrix)

---

## 👨‍💻 Autor

**Alejo S. García Mata**  

Proyecto desarrollado para el Posgrado en Sistemas Embebidos – 2025.