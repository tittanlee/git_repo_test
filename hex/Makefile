RM              = del
CC              = cl.exe /nologo
LINK            = link.exe -nologo
CCLIBS          = user32.lib advapi32.lib
LIBCURSES       = pdcurses.lib
CURSESDLL       = pdcurses.dll
PDCURSES_SRCDIR = /I../../
CFLAGS          = -O1
BUILD         = $(CC) $(PDCURSES_SRCDIR) -c $(CFLAGS) $(DLLOPT) $(WIDEOPT) $(UTF8OPT) $(INFOPT)
OBJECTS         = main.obj

hexdir          = D:\project\Utility\PDCurses\demos\hex


HEXOBJS = main.obj hexwin.obj
HEXEXEC = obj.exe


{$(hexdir)\}.c{}.obj::
    $(BUILD) $<


all: $(HEXOBJS) $(HEXEXEC)
#
# main: $(OBJECTS)
#     $(BUILD) /Fe$@ $**
#
obj.exe: $(HEXOBJS)
	$(LINK) $(LDFLAGS) *.obj $(LIBCURSES) $(CCLIBS)

.phony:
clean:
	-$(RM) *.obj
	-$(RM) *.exe
	-$(RM) *.dll
	-$(RM) *.exp
	-$(RM) *.res

