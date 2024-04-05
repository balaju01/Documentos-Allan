#! /usr/bin/env python
from Crypto.Hash import SHA256
from Crypto.Cipher import AES
import random
hash = SHA256.new()

llav=open('llave.txt','r')
sem=llav.read(5)

print sem

hash.update(sem)
otra=hash.digest()
llave = ""

for i  in range(16):
	
	llave=llave+otra[i]
	print str(i)+" "+otra[i]+" "+llave
	
print "\n"
print llave
obj = AES.new(llave, AES.MODE_ECB)
arc=open('cifrado.txt','r')
arch=open('si.txt','w')
lineas=' '
while lineas!="": 
	lineas=arc.read(16)
	
	if (((len(lineas))<16)and((len(lineas))>0)):
		c=16-(len(lineas))
		aux=lineas
		for i in range(c):
			aux=aux+" "
	else:
		aux=lineas
	
	deciphertext = obj.decrypt(lineas)
	arch.write(deciphertext)
	print lineas + "   "+str(len(lineas))+"   "+str(len(aux))+"   "+deciphertext
	

