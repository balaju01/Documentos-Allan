#! /usr/bin/env python
import math
from partes import *
dat=open('dat.txt','r')
dato=dat.read(1000)
dato=dato.replace(',',' ')
m=dato.split()
r=0
ax=[]
orden=[]
dib1=[]
dib2=[]
print(m)
for n in range((len(m))/2):
	print(m[n]+','+m[(len(m)/2)+n])
	r=part(m[n]+','+m[(len(m)/2)+n])
	ax.append(float(m[n]))
	ax.append(float(m[(len(m)/2)+n]))
	r.v=ax
	dib1.append(m[n]+','+m[(len(m)/2)+n])
	dib2.append(r)
	ax=[]
print(dib1)

for n in dib2:
	print(n.nombre)
print(r.v)
print('\n')
m=dib1
dib1=[]
#dib2=[]
print(m)
for n in range((len(m))/2):
	print(m[n]+','+m[(len(m)/2)+n])
	r=part(m[n]+','+m[(len(m)/2)+n])
	dib1.append(m[n]+','+m[(len(m)/2)+n])
	dib2.append(r)
print(dib1)
for n in dib2:
	print(n.nombre)

#0,1,2,3,4,5,6,7

#0,4,1,5,2,6,3,7

#0,4,2,6,1,5,3,7
