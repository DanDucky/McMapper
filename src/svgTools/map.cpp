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
	this->settings.fileName = checkFileName(this->settings.fileName);
}

void McMap::loadMcWorld (std::string pathToFolder) {
	return;
}

void McMap::writeToFile () {

}

// creates a new file name if the file already exists in the selected directory
string McMap::checkFileName (string currentFileName) {
	string directoryPath = "";
	string fileName;
	if (currentFileName.find("/") != std::string::npos) {
		directoryPath = currentFileName.substr(0, currentFileName.find_last_of("/") + 1);
		fileName = currentFileName.substr(currentFileName.find_last_of("/") + 1, currentFileName.length() - currentFileName.find_last_of("/"));
	} else {
		directoryPath = ".";
		fileName = currentFileName;
	}
	int numberOfDuplicates = 0;
	for (const auto & entry : fs::directory_iterator(directoryPath)) {
		if (!entry.is_directory() && entry.path().string().find(fileName) != string::npos && entry.path().string().find(".svg") != string::npos) {
			numberOfDuplicates++;
		}
	}
	if (numberOfDuplicates > 0) {
		currentFileName.append(" (" + to_string(numberOfDuplicates) + ")");
	}
	return currentFileName;
}
