#pragma once
#include "headliner.hpp"
int main()
{
	Roman_rulers
		Gaius_Julius_Caesar{ "Gaius Julius Caesar", -100, -44, },
		Gnaeus_Pompeius_Magnus{ "Gnaeus Pompeius Magnus", -106, -48 },
		Caesar_Augustus{ "Caesar Augustus", -63, 14 },
		Marcus_Antonius{ "Marcus Antonius", -83, -30 },
		Tiberius_Caesar_Augustus{ "Tiberius Caesar Augustus", -42, 37 },
		Caligula{ "Caligula", 12, 41 };


	lived_at_the_same_time(Gaius_Julius_Caesar, Gnaeus_Pompeius_Magnus);

	lived_at_the_same_time(Gaius_Julius_Caesar, Caligula);

	Tiberius_Caesar_Augustus.print_years_of_life();

	Marcus_Antonius.print_years_of_life();

}