TARGET   = out
OBJS     = $(wildcard *.cpp) $(wildcard *.c) #$(wildcard *.o)

INCDIR   =
CFLAGS   = -O2 -G0 -Wall -g
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti -g
ASFLAGS  = $(CFLAGS)

LIBDIR   =
LDFLAGS  =
LIBS     = -lc -g -lpspgum -lpspgu -lpng -lz -lstdc++ -lm -lpsppower

#BUILD_PRX       = 1
#EXTRA_TARGETS   = EBOOT.PBP

#PSP_EBOOT_TITLE = Hello 3D World
#PSP_EBOOT_ICON  = ICON0.png
#PSP_EBOOT_PIC1  = PIC1.png
#PSP_EBOOT_SND0  = #SND0.at3

PSPSDK   = $(shell psp-config --pspsdk-path)

include $(PSPSDK)/lib/build.mak
