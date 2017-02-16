#Programming Python by Mark Lutz
#Chapter1
#Step1: Representing Records

import pprint #for dict of dicts, can't import later on

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
values = ['Sue Jones',45,40000,'hdw']

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


for person in people:
	if person['name'] == 'Sue Jones':
			print(person['pay'])

names = [person['name'] for person in people] #collect names
print(names)

print(list(map((lambda x: x['name']),people))) #ditto, generate

print(sum(person['pay'] for person in people)) #sum all pay


print([rec['name'] for rec in people if rec['age'] >= 45])  #SQL-ish query

print([(rec['age'] ** 2 if rec['age'] >= 45 else rec['age']) for rec in people])

G = (rec['name'] for rec in people if rec['age'] >=45)
print(G)
print(next(G))

G = ((rec['age'] ** 2 if rec['age'] >=45 else rec['age']) for rec in people)
print(G)
print(G.__next__())

for person in people:
	print(person['name'].split()[-1])
	person['pay'] *= 1.10

for person in people: print(person['pay'])

#Nested Structures

bob2 = {'name': {'first': 'Bob', 'last': 'Smith'},
		'age':42,
		'job': ['software','writing'],
		'pay': (40000,50000)}

print(bob2['name']) #bob's full name
print(bob2['name']['last']) #bob's last name
print(bob2['pay'][1]) #bob's upper pay

for job in bob2['job']: print(job) #all of bob's jobs

print(bob2['job'][-1]) #bob's last job

bob2['job'].append('janitor') #bob gets a new job

print(bob2)


#Dictionaries of dictionaries

bob = dict(name='Bob Smith',age = 42,pay=30000,job='dev')
sue = dict(name='Sue Jones', age = 45, pay = 40000, job = 'hdw')

print(bob)

db = {}
db['bob'] = bob #reference in a dict of dicts
db['sue'] = sue

print(db['bob']['name']) #fetch bob's name

db['sue']['pay'] = 50000 #increase sue's pay
print(db['sue']['pay']) #fetch sue's pay

print(db)
pprint.pprint(db)

for key in db:
	print(key, '=>', db[key]['name'])

for key in db:
	print(key,'=>',db[key]['pay'])


for key in db:
	print(db[key]['name'].split()[-1])
	db[key]['pay'] *= 1.10

for record in db.values(): print(record['pay'])

x = [db[key]['name'] for key in db]
print(x)

x = [rec['name'] for rec in db.values()]
print(x)

db['tom'] = dict(name='Tom', age = 50, job=None, pay = 0)
print(db['tom'])
print(db['tom']['name'])

print(list(db.keys()))

print(len(db))

print([rec['age'] for rec in db.values()])

print([rec['age'] for rec in db.values() if rec['age'] >= 45])
