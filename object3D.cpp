#include "object3D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


std::vector <VertexFormat> object3D::CreateRoad(glm::vec3 color) {
    std::vector<VertexFormat> vertices{};

    std::vector <glm::vec3> dots;
    dots.push_back(glm::vec3(87.4, 0, 49));
    dots.push_back(glm::vec3(66.8, 0, 37));
    dots.push_back(glm::vec3(63.3, 0, 34.2));
    dots.push_back(glm::vec3(62.6, 0, 29.7));
    dots.push_back(glm::vec3(65.1, 0, 27.1));
    dots.push_back(glm::vec3(67.2, 0, 23.4));
    dots.push_back(glm::vec3(70.3, 0, 20.1));
    dots.push_back(glm::vec3(71.2, 0, 18));
    dots.push_back(glm::vec3(71.1, 0, 16.8));
    dots.push_back(glm::vec3(70.6, 0, 16.1));
    dots.push_back(glm::vec3(69.3, 0, 15.5));
    dots.push_back(glm::vec3(68.3, 0, 15));
    dots.push_back(glm::vec3(59.3, 0, 13.3));
    dots.push_back(glm::vec3(54.5, 0, 13.3));
    dots.push_back(glm::vec3(51.2, 0, 13.1));
    dots.push_back(glm::vec3(46.8, 0, 12.7));
    dots.push_back(glm::vec3(31.5, 0, 13.6));
    dots.push_back(glm::vec3(9.7, 0, 14.7));
    dots.push_back(glm::vec3(-9, 0, 14));
    dots.push_back(glm::vec3(-24.9, 0, 18.5));
    dots.push_back(glm::vec3(-41.9, 0, 22.4));
    dots.push_back(glm::vec3(-57.3, 0, 28.2));
    dots.push_back(glm::vec3(-62.8, 0, 31));
    dots.push_back(glm::vec3(-66.5, 0, 33.6));

    dots.push_back(glm::vec3(-69.1, 0, 33.3));
    dots.push_back(glm::vec3(-70, 0, 30));
    dots.push_back(glm::vec3(-71.1, 0, 26.2));
    dots.push_back(glm::vec3(-72.8, 0, 22.1));
    dots.push_back(glm::vec3(-73.6, 0, 15.6));
    dots.push_back(glm::vec3(-74.8, 0, 1));
    dots.push_back(glm::vec3(-73.6, 0, -17.8));
    dots.push_back(glm::vec3(-72.8, 0, -43.3));
    dots.push_back(glm::vec3(-66.3, 0, -51));
    dots.push_back(glm::vec3(-58.4, 0, -52.4));
    dots.push_back(glm::vec3(-51.7, 0, -52.3));
    dots.push_back(glm::vec3(-48.4, 0, -49.6));
    dots.push_back(glm::vec3(-49.4, 0, -45.9));
    dots.push_back(glm::vec3(-53.3, 0, -44.4));
    dots.push_back(glm::vec3( -57.4, 0, -41.7));


    dots.push_back(glm::vec3(-57.9, 0, -27.7));
    dots.push_back(glm::vec3(-57.1, 0, -18.2));
    dots.push_back(glm::vec3(-55, 0, -16.6));
    dots.push_back(glm::vec3(-52.3, 0, -15.1));
    dots.push_back(glm::vec3(-52, 0, -11.4));
    dots.push_back(glm::vec3(-51.4, 0, -1));
    dots.push_back(glm::vec3(-53.2, 0, 0.5 ));
    dots.push_back(glm::vec3(-55, 0, 0.8));
    dots.push_back(glm::vec3(-58.7, 0, 1.5));
    dots.push_back(glm::vec3(-60, 0, 6.3));
    dots.push_back(glm::vec3(-57.6, 0, 12.1));
    dots.push_back(glm::vec3(-53.1, 0, 14.4));
    dots.push_back(glm::vec3(-48.1, 0, 13.6));
    dots.push_back(glm::vec3(-38.3, 0, 10.3));
    dots.push_back(glm::vec3(-1.3, 0, 2.4));
    dots.push_back(glm::vec3(-0.8, 0, 0));
    dots.push_back(glm::vec3(4.3, 0,-2.6));
    dots.push_back(glm::vec3(7.5, 0, -3.2));
    dots.push_back(glm::vec3(11.6, 0, -3 ));
    dots.push_back(glm::vec3(16.1, 0, 1.1));
    dots.push_back(glm::vec3(21.5, 0, 2.2));
    dots.push_back(glm::vec3(30.7, 0, 3.2));
    dots.push_back(glm::vec3(60.4, 0, 1.7));
    dots.push_back(glm::vec3(70.6, 0, 3.1));

    dots.push_back(glm::vec3(86.1, 0, 7.5));
    dots.push_back(glm::vec3(95.6, 0, 17.1));
    dots.push_back(glm::vec3(105.2, 0, 26));
    dots.push_back(glm::vec3(118, 0, 44));
    dots.push_back(glm::vec3(117.5, 0, 47.9));
    dots.push_back(glm::vec3(113.1, 0, 49.6));
    dots.push_back(glm::vec3(110, 0, 50));
    dots.push_back(glm::vec3(107.9, 0, 48.3));
    dots.push_back(glm::vec3(107.9, 0, 45.6));
    dots.push_back(glm::vec3(107.1, 0, 42.1));
    dots.push_back(glm::vec3(103.7, 0, 41));
    dots.push_back(glm::vec3(100.5, 0, 42));
    dots.push_back(glm::vec3(98.1, 0, 46.4));
    dots.push_back(glm::vec3(96.6, 0, 50.6));
    dots.push_back(glm::vec3(94.1, 0, 52.3));
    dots.push_back(glm::vec3(91.1, 0, 52));

    

    // Mai multe puncte
    std::vector <glm::vec3> auxiliar;
    for (int i = 0; i < dots.size() - 1; i++) {
        glm::vec3 P1 = dots[i];
        glm::vec3 P2 = dots[i + 1];
        glm::vec3 D = P2 - P1;

        auxiliar.push_back(P1);

        for (int j = 1; j < 10000; j++) {
            float x = j;
            auxiliar.push_back(P1 + D * x / 10000.0f);
        }
        
    }
    //Ultimul punct
    glm::vec3 P1 = dots[dots.size() - 1];
    glm::vec3 P2 = dots[0];
    glm::vec3 D = P2 - P1;
    auxiliar.push_back(P1);

    for (int j = 1; j < 10000; j++) {
        float x = j;
        auxiliar.push_back(P1 + D * x / 10000.0f);
    }

    // Punct sus si jos
    for (int i = 0; i < auxiliar.size() - 1; i++) {
        glm::vec3 P1 = auxiliar[i];
        glm::vec3 P2 = auxiliar[i + 1];
        
        glm::vec3 D = P2 - P1;
        float d = distance(P1, P2);
        glm::vec3 UP = glm::vec3(0, 1, 0);
        glm::vec3 P = glm::cross(D, UP);
        
        glm::vec3 R = P1 + 1.5f * P/d;
        glm::vec3 A = P1 - 1.5f * P/d;


        vertices.push_back(VertexFormat(R, color, glm::vec3(0.2, 0.8, 0.6)));
        vertices.push_back(VertexFormat(A, color, glm::vec3(0.2, 0.8, 0.6)));
    }

    P1 = dots[dots.size()-1];
    P2 = dots[0];
    D = P2 - P1;
    
    glm::vec3 UP = glm::vec3(0, 1, 0);
    glm::vec3 P = glm::cross(D, UP);
    float d = distance(P1, P2);
    glm::vec3 R = P1 + 1.5f * P/d;
    glm::vec3 A = P1 - 1.5f * P/d;


    vertices.push_back(VertexFormat(R, color, glm::vec3(0.2, 0.8, 0.6)));
    vertices.push_back(VertexFormat(A, color, glm::vec3(0.2, 0.8, 0.6)));

    return vertices;
}

