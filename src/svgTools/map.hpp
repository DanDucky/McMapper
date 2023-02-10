#ifndef SRC_SVGTOOLS_MAP_HPP_
#define SRC_SVGTOOLS_MAP_HPP_

#include <string>

namespace mcmap {
	struct McMapSettings {
		int sizeX;
		int sizeZ;
		int layerHeight;
		bool includeRoof;
		std::string fileName = "McMap";
	};

	class McMap {
	public:
		McMap (McMapSettings settings);
		void loadMcWorld(std::string pathToFolder);
		void writeToFile();
	private:
		McMapSettings settings;
		std::string checkFileName (std::string currentFileName);
	};
}

#endif /* SRC_SVGTOOLS_MAP_HPP_ */
