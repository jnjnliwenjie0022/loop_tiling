#CROSS	 = riscv64-elf-
CC       = $(CROSS)g++
AS       = $(CROSS)as

CFILES = $(wildcard *.c)
SFILES  =   
#SFILES  = start.S  
OBJS=$(subst .c,.o,$(CFILES)) $(subst .S,.o,$(SFILES))

LOCALDIR=.

#LDFLAG = -Xlinker -Tae350.ld
#ASFLAG  = -I. -I${LOCALDIR}/include -I${LOCALDIR}/../include 
#LIBFLAG = -static -nostartfiles
#OPTFLAG = -O3 -g3 -fno-inline -mrestrict-argument -mipa-escape-analysis
OPTFLAG = -O3 -g3
#ACEFLAG = -w -Wa,-mace=${LOCALDIR}/lib/libacetool.so -mace -mace-s2s="${LOCALDIR}/include/acr.yaml;${LOCALDIR}/include/aceWrapper.yaml"
FLAGS    = $(LDFLAG) $(ASFLAG) $(LIBFLAG) $(OPTFLAG) $(MFLAG) $(ARG_OPTFLAG) $(ACEFLAG) -DTIME 
EXE=test.bin

ace_rom: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAG) $(LIBFLAG) $(OBJS) -o $@

%.o:%.c
	$(CC) $(ASFLAG) $(ACEFLAG) ${OPTFLAG} ${LIBFLAG} $^ -c -o $@

%.o:%.S
	$(CC) $(ASFLAG) $^ -c -o $@

ace_clean:
	rm -rf lib rtl include model SystemC *.map 

cleanall: ace_clean clean cleanrom


