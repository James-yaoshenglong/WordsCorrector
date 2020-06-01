objects = main.o mainFunction.o Levenshtein.o

all : $(objects)
	g++ $(objects) -o wordsCorrector

main.o :
mainFunction.o :
Levenshtein.o :

.PHONY : clean
clean :
	rm -f wordsCorrector $(objects)