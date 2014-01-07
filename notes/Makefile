TEXFILE = notes
CHAPTERS = chapter01.tex \
		   chapter02.tex \
		   chapter03.tex \
		   chapter04.tex \
		   chapter05.tex \
		   chapter06.tex \
		   chapter07.tex \
		   chapter08.tex \
		   chapter09.tex \
		   chapter10.tex 
TEMPLATES = cpp.sty \
		    DejaVuSansMono.sty \
		    notes.cls \
		    notesutils.sty
		   
all: $(TEXFILE).pdf

$(TEXFILE).pdf: $(TEXFILE).tex $(CHAPTERS) $(TEMPLATES)
	make clean
	pdflatex -synctex=1 -interaction=nonstopmode $(TEXFILE).tex
	pdflatex -synctex=1 -interaction=nonstopmode $(TEXFILE).tex
	pdflatex -synctex=1 -interaction=nonstopmode $(TEXFILE).tex

view: $(TEXFILE).pdf
	make clean
	evince $(TEXFILE).pdf

chrome: $(TEXFILE).pdf
	make clean
	google-chrome $(TEXFILE).pdf

firefox: $(TEXFILE).pdf
	make clean
	firefox $(TEXFILE).pdf

clean:
	-rm *.log
	-rm *.aux
	-rm *.out
	-rm *.synctex.gz
	-rm *.toc
	-rm *.lol
