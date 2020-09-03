# Načítání CSV souboru ze standardního vstupu#

Příklad na procvičení čtení ze souboru a přesměrování souborů do a z programu.

### Vzorový vstup ###

```
Aneta Langerova;30;160;65;
Lojza;1;80;11;
Lidumil Nejed;50;160;70;
Drahomir Vladyka;40;180;80;
```

Tzn. v každém řádku je jméno, věk, výška, váha.
Vytvořte program, který spočítá průměrnou hodnotu věku, výšky, váhy u všech lidí.
Najde a vypíše také jména a věk nejmladšího a nejstaršího člověka.

- Program musí být univerzální a být schopen libovolné množství záznamů.
- Záznamy nemusí obsahovat všechny údaje nebo jich může obsahovat více.
- Pokud záznam není korektně načten, zahazuje se.
- Maximální délka záznamu je 1024 znaků
- Maximální délka jména je 256 znaků


### Vzorový výstup ###

```
Prumerna vaha je: 56 kg 
Prumerna vyska je: 145 cm 
Prumerny vek je: 30 
Nejmladsim je Lojza s vekem 1 
Nejstarsim je Lidumil Nejed s vekem 50
```

### Příklad volání ###
```
./CSV_file < input.txt
```

# EN # 

# Loading CSV file from standard input#

Task for practicing of reading file and redirect file to and out of program.

### Sample input ###

```
Aneta Langerova;30;160;65;
Lojza;1;80;11;
Lidumil Nejed;50;160;70;
Drahomir Vladyka;40;180;80;
```
E.g. in every row is name, age, height, weight.
Create a program, which calculates average age, height and weight.
Finds and prints out name of the oldest and youngest person.

- Program has to ve universal and be able to store any amount of items.
- Notes do not have to contain all the data or it could contain some extra data.
- If the data are not correctly loaded, they are thrown away.
- Maximum length of note is 1024 characters.
- Maximum length of name is 256 characters.

### Example output ###

```
The average weight is: 56 kg 
The average height is: 145 cm 
The average age is: 30 
The youngest is Lojza with the age of 1
The oldest is Lidumil Nejed with the age of 50
```

### Example of running a program ###
```
./CSV_file < input.txt
```