std::vector <unsigned int> object3D::CreateRoad2(std::vector<VertexFormat> vertices) {
    std::vector<unsigned int> indices{};

    for (int i = 0; i < vertices.size() -2; i+=2) {
        indices.push_back(i);
        indices.push_back(i+1);
        indices.push_back(i + 3);

        indices.push_back(i);
        indices.push_back(i + 3);
        indices.push_back(i + 2);
    }

    indices.push_back(vertices.size() - 2);
    indices.push_back(vertices.size() - 1);
    indices.push_back(1);

    indices.push_back(vertices.size() -2);
    indices.push_back(1);
    indices.push_back(0);



    return indices;
}

std::vector <VertexFormat> object3D::CreateS(glm::vec3 color) {
    std::vector<VertexFormat> vertices{ 
            VertexFormat(glm::vec3(-0.2, -1,  0.2), color, glm::vec3(0.2, 0.8, 0.2)),
            VertexFormat(glm::vec3(0.2, -1,  0.2), color, glm::vec3(0.9, 0.4, 0.2)),
            VertexFormat(glm::vec3(-0.2,  0.5,  0.2), color, glm::vec3(0.7, 0.7, 0.1)),
            VertexFormat(glm::vec3(0.2,  0.5,  0.2), color, glm::vec3(0.7, 0.3, 0.7)),
            VertexFormat(glm::vec3(-0.2, -1, -0.2), color, glm::vec3(0.3, 0.5, 0.4)),
            VertexFormat(glm::vec3(0.2, -1, -0.2), color, glm::vec3(0.5, 0.2, 0.9)),
            VertexFormat(glm::vec3(-0.2,  0.5, -0.2), color, glm::vec3(0.7, 0.0, 0.7)),
            VertexFormat(glm::vec3(0.2,  0.5, -0.2), color, glm::vec3(0.1, 0.5, 0.8)), 
    };


    return vertices;
}

