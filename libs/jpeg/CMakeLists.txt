cmake_minimum_required(VERSION 3.31)

project(jpeg C)

set(
    JPEG_HEADERS
    jpeglib.h
    jconfig.h
    jmorecfg.h
    jerror.h
    jinclude.h
    jpegint.h
    jdct.h
    jmemsys.h
    jversion.h
)

set(
    JPEG_SOURCES
    jcapimin.c
    jcapistd.c
    jdapimin.c
    jdapistd.c
    jcomapi.c
    jcparam.c
    jctrans.c
    jdtrans.c
    jcinit.c
    jcmaster.c
    jcmainct.c
    jcprepct.c
    jccoefct.c
    jccolor.c
    jcsample.c
    jcdctmgr.c
    jfdctint.c
    jfdctfst.c
    jfdctflt.c
    jchuff.c
    jcarith.c
    jcmarker.c
    jdatadst.c
    jdmaster.c
    jdinput.c
    jdmainct.c
    jdcoefct.c
    jdpostct.c
    jdmarker.c
    jdhuff.c
    jdarith.c
    jddctmgr.c
    jidctint.c
    jidctfst.c
    jidctflt.c
    jdsample.c
    jdcolor.c
    jdmerge.c
    jquant1.c
    jquant2.c
    jdatasrc.c
    jaricom.c
    jerror.c
    jmemmgr.c
    jutils.c
    jmemnobs.c	#"No backing store": assumes adequate virtual memory exists.
    # jmemansi.c	#Makes temporary files with ANSI-standard routine tmpfile().
    # jmemname.c	#Makes temporary files with program-generated file names.
    # jmemdos.c	#Custom implementation for MS-DOS (16-bit environment only): can use extended and expanded memory as well as temp files.
    # jmemmac.c	#Custom implementation for Apple Macintosh.
)

add_library(jpeg STATIC ${JPEG_HEADERS} ${JPEG_SOURCES})

set_target_properties(jpeg PROPERTIES PUBLIC_HEADER "${JPEG_HEADERS}")

install(
    TARGETS jpeg
    PUBLIC_HEADER DESTINATION include/jpeg
)