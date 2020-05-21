


djobradovic@singidunum.ac.rs


recnik = {
    'a':0,
    'b':0
}

def analiziraj_liniju(linija, recnik):
    for t in linija:
        t = t.lower()
        if t in recnik:
            recnik[t] += 1
        else:
            recnik[t] = 1



c = 0
with open('hobit.txt') as file:
    for linija in file:
        analiziraj_liniju(linija, recnik)
print(recnik)

najveci = None
for rec in recnik:
    print(rec, recnik[rec])
    if rec != ' ':
        if najveci == None:
            najveci = {
                'karakter': rec,
                'broj ponavljanja':recnik[rec]
            }
        else:
            if recnik[rec] > najveci['broj ponavljanja']:
                najveci = {
                    'karakter': rec,
                    'broj ponavljanja':recnik[rec]
                }

print(najveci)

print('U datoteci ima {} karaktera'.format(c))