std::vector <unsigned int> object3D::CreateS2(std::vector<VertexFormat> vertices) {
    std::vector<unsigned int> indices{
            0, 1, 2,        1, 3, 2,
            2, 3, 7,        2, 7, 6,
            1, 7, 3,        1, 5, 7,
            6, 7, 4,        7, 5, 4,
            0, 4, 1,        1, 4, 5,
            2, 6, 4,        0, 2, 4,
    };




    return indices;
}

std::vector <VertexFormat> object3D::CreateGrass(glm::vec3 color) {
    
    std::vector<VertexFormat> vertices{};

    for (int i = -400; i < 400; i+= 10) {
        for (int j = -400; j < 400; j+= 10) {
            vertices.push_back(VertexFormat(glm::vec3(j, 0, i), color, glm::vec3(0.2, 0.8, 0.6)));
            vertices.push_back(VertexFormat(glm::vec3(j+10, 0, i), color, glm::vec3(0.2, 0.8, 0.6)));
            vertices.push_back(VertexFormat(glm::vec3(j, 0, i+10), color, glm::vec3(0.2, 0.8, 0.6)));
            vertices.push_back(VertexFormat(glm::vec3(j + 10, 0, i+10), color, glm::vec3(0.2, 0.8, 0.6)));
        }
    }

    return vertices;
}

std::vector <unsigned int> object3D::CreateGrass2(std::vector<VertexFormat> vertices) {
    

    std::vector<unsigned int> indices{};

    for (int i = 0; i < vertices.size(); i+=4) {
        indices.push_back(i);
        indices.push_back(i+1);
        indices.push_back(i+2);

        indices.push_back(i + 2);
        indices.push_back(i + 3);
        indices.push_back(i + 1);
    }

    return indices;
}

