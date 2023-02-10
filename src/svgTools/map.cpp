#include "map.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;
using namespace mcmap;
namespace fs = std::filesystem;

McMap::McMap (McMapSettings settings) {
	this->settings = settings;
	if (settings.fileName.find(".svg") != std::string::npos) {
		this->settings.fileName = this->settings.fileName.substr(0, settings.fileName.find(".svg"));
	}
	checkFileName(this->settings.fileName);
}

void McMap::loadMcWorld (std::string pathToFolder) {
	return;
}

void McMap::writeToFile () {

}

string McMap::checkFileName (string currentFileName) {
	string directoryPath = "";
	if (currentFileName.find("/") != std::string::npos) {
		directoryPath = currentFileName.substr(0, currentFileName.find_last_of("/") + 1);
	} else {
		directoryPath = ".";
	}
	for (const auto & entry : fs::directory_iterator(directoryPath)) {
		std::cout << entry.path() << std::endl;
	}
	return "meow";
}
