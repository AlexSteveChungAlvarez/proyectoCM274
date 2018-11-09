n<-10000

M = c()
S = c()

fn = function(x,y){
	if(y<x^2){
		return (1)
	} else {
		return (0)
	}
}

for(i in 1:n){
	m = runif(2,-2,2)
	S = c(S,fn(m[1],m[2]))
	M = c(M,m)
}
dyn.load("rn.so")

M <- matrix(M, nrow = n, byrow = TRUE)

#S <- c(0,1,0,1)
s<-.C("main",as.integer(2),as.integer(n),t(M),S)[2]
