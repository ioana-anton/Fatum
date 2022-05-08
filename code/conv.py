import sys
from xml.dom.pulldom import END_DOCUMENT

# nume_define input_file output_file

name = sys.argv[1]
name = name.upper()


fin = open(sys.argv[2], "r")
art = fin.read()
fin.close()


fout = open(sys.argv[3], "a")

fout.write("\n#define " + name + " " + '"')
for c in art:
    toWrite = c
    if(c == '\n'):
        toWrite = "\\n"
    elif c == '\\':
        toWrite="\\\\"

    fout.write(toWrite)
fout.write('"')

#WARNING LA CARACTERELE SPECIALE!
#define HORSE "            .''\n  ._.-.___.' (`\\\n //(        ( `'\n'/ )\\ ).__. )\n' <' `\\ ._/'\\\n   `   \\    \\\n"
fout.close()