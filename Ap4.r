#Probando con funciones que van de {0,1}^(nIng) a {0,1}
n = 100
nIng = 5

for(i in 1:n){
	m = sample(x = c(0,1), nIng, replace = T, prob = c(.5,.5))
	print(m)
}

dyn.load("rn.so")

M <- matrix(M, nrow = n, byrow = TRUE)

s<-.C("main",as.integer(nIng),as.integer(n),t(M),S)[2]
