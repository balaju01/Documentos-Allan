import smtp2
from smtp2 import smtpAllMensaje
from smtp2 import smtpEnpaquetar

user="festivalsonparamilo@gmail.com"
passwd="festival160602"
server="smtp.gmail.com"
def sonParaMiloCorreos(file):
	participantes = open(file, "r")
	correos = []
	for line in participantes:
		datosCorreo = line.split(',')
		text='Tus datos han quedado registrados satisfactoriamente con el n\xc3\xbamero de folio "'+datosCorreo[2]+'" Conserva este n\xc3\xbamero para futuros tr\xc3\xa1mites. Estamos revisando tu propuesta. La determinaci\xc3\xb3n del Comit\xc3\xa9 Organizador se te dar\xc3\xa1 a conocer a m\xc3\xa1s tardar el 30 de abril del a\xc3\xb1o en curso.\nPersona: '+datosCorreo[0]+'\nCorreo: '+datosCorreo[1]
		#print(text)
		correos.append(smtpEnpaquetar(datosCorreo[1].strip(), datosCorreo[0].strip(), user, text, []))
	#print(correos)
	smtpAllMensaje(correos, user, passwd, server, 587, False)

sonParaMiloCorreos("correoFSPM.txt")