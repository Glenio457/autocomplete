@echo off
cd src
g++ main.cpp -o ../bin/meu_programa
cd ..
bin\meu_programa datasets\actors.txt 9