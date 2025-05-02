import numpy as np

#operações basicas

a = np.array([[1,2], [3,4]])
b = np.array([[5,6], [7,8]])

print(a)
print(b)

c = np.dot(a, b) #multiplicação
print(c)

a_transposta = a.T #transposta
print(a_transposta)

det_a = np.linalg.det(a) #determinante
print(int(det_a))

inv_a = np.linalg.inv(a) #inversa
print(inv_a)

#transformçãoes geometricas 2d
#translação; rotação; escala; espelhamento; shear 


