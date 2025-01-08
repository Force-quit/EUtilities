#include "../src/EUtilities.h"
#include "../src/EUtilities-Windows.h"

int main()
{
	eutilities::sleepFor(1000);
	eutilities::fullKeyPress(eutilities::Key::WINDOWS);
}
