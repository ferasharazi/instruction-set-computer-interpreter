//▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥
// Instruction Set Interpreter
//▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*****
  This is a function that takes the value of an instruction,
  and then checks whether the instruction value is correct or not.
*****/
bool checkInstruction(string value);

/*****
  This is a function that takes the value of an instruction,
  whether BINARY or HEX, and then returns the correct
  description of the input instruction.
*****/
string instructionInterpreterBinaryHex(string value);

/*****
  This is a function that takes the instruction value
  as a STRING, and then prints the description to the screen.
*****/
string instructionInterpreterString(string ins);

/*****
  This is a function that prints all instructions.
*****/
void printAllInstructions();

//▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥
// Main

int main() {
	cout << "░░░░░░░░░░░░░░░░░░ Instruction Set Interpreter ░░░░░░░░░░░░░░░░░░ \n\n";
	cout << "◗ Part 1: Reading from a Text File \n"
		 << "◗ Part 2: Reading from the Screen (Binary or HEX) \n"
		 << "◗ Part 3: Reading from the Screen (Instruction String) \n"
		 << "◗ Part 4: View all instructions \n"
		 << "◗ Part 5: Exit the program \n\n"
		 << "▶ Please enter the part number [1-5]: ";

	int choice;
	cin >> choice;
	cout << endl;

	switch(choice) {
//▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥
// Part 1: Reading from a Text File

	case 1: {
		  ifstream inFile;
		  ofstream outFile;
		  inFile.open("input.txt");
		  outFile.open("output.txt");
		  string value;
		  
		  cout << "▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭ \n\n"
		  	   << "◗ Part 1: Reading from a Text File \n\n"
		       << "✔ The instructions were read from the file... \n"
		       << "✔ The instructions are printed on the screen and in the file... \n\n";

	// While loop using function eof (END-OF-FILE)
	// Read from file & print on screen and in file (line by line from Text File)
		  while(!inFile.eof()) {
		  	inFile >> value;

		  	cout << "~~~~~\n\n";
		  	cout << "Instruction value: " << value << endl;
		  	outFile << "Instruction value: " << value << endl;
		  	if(checkInstruction(value) == true) {
		  		cout << instructionInterpreterBinaryHex(value);
		  		outFile << instructionInterpreterBinaryHex(value);
		  	} else
		  		cout << "There is an error in the instruction value ✖\n";
		  }

		  inFile.close();
		  outFile.close();

		  break;
	  }

//▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥
// Part 2: Reading from the Screen (Binary or HEX)

	case 2: {
		  string value;

		  cout << "▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭ \n\n";
		  cout << "◗ Part 2: Reading from the Screen (Binary or HEX) \n\n";
		  cout << "▶ Enter instructions in BINARY or HEX format: ";
		  cin >> value;
		  cout << endl;

		  if(checkInstruction(value) == true)
			  cout << instructionInterpreterBinaryHex(value);
		  else
			  cout << "There is an error in the instruction value ✖\n";

		  break;
	  }

//▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥
// Part 3: Reading from the Screen (Instruction String)

	case 3: {
		  string ins;

		  cout << "▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭ \n\n";
		  cout << "◗ Part 3: Reading from the Screen (Instruction String) \n\n";
		  cout << "▶ Enter instructions in STRING format (UPPERCASE): ";
		  cin >> ins;
		  cout << endl;

		  cout << instructionInterpreterString(ins);

		  break;
	 }

//▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥
// Part 4: View all instructions

	case 4: {
		 printAllInstructions();

		 break;
	 }

//▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥
// Part 5: Exit the program

	case 5: {
		 cout << "\n\n\n \t Thank you, Dr.Hesham Alhumyani ♥" << endl;

		 break;
	 }

//▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥
	default:
		 cout << "Choose an error and try again ✖" << endl;
	}

	return 0;
}

//▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥▥
// Functions

bool checkInstruction(string value) {
// Check binary
    if (value.length() == 16 && value != "0000000000000000") {
        for (int i = 0; i < 16; i++) {
            if (value[i] == '1' || value[i] == '0') continue;
            else return false;
        } return true;
    }

// Check hex
    else if (value.length() == 4 && value != "0000") {
        for (int i = 0; i < 4; i++) {
            if ((value[i] >= '0' && value[i] <= '9') ||
                (value[i] >= 'A' && value[i] <= 'F'))
                continue;
            else return false;
        } return true;
    }

// Other
    else return false;
}

