#Implementing Derivatives Models - Clewlow and Strickland
#Chapter 2
#Figure 2.3
#valuation of a European call in a multiplcative tree
from math import exp,pow

#parameters 
#precompute constants
K = 100
T = 1
S = 100
r = 0.06
N = 3
u = 1.1
d = .9091
dt = T/N  #.3333
p = (exp(r*dt)-d)/(u-d) #.5802
disc = exp(-r*dt) #.9802

print(dt)
print(p)
print(disc)


#initialize asset price at maturity step N
N1 = N+1
St = [0.0] * N1

St[0] = S*pow(d,N)

for j in range(1,N+1):
	St[j] = St[j-1]*u/d
	#print(j)

print(str(St))

#initialize option values at maturity

C = [0.0] * N1

for j in range(0,N1):
	C[j] = max(0.0, float(St[j]-K))

print (str(C))

#step back through the tree

for i in range(N,0,-1):
	for j in range(0,i):
	#print(j)
		C[j] = disc * (p* C[j+1] + (1-p)*C[j])

print(str(C))

print("European Call: " +  str(C[0]))