std::vector <glm::vec3> object3D::CreateTrees(glm::vec3 color) {
    std::vector<glm::vec3> vertices{};

    std::vector <glm::vec3> dots;
    dots.push_back(glm::vec3(87.4, 0, 49));
    dots.push_back(glm::vec3(83, 0, 46.4));//M4
    dots.push_back(glm::vec3(77.4, 0, 44.1)); //A4
    dots.push_back(glm::vec3(71.4, 0, 40));//L4
    dots.push_back(glm::vec3(66.8, 0, 37));
    dots.push_back(glm::vec3(63.3, 0, 34.2));
    dots.push_back(glm::vec3(62.6, 0, 29.7));
    dots.push_back(glm::vec3(65.1, 0, 27.1));
    dots.push_back(glm::vec3(67.2, 0, 23.4));
    dots.push_back(glm::vec3(70.3, 0, 20.1));
    dots.push_back(glm::vec3(71.2, 0, 18));
    dots.push_back(glm::vec3(71.1, 0, 16.8));
    dots.push_back(glm::vec3(70.6, 0, 16.1));
    dots.push_back(glm::vec3(69.3, 0, 15.5));
    dots.push_back(glm::vec3(68.3, 0, 15));
    dots.push_back(glm::vec3(59.3, 0, 13.3));
    dots.push_back(glm::vec3(54.5, 0, 13.3));
    dots.push_back(glm::vec3(51.2, 0, 13.1));
    dots.push_back(glm::vec3(46.8, 0, 12.7));
    dots.push_back(glm::vec3(39.6, 0, 13.2));//K4
    dots.push_back(glm::vec3(31.5, 0, 13.6));
    dots.push_back(glm::vec3(21.3, 0, 14.1));//J4
    dots.push_back(glm::vec3(9.7, 0, 14.7));
    dots.push_back(glm::vec3(1.5, 0, 14.9));//I4
    dots.push_back(glm::vec3(-9, 0, 14));
    dots.push_back(glm::vec3(-16.8, 0, 16.2));//H4
    dots.push_back(glm::vec3(-24.9, 0, 18.5));
    dots.push_back(glm::vec3(-33.6, 0, 20.5));//G4
    dots.push_back(glm::vec3(-41.9, 0, 22.4));
    dots.push_back(glm::vec3(-49.6, 0, 25.3));//F4
    dots.push_back(glm::vec3(-57.3, 0, 28.2));
    dots.push_back(glm::vec3(-62.8, 0, 31));
    dots.push_back(glm::vec3(-66.5, 0, 33.6));

    dots.push_back(glm::vec3(-69.1, 0, 33.3));
    dots.push_back(glm::vec3(-70, 0, 30));
    dots.push_back(glm::vec3(-71.1, 0, 26.2));
    dots.push_back(glm::vec3(-72.8, 0, 22.1));
    dots.push_back(glm::vec3(-73.6, 0, 15.6));
    dots.push_back(glm::vec3(-74.1, 0, 1));//T3
    //dots.push_back(glm::vec3(-74.8, 0, 1));
    dots.push_back(glm::vec3(-74.3, 0, -7.6));//S3
    dots.push_back(glm::vec3(-73.6, 0, -17.8));
    dots.push_back(glm::vec3(-73.4, 0, -25.4));//R3
    dots.push_back(glm::vec3(-73.1, 0, -33.9));//Q3
    dots.push_back(glm::vec3(-72.8, 0, -43.3));
    dots.push_back(glm::vec3(-66.3, 0, -51));
    dots.push_back(glm::vec3(-58.4, 0, -52.4));
    dots.push_back(glm::vec3(-51.7, 0, -52.3));
    dots.push_back(glm::vec3(-48.4, 0, -49.6));
    dots.push_back(glm::vec3(-49.4, 0, -45.9));
    dots.push_back(glm::vec3(-53.3, 0, -44.4));
    dots.push_back(glm::vec3(-57.4, 0, -41.7));


    dots.push_back(glm::vec3(-57.9, 0, -27.7));
    dots.push_back(glm::vec3(-57.1, 0, -18.2));
    dots.push_back(glm::vec3(-55, 0, -16.6));
    dots.push_back(glm::vec3(-52.3, 0, -15.1));
    dots.push_back(glm::vec3(-52, 0, -11.4));
    dots.push_back(glm::vec3(-51.4, 0, -1));
    dots.push_back(glm::vec3(-53.2, 0, 0.5));
    dots.push_back(glm::vec3(-55, 0, 0.8));
    dots.push_back(glm::vec3(-58.7, 0, 1.5));
    dots.push_back(glm::vec3(-60, 0, 6.3));
    dots.push_back(glm::vec3(-57.6, 0, 12.1));
    dots.push_back(glm::vec3(-53.1, 0, 14.4));
    dots.push_back(glm::vec3(-48.1, 0, 13.6));
    dots.push_back(glm::vec3(-38.3, 0, 10.3));
    dots.push_back(glm::vec3(-24.5, 0, 7.3)); //U3
    dots.push_back(glm::vec3(-10.4, 0, 4.3)); //v3
    dots.push_back(glm::vec3(-1.3, 0, 2.4));
    dots.push_back(glm::vec3(-0.8, 0, 0));
    dots.push_back(glm::vec3(4.3, 0, -2.6));
    dots.push_back(glm::vec3(7.5, 0, -3.2));
    dots.push_back(glm::vec3(11.6, 0, -3));
    dots.push_back(glm::vec3(16.1, 0, 1.1));
    dots.push_back(glm::vec3(21.5, 0, 2.2));
    dots.push_back(glm::vec3(30.7, 0, 3.2));
    dots.push_back(glm::vec3(38.6, 0, 2.7));//T4
    dots.push_back(glm::vec3(44.6, 0, 2.5)); //W3
    dots.push_back(glm::vec3(52.3, 0, 2.3));//S4
    dots.push_back(glm::vec3(60.4, 0, 1.7));
    dots.push_back(glm::vec3(70.6, 0, 3.1));
    dots.push_back(glm::vec3(79.7, 0, 5.6));//R4

    dots.push_back(glm::vec3(86.1, 0, 7.5));
    dots.push_back(glm::vec3(92, 0, 13.4));//Q4
    dots.push_back(glm::vec3(95.6, 0, 17.1));
    dots.push_back(glm::vec3(100.9, 0, 22));//P4
    dots.push_back(glm::vec3(105.2, 0, 26));
    dots.push_back(glm::vec3(109.2, 0, 31.7));//O4
    dots.push_back(glm::vec3(112.3, 0, 36)); //Z3
    dots.push_back(glm::vec3(115.3, 0, 40.2));//N4
    dots.push_back(glm::vec3(118, 0, 44));
    dots.push_back(glm::vec3(117.5, 0, 47.9));
    dots.push_back(glm::vec3(113.1, 0, 49.6));
    dots.push_back(glm::vec3(110, 0, 50));
    dots.push_back(glm::vec3(107.9, 0, 48.3));
    dots.push_back(glm::vec3(107.9, 0, 45.6));
    dots.push_back(glm::vec3(107.1, 0, 42.1));
    dots.push_back(glm::vec3(103.7, 0, 41));
    dots.push_back(glm::vec3(100.5, 0, 42));
    dots.push_back(glm::vec3(98.1, 0, 46.4));
    dots.push_back(glm::vec3(96.6, 0, 50.6));
    dots.push_back(glm::vec3(94.1, 0, 52.3));
    dots.push_back(glm::vec3(91.1, 0, 52));
 

    // Punct sus si jos
    for (int i = 0; i < dots.size() - 1; i++) {
        glm::vec3 P1 = dots[i];
        glm::vec3 P2 = dots[i + 1];

        glm::vec3 D = P2 - P1;
        float d = distance(P1, P2);
        glm::vec3 UP = glm::vec3(0, 1, 0);
        glm::vec3 P = glm::cross(D, UP);

        glm::vec3 R = P1 + 4.0f * P / d;
        glm::vec3 A = P1 - 4.0f * P / d;


        vertices.push_back(R);
        vertices.push_back(A);
    }

    glm::vec3 P1 = dots[dots.size() - 1];
    glm::vec3 P2 = dots[0];
    glm::vec3 D = P2 - P1;

    glm::vec3 UP = glm::vec3(0, 1, 0);
    glm::vec3 P = glm::cross(D, UP);
    float d = distance(P1, P2);
    glm::vec3 R = P1 + 4.0f * P / d;
    glm::vec3 A = P1 - 4.0f * P / d;

    vertices.push_back(R);
    vertices.push_back(A);
    return vertices;
}