string instructionInterpreterBinaryHex(string value) {
// REGISTER REFERENCE INSTRUCTIONS
	if(value.substr(0,4) == "0111" || value.substr(0,1) == "7") {
		if(value == "0111100000000000" || value == "7800"){
			return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
				 	"❑ Symbol: CLA \n"
				 	"❑ Hex code: 7800 \n"
				 	"❑ Description: Clear AC \n\n");
		} else if(value == "0111010000000000" || value == "7400"){
			return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
				 	"❑ Symbol: CLE \n"
				 	"❑ Hex code: 7400 \n"
				 	"❑ Description: Clear E \n\n");
		} else if(value == "0111001000000000" || value == "7200"){
			return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
				 	"❑ Symbol: CMA \n"
				 	"❑ Hex code: 7200 \n"
				 	"❑ Description: Complement AC \n\n");
		} else if(value == "0111000100000000" || value == "7100"){
			return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
				 	"❑ Symbol: CME \n"
				 	"❑ Hex code: 7100 \n"
				 	"❑ Description: Complement E \n\n");
		} else if(value == "0111000010000000" || value == "7080"){
			return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
				 	"❑ Symbol: CIR \n"
				 	"❑ Hex code: 7080 \n"
				 	"❑ Description: Circulate right AC and E \n\n");
		} else if(value == "0111000001000000" || value == "7040"){
			return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
				 	"❑ Symbol: CIL \n"
				 	"❑ Hex code: 7040 \n"
				 	"❑ Description: Circulate left AC and E \n\n");
		} else if(value == "0111000000100000" || value == "7020"){
			return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
				 	"❑ Symbol: INC \n"
				 	"❑ Hex code: 7020 \n"
				 	"❑ Description: Increment AC \n\n");
		} else if(value == "0111000000010000" || value == "7010"){
			return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
					"❑ Symbol: SPA \n"
					"❑ Hex code: 7010 \n"
					"❑ Description: Skip next instr. if AC is positive \n\n");
		} else if(value == "0111000000001000" || value == "7008"){
			return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
				 	"❑ Symbol: SNA \n"
				 	"❑ Hex code: 7008 \n"
				 	"❑ Description: Skip next instr. if AC is negative \n\n");
		} else if(value == "0111000000000100" || value == "7004"){
			return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
				 	"❑ Symbol: SZA \n"
				 	"❑ Hex code: 7004 \n"
				 	"❑ Description: Skip next instr. if AC is zero \n\n");
		} else if(value == "0111000000000010" || value == "7002"){
			return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
				 	"❑ Symbol: SZE \n"
				 	"❑ Hex code: 7002 \n"
				 	"❑ Description: Skip next instr. if E is zero \n\n");
		} else if(value == "0111000000000001" || value == "7001"){
			return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
				 	"❑ Symbol: HLT \n"
				 	"❑ Hex code: 7001 \n"
				 	"❑ Description: Halt computer \n\n");
		} else
			return ("There is an error in the instruction value ✖\n");
	}

	
// I/O REFERENCE INSTRUCTIONS
	else if(value.substr(0,4) == "1111" || value.substr(0,1) == "F") {
		if(value == "1111100000000000" || value == "F800"){
			return ("❑ INPUT-OUTPUT INSTRUCTIONS \n"
				 	"❑ Symbol: INP \n"
				 	"❑ Hex code: F800 \n"
				 	"❑ Description: Input character to AC \n\n");
		} else if(value == "1111010000000000" || value == "F400"){
			return ("❑ INPUT-OUTPUT INSTRUCTIONS \n"
				 	"❑ Symbol: OUT \n"
				 	"❑ Hex code: F400 \n"
				 	"❑ Description: Output character from AC \n\n");
		} else if(value == "1111001000000000" || value == "F200"){
			return ("❑ INPUT-OUTPUT INSTRUCTIONS \n"
				 	"❑ Symbol: SKI \n"
				  	"❑ Hex code: F200 \n"
				 	"❑ Description: Skip on input flag \n\n");
		} else if(value == "1111000100000000" || value == "F100"){
			return ("❑ INPUT-OUTPUT INSTRUCTIONS \n"
				 	"❑ Symbol: SKO \n"
				 	"❑ Hex code: F100 \n"
				 	"❑ Description: Skip output flag \n\n");
		} else if(value == "1111000010000000" || value == "F080"){
			return ("❑ INPUT-OUTPUT INSTRUCTIONS \n"
				 	"❑ Symbol: ION \n"
				 	"❑ Hex code: F080 \n"
				 	"❑ Description: Interrupt on \n\n");
		} else if(value == "1111000001000000" || value == "F040"){
			return ("❑ INPUT-OUTPUT INSTRUCTIONS \n"
				 	"❑ Symbol: IOF \n"
				 	"❑ Hex code: F040 \n"
				 	"❑ Description: Interrupt off \n\n");
		} else
			return ("There is an error in the instruction value  ✖\n");
	}

	
