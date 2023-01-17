#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object3D
{

    // Create square with given bottom left corner, length and color
    

    /*Mesh* CreateRoad(
        const std::string& name,
        float length,
        glm::vec3 color,
        bool fill);*/

    std::vector <VertexFormat> CreateRoad(glm::vec3 color);

    std::vector <unsigned int> CreateRoad2(std::vector <VertexFormat> vertices);

    std::vector <VertexFormat> CreateS(glm::vec3 color);

    std::vector <unsigned int> CreateS2(std::vector <VertexFormat> vertices);

    std::vector <VertexFormat> CreateGrass(glm::vec3 color);

    std::vector <unsigned int> CreateGrass2(std::vector <VertexFormat> vertices);

    std::vector <glm::vec3> CreateTrees(glm::vec3 color);

    std::vector <glm::vec3> CreateLine(glm::vec3 color);

    std::vector <VertexFormat> CreateTree(glm::vec3 color, glm::vec3 color2);

    std::vector <unsigned int> CreateTree2(std::vector <VertexFormat> vertices);

}

