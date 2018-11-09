dyn.load("rnEval.so")
#Probando con algunas entradas
p1 <- c(.5,.5)
p2 <- c(-.5,1.5)
p3 <- c(1.5,-1)
r  <- 0

#Evalúa la función generada en un vector, y guarda la salida en r
.C("main",p1,r)
#Además esta llamada a .C devolverá p1 y r

.C("main",p2,r)

.C("main",p3,r)
