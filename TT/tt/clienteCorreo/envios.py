import threading
import hashlib
import time
import os
import urllib2
import email
import base64
import SSE
from SSE import empaquetar
#from empaquetar import empaquetar
from subprocess import call

from smtp2 import smtpEnpaquetar, smtpAllMensaje
from listarCorreos import listaCorreos, listaCorreosView

class envios(threading.Thread):
	
	def __init__(self, correoDes, correoOri, asunto, body, attach, config):
		threading.Thread.__init__(self)
		self.correoD = correoDes
		self.correoO = correoOri
		self.asunto = asunto
		self.cuerpo = body
		self.attachment = attach
		self.configuracion=config
	
	def run(self):
		print("envios")
		body,ruta = empaquetar(self.cuerpo,self.asunto,0)
		body += "\n------SSE Cipher------\n"
		body += self.firma()
		body += "\n------SSE Cipher------\n"
		print(body)
		ms=smtpEnpaquetar(self.correoD, self.asunto, self.correoO, body, self.attachment)
		m = hashlib.md5()
		m.update(time.asctime(time.localtime(time.time())))
		aux = m.hexdigest()+".txt"
		path=os.path.join("./Usuarios",self.correoO,"Salida")
		print(ms.as_string())
		print(os.path.join(path,aux))
		fp = open(os.path.join(path,aux), 'w')
		fp.write(ms.as_string())
		fp.close()
		listaCorreos(path)
		self.enviarCorreos(os.path.join("./Usuarios",self.correoO),"Salida")

	def firma(self):
		m = hashlib.md5()
		localtime = time.asctime( time.localtime(time.time()) )
		m.update(self.correoD+localtime+self.correoO)
		return m.hexdigest()

	def enviarCorreos(self,path,carpeta):
		try:
			response=urllib2.urlopen('http://correocifrado.esy.es',timeout=1)
			salida=os.path.join(path,carpeta)
			dic=listaCorreosView(salida)
			correos = []
			for arc in dic.keys():
				fp = open(os.path.join(salida,arc), 'r')
				ms = email.message_from_file(fp)
				fp.close()
				correos.append(ms)
			smtpAllMensaje(correos, self.configuracion["user"], self.configuracion["passwd"], self.configuracion["hostSmtp"], self.configuracion["portSmtp"], False)
			for arc in dic.keys():
				origen = os.path.join(salida,arc)
				destino =os.path.join(path,"Enviados",arc)
				instruc = "mv "+origen+" "+destino
				call(instruc, shell=True)
			listaCorreos(os.path.join(path,"Enviados"))
			listaCorreos(salida)
		except urllib2.URLError as err: 
			print("Sin conexion")
#aux = envios("sdfg", "dsfg","asdfd","dfg",[])
#aux.run()