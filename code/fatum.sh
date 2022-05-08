#g++ -o fatum fatum.cpp $(mysql_config --libs) `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
#g++ -o fatum fatum.cpp
rm fatum
rm output.txt
gcc -o fatum fatum.c gameplay/utils.c gameplay/gameplay.c
FILE=./fatum
if test -f "$FILE"; then
    xterm -hold -title "Fatum Mundi" -bg Cornsilk1 -fg Red3 -e ./fatum
fi
