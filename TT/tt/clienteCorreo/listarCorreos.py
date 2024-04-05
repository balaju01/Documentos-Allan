import json
import os
import email
import quopri

from os import path

def listFiles(folder):
	return [d for d in os.listdir(folder) if path.isfile(path.join(folder, d))]

def listaCorreos(ruta):
	print("listaCorreos")
	archivos = listFiles(ruta)
	disc={}
	for archivo in archivos:
		if archivo.find(".txt")>0:
			fp = open(path.join(ruta,archivo), 'r')
			ms = email.message_from_file(fp)
			fp.close()
			if len(ms.get_payload())>1:
				disc[archivo]=(ms['Subject'],ms['From'],ms['Date'],"mail-attachment")
			else:
				disc[archivo]=(ms['Subject'],ms['From'],ms['Date'],"")
	lista=open(path.join(ruta,"lista.json"),"w")	
	lista.write(json.dumps(disc))
	lista.close
	print("Fin listaCorreos")

def listaCorreosView(ruta):
	print("listaCorreosView")
	disc={}
	jsonCorreo = open(os.path.join(ruta,"lista.json"),"r")
	if jsonCorreo:
		jsonLectura = jsonCorreo.readline()
		jsonCorreo.close()
		dic = json.loads(jsonLectura)
		return dic
	else:
		return None
	print("Fin listaCorreosView")

def contarCorreo(directorio):
	print("contarCorreo")
	if directorio==None:
		return -1
	for files in os.walk(directorio):
		num=0
		for file in files[2]:
			if file.find(".txt")>0:
				num+=1
	print("Fin contarCorreo")
	return num

def body(ms):
	print("body")
	charset = ms.get_content_charset()
	if ms.is_multipart():
		for payload in ms.get_payload():
			ctype=payload.get_content_type()
			cdispo = str(payload.get('Content-Disposition'))
			if payload.is_multipart():
				return body(payload)
				break
			elif ctype=='text/plain' and 'attachment' not in cdispo:
				charset = payload.get_content_charset()
				aux = payload.get_payload(decode=True)
				print("Fin body")
				return aux.decode(charset)
	else:
		aux = ms.get_payload(decode=True)
		print("Fin body")
		return aux.decode(charset)
#listaCorreos("./Usuarios/jonny.test.arc.99@hotmail.com/Entrada/")
#print(listaCorreosView("./Usuarios/jonny.test.arc.99@hotmail.com/Entrada/"))
#print(contarCorreo("./Usuarios/jonny.test.arc.99@hotmail.com/Enviados/"))