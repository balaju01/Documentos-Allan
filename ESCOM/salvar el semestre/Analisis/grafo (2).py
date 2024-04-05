from Grafos.nodo import *
from collections import deque

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
        
    
    
    
    
    
        
        