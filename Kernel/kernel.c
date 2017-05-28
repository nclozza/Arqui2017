#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
#include <interruptions.h>
#include <asciicode.h>
extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss;
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;

static const uint64_t PageSize = 0x1000;
extern unsigned int readk();

static void * const sampleCodeModuleAddress = (void*)0x400000;
static void * const sampleDataModuleAddress = (void*)0x500000;

typedef int (*EntryPoint)();


void clearBSS(void * bssAddress, uint64_t bssSize)
{
	memset(bssAddress, 0, bssSize);
}

void * getStackBase()
{
	return (void*)(
		(uint64_t)&endOfKernel
		+ PageSize * 8				//The size of the stack itself, 32KiB
		- sizeof(uint64_t)			//Begin at the top of the stack
	);
}

void * initializeKernelBinary()
{
	char buffer[10];

	ncPrint("[x64BareBones]");
	ncNewline();

	ncPrint("CPU Vendor:");
	ncPrint(cpuVendor(buffer));
	ncNewline();

	ncPrint("[Loading modules]");
	ncNewline();
	void * moduleAddresses[] = {
		sampleCodeModuleAddress,
		sampleDataModuleAddress
	};

	loadModules(&endOfKernelBinary, moduleAddresses);
	ncPrint("[Done]");
	ncNewline();
	ncNewline();

	ncPrint("[Initializing kernel's binary]");
	ncNewline();

	clearBSS(&bss, &endOfKernel - &bss);

	ncPrint("  text: 0x");
	ncPrintHex((uint64_t)&text);
	ncNewline();
	ncPrint("  rodata: 0x");
	ncPrintHex((uint64_t)&rodata);
	ncNewline();
	ncPrint("  data: 0x");
	ncPrintHex((uint64_t)&data);
	ncNewline();
	ncPrint("  bss: 0x");
	ncPrintHex((uint64_t)&bss);
	ncNewline();

	ncPrint("[Done]");
	ncNewline();
	ncNewline();
	return getStackBase();
}

char *video = (char *) 0xB8000;

void tickHandler() {
	// video[i++] = i;	
}

void keyboardHandler() {
	int a= readk();
	a=ASCII_VALUE[a];
	ncPrintChar(a);
}

void sti();
void irq0Handler();
void irq1Handler();
void setPicMaster(uint16_t);

typedef void (*handler_t)(void);

handler_t handlers[] = {tickHandler,
												keyboardHandler
											 };

void irqDispatcher(int irq) {
	handlers[irq]();
}

int main()
{	
	interruptSetHandler(0x20, (uint64_t) irq0Handler);
	interruptSetHandler(0x21, (uint64_t) irq1Handler);
	
	setPicMaster(0xFC);
	
	sti();

	while(1) {
		int k = 0;
		while(k < 1000*1000*20) {
			k++;
		}
		
	}


	/* Aca voy a la parte de UserLand */
	//ncPrintHex(((EntryPoint)sampleCodeModuleAddress)());

	return 0;
}
