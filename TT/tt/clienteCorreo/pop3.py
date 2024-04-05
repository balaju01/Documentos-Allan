import os
import poplib
import string
import StringIO
import email
import hashlib
import listarCorreos
import threading
from listarCorreos import listaCorreos
# For guessing MIME type based on file name extension
from email import encoders
from email.message import Message
from email.mime.audio import MIMEAudio
from email.mime.base import MIMEBase
from email.mime.image import MIMEImage
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

#path="/home/jonnytest/Documentos/Usuarios/"
class conexionPop3(threading.Thread):

	def __init__(self, host, port, keyfile, certfile, user, passwd, ssl, delete, path):
		threading.Thread.__init__(self)
		self.host = host
		self.port = port
		self.keyfile = keyfile
		self.certfile = certfile
		self.user = user
		self.passwd = passwd
		self.ssl = ssl
		self.delete = delete
		self.path = path
		
	def run(self):
		print("abriendo conexion")
		try:
			if self.ssl:
				M = poplib.POP3_SSL(host=self.host, port=self.port, keyfile=self.keyfile, certfile=self.certfile)
			else:
				M = poplib.POP3(host=self.host, port=self.port)
			#M.set_debuglevel(2)
		except poplib.error_proto, e:
			print(e)
			print("Error de conexion")
			return 0;
		success = False
		print("Validando usuario")
		while success == False:
			lista={}
			try:
				M.user(self.user)
				M.pass_(self.passwd)
				numMesanjes = len(M.list()[1])
				for id in range(1,(numMesanjes+1)):
					resp, text, octets = M.retr(id)
					text = string.join(text, "\n")
					ms = email.message_from_string(text)
					print(ms["Date"])
					m = hashlib.md5()
					m.update(ms["Date"])
					aux = m.hexdigest()+".txt"
					file=os.path.join(self.path,aux)
					if os.path.exists(file):
						if self.delete:
							m.dele(id)
					else:
						composed = ms.as_string()
						fp = open(file, 'w')
						fp.write(composed)
						fp.close()
						if self.delete:
							m.dele(id)
				listaCorreos(self.path)
			except poplib.error_proto:
				print("Invalid credentials")
			else:
				print("Successful login")
				success = True
			finally:
				if M: 
					M.quit()

#popDescarga(host='pop3.live.com', port=995, keyfile="./Seguridad/server2048.key", certfile="./Seguridad/server2048.pem",user="jonny.test.arc.99@hotmail.com",passwd="360_live",ssl=True,delete=False)