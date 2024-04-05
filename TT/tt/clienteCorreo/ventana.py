import gi
import os
import email
import json
import SSE
import re
import captchas

gi.require_version('Gtk', '3.0')
from gi.repository import Gtk, Gio
from smtp2 import datosPrincipales
from listarCorreos import listaCorreosView
from listarCorreos import contarCorreo
from listarCorreos import body
from pop3 import conexionPop3
from envios import envios

path = './Usuarios'
EMAIL_REGEX = re.compile(r'([(a-z0-9\_\-\.)]+@[(a-z0-9\_\-\.)]+\.[(a-z)]{2,15})')

def listdirs(folder):
	return [d for d in os.listdir(folder) if os.path.isdir(os.path.join(folder, d))]

def listFiles(folder):
	return [d for d in os.listdir(folder) if os.path.isfile(os.path.join(folder, d))]

class MyWindow(Gtk.Window):

	user=listdirs(path)
	selectCarpeta=None
	selectUsuario=None
	config={}

	def __init__(self):
		jsonCorreo = open("config.json","r")
		jsonLectura = jsonCorreo.readline()
		jsonCorreo.close()
		self.config = json.loads(jsonLectura)
		Gtk.Window.__init__(self, title="Cliente de Correos")
		self.set_border_width(4)
		self.set_default_size(800, 600)

		self.notebook = Gtk.Notebook()
		self.add(self.notebook)

		self.page = self.newPage()
		self.page.set_border_width(10)
		self.notebook.append_page(self.page, Gtk.Label('Index'))

	def visorCorreo(self):
		vistaCorre = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
		self.emisor = Gtk.Label("De: ")
		self.emisor.set_justify(Gtk.Justification.LEFT)
		self.destinatorio = Gtk.Label("Para: ")
		self.destinatorio.set_justify(Gtk.Justification.LEFT)
		self.asunto = Gtk.Label("Asunto: ")
		self.asunto.set_justify(Gtk.Justification.LEFT)
		descifrado= Gtk.Button(label="Descifrar")
		descifrado.connect("clicked", self.descifrarBody)
		box1 = Gtk.VBox(False,10)
		box1.pack_start(self.emisor,True,True,0)
		box1.pack_end(self.destinatorio,False,True,0)
		box2 = Gtk.HBox(False,0)
		box2.pack_start(self.asunto,False, False, 0)
		box2.pack_end(descifrado,False,False,0)
		self.cuerpo = Gtk.TextView()
		self.cuerpo.set_editable(False)
		scrol = Gtk.ScrolledWindow()
		scrol.set_hexpand(True)
		scrol.set_vexpand(True)
		scrol.add(self.cuerpo)
		self.adjuntos = Gtk.Label("Adjuntos")
		self.adjuntos.set_justify(Gtk.Justification.LEFT)
		scrol2 = Gtk.ScrolledWindow()
		scrol2.set_hexpand(True)
		scrol2.add(self.adjuntos)
		vistaCorre.add(box1)
		vistaCorre.add(box2)
		vistaCorre.add(scrol)
		vistaCorre.add(scrol2)
		return vistaCorre

	def visorCorreoNuevo(self):
		vistaCorre = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
		newDest = Gtk.Entry(name="Destino")
		newDest.set_editable(True)
		newAsunto = Gtk.Entry(name="Asunto")
		newAsunto.set_editable(True)

		destinatorio = Gtk.Label("De: ")
		destinatorio.set_justify(Gtk.Justification.LEFT)
		asunto = Gtk.Label("Asunto: ")
		asunto.set_justify(Gtk.Justification.LEFT)

		Cerrar = Gtk.Button(label="Cerrar")
		Cerrar.connect("clicked", self.cerrarPagina)
		Enviar = Gtk.Button(label="Enviar")
		Enviar.connect("clicked", self.enviarMensage)

		box1 = Gtk.HBox(False,0)
		box1.pack_start(destinatorio,False,False,0)
		box1.pack_start(newDest,True,True,0)
		
		box2 = Gtk.HBox(False,0)
		box2.pack_start(asunto,False, False, 0)
		box2.pack_start(newAsunto,True, True, 0)

		box3 = Gtk.HBox(False,0)
		box3.pack_end(Cerrar,False, False, 0)
		box3.pack_end(Enviar,False, False, 0)

		cuerpo = Gtk.TextView(name="cuerpo")
		scrol = Gtk.ScrolledWindow()
		scrol.set_hexpand(True)
		scrol.set_vexpand(True)
		scrol.add(cuerpo)
		adjuntos = Gtk.Label("Adjuntos")
		adjuntos.set_justify(Gtk.Justification.LEFT)
		scrol2 = Gtk.ScrolledWindow()
		scrol2.set_hexpand(True)
		scrol2.add(adjuntos)
		vistaCorre.add(box1)
		vistaCorre.add(box2)
		vistaCorre.add(scrol)
		vistaCorre.add(scrol2)
		vistaCorre.add(box3)
		return vistaCorre

	def cerrarPagina(self,button):
		print("cerrarPagina")
		page=self.notebook.get_current_page()
		self.notebook.remove_page(page)
		self.notebook.show_all()

	def enviarMensage(self,button):
		print("enviarMensage")
		page=self.notebook.get_current_page()
		contenedor = self.notebook.get_nth_page(page)
		asunto = ""
		destino = ""
		cuerpo = ""
		for c in contenedor.get_children():
				for x in c.get_children():
					if isinstance(x,Gtk.Entry):
						if x.get_name() == "Destino":
							destino = x.get_text()
						elif x.get_name() == "Asunto":
							asunto = x.get_text()
					if isinstance(x,Gtk.TextView):
						buf = x.get_buffer()
						end_iter = buf.get_end_iter()
						start_iter = buf.get_start_iter()
						cuerpo = x.get_buffer().get_text(start_iter, end_iter, True)
		if not destino.split():
			dialog = Gtk.MessageDialog(self, 0, Gtk.MessageType.ERROR,
				Gtk.ButtonsType.CANCEL, "Error al enviar Mensaje")
			dialog.format_secondary_text(
				"El correo Destinatario no ha sido ingresado.")
			dialog.run()
			dialog.destroy()
		elif not asunto and not cuerpo:
			dialog = Gtk.MessageDialog(self, 0, Gtk.MessageType.WARNING,
				Gtk.ButtonsType.OK_CANCEL, "Mensaje vacio")
			dialog.format_secondary_text(
				"El mensaje de correo esta vacio, decea que se envie?")
			response = dialog.run()
			if response == Gtk.ResponseType.OK:
				print("Mensaje Incompleto")
				t = envios(destino,self.user[0],asunto,cuerpo,[],self.config)
				t.start()
			dialog.destroy()
		else:
			print("Mensaje Completo")
			t = envios(destino,self.user[0],asunto,cuerpo,[],self.config)
			t.start()
		print("Asunto: "+asunto)
		print("Destino: "+destino)
		print("Cuerpo: "+cuerpo)
		print("cerrarPagina")
		page=self.notebook.get_current_page()
		self.notebook.remove_page(page)
		self.notebook.show_all()
		#print(contenedor.query_child_packing())

	def descifrarBody(self, button):
		print "Descrifrar body"
		bodyBuffer=self.cuerpo.get_buffer()
		start_iter = bodyBuffer.get_start_iter()
		end_iter = bodyBuffer.get_end_iter()
		text = bodyBuffer.get_text(start_iter, end_iter, True) 
		firma=text.find("------SSE Cipher------")
		if(firma>=0):
			text2 = text[firma:]
			m = re.search('\-\n(.+)\n\-',text2)
			if(m!=None):
				textFirma = m.group(1)
				print textFirma
				correoOrigen=self.emisor.get_text()
				correoDestino=self.destinatorio.get_text()
				m = re.search("([(a-z0-9\_\-\.)]+@[(a-z0-9\_\-\.)]+\.[(a-z)]{2,15})",correoOrigen)
				correoOriegen = m.group(1)
				m = re.search("([(a-z0-9\_\-\.)]+@[(a-z0-9\_\-\.)]+\.[(a-z)]{2,15})",correoDestino)
				correoDestino = m.group(1)
				captchas.buscarCAPTCHAS(textFirma,correoDestino,correoOriegen)
				print(correoOriegen)
				print(correoDestino)


	def listaMail(self, usuario, carpeta):
		scrollable_treelist = Gtk.ScrolledWindow()
		scrollable_treelist.set_vexpand(True)
		
		software_liststore = Gtk.ListStore(str, str, str, str)
		#archivos = listdirs(path+usuario+"/"+carpeta)
		if self.selectCarpeta == None:
			archivos = [("", "",  "", "")]
		else:
			archivos = [("prueba", "prueba",  "prueba", "mail-attachment")]
		for archivo in archivos:
			software_liststore.append(list(archivo))
		
		lista = software_liststore.filter_new()

		self.listaCar = Gtk.TreeView.new_with_model(lista)
		self.listaCar.connect("row-activated",self.celdasCorreo)
		for i, column_title in enumerate(["Asunto", "Correo", "Fecha", "Adjunto"]):
			if i == 3:
				renderer = Gtk.CellRendererPixbuf()
				column = Gtk.TreeViewColumn(column_title, renderer, icon_name=i)
			else:
				renderer = Gtk.CellRendererText()
				column = Gtk.TreeViewColumn(column_title, renderer, text=i)
			self.listaCar.append_column(column)

		scrollable_treelist = Gtk.ScrolledWindow()
		scrollable_treelist.set_vexpand(True)
		scrollable_treelist.set_hexpand(True)
		scrollable_treelist.add(self.listaCar)
		
		return scrollable_treelist

	def listaCarpetas(self, usuarios):
		treestore = Gtk.TreeStore(str)
		numCorreo = 0
		for usuario in usuarios:
			carpetas = listdirs(os.path.join(path,usuario))
			piter = treestore.append(None, ['%s' % usuario])
			for carpeta in carpetas:
				numCorreo = contarCorreo(os.path.join(path,usuario,carpeta))
				if carpeta=="Entrada":
					treestore.prepend(piter, ['%s \t %d' % (carpeta, numCorreo)])
				else:
					treestore.append(piter, ['%s \t %d' % (carpeta, numCorreo)])

		treeview = Gtk.TreeView(treestore)		
		tvcolumn = Gtk.TreeViewColumn('Cuentas de Correos')
		tvcolumn.set_reorderable(False)
		treeview.append_column(tvcolumn)
		treeview.connect("row-activated",self.celdasCarp)
		cell = Gtk.CellRendererText()
		tvcolumn.pack_start(cell, True)
		tvcolumn.add_attribute(cell, 'text', 0)
		treeview.set_search_column(0)
		tvcolumn.set_sort_column_id(0)
		treeview.set_reorderable(False)
		return treeview

	def celdasCorreo(self, treeview, posi, column):
		model = treeview.get_model()
		car = model.get_iter(posi)
		correo = (model.get_value(car, 0),model.get_value(car, 1),model.get_value(car, 2),model.get_value(car, 3))
		for key in self.listaCotejoCorreos:
			aux = self.listaCotejoCorreos[key]
			if ((aux[1]==correo[1]) and (aux[2]==correo[2])):
				archivo=key
				break
		ruta=os.path.join(path, self.selectUsuario, self.selectCarpeta, archivo)
		fp=open(ruta,"r")
		ms = email.message_from_file(fp)
		fp.close()
		self.destinatorio.set_text("Para: "+ms['To'])
		self.emisor.set_text("De: "+ms['From'])
		self.asunto.set_text("Asunto: "+ms['Subject'])
		textbody = body(ms)
		print(textbody)
		buffered = Gtk.TextBuffer()
		buffered.set_text(textbody.strip())
		self.cuerpo.set_buffer(buffered)
		#print(correo in self.listaCotejoCorreos)

	def celdasCarp(self, treeview, posi, column):
		model = treeview.get_model()
		car = model.get_iter(posi)
		carpeta = model.get_value(car, 0)
		if carpeta.find('@')>0:
			return
		carpeta = carpeta.split('\t')[0].strip()
		self.selectCarpeta=carpeta
		usu = model.iter_parent(car)
		usuario = model.get_value(usu, 0)
		self.selectUsuario=usuario
		self.listaCotejoCorreos = listaCorreosView(os.path.join(path,usuario,carpeta))
		software_liststore = Gtk.ListStore(str, str, str, str)
		for reg in self.listaCotejoCorreos:	
			software_liststore.append(self.listaCotejoCorreos[reg])
		lista = software_liststore.filter_new()
		self.listaCar.set_model(lista)

	def headerMail(self):
		box = Gtk.HBox(False,0)
		botonNewMail = Gtk.Button(label="Nuevo correo")
		botonNewMail.connect("clicked", self.nuevoCorreo,"newMail")
		botonEnviarRecibir = Gtk.Button(label="Enviar y Recibir")
		botonEnviarRecibir.connect("clicked", self.enviarRecibir)
		botonHerramientas = Gtk.Button(label="Herramientas")
		box.pack_start(botonNewMail, False, False, 0)
		box.pack_start(botonEnviarRecibir, False, False, 0)
		#box.pack_end(botonHerramientas, False, False, 0)
		return box

	def nuevoCorreo(self, button,name):
		print(name)
		self.pageNuevoCorreo = self.visorCorreoNuevo()
		self.pageNuevoCorreo.set_border_width(10)
		self.notebook.insert_page(self.pageNuevoCorreo, Gtk.Label("Nuevo Correo"),1)
		self.notebook.show_all()

	def enviarRecibir(self, button):
		print(self.config)
		host = self.config["hostPop"]
		port = self.config["portPop"]
		keyfile = self.config["keyfile"]
		certfile = self.config["certfile"]
		user = self.config["user"]
		passwd = self.config["passwd"]
		ssl = self.config["ssl"]
		delete = self.config["delete"]
		ruta = os.path.join(path,user,"Entrada")
		t=conexionPop3(host, port, keyfile, certfile, user, passwd, ssl, delete, ruta)
		t.start()
		#popDescarga(host, port, keyfile, certfile, user, passwd, ssl, delete, path)

	def newPage(self):
		marco = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
		barra = self.headerMail()
		areaCorreo = Gtk.Box(spacing=10)


		listaCap = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
		listaCap.add(self.listaCarpetas(self.user))
		areaViewCorreo = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
		listaCorreo = Gtk.Box(spacing=10)
		self.listaM = self.listaMail(self.user[0],'Entrada')
		listaCorreo.add(self.listaM)
		viewCorreo = Gtk.Box(spacing=10)
		self.visorCo = self.visorCorreo()
		viewCorreo.add(self.visorCo)

		areaViewCorreo.pack_start(listaCorreo, False, True, 0)
		areaViewCorreo.pack_start(viewCorreo, True, True, 0)

		areaCorreo.add(listaCap)
		areaCorreo.add(areaViewCorreo)

		marco.pack_start(barra, False, False, 0)
		marco.pack_end(areaCorreo, True, True, 0)
		return marco


win = MyWindow()
win.connect("delete-event", Gtk.main_quit)
win.show_all()
Gtk.main()