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

std::vector<Vertex> GetVerticesFromObj(const std::string& objScene)
{
	std::ifstream file(objScene);
	if (!file)
		return std::vector<Vertex>();

	std::vector<FVector3> positions;
	std::vector<FVector3> normals;
	std::vector<FVector2> UVs;

	std::vector<Vertex> vertices;
	std::vector<u_int> indices;

	size_t lastStop = 0;

	std::string sCommand;
	while (!file.eof())
	{
		//read the first word of the string, use the >> operator (istream::operator>>) 
		file >> sCommand;
		//use conditional statements to process the different commands	
		if (sCommand == "#")
		{
			// Ignore Comment
		}
		else if (sCommand == "v")
		{
			//Vertex
			float x, y, z;
			file >> x >> y >> z;
			positions.push_back(FVector3{ x, y, -z });
		}
		else if (sCommand == "vt")
		{
			// Vertex TexCoord
			float u, v;
			file >> u >> v;
			UVs.push_back(FVector2{ u, 1 - v });
		}
		else if (sCommand == "vn")
		{
			// Vertex Normal
			float x, y, z;
			file >> x >> y >> z;
			normals.push_back(FVector3{ x, y, z });
		}
		else if (sCommand == "f")
		{
			//if a face is read:
			//construct the 3 vertices, add them to the vertex array
			//add three indices to the index array
			//add the material index as attibute to the attribute array
			//
			// Faces or triangles
			Vertex vertex{};
			size_t iPosition, iTexCoord, iNormal;
			for (size_t iFace = 0; iFace < 3; iFace++)
			{
				// OBJ format uses 1-based arrays
				file >> iPosition;
				vertex.position = positions[iPosition - 1];

				if ('/' == file.peek())//is next in buffer ==  '/' ?
				{
					file.ignore();//read and ignore one element ('/')

					if ('/' != file.peek())
					{
						// Optional texture coordinate
						file >> iTexCoord;
						//vertex.uv = UVs[iTexCoord - 1];
					}

					if ('/' == file.peek())
					{
						file.ignore();

						// Optional vertex normal
						file >> iNormal;
						vertex.normal = normals[iNormal - 1];
					}
				}

				vertices.push_back(vertex);
				indices.push_back(uint32_t(vertices.size()) - 1);
			}
		}

		//read till end of line and ignore all remaining chars
		file.ignore(1000, '\n');
	}
	file.close();
	return vertices;



}
