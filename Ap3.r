dyn.load("rnEval.so")
n = 10
r = 0
for(i in 1:n){
	p = runif(2,-1,1)
	print(.C("main",p,r)[2])
}
