#ifndef asciicode
#define asciicode


const char ASCII_VALUE[]=
        {  	0,27,'1','2','3','4','5','6','7','8','9','0','\'','¿','\b',
	   	'\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',/*CTRL*/0,'a' ,'s',
           	'd','f','g','h','j','k','l','ñ','{','|',/*LSHIFT*/0,'}','z','x','c' ,'v',
           	'b','n','m',',','.','-',/*RSHIFT*/0,'*',/*LALT*/0,' '};

const char SHIFT_ASCII_VALUE[]=
        //    0  1  2   3   4   5   6   7   8   9   A   B   C   D   E   F
        {    0,27,'!','\"','#','$','%','&','/','(',')','=','?','¡','\b','\t',
             'Q','W','E','R','T','Y','U','I','O','P','¨','*','\n',/*CTRL*/0,'A','S',
             'D','F','G','H','J','K','L','Ñ','[','°',/*LSHIFT*/0,']','Z','X','C','V',
             'B','N','M',';',':','_',/*RSHIFT*/0,'*',/*LALT*/0,' '};

const char* KEYS_VALUES[] = {"", "ESC", "1", "2", "3", "4", "5", "6", "7", "8", "9", 			// 0 - 10
                             "0", "'", "¿", "BACKSPACE", "    ", "q", "w", "e", "r", "t",// 11 - 20
                             "y", "u", "i", "o", "p", "´", "+", "", "", "a",				// 21 - 30
                             "s", "d", "f", "g", "h", "j", "k", "l", "", "{", 			// 31 - 40
                             "|", "LSHIFT", "}", "z", "x", "c", "v", "b", "n", "m",  	// 41 - 50
                             ",", ".", "-", "", "*", "ALT", " ", "", "", "",				// 51 - 60
                             "", "", "", "", "", "", "", "", "", "", 					// 61 - 70
                             "7", "UARR", "9", "-", "LARR", "5", "RARR", "+", "1", "2",  // 71 - 80
                             "3", "0", ".", "", "", "", "", "", "", "",};


const char* SHIFT_KEYS_VALUES[] = {"", "ESC", "!", "\"", "#", "$", "%", "&", "/", "(", ")", 	// 0 - 10
                                   "=", "?", "¡", "BACKSPACE", "    ", "Q", "W", "E", "R", "T",// 11 - 20
                                   "Y", "U", "I", "O", "P", "¨", "*", "", "", "A",				// 21 - 30
                                   "S", "D", "F", "G", "H", "J", "K", "L", "", "[", 			// 31 - 40
                                   "°", "LSHIFT", "]", "Z", "X", "C", "V", "B", "N", "M",  		// 41 - 50
                                   ";", ":", "_", "", "*", "ALT", " ", "", "", "",				// 51 - 60
                                   "", "", "", "", "", "", "", "", "", "", 					// 61 - 70
                                   "7", "8", "9", "-", "4", "5", "6", "+", "1", "2", 			// 71 - 80
                                   "3", "0", ".", "", "", "", "", "", "", ""}; 				// 81 - 90


#endif
