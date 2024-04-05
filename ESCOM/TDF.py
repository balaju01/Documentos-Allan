#! /usr/bin/env python
import math
dat=open('dat.txt','r')
dato=dat.read(1000)
dato=dato.replace(',',' ')
m=dato.split()
rr=[]
p=0.0
o=0.0
r=0
i=0
res=0.0
ax=""
inf=0
sup=0

print(m)
for k in range(len(m)):
	res=0.0
	for n in range(len(m)):
		o=(2.0*math.pi*k)/len(m)
		r=round(math.cos(o*n),2)
		print(math.sin(o*n))
		i=-1j*(round(math.sin(o*n),2))
		p=r+i
		p=p*float(m[n])
		res=res+p
		print("k:"+repr(k)+" n:"+repr(n)+" o:"+repr(o)+" m:"+repr(m[n])+" p:"+repr(p)+" res:"+repr(res))
	print("\n")
	rr.append(res/len(m))
print("\n")
#print(rr)
resu=open('resultados.txt','w')
op=','.join(str(e) for e in rr)
print(op)
resu.write(op)
dat.close()
resu.close()



