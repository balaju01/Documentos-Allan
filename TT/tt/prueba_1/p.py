#! /usr/bin/env python
from Crypto.Hash import SHA256
from Crypto.Cipher import AES
from captcha.image import ImageCaptcha
import os
import random
hash = SHA256.new()
semilla=""
r=0
image = ImageCaptcha(fonts=['./fon/A.ttf', './fon/B.ttf'])
for i in range(5):
	r=random.randrange(100)
	semilla=semilla+chr(r)
	print str(i)+" "+str(r)+" "+chr(r)+" "+semilla
	
print semilla+"\n"

data = image.generate(semilla)
image.write(semilla, '/tmp/out.png')
image.write(semilla, 'out.png')

os.remove("/tmp/out.png")

hash.update(semilla)
otra=hash.digest()
llave = ""
print otra


for i  in range(16):
	
	llave=llave+otra[i]
	print str(i)+" "+otra[i]+" "+llave
	
print "\n"
print llave
archy=open('llave.txt','w')
archy.write(semilla)
archy.close()
arc=open('cifrado.txt','w')
archi=open('1443750804.V805Idc01e2M920300.jonnytest:2,S','r')
obj = AES.new(llave, AES.MODE_ECB)
lineas=' '
c=0
while lineas!="": 
	c=c+1
	lineas=archi.read(16)
	
	if (((len(lineas))<16)and((len(lineas))>0)):
		c=16-(len(lineas))
		aux=lineas
		for i in range(c):
			aux=aux+" "
	else:
		aux=lineas
	
	ciphertext = obj.encrypt(aux)
	arc.write(ciphertext)
	print str(c) +"   " + lineas + "   "+str(len(lineas))+"   "+str(len(aux))+"   "+ciphertext
	

archi.close()
arc.close()


