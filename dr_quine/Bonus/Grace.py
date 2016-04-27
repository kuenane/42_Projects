'''
J'aime les poneys
'''

import sys

def percent():
    return '%'

def retx(x):
    return x

def FT(x):
    eol = '\n'
    qt = '"'
    esc = '\\'
    tab = "    "
    str = "'''%cJ'aime les poneys%c'''%c%cimport sys%c%cdef percent():%c%sreturn '%c'%c%cdef retx(x):%c%sreturn x%c%cdef FT(x):%c%seol = '%cn'%c%sqt = '%c'%c%sesc = '%c%c'%c%stab = %c    %c%c%sstr = %c%s%c%c%ssys.stdout = open('Grace_kid.py', 'w')%c%sprint str %c (eol, eol, eol, eol, eol, eol, eol, tab, percent(), eol, eol, eol, tab, eol, eol, eol, tab, esc, eol, tab, qt, eol, tab, esc, esc, eol, tab, qt, qt, eol, tab, qt, str, qt, eol, tab, eol, tab, percent(), eol, tab, eol, eol)%c%sretx(x)%c%cFT(0)"
    sys.stdout = open('Grace_kid.py', 'w')
    print str % (eol, eol, eol, eol, eol, eol, eol, tab, percent(), eol, eol, eol, tab, eol, eol, eol, tab, esc, eol, tab, qt, eol, tab, esc, esc, eol, tab, qt, qt, eol, tab, qt, str, qt, eol, tab, eol, tab, percent(), eol, tab, eol, eol)
    retx(x)

FT(0)
