#include "Source.h"
#include "APIEnvir.h"
#include "ACAPinc.h"

namespace GIS {
	static const GS::HashTable<GS::UniString, GS::UShort> JUDETE_UAT{
		{"ALBA",10},
		{"ARAD",29},
		{"ARGES",38},
		{"BACAU",47},
		{"BIHOR",56},
		{"BISTRITA",65},
		{"BOTOSANI",74},
		{"BRAILA",92},
		{"BRASOV",83},
		{"BUCURESTI",403},
		{"BUZAU",109},
		{"CALARASI",519},
		{"CARAS-SEVERIN",118},
		{"CLUJ",127},
		{"CONSTANTA",136},
		{"COVASNA",145},
		{"DAMBOVITA",154},
		{"DOLJ",163},
		{"GALATI",172},
		{"GIURIGIU",528},
		{"GORJ",181},
		{"HARGHITA",190},
		{"HUNEDOARA",207},
		{"IALOMITA",216},
		{"IASI",225},
		{"ILFOV",234},
		{"MARAMURES",243},
		{"MEHEDINTI",252},
		{"MURES",261},
		{"NEAMT",270},
		{"OLT",289},
		{"PRAHOVA",298},
		{"SALAJ",314},
		{"SATU-MARE",305},
		{"SIBIU",323},
		{"SUCEAVA",332},
		{"TELEORMAN",341},
		{"TIMIS",350},
		{"TULCEA",369},
		{"VALCEA",387},
		{"VASLUI",378},
		{"VRANCEA",396} };

	Entry::Entry()
	{
		DBPrintf("Main entry point");
	}

	Entry::~Entry()
	{
	}
}