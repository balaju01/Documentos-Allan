#! /usr/bin/env python

from io import BytesIO
from captcha.audio import AudioCaptcha
from captcha.image import ImageCaptcha

audio = AudioCaptcha(voicedir='voices')
image = ImageCaptcha(fonts=['correo_prueba1 / A.ttf'])

#data = audio.generate('1234')
#assert isinstance(data, bytearray)
#audio.write('1234', 'out.wav')

data = image.generate('1234')
#assert isinstance(data, BytesIO)
image.write('1234', 'out.png')
