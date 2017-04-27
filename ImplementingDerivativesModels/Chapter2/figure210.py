#Implementing Derivatives Models - Clewlow and Strickland
#Chapter 2
#Figure 2.10
#valuation of a European Call in an additive tree
from math import exp,pow,sqrt

#parameters 
#precompute constants
K = 100
T = 1.0
S = 100
sig = 0.2
r = 0.06
N = 3


dt = round(T/N,4)  #.3333
nu = round(r-0.5*pow(sig,2),4) #.04
dxu = round(sqrt(pow(sig,2)*dt + pow(nu*dt,2)),4) #.1162
dxd = -dxu #-.1162
pu = round(.5 + .5*(nu*dt/dxu),4) #.5574
pd = 1-pu #.4426
disc = round(exp(-r*dt),4) #.9802

print(dt)
print(nu)
print(dxu)
print(dxd)
print(pu)
print(pd)
print(disc)


#initialize asset price at maturity step N
N1 = N+1
St = [0.0] * N1

St[0] = round(S*exp(N*dxd),4)

for j in range(1,N1):
	St[j] = round(St[j-1]*exp(dxu-dxd),4)
	#print(j)

print(str(St))

#initialize option values at maturity

C = [0.0] * N1

for j in range(0,N1):
	C[j] = round(max(0.0, float(St[j]-K)),4)

print (str(C))

#step back through the tree

for i in range(N,0,-1):
	for j in range(0,i):
	#print(j)
		C[j] = round(disc * (pu* C[j+1] + pd*C[j]),4)

print(str(C))

print("European Call: " +  str(C[0]))