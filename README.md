# C++ Concurrency In Action #
This document contains the notes, musings, and thoughts generated during my
reading of "C++ Concurrency in Action" by Anthony Williams. The notes were
taken primarily to encourage a thorough reading of the book and to help me
recall the most important tidbits from the book upon a rereading of my notes. I
can imagine the notes may be helpful to more than just me, so I am making them
publicly available. A concurrent programming novice, I cannot guarantee my
notes are entirely correct, or even sensical at times. If you ever encounter a
mistake, please contact me at mjw297@cornell.edu.

## Index ##
- **doc** Doxygen documentation for code in `/src`.
- **listings** Stand alone executables included in the notes
- **notes** LaTeX files used to generate notes.
- **res** Miscellaneous resources
    - **img** Images
- **src** Source code written to be included in listings

## Dependencies ##
- C++11 compliant compiler
- Boost
- Doxygen (optional)

If you do not have Boost, you can still build many of the listings and much of
the code, but you may have to modify makefiles in order to do so.

## Building the Notes ##
A pre-built pdf of the notes is included in `/notes`. If you want to build the
notes yourself, navigate to '/notes` and run any of the following make commands.

    make
    make notes.pdf
    make view
    make chrome
    make firefox

## Building the Documentation ##
To build doxygen documentation for the code in `/src`, navigate to `/doc` and
run any of the following make commands.

    make
    make doc
    make view
    make chrome 
    make firefox
