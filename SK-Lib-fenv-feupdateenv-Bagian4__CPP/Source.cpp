#include <iostream>
#include <cmath>
#include <cfenv>
#include <conio.h>

#pragma fenv_access (on)

/*	Source by Programiz
	Modified For Learn by Rizky Khapidsyah
	I.D.E : Visual Studio 2019
	Compiler : MVC (Microsoft)
*/

using namespace std;

void print_exceptions() {
	cout << "Raised exceptions: ";

	if (fetestexcept(FE_ALL_EXCEPT)) {
		if (fetestexcept(FE_DIVBYZERO)) {
			cout << "FE_DIVBYZERO ";
		}
			
		if (fetestexcept(FE_INEXACT)) {
			cout << "FE_INEXACT ";
		}
			
		if (fetestexcept(FE_INVALID)) {
			cout << "FE_INVALID ";
		}
			
		if (fetestexcept(FE_OVERFLOW)) {
			cout << "FE_OVERFLOW ";
		}
			
		if (fetestexcept(FE_UNDERFLOW)) {
			cout << "FE_UNDERFLOW ";
		}
	} else {
		cout << "None";
	}
	
	cout << endl;
}

int main() {
	fenv_t envp;

	/* raise certain exceptions */
	feraiseexcept(FE_INVALID | FE_DIVBYZERO);
	print_exceptions();

	/* saves and clears current exceptions */
	feupdateenv(&envp);
	print_exceptions();

	/* restores saved exceptions */
	feupdateenv(&envp);
	print_exceptions();

	_getch();
	return 0;
}