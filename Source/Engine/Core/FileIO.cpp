#include "FileIO.h"

namespace yogi
{
	std::string yogi::getFilePath()
	{
		return std::filesystem::current_path().string();
	}
}
