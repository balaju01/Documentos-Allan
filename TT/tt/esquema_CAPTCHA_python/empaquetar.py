from Ek_din import cifrar
from subprocess import call
import types
import json
import zipfile
def empaquetar(body,asunto,op):
	s=cifrar(body,asunto,op)
	asunto=asunto.replace(" ","_")
	disc={}
	#print(s[1])
	ass=asunto+"_CAPTCHA.zip"
	if type(s[1])==types.StringType:
		zi=call("zip -r "+ass+" "+s[1], shell=True)
		mv=call("mv ./"+ass+" /tmp", shell=True)
		rmm=call("rm -rf "+s[1], shell=True)
		return (s[0],"/tmp/"+ass)
	else:
				
		zi=call("zip -r "+ass+" "+s[1][1], shell=True)
		mv=call("mv ./"+ass+" /tmp", shell=True)
		rmm=call("rm -rf "+s[1][1], shell=True)
		return (s[0],"/tmp/"+ass)