// MEMORY REFERENCE INSTRUCTIONS
	else {
   // Direct
		if((value.length() == 4 && value.substr(0,1) <= "6") || (value.length() == 16 && value.substr(0,1) == "0")){
			if(value.substr(0,4) == "0000" || value.substr(0,1) == "0"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
						"❑ Symbol: AND \n"
					 	"❑ Hex code: 0XXX (Direct)\n"
					 	"❑ Description: AND memory word to AC \n\n");
			} else if(value.substr(0,4) == "0001" || value.substr(0,1) == "1"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
					  	"❑ Symbol: ADD \n"
					 	"❑ Hex code: 1XXX (Direct)\n"
					  	"❑ Description: Add memory word to AC \n\n");
			} else if(value.substr(0,4) == "0010" || value.substr(0,1) == "2"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
					    "❑ Symbol: LDA \n"
					 	"❑ Hex code: 2XXX (Direct)\n"
					 	"❑ Description: Load AC from memory \n\n");
			} else if(value.substr(0,4) == "0011" || value.substr(0,1) == "3"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
					 	"❑ Symbol: STA \n"
				   	 	"❑ Hex code: 3XXX (Direct)\n"
					 	"❑ Description: Store content of AC into memory \n\n");
			} else if(value.substr(0,4) == "0100" || value.substr(0,1) == "4"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
					 	"❑ Symbol: BUN \n"
					 	"❑ Hex code: 4XXX (Direct)\n"
					 	"❑ Description: Branch unconditionally \n\n");
			} else if(value.substr(0,4) == "0101" || value.substr(0,1) == "5"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
				   	 	"❑ Symbol: BSA \n"
					 	"❑ Hex code: 5XXX (Direct)\n"
					 	"❑ Description: Branch and save return address \n\n");
			} else if(value.substr(0,4) == "0110" || value.substr(0,1) == "6"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
					 	"❑ Symbol: ISZ \n"
					 	"❑ Hex code: 6XXX (Direct)\n"
					 	"❑ Description: Increment and skip if zero \n\n");
			}
   // Indirect
		} else {
			if(value.substr(0,4) == "1000" || value.substr(0,1) == "8"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
					 	"❑ Symbol: AND \n"
					 	"❑ Hex code: 8XXX (Indirect)\n"
					 	"❑ Description: AND memory word to AC \n\n");
			} else if(value.substr(0,4) == "1001" || value.substr(0,1) == "9"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
					 	"❑ Symbol: ADD \n"
					 	"❑ Hex code: 9XXX (Indirect)\n"
					 	"❑ Description: Add memory word to AC \n\n");
			} else if(value.substr(0,4) == "1010" || value.substr(0,1) == "A"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
					 	"❑ Symbol: LDA \n"
					 	"❑ Hex code: AXXX (Indirect)\n"
					 	"❑ Description: Load AC from memory \n\n");
			} else if(value.substr(0,4) == "1011" || value.substr(0,1) == "B"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
					 	"❑ Symbol: STA \n"
					 	"❑ Hex code: BXXX (Indirect)\n"
					 	"❑ Description: Store content of AC into memory \n\n");
			} else if(value.substr(0,4) == "1100" || value.substr(0,1) == "C"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
					 	"❑ Symbol: BUN \n"
					 	"❑ Hex code: CXXX (Indirect)\n"
					 	"❑ Description: Branch unconditionally \n\n");
			} else if(value.substr(0,4) == "1101" || value.substr(0,1) == "D"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
					 	"❑ Symbol: BSA \n"
					 	"❑ Hex code: DXXX (Indirect)\n"
					 	"❑ Description: Branch and save return address \n\n");
			} else if(value.substr(0,4) == "1110" || value.substr(0,1) == "E"){
				return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
				 	    "❑ Symbol: ISZ \n"
					 	"❑ Hex code: EXXX (Indirect)\n"
					 	"❑ Description: Increment and skip if zero \n\n");
			}
		}
	}
	return ("There is an error in the instruction value ✖\n");
}

