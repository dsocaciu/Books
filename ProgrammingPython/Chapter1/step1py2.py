#Programming Python by Mark Lutz
#Chapter1
#Step1: Representing Records

from __future__ import print_function #for python 2.7, in order to make the sep line below work

#Using Lists
bob = ['Bob Smith',42,30000,'software']
sue = ['Sue Jones',45,40000,'hardware']

print(bob[0],sue[2])

print (bob[0].split()[-1]) #what's bob's last name?

sue[2] *=1.25 #give sue a 25% raise
print(sue)

#A database list
people = [bob,sue] #reference in list of lists
for person in people:
	print(person)

print(people[1][0])

for person in people:
	print(person[0].split()[-1]) #print last name
	person[2] *= 1.2 #give each a 20% raises

for person in people: print(person[2]) #check new pay

pays = [person[2] for person in people] #collect all pay
print(pays)

pays = map((lambda x: x[2]),people) #ditto (map is a generator in 3.x)
print(list(pays))

print(sum(person[2] for person in people)) #generator expresson, sum built in

people.append(['Tom',50,0,None])
print(len(people))

print(people[-1][0])

#Field labels
NAME, AGE, PAY = range(3)

bob = ['Bob Smith',42,10000]
print(bob[NAME])

print(PAY,bob[PAY])

#list of tuples, tuples record both a field name and a vlaue

bob = [['name','Bob Smith'],['age',42],['pay',10000]]
sue = [['name','Sue Jones'],['age',45],['pay',20000]]
people = [bob,sue]

for person in people:
	print(person[0][1],person[2][1]) #name, pay

print([person[0][1] for person in people]) #collect name

for person in people:
	print(person[0][1].split()[-1]) #get last names
	person[2][1] *= 1.1 #give a 10% raise

for person in people: print(person[2])

for person in people:
	for(name,value) in person:
		if name == 'name': print(value) #find a specific field


def field(record,label):  #define fetcher function
	for(fname,fvalue) in record:
		if fname == label: #find any field by name
			return fvalue

print(field(bob,'name'))
print(field(sue,'pay'))

for rec in people:
	print(field(rec,'age')) #print all ages


#Using Dictionaries

bob = {'name' : 'Bob Smith', 'age':42, 'pay':30000, 'job':'dev'}
sue = {'name' : 'Sue Jones', 'age':45, 'pay':40000, 'job':'hdw'}

print(bob['name'], sue['pay'])

print(bob['name'].split()[-1])

sue['pay'] *= 1.10
print(sue['pay'])

#Other ways to make Dictionaries
bob = dict(name='Bob Smith', age=42, pay=30000, job='dev')
sue = dict(name='Sue Jones', age=45, pay=40000, job='hdw')

print(bob)
print(sue)

sue = {}
sue['name'] = 'Sue Jones'
sue['age'] = 45
sue['pay'] = 40000
sue['job'] = 'hdw'

print(sue)

names = ['name','age','pay','job']
values = ['Sue Jones',42,40000,'hdw']

print(list(zip(names,values)))
sue = dict(zip(names,values))

print(sue)


fields  = ('name', 'age','job','pay')
record = dict.fromkeys(fields, '?')
print(record)

#List of dictionaries

print(bob)
print(sue)



people = [bob,sue] #reference in a list
for person in people:
		print(person['name'],person['pay'], sep=', ') #all name, pay