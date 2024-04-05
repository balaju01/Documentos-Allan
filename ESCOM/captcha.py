#!/usr/bin/python
from io import BytesIO
from captcha.audio import AudioCaptcha
from captcha.image import ImageCaptcha

#audio = AudioCaptcha(voicedir='/path/to/voices')
image = ImageCaptcha(fonts=['./fon/A.ttf', './fon/B.ttf'])

#data = audio.generate('1234')
#assert isinstance(data, bytearray)
#audio.write('1234', 'out.wav')

data = image.generate('<)?Y(')
#assert isinstance(data, BytesIO)
image.write('<)?Y(', 'out.png')
