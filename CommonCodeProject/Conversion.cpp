#include "Conversion.h"

#include <direct.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/stream.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/istreamwrapper.h"

#include "Conversion.h"

void JsonToObj(const std::string& jsonFile, const std::string& objFile)
{
	std::ifstream iJSONfile(jsonFile);
	std::ofstream oOBJFile{ objFile };
	if (!iJSONfile)
	{
		std::cerr << "Could not open file" << std::endl;
		return;
	}

	int vertexCount = 0;
	oOBJFile << "mtllib " << "minecraftscene.mtl" << std::endl;

	rapidjson::IStreamWrapper jsonWrapper{ iJSONfile };
	rapidjson::Document jsonDocument{};
	jsonDocument.ParseStream(jsonWrapper);

	for (auto& layers : jsonDocument.GetArray())
	{
		std::string layer = layers["layer"].GetString();
		auto& valPositions = layers["positions"];
		for (auto iter = valPositions.Begin(); iter != valPositions.End(); ++iter)
		{
			const rapidjson::Value& pos = *iter;
			float position[3] = {
				static_cast<float>(pos[0].GetInt()),
				static_cast<float>(pos[1].GetInt()),
				static_cast<float>(pos[2].GetInt())
			};
			AddCube(oOBJFile, position, vertexCount, layer);
		}

	}



}

void AddCube(std::ofstream& fs, float* position, int& vertexCount, const std::string& layer)
{
	fs << "usemtl " << layer << " \n";
	fs << "o " << "block " << std::to_string(vertexCount / 8) << "\n";

	fs << "v " << 0.0f + position[0] << " " << 0.0f + position[2] << " " << 0.0f + position[1] << " \n";
	fs << "v " << 0.0f + position[0] << " " << 0.0f + position[2] << " " << 1.0f + position[1] << " \n";
	fs << "v " << 0.0f + position[0] << " " << 1.0f + position[2] << " " << 0.0f + position[1] << " \n";
	fs << "v " << 0.0f + position[0] << " " << 1.0f + position[2] << " " << 1.0f + position[1] << " \n";
	fs << "v " << 1.0f + position[0] << " " << 0.0f + position[2] << " " << 0.0f + position[1] << " \n";
	fs << "v " << 1.0f + position[0] << " " << 0.0f + position[2] << " " << 1.0f + position[1] << " \n";
	fs << "v " << 1.0f + position[0] << " " << 1.0f + position[2] << " " << 0.0f + position[1] << " \n";
	fs << "v " << 1.0f + position[0] << " " << 1.0f + position[2] << " " << 1.0f + position[1] << " \n";

	fs << "vn " << 0.0f << " " << 0.0f << " " << 1.0f << "\n";
	fs << "vn " << 0.0f << " " << 0.0f << " " << -1.0f << "\n";
	fs << "vn " << 0.0f << " " << 1.0f << " " << 0.0f << "\n";
	fs << "vn " << 0.0f << " " << -1.0f << " " << 0.0f << "\n";
	fs << "vn " << 1.0f << " " << 0.0f << " " << 0.0f << "\n";
	fs << "vn " << -1.0f << " " << 0.0f << " " << 0.0f << "\n";

	fs << "f " << 1 + vertexCount << "/" << 2 + vertexCount << " " << 7 + vertexCount << "/" << 2 + vertexCount << " " << 5 + vertexCount << "/" << 2 + vertexCount << "\n";
	fs << "f " << 1 + vertexCount << "/" << 2 + vertexCount << " " << 3 + vertexCount << "/" << 2 + vertexCount << " " << 7 + vertexCount << "/" << 2 + vertexCount << "\n";
	fs << "f " << 1 + vertexCount << "/" << 6 + vertexCount << " " << 4 + vertexCount << "/" << 6 + vertexCount << " " << 3 + vertexCount << "/" << 6 + vertexCount << "\n";
	fs << "f " << 1 + vertexCount << "/" << 6 + vertexCount << " " << 2 + vertexCount << "/" << 6 + vertexCount << " " << 4 + vertexCount << "/" << 6 + vertexCount << "\n";
	fs << "f " << 3 + vertexCount << "/" << 3 + vertexCount << " " << 8 + vertexCount << "/" << 3 + vertexCount << " " << 7 + vertexCount << "/" << 3 + vertexCount << "\n";
	fs << "f " << 3 + vertexCount << "/" << 3 + vertexCount << " " << 4 + vertexCount << "/" << 3 + vertexCount << " " << 8 + vertexCount << "/" << 3 + vertexCount << "\n";
	fs << "f " << 5 + vertexCount << "/" << 5 + vertexCount << " " << 7 + vertexCount << "/" << 5 + vertexCount << " " << 8 + vertexCount << "/" << 5 + vertexCount << "\n";
	fs << "f " << 5 + vertexCount << "/" << 5 + vertexCount << " " << 8 + vertexCount << "/" << 5 + vertexCount << " " << 6 + vertexCount << "/" << 5 + vertexCount << "\n";
	fs << "f " << 1 + vertexCount << "/" << 4 + vertexCount << " " << 5 + vertexCount << "/" << 4 + vertexCount << " " << 6 + vertexCount << "/" << 4 + vertexCount << "\n";
	fs << "f " << 1 + vertexCount << "/" << 4 + vertexCount << " " << 6 + vertexCount << "/" << 4 + vertexCount << " " << 2 + vertexCount << "/" << 4 + vertexCount << "\n";
	fs << "f " << 2 + vertexCount << "/" << 1 + vertexCount << " " << 6 + vertexCount << "/" << 1 + vertexCount << " " << 8 + vertexCount << "/" << 1 + vertexCount << "\n";
	fs << "f " << 2 + vertexCount << "/" << 1 + vertexCount << " " << 8 + vertexCount << "/" << 1 + vertexCount << " " << 4 + vertexCount << "/" << 1 + vertexCount << "\n";
	vertexCount += 8;

	fs << std::endl;
}