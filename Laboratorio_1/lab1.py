import matplotlib.pyplot as plt

# Lees las distancias desde el archivo
distances = []
with open('distancias.txt', 'r') as file:
    for line in file:
        distance = float(line.strip())
        distances.append(distance)

# Generar el histograma
plt.hist(distances, bins=20, edgecolor='black')
plt.xlabel('Distancia Euclidiana')
plt.ylabel('Frecuencia')
plt.title('Histograma de Distancias Euclidianas con dimension 5000')
plt.show()
