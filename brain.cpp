#include <iostream>
using namespace std;

#include "blogic.h" 	//The binary logic functions


int alu(int f0, int f1, int inva, int ena, int enb, int c_i, int a, int b) {

	//Full ADDER
	//first and gate
	band(bxor(inva, band(a, ena)), band(b, enb), band(f0, f1));
	//first xor gate
	bxor(bxor(inva, band(a, ena)), band(b, enb));
	//second and gate
	band(band(f0, f1), bxor(bxor(inva, band(a, ena)), band(b, enb)), c_i);
	//CARRY OUT VALUE
	bor(band(bxor(inva, band(a, ena)), band(b, enb), band(f0, f1)), band(band(f0, f1), 
		bxor(bxor(inva, band(a, ena)), band(b, enb)), c_i));
	//Second xor gate
	bxor(c_i, bxor(bxor(inva, band(a, ena)), band(b, enb)));

	//Sum and gate
	band(bxor(c_i, bxor(bxor(inva, band(a, ena)), band(b, enb))), band(f0, f1));

	//half of final xor
	bxor(band(band(bxor(inva, band(a, ena)), band(b, enb)), band(bnot(f0), bnot(f1))),
		band(bor(bxor(inva, band(a, ena)), band(b, enb)), band(bnot(f0), f1))); 
	//other half of xor
	bxor(band(bnot(band(b, enb)), band(f0, bnot(f1))), 
		band(bxor(c_i, bxor(bxor(inva, band(a, ena)), band(b, enb))), band(f0, f1)));

	//TOTAL
	bxor(bxor(band(band(bxor(inva, band(a, ena)), band(b, enb)), band(bnot(f0), bnot(f1))),
			band(bor(bxor(inva, band(a, ena)), band(b, enb)), band(bnot(f0), f1))), 
		bxor(band(bnot(band(b, enb)), band(f0, bnot(f1))), 
			band(bxor(c_i, bxor(bxor(inva, band(a, ena)), band(b, enb))), band(f0, f1))));

	//CARRY OUT VALUE
	bor(band(bxor(inva, band(a, ena)), band(b, enb), band(f0, f1)), band(band(f0, f1), 
		bxor(bxor(inva, band(a, ena)), band(b, enb)), c_i));

	//lOGICAL uNIT
	//A and B
	band(band(bxor(inva, band(a, ena)), band(b, enb)), band(bnot(f0), bnot(f1)));
	//A or B
	band(bor(bxor(inva, band(a, ena)), band(b, enb)), band(bnot(f0), f1));
	//not B
	band(bnot(band(b, enb)), band(f0, bnot(f1)));


	//A-unit
	bxor(inva, band(a, ena));
	//B-unit
	band(b, enb);


	//decoder
	band(bnot(f0), bnot(f1));
	band(bnot(f0), f1);
	band(f0, bnot(f1));
	band(f0, f1);
}


int main() {
	cout<<alu(0,0,0,1,1,0,1,0)<<endl;

}