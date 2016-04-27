import sys, os

def main():
    i = 5
    eol = '\n'
    qt = '"'
    esc = '\\'
    tab = "    "
    percent = '%'
    s = "import sys, os%c%cdef main():%c%si = %d%c%seol = '%cn'%c%sqt = '%c'%c%sesc = '%c%c'%c%stab = %c    %c%c%spercent = '%c'%c%ss = %c%s%c%c%sif (sys.argv[0] != %cSully.py%c): i -= 1%c%snextname = %cSully_%c + str(i) + %c.py%c%c%ssys.stdout = open(nextname, 'w')%c%sprint s %c (eol, eol, eol, tab, i, eol, tab, esc, eol, tab, qt, eol, tab, esc, esc, eol, tab, qt, qt, eol, tab, percent, eol, tab, qt, s, qt, eol, tab, qt, qt, eol, tab, qt, qt, qt, qt, eol, tab, eol, tab, percent, eol, tab, eol, tab, qt, qt, eol, eol)%c%ssys.stdout = sys.__stdout__%c%sif (i > 0): os.system(%cpython %c + nextname)%c%cmain()"
    if (sys.argv[0] != "Sully.py"): i -= 1
    nextname = "Sully_" + str(i) + ".py"
    sys.stdout = open(nextname, 'w')
    print s % (eol, eol, eol, tab, i, eol, tab, esc, eol, tab, qt, eol, tab, esc, esc, eol, tab, qt, qt, eol, tab, percent, eol, tab, qt, s, qt, eol, tab, qt, qt, eol, tab, qt, qt, qt, qt, eol, tab, eol, tab, percent, eol, tab, eol, tab, qt, qt, eol, eol)
    sys.stdout = sys.__stdout__
    if (i > 0): os.system("python " + nextname)

main()
