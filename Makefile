CPP=g++ -g

RM = rm -f

%.o : %.cpp 
	$(CPP) -o $@ -c $< 


matrice.o : matrice.cpp matrice.h arrete.h
graphListe.o : graphListe.cpp graphListe.h arrete.h
arrete.o : arrete.cpp arrete.h
main.o : main.cpp arrete.h graphListe.h matrice.h

gr : main.o arrete.o graphListe.o matrice.o 
	$(CPP) $^ -o $@

clean :
	$(RM) main.o arrete.o graphListe.o matrice.o gr  

.PHONY: clean
