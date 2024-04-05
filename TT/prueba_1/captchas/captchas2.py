from random import randrange

def eucExt(a,b):
    r = [a,b]
    s = [1,0] 
    i = 1
    q = [[]]
    while (r[i] != 0): 
        q = q + [r[i-1] // r[i]]
        r = r + [r[i-1] % r[i]]
        s = s + [s[i-1] - q[i]*s[i]]
        i = i+1
    return s[i-1]%b

def GenerarPares(p=7,w=5,t=2,k=0):
    pares =[]
    a = [k]
    for aux in range(0,w):
        pares.append([randrange(p),0])
    for aux in range(1,t):
        a.append(randrange(p))
    for aux in pares:
        suma = k
        for aux2 in range(1,t):
            suma = (suma+(a[aux2]*(aux[0]**aux2)))%p
        aux[1] =suma
    return pares
def secreto(pares,p):
    suma = 0
    for aux in pares:
        ind = pares.index(aux)
        lis = pares[:ind] + pares[(ind+1):]
        num=1
        den=1
        for aux2 in lis:
            num = (num*(aux2[0])*-1)%p
            den = (den*((aux[0]-aux2[0])%p))%p
        den = eucExt(den,p)
        suma += (den*aux[1]*num)%p
    return suma%p
n =67
pares = GenerarPares(n,5,3,23)
pares2 = [pares[1], pares[4], pares[0]]
#pares2 = [[4,0],[1,8],[2,7],[5,11]]
print pares
print pares2
a = secreto(pares2,n)
print a