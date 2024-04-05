from Ek_din import cifrar
from subprocess import call
import types
import json
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
		for i in s[1][0]:
			disc[i[1]]=i[0]

		lista=open(s[1][1]+"/lista.json","w")	
		lista.write(json.dumps(disc))
		lista.close
		zi=call("zip -r "+ass+" "+s[1][1], shell=True)
		mv=call("mv ./"+ass+" /tmp", shell=True)
		rmm=call("rm -rf "+s[1][1], shell=True)
		return (s[0],"/tmp/"+ass)
