import csv

class Carro:
    def __init__(self, placa, modelo, cor, ano):
        self.placa = placa
        self.modelo = modelo
        self.cor = cor
        self.ano = ano

    def get(self):
        return '{} {} {} {}'.format(self.placa, self.modelo, self.cor, self.ano)

def ordena(carros):
    tam = len(carros)
    for i in range(tam):
        for j in range(i+1,tam):
            if carros[j].ano > carros[i].ano:
                carros[i], carros[j] = carros[j], carros[i]

arq = open('carros.csv', 'r' )
reader = csv.reader(arq)
carros = []

for i in reader:
    carros.append(Carro(i[0], i[1], i[2], int(i[3])))

ordena(carros)
for i in carros:
    print(i.get())
