def eucExt(a,b):
 r = [a,b]
 s = [1,0] 
 t = [0,1]
 i = 1
 q = [[]]
 while (r[i] != 0): 
  q = q + [r[i-1] // r[i]]
  r = r + [r[i-1] % r[i]]
  s = s + [s[i-1] - q[i]*s[i]]
  t = t + [t[i-1] - q[i]*t[i]]
  i = i+1
 return (r[i-1], s[i-1], ((t[i-1])%a))

try:
 print "Sean a1, a2 enteros\n"
 a1 = raw_input("Teclea el valor de a1: ")
 print "\ta1 =",a1
 a2 = raw_input("Teclea el valor de a2: ")
 print "\ta2 =",a2
 print "\t\tMCD(", a1, ",", a2, ") =", eucExt(int(a1),int(a2))[0]
 print "\t\t", eucExt(int(a1),int(a2))[0], "=", a1, "(", eucExt(int(a1),int(a2))[1], ") +", a2, "(", eucExt(int(a1),int(a2))[2], ")"
except ValueError:
 print "No metiste un numero jaja"