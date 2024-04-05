#! /usr/bin/env python
import math
datx=open('datx.txt','r')
datox=datx.read(1000)
datox=datox.replace(',',' ')
x=datox.split()

dath=open('dath.txt','r')
datoh=dath.read(1000)
datoh=datoh.replace(',',' ')
h=datoh.split()

y=[]
for b in range((len(x)+len(h))-1):
	y.append(0)
i=0
j=0

for i in range(len(x)):
	for j in range(len(h)):
        	y[i+j]=y[i+j]+int(x[i])*int(h[j])

resu=open('resultados.txt','w')
op=','.join(str(e) for e in y)
print(op)
resu.write(op)
datx.close()
dath.close()
resu.close()
