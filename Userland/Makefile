include Makefile.inc

SAMPLE_DATA=0001-sampleDataModule.bin

all: sampleCodeModule sampleDataModule hola blobsWar

sampleCodeModule:
	cd SampleCodeModule; make

sampleDataModule:
	printf "This is sample data." >> $(SAMPLE_DATA) && dd if=/dev/zero bs=1 count=1 >> $(SAMPLE_DATA)

hola:
	cd holaMundo; make

blobsWar:
	cd blobsWarModule; make

clean:
	cd SampleCodeModule; make clean
	rm -rf *.bin


.PHONY: sampleCodeModule all clean
