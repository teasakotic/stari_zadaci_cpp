x = 12
y = 34


f = 12.3


lista = [1, 2, 3, 4, 5, 6]
for t in lista:
    print(3*t)


s = 0
for y in lista:
    if y%2 == 0:
        s += y
print(20*'-')
lista = range(5, 15)
for y in lista:
    print(y)
print(20*'-')

for y in lista:
    print(y)


ime = 'djordje     ide     na  fakultet'

for a in ime:
    if a == ' ':
        print(30*'=')
    else:
        print(a)

s = 0
for a in ime:
    if a == 't':
        s+=1

print("Broj pojavljivanja karaktera t je {}".format(s))
print(len(ime))

print("Zbir elemenata liste je:"+str(s))

# ====== broj reci ========
s = 1
p = '*'
for a in ime:
    if a == ' ' and p !=' ':
        s += 1
    p = a

print("Broj reci je {}".format(s))
print("----------------------------")


print('Danas pada sneg!!')