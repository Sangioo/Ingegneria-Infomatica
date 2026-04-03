import random

# generazione file di prova
namelist = ['Paolo', 'Gianni', 'Piero', 'Anna']
risultati = ['1', '2', 'X']

for n in range(1,11):
	f = open(f'partite{n}.csv', 'a', encoding='UTF-8')
	
	for i in range(random.randrange(100000, 1000000)):
		g1 = random.choice(namelist)

		tmp = namelist.copy()
		tmp.remove(g1)
		g2 = random.choice(tmp)

		r = random.choice(risultati)

		f.write(f'\n{g1},{g2},{r}')
	
	f.close()

# generazione di casi di test
for i in range(1, 11):
	for n in range(3):
		nome = random.choice(namelist)
		print(f"myfunction('partite{i}.csv', '{nome}')")