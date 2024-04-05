#!/usr/bin/python
import Tkinter
import Image, ImageTk
imagenAnchuraMaxima=300
imagenAlturaMaxima=200
from Crypto.Hash import SHA256
from Crypto.Cipher import AES
import random
hash = SHA256.new()
# -*- coding: utf-8 -*-

def funcion():

	a=e.get()
	print(a)
	hash.update(a)
	otra=hash.digest()
	llave = ""
	print otra
	for i  in range(16):
	
		llave=llave+otra[i]
		print str(i)+" "+otra[i]+" "+llave
	
	print "\n"
	print llave
	archi=open('cifrado.txt','r')
	arc=open('descifrado.txt','w')
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
	
		ciphertext = obj.decrypt(aux)
		arc.write(ciphertext)
		print str(c) +"   " + lineas + "   "+str(len(lineas))+"   "+str(len(aux))+"   "+ciphertext
	

	archi.close()
	arc.close()
	root.quit()



# abrimos una imagen
img = Image.open('out.png')

img.thumbnail((imagenAnchuraMaxima,imagenAlturaMaxima), Image.ANTIALIAS)
root = Tkinter.Tk()
# titulo de la ventana
root.title("Mostrar imagen")
# Convertimos la imagen a un objeto PhotoImage de Tkinter
tkimage = ImageTk.PhotoImage(img)
# Ponemos la imagen en un Lable dentro de la ventana
label=Tkinter.Label(root, image=tkimage, width=imagenAnchuraMaxima, height=imagenAlturaMaxima).pack()
valor = ""
e = Tkinter.Entry(root)
e.pack()

buttonStart2=Tkinter.Button(root, text="Cerrar",command=funcion).pack()
# Mostramos la ventana

root.mainloop()


