import os
from os import path

def listFiles(folder):
	return [d for d in os.listdir(folder) if path.isfile(path.join(folder, d))]

def buscarCAPTCHAS(firma, correoDes, correoOri):
	ruta=path.join("./CAPTCHAS",firma)
	if path.exists(ruta):
		if path.exists(path.join(ruta,"lista.json")):
			pass
		else:
			archivos = listFiles(ruta)
			print("NumArchivos: "+str(len(archivos)))
			print(archivos)