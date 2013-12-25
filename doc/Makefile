all: doc

doc: src.doxygen.config
	doxygen src.doxygen.config && cd latex && make

view: doc
	evince latex/refman.pdf

chrome: doc
	google-chrome html/index.html

firefox: doc
	firefox html/index.html

clean:
	-rm -r html
	-rm -r latex
