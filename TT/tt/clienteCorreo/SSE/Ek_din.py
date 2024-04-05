from Crypto.Hash import SHA256
import os
import random
import base64
from random import randrange
from map import mapeoBtoI
from map import mapeoItoB
from image import ImageCaptcha
from Crypto.Cipher import AES

def crearSemilla(tam):
	r=0
	semilla=""
	for i in range(tam):
		r=random.randrange(64)
		semilla=semilla+str(mapeoItoB(r))
	return semilla

def crearLlave(semilla1):
	aux=""
	llave=""
	hash = SHA256.new()
	hash.update(semilla1)
	aux=hash.digest()
	llave = ""
	for i  in range(16):
		llave=llave+aux[i]
	return llave

def crearCAPTCHA(op,semilla2,asunto):
	imagen=""
	aux=""
	ax=[]
	xa=""
	s=[]
	c=0
	asunto=asunto.replace(" ","_")
	os.mkdir('./'+asunto+"_CAPTCHA",0755)
	image = ImageCaptcha(fonts=['./SSE/fon/A1.ttf', './SSE/fon/A1.ttf'])
	if (op==0):
		aux='./'+asunto+'_CAPTCHA/CAPTCHA00.png'
		image.write(semilla2, aux)
		return './'+asunto+"_CAPTCHA"
	else:
		for x in semilla2:
			#print(x)
			aux='./'+asunto+'_CAPTCHA/CAPTCHA'+str(c)+'.png'
			xa='CAPTCHA'+str(c)+'.png'
			ax.append(xa)
			s.append(ax)
			ax=[]
			image.write(x, aux)
			c=c+1
		return (s,'./'+asunto+"_CAPTCHA")

def encodeSS(strin):
	bina=""
	aux=""
	for i in range(len(strin)):
		aux=bin(mapeoBtoI(strin[i])).replace("0b","")
		if (len(aux)==6):
			bina=bina+aux
		else:
			while ((len(aux))<6):
				aux="0"+aux
			bina=bina+aux
	return int(str(bina),2)

def decodeSS(strr,w0):
	c=0
	s=""
	capt=""
	letras=[]
	z=bin(strr).replace("0b","")
	while (len(z)<(6*w0)):
		z="0"+z
	for i in z:
		if (c==5):
			c=0
			s=s+i
			letras.append(s)
			s=""
		else:
			c=c+1
			s=s+i
	for j in letras:
		capt=capt+mapeoItoB(int(str(j),2))
	return capt

def eucExt(a,b):
    r = [a,b]
    s = [1,0] 
    i = 1
    q = [[]]
    while (r[i] != 0): 
        q = q + [r[i-1] // r[i]]
        r = r + [r[i-1] % r[i]]
        s = s + [s[i-1] - q[i]*s[i]]
        i = i+1
    return s[i-1]%b

def GenerarPares(p=7,w=5,t=2,k=0):
    pares =[]
    a = [k]
    for aux in range(0,w):
        pares.append([randrange(p),0])
    for aux in range(1,t):
        a.append(randrange(p))
    for aux in pares:
        suma = k
        for aux2 in range(1,t):
            suma = (suma+(a[aux2]*(aux[0]**aux2)))%p
        aux[1] =suma
    return pares

def secreto(pares,p):
    suma = 0
    for aux in pares:
        ind = pares.index(aux)
        lis = pares[:ind] + pares[(ind+1):]
        num=1
        den=1
        for aux2 in lis:
            num = (num*(aux2[0])*-1)%p
            den = (den*((aux[0]-aux2[0])%p))%p
        den = eucExt(den,p)
        suma += (den*aux[1]*num)%p
    return suma%p

def cifrar(body,asunto1,op1=1,ta=5,w1=5,t1=2):
	ruta=""
	salida=""
	if t1>w1:
		salida=""
		ruta=None
		print("w1 < t1")
		return (salida,ruta)
	semilla3=crearSemilla(ta)
	num=0
	cap=[]
	zp=2**(6*ta)
	#print(semilla3)
	if (op1==0):
		ruta=crearCAPTCHA(0,semilla3,asunto1)
	else:
		ruta=[]
		num=encodeSS(semilla3)
		pares=GenerarPares(zp,w1,t1,num)
		#print(pares)
		for x in pares:
			cap.append(decodeSS(x[1],w1))
		ruta=crearCAPTCHA(op1,cap,asunto1)
		num=0
		#print(cap)
		for x in pares:
			ruta[0][num].insert(0,x[0])
			num=num+1
	k=crearLlave(semilla3)
	obj = AES.new(k, AES.MODE_ECB)
	salida=""
	ax=0
	c=0
	strr=""
	#print len(body)
	while (ax < len(body)):
		while (c<16):
			if (ax>=len(body)):
				strr=strr+" "
			else:
				strr=strr+body[ax]
			c=c+1
			ax=ax+1
			#print str(c) +" " + str(ax) 
		c=0
		#print strr
		ciphertext = obj.encrypt(strr)
		salida=salida+ciphertext
		strr=""
	salida = base64.b64encode(salida)
	return (salida,ruta)

def descifrar(body1,capt1,op2):
	aux=[]
	ax=0
	pares=[]
	zp=0
	
	if (op2==0):
		k=crearLlave(capt1)
	else:
		w=len(capt1[0][1])
		zp=2**(6*(len(capt1[0][1])))
		for x in capt1:
			aux=x
			aux[1]=encodeSS(x[1])
			pares.append(aux)	
		#print(pares)
		ax=secreto(pares,zp)
		#print(ax)
		semilla4=decodeSS(ax,w)
		#print(semilla4)
		k=crearLlave(semilla4)
		#print(k)
	obj = AES.new(k, AES.MODE_ECB)
	salida=""
	ax=0
	c=0
	strr=""
	#print len(body1)
	body1 = base64.b64decode(body1)
	while (ax < len(body1)):
		while (c<16):
			if (ax>=len(body1)):
				strr=strr+" "
			else:
				strr=strr+body1[ax]
			c=c+1
			ax=ax+1
			#print str(c) +" " + str(ax) 
		c=0
		#print strr
		ciphertext = obj.decrypt(strr)
		salida=salida+ciphertext
		strr=""
	return salida
