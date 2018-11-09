dyn.load("rnEval.so")
n = 10
r = 0
#Tomamos esta función otra vez para comparar
fn = function(x,y){
	if(y<x^2){
		return (1)
	} else {
		return (0)
	}
}

for(i in 1:n){
	p = runif(2,-1,1)
	s = as.numeric(.C("main",p,r)[2])
	cat("Entrada:\t",p[1],"\t",p[2],"\n")
	cat("Función original: ",fn(p[1],p[2]),"\tFunción generada",s,"\n\n")
}