std::vector <glm::vec3> object3D::CreateLine(glm::vec3 color) {

    std::vector <glm::vec3> dots;
    dots.push_back(glm::vec3(87.4, 0, 49));
    dots.push_back(glm::vec3(83, 0, 46.4));//M4
    dots.push_back(glm::vec3(77.4, 0, 44.1)); //A4
    dots.push_back(glm::vec3(71.4, 0, 40));//L4
    dots.push_back(glm::vec3(66.8, 0, 37));
    dots.push_back(glm::vec3(63.3, 0, 34.2));
    dots.push_back(glm::vec3(62.6, 0, 29.7));
    dots.push_back(glm::vec3(65.1, 0, 27.1));
    dots.push_back(glm::vec3(67.2, 0, 23.4));
    dots.push_back(glm::vec3(70.3, 0, 20.1));
    dots.push_back(glm::vec3(71.2, 0, 18));
    dots.push_back(glm::vec3(71.1, 0, 16.8));
    dots.push_back(glm::vec3(70.6, 0, 16.1));
    dots.push_back(glm::vec3(69.3, 0, 15.5));
    dots.push_back(glm::vec3(68.3, 0, 15));
    dots.push_back(glm::vec3(59.3, 0, 13.3));
    dots.push_back(glm::vec3(54.5, 0, 13.3));
    dots.push_back(glm::vec3(51.2, 0, 13.1));
    dots.push_back(glm::vec3(46.8, 0, 12.7));
    dots.push_back(glm::vec3(39.6, 0, 13.2));//K4
    dots.push_back(glm::vec3(31.5, 0, 13.6));
    dots.push_back(glm::vec3(21.3, 0, 14.1));//J4
    dots.push_back(glm::vec3(9.7, 0, 14.7));
    dots.push_back(glm::vec3(1.5, 0, 14.9));//I4
    dots.push_back(glm::vec3(-9, 0, 14));
    dots.push_back(glm::vec3(-16.8, 0, 16.2));//H4
    dots.push_back(glm::vec3(-24.9, 0, 18.5));
    dots.push_back(glm::vec3(-33.6, 0, 20.5));//G4
    dots.push_back(glm::vec3(-41.9, 0, 22.4));
    dots.push_back(glm::vec3(-49.6, 0, 25.3));//F4
    dots.push_back(glm::vec3(-57.3, 0, 28.2));
    dots.push_back(glm::vec3(-62.8, 0, 31));
    dots.push_back(glm::vec3(-66.5, 0, 33.6));

    dots.push_back(glm::vec3(-69.1, 0, 33.3));
    dots.push_back(glm::vec3(-70, 0, 30));
    dots.push_back(glm::vec3(-71.1, 0, 26.2));
    dots.push_back(glm::vec3(-72.8, 0, 22.1));
    dots.push_back(glm::vec3(-73.6, 0, 15.6));
    dots.push_back(glm::vec3(-74.1, 0, 1));//T3
    dots.push_back(glm::vec3(-74.8, 0, 1));
    dots.push_back(glm::vec3(-74.3, 0, -7.6));//S3
    dots.push_back(glm::vec3(-73.6, 0, -17.8));
    dots.push_back(glm::vec3(-73.4, 0, -25.4));//R3
    dots.push_back(glm::vec3(-73.1, 0, -33.9));//Q3
    dots.push_back(glm::vec3(-72.8, 0, -43.3));
    dots.push_back(glm::vec3(-66.3, 0, -51));
    dots.push_back(glm::vec3(-58.4, 0, -52.4));
    dots.push_back(glm::vec3(-51.7, 0, -52.3));
    dots.push_back(glm::vec3(-48.4, 0, -49.6));
    dots.push_back(glm::vec3(-49.4, 0, -45.9));
    dots.push_back(glm::vec3(-53.3, 0, -44.4));
    dots.push_back(glm::vec3(-57.4, 0, -41.7));


    dots.push_back(glm::vec3(-57.9, 0, -27.7));
    dots.push_back(glm::vec3(-57.1, 0, -18.2));
    dots.push_back(glm::vec3(-55, 0, -16.6));
    dots.push_back(glm::vec3(-52.3, 0, -15.1));
    dots.push_back(glm::vec3(-52, 0, -11.4));
    dots.push_back(glm::vec3(-51.4, 0, -1));
    dots.push_back(glm::vec3(-53.2, 0, 0.5));
    dots.push_back(glm::vec3(-55, 0, 0.8));
    dots.push_back(glm::vec3(-58.7, 0, 1.5));
    dots.push_back(glm::vec3(-60, 0, 6.3));
    dots.push_back(glm::vec3(-57.6, 0, 12.1));
    dots.push_back(glm::vec3(-53.1, 0, 14.4));
    dots.push_back(glm::vec3(-48.1, 0, 13.6));
    dots.push_back(glm::vec3(-38.3, 0, 10.3));
    dots.push_back(glm::vec3(-24.5, 0, 7.3)); //U3
    dots.push_back(glm::vec3(-10.4, 0, 4.3)); //v3
    dots.push_back(glm::vec3(-1.3, 0, 2.4));
    dots.push_back(glm::vec3(-0.8, 0, 0));
    dots.push_back(glm::vec3(4.3, 0, -2.6));
    dots.push_back(glm::vec3(7.5, 0, -3.2));
    dots.push_back(glm::vec3(11.6, 0, -3));
    dots.push_back(glm::vec3(16.1, 0, 1.1));
    dots.push_back(glm::vec3(21.5, 0, 2.2));
    dots.push_back(glm::vec3(30.7, 0, 3.2));
    dots.push_back(glm::vec3(38.6, 0, 2.7));//T4
    dots.push_back(glm::vec3(44.6, 0, 2.5)); //W3
    dots.push_back(glm::vec3(52.3, 0, 2.3));//S4
    dots.push_back(glm::vec3(60.4, 0, 1.7));
    dots.push_back(glm::vec3(70.6, 0, 3.1));
    dots.push_back(glm::vec3(79.7, 0, 5.6));//R4

    dots.push_back(glm::vec3(86.1, 0, 7.5));
    dots.push_back(glm::vec3(92, 0, 13.4));//Q4
    dots.push_back(glm::vec3(95.6, 0, 17.1));
    dots.push_back(glm::vec3(100.9, 0, 22));//P4
    dots.push_back(glm::vec3(105.2, 0, 26));
    dots.push_back(glm::vec3(109.2, 0, 31.7));//O4
    dots.push_back(glm::vec3(112.3, 0, 36)); //Z3
    dots.push_back(glm::vec3(115.3, 0, 40.2));//N4
    dots.push_back(glm::vec3(118, 0, 44));
    dots.push_back(glm::vec3(117.5, 0, 47.9));
    dots.push_back(glm::vec3(113.1, 0, 49.6));
    dots.push_back(glm::vec3(110, 0, 50));
    dots.push_back(glm::vec3(107.9, 0, 48.3));
    dots.push_back(glm::vec3(107.9, 0, 45.6));
    dots.push_back(glm::vec3(107.1, 0, 42.1));
    dots.push_back(glm::vec3(103.7, 0, 41));
    dots.push_back(glm::vec3(100.5, 0, 42));
    dots.push_back(glm::vec3(98.1, 0, 46.4));
    dots.push_back(glm::vec3(96.6, 0, 50.6));
    dots.push_back(glm::vec3(94.1, 0, 52.3));
    dots.push_back(glm::vec3(91.1, 0, 52));


    
    return dots;
}


