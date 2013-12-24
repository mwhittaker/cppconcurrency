TEXFILE = notes

all: tex

tex: $(TEXFILE).tex
	pdflatex -synctex=1 -interaction=nonstopmode $(TEXFILE).tex
	pdflatex -synctex=1 -interaction=nonstopmode $(TEXFILE).tex

view: tex
	evince $(TEXFILE).pdf

clean:
	-rm *.log
	-rm *.aux
	-rm *.out
	-rm *.synctex.gz
	-rm *.toc