string instructionInterpreterString(string ins) {
// REGISTER REFERENCE INSTRUCTIONS
	if(ins == "CLA"){
		return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: CLA \n"
			 	"❑ Hex code: 7800 \n"
			 	"❑ Description: Clear AC \n\n");
	} else if(ins == "CLE"){
		return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: CLE \n"
			 	"❑ Hex code: 7400 \n"
			 	"❑ Description: Clear E \n\n");
	} else if(ins == "CMA"){
		return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: CMA \n"
			 	"❑ Hex code: 7200 \n"
			 	"❑ Description: Complement AC \n\n");
	} else if(ins == "CME"){
		return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: CME \n"
			 	"❑ Hex code: 7100 \n"
			 	"❑ Description: Complement E \n\n");
	} else if(ins == "CIR"){
		return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: CIR \n"
			 	"❑ Hex code: 7080 \n"
			 	"❑ Description: Circulate right AC and E \n\n");
	} else if(ins == "CIL"){
		return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: CIL \n"
			 	"❑ Hex code: 7040 \n"
			 	"❑ Description: Circulate left AC and E \n\n");
	} else if(ins == "INC"){
		return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: INC \n"
			 	"❑ Hex code: 7020 \n"
			 	"❑ Description: Increment AC \n\n");
	} else if(ins == "SPA"){
		return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
				"❑ Symbol: SPA \n"
				"❑ Hex code: 7010 \n"
				"❑ Description: Skip next instr. if AC is positive \n\n");
	} else if(ins == "SNA"){
		return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: SNA \n"
			 	"❑ Hex code: 7008 \n"
			 	"❑ Description: Skip next instr. if AC is negative \n\n");
	} else if(ins == "SZA"){
		return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: SZA \n"
			 	"❑ Hex code: 7004 \n"
			 	"❑ Description: Skip next instr. if AC is zero \n\n");
	} else if(ins == "SZE"){
		return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: SZE \n"
			 	"❑ Hex code: 7002 \n"
			 	"❑ Description: Skip next instr. if E is zero \n\n");
	} else if(ins == "HLT"){
		return ("❑ REGISTER REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: HLT \n"
			 	"❑ Hex code: 7001 \n"
			 	"❑ Description: Halt computer \n\n");
	}

// I/O REFERENCE INSTRUCTIONS
	else if(ins == "INP"){
		return ("❑ INPUT-OUTPUT INSTRUCTIONS \n"
			 	"❑ Symbol: INP \n"
			 	"❑ Hex code: F800 \n"
			 	"❑ Description: Input character to AC \n\n");
	} else if(ins == "OUT"){
		return ("❑ INPUT-OUTPUT INSTRUCTIONS \n"
			 	"❑ Symbol: OUT \n"
			 	"❑ Hex code: F400 \n"
			 	"❑ Description: Output character from AC \n\n");
	} else if(ins == "SKI"){
		return ("❑ INPUT-OUTPUT INSTRUCTIONS \n"
			 	"❑ Symbol: SKI \n"
			  	"❑ Hex code: F200 \n"
			 	"❑ Description: Skip on input flag \n\n");
	} else if(ins == "SKO"){
		return ("❑ INPUT-OUTPUT INSTRUCTIONS \n"
			 	"❑ Symbol: SKO \n"
			 	"❑ Hex code: F100 \n"
			 	"❑ Description: Skip output flag \n\n");
	} else if(ins == "INO"){
		return ("❑ INPUT-OUTPUT INSTRUCTIONS \n"
			 	"❑ Symbol: ION \n"
			 	"❑ Hex code: F080 \n"
			 	"❑ Description: Interrupt on \n\n");
	} else if(ins == "IOF"){
		return ("❑ INPUT-OUTPUT INSTRUCTIONS \n"
			 	"❑ Symbol: IOF \n"
			 	"❑ Hex code: F040 \n"
			 	"❑ Description: Interrupt off \n\n");
	}