std::vector <VertexFormat> object3D::CreateTree(glm::vec3 color, glm::vec3 color2) {

    std::vector<VertexFormat> vertices{
            VertexFormat(glm::vec3(0.0, 2.0,  0.0), color, glm::vec3(0.2, 0.8, 0.6)), // 0
            VertexFormat(glm::vec3(1.5, 0.5,  0.0), color, glm::vec3(0.2, 0.8, 0.6)), // 1
            VertexFormat(glm::vec3(0.0, 0.5,  1.5), color, glm::vec3(0.2, 0.8, 0.6)), // 2

            VertexFormat(glm::vec3(0.0, 2.0,  0.0), color2, glm::vec3(0.2, 0.8, 0.6)), // 3
            VertexFormat(glm::vec3(0.0, 0.5,  1.5), color2, glm::vec3(0.2, 0.8, 0.6)), // 4
            VertexFormat(glm::vec3(-1.5, 0.5,  0.0), color2, glm::vec3(0.2, 0.8, 0.6)), // 5

            VertexFormat(glm::vec3(0.0, 2.0,  0.0), color, glm::vec3(0.2, 0.8, 0.6)), // 6
            VertexFormat(glm::vec3(-1.5, 0.5,  0.0), color, glm::vec3(0.2, 0.8, 0.6)), // 7
            VertexFormat(glm::vec3(0.0, 0.5,  -1.5), color, glm::vec3(0.2, 0.8, 0.6)), // 8

            VertexFormat(glm::vec3(0.0, 2.0,  0.0), color2, glm::vec3(0.2, 0.8, 0.6)), // 9
            VertexFormat(glm::vec3(0.0, 0.5,  -1.5), color2, glm::vec3(0.2, 0.8, 0.6)), // 10
            VertexFormat(glm::vec3(1.5, 0.5,  0.0), color2, glm::vec3(0.2, 0.8, 0.6)), // 11

            VertexFormat(glm::vec3(1.5, 0.5,  0.0), color, glm::vec3(0.2, 0.8, 0.6)), // 12
            VertexFormat(glm::vec3(0.0, 0.5,  1.5), color, glm::vec3(0.2, 0.8, 0.6)), // 13
            VertexFormat(glm::vec3(0.0, 0.5,  -1.5), color, glm::vec3(0.2, 0.8, 0.6)), // 14
            
            VertexFormat(glm::vec3(0.0, 0.5,  -1.5), color, glm::vec3(0.2, 0.8, 0.6)), // 15
            VertexFormat(glm::vec3(-1.5, 0.5,  0.0), color, glm::vec3(0.2, 0.8, 0.6)), // 16
            VertexFormat(glm::vec3(0.0, 0.5,  1.5), color, glm::vec3(0.2, 0.8, 0.6)), // 17

    };

    

    return vertices;
}

std::vector <unsigned int> object3D::CreateTree2(std::vector<VertexFormat> vertices) {


    std::vector<unsigned int> indices{
            0, 1, 2,
            3, 4, 5,
            6, 7, 8,
            9, 10, 11, 
            12, 13, 14,
            15, 16, 17,
    };


    return indices;
}