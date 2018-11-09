
n<-10000 #Número de muestras
M = c()
S = c()

#Esta es la función que queremos replicar
#Tooma un par de coordenadas y devuelve 1 o 0
fn = function(x,y){
	if(y<x^2){
		return (1)
	} else {
		return (0)
	}
}

#Se genera una matriz con pares ordenados aleatorios
#y un vector con sus respectivas salidas
for(i in 1:n){
	m = runif(2,-2,2)
	S = c(S,fn(m[1],m[2]))
	M = c(M,m)
}
M <- matrix(M, nrow = n, byrow = TRUE)

#se carga el programa en C
#el archivo .so es generado al compilarlo con "R CMD SHILB"
#ejecuta la función "main"
dyn.load("rn.so")
s<-.C("main",	as.integer(2),	as.integer(n),	t(M),	S)[2]
#		2 entradas	n muestras
