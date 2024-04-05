import os
import smtplib
import mimetypes
import hashlib
import time
import email
# For guessing MIME type based on file name extension
from email import encoders
from email.message import Message
from email.mime.audio import MIMEAudio
from email.mime.base import MIMEBase
from email.mime.image import MIMEImage
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

def smtpOneMensaje(to, subject, fromUser, text, attach, passwd, server, port, op, ssl):
	outer = MIMEMultipart()
	if to == None:
		return 0
	elif fromUser == None:
		return 1
	elif (subject == None) and (text == None):
		return 2
	elif passwd == None:
		return 3
	elif server == None:
		return 4
	elif port == None:
		return 5

	outer['From'] = fromUser
	outer['To'] = to
	outer['Subject'] = subject
	outer['Date'] = time.asctime(time.localtime(time.time()))


	outer.attach(MIMEText(text))
	for path in attach:
		if not os.path.isfile(path):
			continue
		# Guess the content type based on the file's extension.  Encoding
		# will be ignored, although we should check for simple things like
		# gzip'd or compressed files.
		ctype, encoding = mimetypes.guess_type(path)
		if ctype is None or encoding is not None:
			# No guess could be made, or the file is encoded (compressed), so
			# use a generic bag-of-bits type.
			ctype = 'application/octet-stream'
		maintype, subtype = ctype.split('/', 1)
		if maintype == 'text':
			fp = open(path)
			# Note: we should handle calculating the charset
			msg = MIMEText(fp.read(), _subtype=subtype)
			fp.close()
		elif maintype == 'image':
			fp = open(path, 'rb')
			msg = MIMEImage(fp.read(), _subtype=subtype)
			fp.close()
		elif maintype == 'audio':
			fp = open(path, 'rb')
			msg = MIMEAudio(fp.read(), _subtype=subtype)
			fp.close()
		else:
			fp = open(path, 'rb')
			msg = MIMEBase(maintype, subtype)
			msg.set_payload(fp.read())
			fp.close()
			# Encode the payload using Base64
			encoders.encode_base64(msg)
		# Set the filename parameter
		msg.add_header('Content-Disposition', 'attachment', filename=os.path.basename(path))
		outer.attach(msg)
	# Now send or store the message
	#print(outer.keys())	  
	composed = outer.as_string()
	if op:
		m = hashlib.md5()
		m.update(time.asctime(time.localtime(time.time())))
		aux = m.hexdigest()+".txt"
		fp = open(aux, 'w')
		fp.write(composed)
		fp.close()
		return 6
	else:
		print("abriendo conexion")
		try:
			if ssl:
				s = smtplib.SMTP_SSL(server,port)
			else:
				s = smtplib.SMTP(server,port)
			#s.set_debuglevel(2)
			s.ehlo()
			print("tls")
			s.starttls()
			s.ehlo()
			print("login")
			print(fromUser,passwd)
			s.login(fromUser, passwd)
			print("enviando correo")
			s.sendmail(fromUser, to, composed)
			print("fin")
			s.close()
			return 6
		except Exception, e:
			m = hashlib.md5()
			m.update(time.asctime(time.localtime(time.time())))
			aux = m.hexdigest()+".txt"
			fp = open(aux, 'w')
			fp.write(composed)
			fp.close()
			return 8

def smtpAllMensaje(correos, user, passwd, server, port, ssl):
	if correos == None:
		return 0
	if user == None:
		return 1
	elif passwd == None:
		return 3
	elif server == None:
		return 4
	elif port == None:
		return 5

	print("abriendo conexion")
	try:
		if ssl:
			s = smtplib.SMTP_SSL(server,port)
		else:
			s = smtplib.SMTP(server,port)
		#s.set_debuglevel(2)
		s.ehlo()
		print("tls")
		s.starttls()
		s.ehlo()
		print("login")
		s.login(user, passwd)
		print("enviando correo")
		for ms in correos:
			try:
				composed = ms.as_string()
				s.sendmail(ms['From'], ms['To'], composed)
			except Exception, e:
				m = hashlib.md5()
				m.update(time.asctime(time.localtime(time.time())))
				aux = m.hexdigest()+".txt"
				fp = open(aux, 'w')
				fp.write(composed)
				fp.close()
		print("fin")
		s.close()
		return 6
	except Exception, e:
		return 8

def smtpEnpaquetar(to, subject, fromUser, text, attach):
	outer = MIMEMultipart()
	if to == None:
		return 0
	elif fromUser == None:
		return 1
	elif (subject == None) and (text == None):
		return 2

	outer['From'] = fromUser
	outer['To'] = to
	outer['Subject'] = subject
	outer['Date'] = time.asctime(time.localtime(time.time()))

	outer.attach(MIMEText(text))
	for path in attach:
		if not os.path.isfile(path):
			continue
		# Guess the content type based on the file's extension.  Encoding
		# will be ignored, although we should check for simple things like
		# gzip'd or compressed files.
		ctype, encoding = mimetypes.guess_type(path)
		if ctype is None or encoding is not None:
			# No guess could be made, or the file is encoded (compressed), so
			# use a generic bag-of-bits type.
			ctype = 'application/octet-stream'
		maintype, subtype = ctype.split('/', 1)
		if maintype == 'text':
			fp = open(path)
			# Note: we should handle calculating the charset
			msg = MIMEText(fp.read(), _subtype=subtype)
			fp.close()
		elif maintype == 'image':
			fp = open(path, 'rb')
			msg = MIMEImage(fp.read(), _subtype=subtype)
			fp.close()
		elif maintype == 'audio':
			fp = open(path, 'rb')
			msg = MIMEAudio(fp.read(), _subtype=subtype)
			fp.close()
		else:
			fp = open(path, 'rb')
			msg = MIMEBase(maintype, subtype)
			msg.set_payload(fp.read())
			fp.close()
			# Encode the payload using Base64
			encoders.encode_base64(msg)
		# Set the filename parameter
		msg.add_header('Content-Disposition', 'attachment', filename=os.path.basename(path))
		outer.attach(msg)
	# Now send or store the message
	#print(outer.keys())	  
	return outer

def smtpEnvio(arc,server,port,passwd):
	fp = open(arc, 'r')
	ms = email.message_from_file(fp)
	fp.close()
	fromUser = ms['From']
	to = ms['To']
	composed = ms.as_string()
	try:
		s = smtplib.SMTP(server,port)
		s.ehlo()
		print("tls")
		s.starttls()
		s.ehlo()
		print("login")
		s.login(fromUser, passwd)
		print("enviando correo")
		s.sendmail(fromUser, to, composed)
		print("fin")
		s.close()
		return 0
	except Exception, e:
		return 1

def datosPrincipales(arc):
	fp = open(arc, 'r')
	ms = email.message_from_file(fp)
	fp.close()
	if len(ms.get_payload())>1:
		res =(arc,ms['Subject'],ms['From'],ms['Date'],"mail-attachment")
	else:
		res =(ms['Subject'],ms['From'],ms['Date'],"")
	return list(res)
#smtpMensaje("jonas.arcos.99@gmail.com", "prueba", "jonny.test.arc.99@hotmail.com", "prueba text", ["webcam.jpg"], "360_live", "smtp-mail.outlook.com", 587, True)
#smtpEnvio(arc='pop3.txt',passwd="360_live", server="smtp-mail.outlook.com", port=587)
#print(datosPrincipales("pruebaPop.txt"))