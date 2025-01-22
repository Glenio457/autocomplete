@echo off
cd src
g++ main.cpp -o ..\bin\autocompletar
cd ..
bin\autocompletar datasets\actors.txt 10
