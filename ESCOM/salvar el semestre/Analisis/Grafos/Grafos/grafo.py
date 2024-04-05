from nodo import *
from collections import deque
import os

class Grafo:
    
	def __init__(self, nombre):  
		self.nombre = nombre
		self.numeroNodos = 0
		self.nodos = {}
        
        
	def agregarNodo(self, nombreNodo):
		n  = Nodo(nombreNodo)
		self.nodos[nombreNodo] = n
		self.numeroNodos = self.numeroNodos + 1
        
	def __str__(self):
		return self.nombre + " NUMERO NODOS: "+ str(self.numeroNodos)
        
	def obtenerNodos(self):
		return self.nodos
    
	def obtenerNombresNodos(self):
		return self.nodos.keys()
    
	def obtenerNodo(self, nombreNodo):
		return self.nodos[nombreNodo]
    
    
	def busquedaProfundidad(self, nombreNodoOrigen):
		for nn in self.obtenerNombresNodos():
			n = self.obtenerNodo(nn)
			n.color = BLANCO
			n.pi = None
		self.tiempo = 0
        
		nodoOrigen = self.obtenerNodo(nombreNodoOrigen)
		self.bp_visita(nodoOrigen)
    
	def bp_visita(self, u):
    
		u.color = GRIS
		self.tiempo += 1
		u.d = self.tiempo
        
		for nv in u.obtenerVecinos():
			v = self.obtenerNodo(nv)
			if v.color is BLANCO:
				v.pi = u.nombre
				self.bp_visita(v)
        
		u.color = NEGRO
		self.tiempo += 1
		u.f = self.tiempo
    
    
	def busquedaAmplitud(self, nombreNodoOrigen):
        
		for nn in self.obtenerNombresNodos():
			if nn is not nombreNodoOrigen:
				n = self.obtenerNodo(nn)
				n.color = BLANCO
				n.d = INFINITO
				n.pi = None
                
		s = self.obtenerNodo(nombreNodoOrigen)
		s.color = GRIS
		s.d = 0
		s.pi = SIN_ANTECESOR
        
		Q = deque()
        
		Q.append(s)
        
		while len(Q) is not 0:
			z = Q.popleft()
            
			for nv in z.obtenerVecinos():
				v = self.obtenerNodo(nv)
				if v.color is BLANCO:
					v.color = GRIS
					v.d = z.d + 1
					v.pi = z.nombre
					Q.append(v)
            
			z.color = NEGRO
            
	def imprimirNodos(self):
		for n in self.nodos.values():
			print(n)
            
             
	def ruta(self, nombreNodoDestino, lista):    
			
		if lista is None:
			lista = deque()
			
		lista.appendleft(nombreNodoDestino)
	
		nd = self.obtenerNodo(nombreNodoDestino)
			
		if nd.pi is not None:
			return self.ruta(nd.pi, lista)
				
		return lista
			
			
	def evaluar(self,nodo,Origen,Destino,antecesor):
		heu=0
		#nodo.pi=antecesor
		self.busquedaAmplitud(Origen)
		heu=nodo.d
		self.busquedaAmplitud(nodo.nombre)
		n=self.obtenerNodo(Destino)
		heu=heu+n.d
		if heu<nodo.heuristica:
			nodo.heuristica=heu
			nodo.pi1=antecesor

	def evaluarr(self,nodo,Origen,Destino,antecesor):
		heu=0
		self.busquedaAmplitud(nodo.nombre)
		n=self.obtenerNodo(Destino)
		heu=heu+n.d
		if heu<nodo.heuristica:
			nodo.heuristica=heu
			nodo.pi1=antecesor
	
	def aEstrella(self,O,D):
		ref=10000
		c=0
		Qa=deque()
		Qc=deque()
		n=self.obtenerNodo(O)
		n.heuristica=5
		self.evaluar(n,O,D,None)
		Qa.append(n)
		
		for i in range(len(Qa)):
			if Qa[i].nombre==D:
				c=c+1
		
		while len(Qa)>0 and c==0:
			for i in range(len(Qa)):
				if Qa[i].heuristica<ref:
					n=Qa[i]
					ref=Qa[i].heuristica
			#os.system("pause")
			
			for i in n.obtenerVecinos():
				v=self.obtenerNodo(i)
				self.evaluar(v,O,D,n.nombre)
				for j in range(len(Qc)):
					if Qc[j].nombre==v.nombre:
						c=c+1
				if c==0:
					Qa.append(v)
				c=0
			
			
			for i in range(len(Qa)):
				if Qa[i].nombre==D:
					c=c+1
			#os.system("pause")
			Qc.append(n)
			Qa.remove(n)
			#print(Qa)
			ref=10000
		for i in self.obtenerNombresNodos():
			n=self.obtenerNodo(i)
			n.pi=n.pi1
			
	def primMejor(self,O,D):
		ref=10000
		c=0
		Qa=deque()
		Qc=deque()
		n=self.obtenerNodo(O)
		n.heuristica=5
		self.evaluarr(n,O,D,None)
		Qa.append(n)
		
		for i in range(len(Qa)):
			if Qa[i].nombre==D:
				c=c+1
		
		while len(Qa)>0 and c==0:
			for i in range(len(Qa)):
				if Qa[i].heuristica<ref:
					n=Qa[i]
					ref=Qa[i].heuristica
			#os.system("pause")
			
			for i in n.obtenerVecinos():
				v=self.obtenerNodo(i)
				self.evaluarr(v,O,D,n.nombre)
				for j in range(len(Qc)):
					if Qc[j].nombre==v.nombre:
						c=c+1
				if c==0:
					Qa.append(v)
				c=0
			
			
			for i in range(len(Qa)):
				if Qa[i].nombre==D:
					c=c+1
			#os.system("pause")
			Qc.append(n)
			Qa.remove(n)
			#print(Qa)
			ref=10000
		for i in self.obtenerNombresNodos():
			n=self.obtenerNodo(i)
			n.pi=n.pi1