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
	r = c(p,.C("main",p,r)[2],fn(p))
	print(r)
}
