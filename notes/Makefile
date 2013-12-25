TEXFILE = notes

all: tex

tex: $(TEXFILE).tex 
	make clean
	pdflatex -synctex=1 -interaction=nonstopmode $(TEXFILE).tex
	pdflatex -synctex=1 -interaction=nonstopmode $(TEXFILE).tex

view: tex 
	make clean
	evince $(TEXFILE).pdf

chrome: tex
	make clean
	google-chrome $(TEXFILE).pdf

firefox: tex
	make clean
	firefox $(TEXFILE).pdf

clean:
	-rm *.log
	-rm *.aux
	-rm *.out
	-rm *.synctex.gz
	-rm *.toc
	-rm *.lol
