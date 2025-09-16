#!/bin/bash


# # update to latest commit my latex wrapper
# git submodule update --remote --merge



# compile

cd /home/Cyber_Wolf/Coding/5_university/matan

latexmk \
    -outdir="./build/" \
    -shell-escape \
    -verbose \
    -file-line-error \
    -synctex=1 \
    -lualatex \
    -interaction=nonstopmode \
    -pvc \
    "./src/main.tex"

    # -pdf -pvc -interaction=nonstopmode \
    # -f \

# latexmk -shell-escape -verbose -file-line-error -synctex=1 -interaction=nonstopmode  -lualatex -outdir=build 'main.tex'
