import math

def factorial(n):
    """Calcula el factorial de un número."""
    return math.factorial(n)

def generar_numero(d, n):
    """Genera el número repitiendo el dígito d n! veces."""
    repeticiones = factorial(n)
    return int(str(d) * repeticiones)

def verificar_divisibilidad(numero):
    """Verifica si el número es divisible entre 1, 3, 5, 7 o 9."""
    divisores = [1, 3, 5, 7, 9]
    resultados = {divisor: (numero % divisor == 0) for divisor in divisores}
    return resultados

def main():
    try:
        # Solicitar al usuario los valores de d y n
        d = int(input("Ingresa el dígito (0-9): "))
        if d < 0 or d > 9:
            print("Por favor, ingresa un dígito válido entre 0 y 9.")
            return

        n = int(input("Ingresa el número n para calcular n!: "))
        if n < 0:
            print("Por favor, ingresa un número entero no negativo.")
            return

        # Generar el número y verificar divisibilidad
        numero_generado = generar_numero(d, n)
        print(f"El número generado es: {numero_generado}")

        divisibilidad = verificar_divisibilidad(numero_generado)
        for divisor, es_divisible in divisibilidad.items():
            print(f"¿Es divisible entre {divisor}? {'Sí' if es_divisible else 'No'}")

    except ValueError:
        print("Entrada inválida. Por favor, ingresa números enteros.")

if __name__ == "__main__":
    main()
