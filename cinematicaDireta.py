import numpy as np
from matplotlib import pyplot as plt

def cinematicaDiretaScara(a1, a2, theta1, theta2):
    theta1_rad = np.radians(theta1)
    theta2_rad = np.radians(theta2)

    x = a1 * np.cos(theta1_rad) + a2 * np.cos(theta1_rad + theta2_rad)
    y = a1 * np.sin(theta1_rad) + a2 * np.sin(theta1_rad + theta2_rad)

    return x, y

def plotarScara(a1, a2, theta1, theta2):
    theta1_rad = np.radians(theta1)
    theta2_rad = np.radians(theta2)
    
    x0, y0 = 0,0

    #posição primeira junta
    x1 = a1 * np.cos(theta1_rad)
    y1 = a1 * np.sin(theta1_rad)
    
    #posição segunda junta
    x2, y2 = cinematicaDiretaScara(a1, a2, theta1, theta2)

    #plotando
    plt.figure("scara positions")
    plt.plot([x0,x1], [y0,y1], label="Elo 1")
    plt.plot([x1,x2], [y1,y2], label="Elo 2")
    plt.plot(x2,y2, label="Efetuador")
    plt.grid()
    plt.show()

#exemplo de uso

x,y = cinematicaDiretaScara(0.5, 0.3, 30, 45)
print(f"Posição do efetuador: x = {x:.2f} m, y = {y:.2f} m")
plotarScara(0.5, 0.3, 30, 45)