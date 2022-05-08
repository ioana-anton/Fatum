FILE=./output.txt
if test -f "$FILE"; then
rm output.txt
fi
yacc -d fatum.y
lex fatum.l
gcc -o parser lex.yy.c y.tab.c -ly -ll -lm