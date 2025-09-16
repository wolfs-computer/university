#!/bin/bash



TEXINPUTS=/home/Cyber_Wolf/Coding/1_projects/latex_libs/wrapper/basic//:$TEXINPUTS latexmk \
    -outdir=./build \
    -shell-escape \
    -verbose \
    -file-line-error \
    -synctex=1 \
    -interaction=nonstopmode \
    -lualatex \
    test_pack.tex
