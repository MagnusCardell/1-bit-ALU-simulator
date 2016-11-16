#include <iostream>
using namespace std;

#include "blogic.h" 	//The binary logic functions
/** Function: alu
	Purpose: simulate a 1-bit ALU computation
	arguments: 8 int-(f0, f1, inva, ena, enb, c_i, a, b)
	return: the output and carry out
*/
int alu(int f0, int f1, int inva, int ena, int enb, int c_i, int a, int b) {

	//SUM
	int x = bor(bor(band(band(bxor(inva, band(a, ena)), band(b, enb)), band(bnot(f0), bnot(f1))),
			band(bor(bxor(inva, band(a, ena)), band(b, enb)), band(bnot(f0), f1))), 
		bor(band(bnot(band(b, enb)), band(f0, bnot(f1))), 
			band(bxor(c_i, bxor(bxor(inva, band(a, ena)), band(b, enb))), band(f0, f1))));

	//CARRY OUT VALUE
	int y = bor(band(bxor(inva, band(a, ena)), band(b, enb), band(f0, f1)), band(band(f0, f1), 
		bxor(bxor(inva, band(a, ena)), band(b, enb)), c_i));

	//Create bitmap for return
	x = x <<1;
	return bor(x,y);
}

/** Function: print_call
	Purpose: print the return data from function 'alu' with some formatting
	arguments: 8 int-(f0, f1, inva, ena, enb, c_i, a, b)
	return: nothing
*/
void print_call(int f0, int f1, int inva, int ena, int enb, int c_i, int a, int b) {

	cout<<"alu("<<f0<<", "<<f1<<", "<<inva<<", "<<ena<<", "<<enb<<", "<<c_i<<", "<<a<<", "<<b
		<<") --> "<< alu(f0, f1, inva, ena, enb, c_i, a, b)<<endl;

}
/** Function: print_section
	Purpose: print label, then call print_call with all possible combinations
			for the values A, B, and Carry_In
	arguments: 5 int-(f0, f1, inva, ena, enb)
	return: nothing
*/
void print_section(int f0, int f1, int inva, int ena, int enb) {
	cout<<"F0="<<f0<<", F1="<<f1<<", INVA="<<inva<<", ENA="<<ena<<", ENB="<<enb<<endl;
	print_call(f0, f1, inva, ena, enb, 0, 0, 0);
	print_call(f0, f1, inva, ena, enb, 0, 0, 1);
	print_call(f0, f1, inva, ena, enb, 0, 1, 0);
	print_call(f0, f1, inva, ena, enb, 0, 1, 1);
	print_call(f0, f1, inva, ena, enb, 1, 0, 0);
	print_call(f0, f1, inva, ena, enb, 1, 0, 1);
	print_call(f0, f1, inva, ena, enb, 1, 1, 0);
	print_call(f0, f1, inva, ena, enb, 1, 1, 1);
	cout<<endl;
}
// main function prints all 32 combinations of control values
int main() {z
	print_section(0, 0, 0, 0, 0);
	print_section(0, 0, 0, 0, 1);
	print_section(0, 0, 0, 1, 0);
	print_section(0, 0, 0, 1, 1);
	print_section(0, 0, 1, 0, 0);
	print_section(0, 0, 1, 0, 1);
	print_section(0, 0, 1, 1, 0);
	print_section(0, 0, 1, 1, 1);
	print_section(0, 1, 0, 0, 0);
	print_section(0, 1, 0, 0, 1);
	print_section(0, 1, 0, 1, 0);
	print_section(0, 1, 0, 1, 1);
	print_section(0, 1, 1, 0, 0);
	print_section(0, 1, 1, 0, 1);
	print_section(0, 1, 1, 1, 0);
	print_section(0, 1, 1, 1, 1);
	print_section(1, 0, 0, 0, 0);
	print_section(1, 0, 0, 0, 1);
	print_section(1, 0, 0, 1, 0);
	print_section(1, 0, 0, 1, 1);
	print_section(1, 0, 1, 0, 0);
	print_section(1, 0, 1, 0, 1);
	print_section(1, 0, 1, 1, 0);
	print_section(1, 0, 1, 1, 1);
	print_section(1, 1, 0, 0, 0);
	print_section(1, 1, 0, 0, 1);
	print_section(1, 1, 0, 1, 0);
	print_section(1, 1, 0, 1, 1);
	print_section(1, 1, 1, 0, 0);
	print_section(1, 1, 1, 0, 1);
	print_section(1, 1, 1, 1, 0);
	print_section(1, 1, 1, 1, 1);
}