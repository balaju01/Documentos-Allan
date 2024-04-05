def mult_mat(A,B):
	a=int(len(A[0]))
	b=int(len(B))
	C
	if a != b:
		print("NO SE PUEDE REALISAR LA MULTIPLICASION DE MATRICES")
	else :
		for i in range(b):
			for j in range(a):
				C[i][j]=C[i][j]+(A[i][j]*B[i][j])
		return C

def mi_funcion(param1, param2):
    """Esta funcion imprime los dos valores pasados
    como parametros"""
    print (param1)
    print (param2)
		
def exp_mat(A,n):
	r=(n/2)
	r1=((n-1)/2)
	R=0
	if n==1:
		return A
	elif (n%2)==0:
		B=exp_mat(A,r)
		return mult_mat(B,B)
	elif (n%2)==1:
		B=exp_mat(A,(r1)
		R=mult_mat(B,B)
		return R

def fibo_chido(A,n):
	if (n==0) or (n==1):
		return n
	else :
		R=exp_mat(A,(n-1))
		return (R[0][0])



print("introdusca que elemento de la serie de fibonacci quiere conseguir \n")

n=int(input("Elemento No.: ",))
M=[[1,1],[1,0]]
mi_funcion("hola", 2)
fibo_chido(M,n)

