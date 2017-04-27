#Implementing Derivatives Models - Clewlow and Strickland
#Chapter 2
#Figure 2.5
#valuation of an American put in a multiplcative tree
from math import exp,pow

#parameters 
#precompute constants
K = 100
T = 1.0
S = 100
r = 0.06
N = 3
u = 1.1
d = .9091
dt = round(T/N,4)  #.3333
p = round((exp(r*dt)-d)/(u-d),4) #.5802
disc = round(exp(-r*dt),4) #.9802

print(dt)
print(p)
print(disc)


#initialize asset price at maturity step N
N1 = N+1
St = [0.0] * N1

St[0] = round(S*pow(d,N),4)

for j in range(1,N+1):
	St[j] = round(St[j-1]*u/d,2)
	#print(j)

print(str(St))

#initialize option values at maturity

C = [0.0] * N1

for j in range(0,N1):
	C[j] = round(max(0.0, float(K-St[j])),4)

print (str(C))

#step back through the tree

for i in range(N,0,-1):
	for j in range(0,i):
	#print(j)
		C[j] = round(disc * (p* C[j+1] + (1-p)*C[j]),4)
		St[j] = round(St[j]/d,4)
		C[j] = round(max(C[j], K-St[j]),4)

print(str(C))

print("American put: " +  str(C[0]))