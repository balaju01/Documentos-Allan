from nodo import *
from grafo import *
g = Grafo("Mi grafo 1")
archivo=open("educacion_fundamental.txt","r")
arch=open("platillos_voladores.txt","r")
lo=arch.read()
li=archivo.read()
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
	print(n)
	for j in range(c):
		if n!=final[j]:
			m=final[j]
			if len(n)>len(m):
				comp=comp+1
				for k in range(len(m)):
					if n[k]!=m[k]:
						comp=comp+1
						#print("si 1")
					#else:
					#	print("igual")
			else:
				if len(m)>len(n):
					comp=comp+1
				for k in range(len(n)):
					if n[k]!=m[k]:
						comp=comp+1
						#print("si 2")
					#else:
						#print("igual")
		if comp==1:
			no.agregarVecino(m,1)
			print(m)
		comp=0
	print(no.vecinos)
	print("\n")
print(c)