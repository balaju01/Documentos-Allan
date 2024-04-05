from nodo import *
from grafo import *


g = Grafo("Mi grafo 1")
print(g)
"""
g.agregarNodo("r")
g.agregarNodo("s")
g.agregarNodo("t")
g.agregarNodo("u")
g.agregarNodo("v")
g.agregarNodo("w")
g.agregarNodo("x")
g.agregarNodo("y")
g.agregarNodo("a")

print(g)

print(g.obtenerNombresNodos())

r = g.obtenerNodo("r")
r.agregarVecino("s", 1)
r.agregarVecino("v", 1)

s = g.obtenerNodo("s")
s.agregarVecino("r", 1)
s.agregarVecino("w", 1)

t = g.obtenerNodo("t")
t.agregarVecino("u", 1)
t.agregarVecino("w", 1)
t.agregarVecino("x", 1)

u = g.obtenerNodo("u")
u.agregarVecino("t", 1)
u.agregarVecino("x", 1)
u.agregarVecino("y", 1)

v = g.obtenerNodo("v")
v.agregarVecino("r", 1)

w = g.obtenerNodo("w")
w.agregarVecino("s", 1)
w.agregarVecino("t", 1)
w.agregarVecino("x", 1)

x = g.obtenerNodo("x")
x.agregarVecino("t", 1)
x.agregarVecino("u", 1)
x.agregarVecino("w", 1)
x.agregarVecino("y", 1)

y = g.obtenerNodo("y")
y.agregarVecino("u", 1)
y.agregarVecino("x", 1)


print(r.obtenerVecinos())
print(s.obtenerVecinos())
print(t.obtenerVecinos())
print(u.obtenerVecinos())
print(v.obtenerVecinos())
print(w.obtenerVecinos())
print(x.obtenerVecinos())
print(y.obtenerVecinos())
"""

archivo=open("educacion_fundamental.txt","r")
arch=open("platillos_voladores.txt","r")
#archi=open("psicologia_revolucionaria.txt","r")
lo=arch.read()
li=archivo.read()
#la=archi.read()
li=li+lo
li=li.replace("\n"," ")
li=li.replace("\t"," ")
li=li.replace("\f"," ")
li=li.replace("\r"," ")
li=li.replace("."," ")
li=li.replace(","," ")
li=li.replace("-"," ")
li=li.replace("<"," ")
li=li.replace(">"," ")
li=li.replace(";"," ")
li=li.replace(":"," ")
li=li.replace("_"," ")
li=li.replace("{"," ")
li=li.replace("}"," ")
li=li.replace("["," ")
li=li.replace("]"," ")
li=li.replace("^"," ")
li=li.replace("+"," ")
li=li.replace("*"," ")
li=li.replace("~"," ")
li=li.replace("\'"," ")
li=li.replace("?"," ")
li=li.replace("\\"," ")
li=li.replace("0"," ")
li=li.replace("="," ")
li=li.replace("9"," ")
li=li.replace(")"," ")
li=li.replace("8"," ")
li=li.replace("("," ")
li=li.replace("/"," ")
li=li.replace("7"," ")
li=li.replace("6"," ")
li=li.replace("&"," ")
li=li.replace("5"," ")
li=li.replace("%"," ")
li=li.replace("4"," ")
li=li.replace("$"," ")
li=li.replace("3"," ")
li=li.replace("#"," ")
li=li.replace("2"," ")
li=li.replace("\""," ")
li=li.replace("1"," ")
li=li.replace("!"," ")
li=li.replace("|"," ")

li=li.lower()
final=[]
te_pro=li.split(' ')
te_pro=list(set(te_pro))
comp=0
for i in range(len(te_pro)):
	if len(te_pro[i])==4 or len(te_pro[i])==5:
		final.append(te_pro[i])
c=int(len(final))
for i in range(c):
	n=final[i]
	g.agregarNodo(n)
	no=g.obtenerNodo(n)
	#print(n)
	for j in range(c):
		if n!=final[j]:
			m=final[j]
			if len(n)>len(m):
				comp=comp+1
				for k in range(len(m)):
					if n[k]!=m[k]:
						comp=comp+1
						
			else:
				if len(m)>len(n):
					comp=comp+1
				for k in range(len(n)):
					if n[k]!=m[k]:
						comp=comp+1
						
		if comp==1:
			no.agregarVecino(m,1)
			#print(m)
		comp=0
	#print(no.vecinos)
	#print("\n")



g.imprimirNodos()

en=raw_input("introduce el nodo origen: ")
sa=raw_input("introduce el nodo destino: ")

g.busquedaAmplitud(en)

g.imprimirNodos()

ruta = g.ruta(sa, None)

print(ruta)

#print(c)
"""
g2 = Grafo("Mi grafo 2-> Busqueda en profundidad")

g2.agregarNodo("u")
g2.agregarNodo("v")
g2.agregarNodo("w")
g2.agregarNodo("x")
g2.agregarNodo("y")
g2.agregarNodo("z")

u = g2.obtenerNodo("u")
u.agregarVecino("v", 1)
u.agregarVecino("x", 1)

v = g2.obtenerNodo("v")
v.agregarVecino("y", 1)

w = g2.obtenerNodo("w")
w.agregarVecino("y", 1)
w.agregarVecino("z", 1)

x = g2.obtenerNodo("x")
x.agregarVecino("v", 1)

y = g2.obtenerNodo("y")
y.agregarVecino("x", 1)
"""
g.busquedaProfundidad(en)

print(g)

g.imprimirNodos()

ruta3 = g.ruta(sa, None)




print("\n")
print("Anchura")
print(ruta)
print("\n")
print("Profundidad")
print(ruta3)
print("\n")
print("A*")
g.aEstrella(en,sa)
ruta2=g.ruta(sa,None)
print(ruta2)
print("\n")
print("Primero Mejor")
g.primMejor(en,sa)
ruta3=g.ruta(sa,None)
print(ruta3)
#print(c)

















