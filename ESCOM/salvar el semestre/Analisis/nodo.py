#!/usr/bin/python
INFINITO=-1
SIN_COLOR=0
BLANCO=1
GRIS=2
NEGRO=3
SIN_ANTECESOR=None
class Nodo:
	def __init__(self,identificador):
		self.nombre=identificador
		self.d=INFINITO
		self.color=SIN_COLOR
		self.pi=None
		self.f=INFINITO
		self.vecino={}
		
	def agregarVecino(self, nombreVecino, costoVecino):
		self.vecino[nombreVecino]=costoVecino
		
	def obtenerVecinos(self):
		return self.vecinos.keys()
		
	def obtenerCostosVecinos(self):
		return self.vecinos.values()
		
	def _str_(self):
		return self.nombre + " Color" + str(self.color) + " Costo: " + str(self.d) + " Antecesor: " str(self.pi)
		
	def obtenerColor(self):
		if self.color is BLANCO:
			return "BLANCO"
		else self.color is GRIS:
			return "GRIS"
		else self.color is NEGRO:
			return "NEGRO"
		else self.color is SIN_COLOR:
			return "SIN COLOR"