// MEMORY REFERENCE INSTRUCTIONS
	else if(ins == "AND"){
		return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
				"❑ Symbol: AND \n"
			 	"❑ Hex code: 0XXX (direct) or 8XXX (indirect) \n"
			 	"❑ Description: AND memory word to AC \n\n");
	} else if(ins == "ADD"){
		return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
			    "❑ Symbol: ADD \n"
			 	"❑ Hex code: 1XXX (direct) or 9XXX (indirect) \n"
				"❑ Description: Add memory word to AC \n\n");
	} else if(ins == "LDA"){
		return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: LDA \n"
			 	"❑ Hex code: 2XXX (direct) or AXXX (indirect) \n"
			 	"❑ Description: Load AC from memory \n\n");
	} else if(ins == "STA"){
		return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
				"❑ Symbol: STA \n"
			 	"❑ Hex code: 3XXX (direct) or BXXX (indirect) \n"
			 	"❑ Description: Store content of AC into memory \n\n");
	} else if(ins == "BUN"){
		return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: BUN \n"
			 	"❑ Hex code: 4XXX (direct) or CXXX (indirect) \n"
			 	"❑ Description: Branch unconditionally \n\n");
	} else if(ins == "BSA"){
		return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: BSA \n"
			 	"❑ Hex code: 5XXX (direct) or DXXX (indirect) \n"
			 	"❑ Description: Branch and save return address \n\n");
	} else if(ins == "ISZ"){
		return ("❑ MEMORY REFERENCE INSTRUCTIONS \n"
			 	"❑ Symbol: ISZ \n"
			 	"❑ Hex code: 6XXX (direct) or EXXX (indirect)\n"
			 	"❑ Description: Increment and skip if zero \n\n");
	} else
		return ("There is an error in the instruction value ✖\n");
}

void printAllInstructions() {
//Head table
	cout << "▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭\n"
		 << "Symbol\t\t Hex code\t\t Description\n"
		 << "▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭"
		 << endl;

//MEMORY REFERENCE INSTRUCTIONS
	cout << "❯ MEMORY REFERENCE INSTRUCTIONS\n"
		 << "AND\t\t 0or8\t\t\t AND memory word to AC\n"
		 << "ADD\t\t 1or9\t\t\t Add memory word to AC\n"
		 << "LDA\t\t 2orA\t\t\t Load AC from memory\n"
		 << "STA\t\t 3orB\t\t\t Store content of AC into memory\n"
		 << "BUN\t\t 4orc\t\t\t Branch unconditionally\n"
		 << "BSA\t\t 5orD\t\t\t Branch and save return address\n"
		 << "ISZ\t\t 6orE\t\t\t Increment and skip if zero\n"
		 << "▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭"
		 << endl;

//REGISTER REFERENCE INSTRUCTIONS
	cout << "❯ REGISTER REFERENCE INSTRUCTIONS\n"
		 << "CLA\t\t 7800\t\t\t Clear AC\t \n"
		 << "CLE\t\t 7400\t\t\t Clear E\n"
		 << "CMA\t\t 7200\t\t\t Complement AC\n"
		 << "CME\t\t 7100\t\t\t Complement E\n"
		 << "CIR\t\t 7080\t\t\t Circulate right AC and E\n"
		 << "CIL\t\t 7040\t\t\t Circulate left AC and E\n"
		 << "INC\t\t 7020\t\t\t Increment AC\n"
		 << "SPA\t\t 7010\t\t\t Skip next instr. if AC is positive\n"
		 << "SNA\t\t 7008\t\t\t Skip next instr. if AC is negative\n"
		 << "SZA\t\t 7004\t\t\t Skip next instr. if AC is zero\n"
		 << "SZE\t\t 7002\t\t\t Skip next instr. if E is zero\n"
		 << "HLT\t\t 7001\t\t\t Halt computer\n"
		 << "▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭"
		 << endl;

//INPUT-OUTPUT INSTRUCTIONS
	cout << "❯ INPUT-OUTPUT INSTRUCTIONS\n"
		 << "INP\t\t F800\t\t\t Input character to AC\n"
		 << "OUT\t\t F400\t\t\t Output character from AC\n"
		 << "SKI\t\t F200\t\t\t Skip on input flag\n"
		 << "SKO\t\t F100\t\t\t Skip output flag\n"
		 << "ION\t\t F080\t\t\t Interrupt on\n"
		 << "IOF\t\t F040\t\t\t Interrupt off\n"
		 << "▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭▭"
		 << endl;
}
