CXXFLAGS = -O3 -std=c++11 -Wall

.SILENT :
.PHONY : all clean doc html pdf test

all : test color recursion

clean :
	rm -rf color recursion results.txt

color : color.h color.cpp color2.cpp
	$(CXX) $(CXXFLAGS) -o color color.cpp color2.cpp

doc : html pdf

html : html/index.html

html/index.html : doxyfile enum.h README.md TPL.h 
	doxygen

pdf : html TPL.pdf

recursion :
	$(CXX) $(CXXFLAGS) -o recursion recursion.cpp

results.txt : test.cpp TPL.h TPLRecursion.h expected.txt
	cpp test.cpp | sed -e "/#/d" -e "/^\s*$$/d" > results.txt
	diff -y --suppress-common-lines expected.txt results.txt
	@echo "Passed."

test : results.txt

TPL.pdf :
	(cd latex && make)
	mv latex/refman.pdf TPL.pdf
