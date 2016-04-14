# additional include paths necessary to compile the C++ programs
ifdef SystemRoot
    AM_CXXFLAGS = -DWIN32 -std=c++0x -I$(top_srcdir)/src -I$(top_srcdir)/dependencies/dc-core/src @AM_CXXFLAGS@
else
    AM_CXXFLAGS = -std=c++0x -I$(top_srcdir)/src -I$(top_srcdir)/dependencies/dc-core/src @AM_CXXFLAGS@
endif

###############################################################################
# THE PROGRAMS TO BUILD
###############################################################################

# the program to build (the names of the final binaries)
bin_PROGRAMS = dcConsole

# list of sources
dcConsole_SOURCES =    \
                        main.cpp

dcConsole_LDADD =  $(top_builddir)/src/dc-core/dcCore.a $(AM_LDFLAGS)