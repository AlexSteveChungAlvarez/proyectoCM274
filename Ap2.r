dyn.load("rnEval.so")
p1 <- c(.5,.7)
p2 <- c(-.2,1.3)
p3 <- c(1.1,-1.4)
r  <- 0

.C("main",p1,r)

.C("main",p2,r)

.C("main",p3,r)
