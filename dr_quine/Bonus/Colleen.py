'''
this is an awesome comment
'''

def ret0():
    return 0

def main():
    '''
    but this is an useless comment
    '''
    eol = '\n'
    qt = '"'
    esc = '\\'
    tab = "    "
    percent = "%"
    str = "'''%cthis is an awesome comment%c'''%c%cdef ret0():%c%sreturn 0%c%cdef main():%c%s'''%c%sbut this is an useless comment%c%s'''%c%seol = '%cn'%c%sqt = '%c'%c%sesc = '%c%c'%c%stab = %c    %c%c%spercent = %c%c%c%c%sstr = %c%s%c%c%sprint str %c (eol, eol, eol, eol, eol, tab, eol, eol, eol, tab, eol, tab, eol, tab, eol, tab, esc, eol, tab, qt, eol, tab, esc, esc, eol, tab, qt, qt, eol, tab, qt, percent, qt, eol, tab, qt, str, qt, eol, tab, percent, eol, tab, eol, eol)%c%sret0()%c%cmain()"
    print str % (eol, eol, eol, eol, eol, tab, eol, eol, eol, tab, eol, tab, eol, tab, eol, tab, esc, eol, tab, qt, eol, tab, esc, esc, eol, tab, qt, qt, eol, tab, qt, percent, qt, eol, tab, qt, str, qt, eol, tab, percent, eol, tab, eol, eol)
    ret0()

main()
