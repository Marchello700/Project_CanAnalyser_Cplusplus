#include "CanData.h"
#include <string>

#ifndef canParserH
#define canParserH

namespace CanParser {
	TCanDataFrame * CanScannerParser(const std::string line);
}

#endif //canParserH
