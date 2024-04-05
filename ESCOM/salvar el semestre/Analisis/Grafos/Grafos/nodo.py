
INFINITO = -1

SIN_COLOR = 0
BLANCO = 1
GRIS = 2
NEGRO = 3

SIN_ANTECESOR = None

class Nodo:

    def __init__(self, identificador):
		self.nombre = identificador
		self.d = INFINITO
		self.color = SIN_COLOR
		self.pi = None
		self.pi1=None
		self.vecinos = {}
		self.f = INFINITO
		self.heuristica=10000
		
        
    def agregarVecino(self, nombreVecino, costoVecino):
        self.vecinos[nombreVecino] = costoVecino
        
    def obtenerVecinos(self):
        return self.vecinos.keys()
    
    def obtenerCostosVecinos(self):
        return self.vecinos.values()
    
    def obtenerColor(self):
        if self.color is BLANCO:
            return "BLANCO"
        elif self.color is GRIS:
            return "GRIS"
        elif self.color is NEGRO:
            return "NEGRO"
        else:
            return "SIN COLOR"
    
    def __str__(self):
        return self.nombre + " Color: "+ self.obtenerColor()+ " Costo: "+str(self.d)+"/"+str(self.f)+" Antecesor: "+str(self.pi)+"/"+str(self.pi1) + " Heuristica: "+str(self.heuristica)
    
    
    