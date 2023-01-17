#include "lab_m1/Tema2/Tema2.h"

#include <vector>
#include <string>
#include <iostream>

#include "lab_m1/lab4/transform3D.h"
#include "lab_m1/Tema2/object3D.h"
#include "lab_m1/lab5/lab_camera.h"

#define drawOneLine(x, y, z, t) glBegin(GL_LINES);

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}


void Tema2::Init()
{
    polygonMode = GL_FILL;

    CreateMesh("road", object3D::CreateRoad(glm::vec3(0.15, 0.15, 0.15)), object3D::CreateRoad2(object3D::CreateRoad(glm::vec3(0.15, 0.15, 0.15))));
    CreateMesh("tree", object3D::CreateS(glm::vec3(0.4, 0.3, 0)), object3D::CreateS2(object3D::CreateS(glm::vec3(1, 1, 0))));
    CreateMesh("grass", object3D::CreateGrass(glm::vec3(0.5, 1.0, 0)), object3D::CreateGrass2(object3D::CreateGrass(glm::vec3(0, 0.9, 0.))));
    CreateMesh("tree2", object3D::CreateTree(glm::vec3(0.4, 0.8, 0), glm::vec3(0.4, 0.9, 0)), object3D::CreateTree2(object3D::CreateTree(glm::vec3(0, 0.9, 0), glm::vec3(0.4, 0.9, 0))));
    
    CreateMesh("treewhite", object3D::CreateS(glm::vec3(0.0, 0.0, 0.2)), object3D::CreateS2(object3D::CreateS(glm::vec3(1, 1, 0))));
    CreateMesh("grasswhite", object3D::CreateGrass(glm::vec3(0.9, 1.0, 1.0)), object3D::CreateGrass2(object3D::CreateGrass(glm::vec3(0, 0.9, 0.))));
    CreateMesh("tree2white", object3D::CreateTree(glm::vec3(0.9, 1.0, 1.0), glm::vec3(0.9, 0.9, 0.9)), object3D::CreateTree2(object3D::CreateTree(glm::vec3(0, 0.9, 0), glm::vec3(0.4, 0.9, 0))));

    
    CreateMesh("grassorange", object3D::CreateGrass(glm::vec3(0.7, 0.5, 0)), object3D::CreateGrass2(object3D::CreateGrass(glm::vec3(0, 0.9, 0.))));
    CreateMesh("tree2orange", object3D::CreateTree(glm::vec3(0.9, 0.5, 0.2), glm::vec3(0.8, 0.4, 0.3)), object3D::CreateTree2(object3D::CreateTree(glm::vec3(0, 0.9, 0), glm::vec3(0.4, 0.9, 0))));

    CreateMesh("Start", object3D::CreateS(glm::vec3(1, 0.3, 0)), object3D::CreateS2(object3D::CreateS(glm::vec3(1, 1, 0))));

    trees = object3D::CreateTrees(glm::vec3(0.4, 0.3, 0));

    line = object3D::CreateLine(glm::vec3(0.4, 0.3, 0));

    Mesh* mesh2 = new Mesh("myCar");
    mesh2->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "my_models/car"), "Car.fbx");
    meshes[mesh2->GetMeshID()] = mesh2;

    aux = 0;
    white = 0;

    // Initialize tx, ty and tz (the translation steps)
    translateX = 1.5*line[0].x;
    translateY = 0.5;
    translateZ = 1.5*line[0].z;
    
    // Initialize sx, sy and sz (the scale factors)
    scaleX = 0.35;
    scaleY = 0.35;
    scaleZ = 0.35;

    // Initialize angular steps
    angularStepOX = 0;
    angularStepOY = 0;
    angularStepOZ = 0;


    Shader* shader = new Shader("LabShader");
    shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
    shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
    shader->CreateAndLink();
    shaders[shader->GetName()] = shader;

    Shader* shader2 = new Shader("LabShader2");
    shader2->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "VertexShader2.glsl"), GL_VERTEX_SHADER);
    shader2->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema2", "shaders", "FragmentShader2.glsl"), GL_FRAGMENT_SHADER);
    shader2->CreateAndLink();
    shaders[shader2->GetName()] = shader2;

    camera = new implemented::Camera();
    camera->Set(glm::vec3(translateX + 0, 3, translateZ + 4), glm::vec3(translateX + 0, 1, translateZ+ 0), glm::vec3(0, 1, 0));
    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

    // Sets the resolution of the small viewport
    glm::ivec2 resolution = window->GetResolution();
    miniViewportArea = ViewportArea(50, 50, resolution.x / 5.f, resolution.y / 5.f);


    // Inamici
    pozx[0] = -0.8;
    pozy[0] = 0;
    k[0] = 10;
    coef[0] = 0;

    pozx[1] = -0.8;
    pozy[1] = 0;
    k[1] = 8;
    coef[1] = 0;

    pozx[2] = -0.8;
    pozy[2] = 0;
    k[2] = 6;
    coef[2] = 0;

    pozx[3] = -0.8;
    pozy[3] = 0;
    k[3] = 4;
    coef[3] = 0;

    pozx[4] = -0.8;
    pozy[4] = 0;
    k[4] = 2;
    coef[4] = 0;

    pozx[5] = -0.8;
    pozy[5] = 0;
    k[5] = 20;
    coef[5] = 0;

    pozx[5] = -0.8;
    pozy[5] = 0;
    k[5] = 50;
    coef[5] = 0;

    pozx[6] = -0.8;
    pozy[6] = 0;
    k[6] = 70;
    coef[6] = 0;

    pozx[7] = -0.8;
    pozy[7] = 0;
    k[7] = 90;
    coef[7] = 0;

    pozx[8] = -0.8;
    pozy[8] = 0;
    k[8] = 100;
    coef[8] = 0;

    pozx[9] = -0.8;
    pozy[9] = 0;
    k[9] = 0;
    coef[9] = 0;

    time = 0;

}

Mesh* Tema2::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices)
{
    unsigned int VAO = 0;
    // Create the VAO and bind it
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Create the VBO and bind it
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Send vertices data into the VBO buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    // Create the IBO and bind it
    unsigned int IBO;
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

    // Send indices data into the IBO buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

    // ========================================================================
    // This section demonstrates how the GPU vertex shader program
    // receives data.

 

    // Set vertex position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

    // Set vertex normal attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

    // Set texture coordinate attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

    // Set vertex color attribute
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
    // ========================================================================

    // Unbind the VAO
    glBindVertexArray(0);

    // Check for OpenGL errors
    CheckOpenGLError();

    // Mesh information is saved into a Mesh object
    meshes[name] = new Mesh(name);
    meshes[name]->InitFromBuffer(VAO, static_cast<unsigned int>(indices.size()));
    meshes[name]->vertices = vertices;
    meshes[name]->indices = indices;
    return meshes[name];
}

void Tema2::RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix) {
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    glm::vec3 posit = glm::vec3(translateX, translateY, translateZ);
    int location = glGetUniformLocation(shader->program, "CarP");
    glUniform3fv(location, 1, glm::value_ptr(posit));

    location = glGetUniformLocation(shader->program, "Time");

    glUniform1f(location, Engine::GetElapsedTime());

    mesh->Render();


}




void Tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.4, 0.7, 1, 0.5);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Sets the screen area where to draw
    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::RenderScene(float deltaTimeSeconds) {
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(0, 0.05, 0);
    modelMatrix *= transform3D::Scale(1.5, 1.5, 1.5);
    RenderMesh(meshes["road"], shaders["LabShader"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Scale(1.5, 1.5, 1.5);
    if (white == 0) {
        RenderMesh(meshes["grass"], shaders["LabShader"], modelMatrix);
    }
    if (white == 1) {
        RenderMesh(meshes["grasswhite"], shaders["LabShader"], modelMatrix);
    }
    if (white == 2) {
        RenderMesh(meshes["grassorange"], shaders["LabShader"], modelMatrix);
    }

    for (int i = 1; i < trees.size(); i+=3) {
        modelMatrix = glm::mat4(1);
        modelMatrix *= transform3D::Scale(1.5, 1.5, 1.5);
        
        modelMatrix *= transform3D::Translate(trees[i].x, trees[i].y, trees[i].z);
        if (white == 0) {
            RenderMesh(meshes["tree2"], shaders["LabShader"], modelMatrix);
        }
        if (white == 1){
            RenderMesh(meshes["tree2"], shaders["LabShader"], modelMatrix);
        }
        if (white == 2) {
            RenderMesh(meshes["tree2orange"], shaders["LabShader"], modelMatrix);
        }
        RenderMesh(meshes["tree"], shaders["LabShader"], modelMatrix);
        
        modelMatrix *= transform3D::Translate(0, 0.5, 0);
        if (white == 0) {
            RenderMesh(meshes["tree2"], shaders["LabShader"], modelMatrix);
        }
        if (white == 1){
            RenderMesh(meshes["tree2white"], shaders["LabShader"], modelMatrix);
        }
        if (white == 2) {
            RenderMesh(meshes["tree2orange"], shaders["LabShader"], modelMatrix);
        }
    }

    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(translateX, translateY, translateZ);
    modelMatrix *= transform3D::RotateOY(angularStepOY);
    modelMatrix *= transform3D::Scale(0.3, 0.3, 0.3);
    modelMatrix *= transform3D::RotateOX(RADIANS(-90.0f));

    RenderMesh(meshes["myCar"], shaders["LabShader2"], modelMatrix);
    
    
    // inamici
    
    for (int i = 0; i < 10; i++) {
        modelMatrix = glm::mat4(1);
        float angle;
        glm::vec3 v1, v2, v_dir;
        if (k[i] < line.size() - 1) {
            v1 = 1.5f * line[k[i]];
            v2 = 1.5f * line[k[i] + 1];
        }
        else {
            v1 = 1.5f * line[k[i]];
            v2 = 1.5f * line[0];
        }
        v_dir = v2 - v1;
        float d = distance(v1, v2);

        pozx[i] = v1.x;
        pozy[i] = v1.z;

        pozx[i] += (v_dir * coef[i]).x;
        pozy[i] += (v_dir * coef[i]).z;
        coef[i] += deltaTimeSeconds * (i+1) / d;
        if (coef[i] >= 1) {
            k[i]++;
            coef[i] = 0;
        }
        if (k[i] > line.size()-1) {
            k[i] = 0;
        }

        // unghi la care se rotesc
        if (((v2.z - v1.z) == 0.0f) && ((v2.x - v1.x) > 0)) {
            angle = M_PI * 0.5;
        }
        else if ((v2.z - v1.z == 0.0f) && ((v2.x - v1.x) < 0)) {
            angle = -M_PI * 0.5;
        }
        else {
            angle = atan((v2.x - v1.x) / (v2.z - v1.z));
        }
        if (((v2.z - v1.z) < 0.0f) && ((v2.x - v1.x) > 0.0f)) {
            angle += M_PI;
        }
        if (((v2.z - v1.z) < 0.0f) && ((v2.x - v1.x) < 0.0f)) {
            angle -= M_PI;
        }


        modelMatrix *= transform3D::Translate(pozx[i], 0.2, pozy[i]);
        modelMatrix *= transform3D::Scale(0.3, 0.3, 0.3);
        modelMatrix *= transform3D::RotateOY(angle);
        modelMatrix *= transform3D::RotateOX(RADIANS(-90.0f));
        RenderMesh(meshes["myCar"], shaders["LabShader2"], modelMatrix);
    }
    
    

   
}

void Tema2::Update(float deltaTimeSeconds)
{
    time += deltaTimeSeconds;
    if (time < 10) {
        white = 0;
    }
    else if (time < 20) {
        white = 2;
    }
    else if (time < 30) {
        white = 1;
    }
    else {
        white = 0;
    }
    glLineWidth(3);
    glPointSize(5);
    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);

    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

    RenderScene(deltaTimeSeconds);
   

    glClear(GL_DEPTH_BUFFER_BIT);
    // Camera in miniViewport
    glViewport(miniViewportArea.x, miniViewportArea.y, miniViewportArea.width, miniViewportArea.height);

    glm::vec3 position = camera->position;
    glm::vec3 fw = camera->forward;
    glm::vec3 up = camera->up;
    glm::vec3 right = camera->right;

    camera->Set(glm::vec3(translateX + 0.0f, 10.0f, translateZ + 1.0f), glm::vec3(translateX, 2, translateZ), glm::vec3(0, 1, 0));

    projectionMatrix = glm::ortho(-20.0f , 20.0f, -10.0f, 10.0f, 0.01f, 800.0f);
    RenderScene(deltaTimeSeconds);
    camera->position = position;
    camera->forward = fw;
    camera->up = up;
    camera->right = right;

    //DrawCoordinateSystem();
}

void Tema2::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema2::OnInputUpdate(float deltaTime, int mods)
{
   
        float copz, copx;
        int verif = 1;
        for (int i = 0; i < 6; i++) {
            int f = ((translateX - pozx[i]) * (translateX - pozx[i]) + (translateZ - pozy[i]) * (translateZ - pozy[i]));
            if (f <= 1.5) {
                verif = 0;
            }
        }
        if (verif == 1) {
            if (window->KeyHold(GLFW_KEY_W)) {
                // Verific daca se iese din pista
                copz = translateZ;
                copx = translateX;
                translateZ -= deltaTime * 10 * cos(angularStepOY);
                translateX -= deltaTime * 10 * sin(angularStepOY);

                int ok = 1;

                for (int i = 0; i < line.size() - 1; i++) {
                    glm::vec3 v1, v2, v_dir;
                    v1 = line[i] * 1.5f;
                    v2 = line[i + 1] * 1.5f;
                    v_dir = v2 - v1;
                    float a, b, c;
                    a = (translateX - v1.x) * (v2.x - v1.x);
                    b = (translateZ - v1.z) * (v2.z - v1.z);
                    c = (distance(v1, v2) * distance(v1, v2));
                    float u = (a + b) / c;
                    u = max(0.f, min(1.f, u));

                    float x, y;
                    x = v1.x + u * (v2.x - v1.x);
                    y = v1.z + u * (v2.z - v1.z);
                    float dist = distance(glm::vec3(x, 0, y), glm::vec3(translateX, 0, translateZ));

                    glm::vec3 D = v2 - v1;
                    glm::vec3 P = cross(D, glm::vec3(0, 1, 0));
                    float dist2 = distance(glm::vec3(0), D);
                    glm::vec3 R = v1 + 2.0f * P / dist2;
                    if (dist < distance(R, v1)) {
                        ok = 0;
                    }
                }

                glm::vec3 v1, v2, v_dir;
                v1 = line[line.size() - 1] * 1.5f;
                v2 = line[0] * 1.5f;
                v_dir = v2 - v1;
                float a, b, c;
                a = (translateX - v1.x) * (v2.x - v1.x);
                b = (translateZ - v1.z) * (v2.z - v1.z);
                c = (distance(v1, v2) * distance(v1, v2));
                float u = (a + b) / c;
                u = max(0.f, min(1.f, u));

                float x, y;
                x = v1.x + u * (v2.x - v1.x);
                y = v1.z + u * (v2.z - v1.z);
                float dist = distance(glm::vec3(x, 0, y), glm::vec3(translateX, 0, translateZ));

                glm::vec3 D = v2 - v1;
                glm::vec3 P = cross(D, glm::vec3(0, 1, 0));
                float dist2 = distance(glm::vec3(0), D);
                glm::vec3 R = v1 + 2.0f * P / dist2;
                if (dist < distance(R, v1)) {
                    ok = 0;
                }


                if (ok == 1) {
                    translateZ = copz;
                    translateX = copx;
                }
                else {

                    camera->MoveForward(10 * deltaTime);
                }



            }

            if (window->KeyHold(GLFW_KEY_S)) {
                copz = translateZ;
                copx = translateX;
                translateZ += deltaTime * 10 * cos(angularStepOY);
                translateX += deltaTime * 10 * sin(angularStepOY);

                int ok = 1;

                for (int i = 0; i < line.size() - 1; i++) {
                    glm::vec3 v1, v2, v_dir;
                    v1 = line[i] * 1.5f;
                    v2 = line[i + 1] * 1.5f;
                    v_dir = v2 - v1;
                    float a, b, c;
                    a = (translateX - v1.x) * (v2.x - v1.x);
                    b = (translateZ - v1.z) * (v2.z - v1.z);
                    c = (distance(v1, v2) * distance(v1, v2));
                    float u = (a + b) / c;
                    u = max(0.f, min(1.f, u));

                    float x, y;
                    x = v1.x + u * (v2.x - v1.x);
                    y = v1.z + u * (v2.z - v1.z);
                    float dist = distance(glm::vec3(x, 0, y), glm::vec3(translateX, 0, translateZ));

                    glm::vec3 D = v2 - v1;
                    glm::vec3 P = cross(D, glm::vec3(0, 1, 0));
                    float dist2 = distance(glm::vec3(0), D);
                    glm::vec3 R = v1 + 2.0f * P / dist2;
                    if (dist < distance(R, v1)) {
                        ok = 0;
                    }
                }

                glm::vec3 v1, v2, v_dir;
                v1 = line[line.size() - 1] * 1.5f;
                v2 = line[0] * 1.5f;
                v_dir = v2 - v1;
                float a, b, c;
                a = (translateX - v1.x) * (v2.x - v1.x);
                b = (translateZ - v1.z) * (v2.z - v1.z);
                c = (distance(v1, v2) * distance(v1, v2));
                float u = (a + b) / c;
                u = max(0.f, min(1.f, u));

                float x, y;
                x = v1.x + u * (v2.x - v1.x);
                y = v1.z + u * (v2.z - v1.z);
                float dist = distance(glm::vec3(x, 0, y), glm::vec3(translateX, 0, translateZ));

                glm::vec3 D = v2 - v1;
                glm::vec3 P = cross(D, glm::vec3(0, 1, 0));
                float dist2 = distance(glm::vec3(0), D);
                glm::vec3 R = v1 + 2.0f * P / dist2;
                if (dist < distance(R, v1)) {
                    ok = 0;
                }


                if (ok == 1) {
                    translateZ = copz;
                    translateX = copx;
                }
                else {

                    camera->MoveForward(-10 * deltaTime);
                }

            }

            if (window->KeyHold(GLFW_KEY_A)) {
                angularStepOY += deltaTime;
                camera->RotateThirdPerson_OY(deltaTime);

            }
            if (window->KeyHold(GLFW_KEY_D)) {
                angularStepOY -= deltaTime;
                camera->RotateThirdPerson_OY(-deltaTime);
            }
        }
    

    

}


void Tema2::OnKeyPress(int key, int mods)
{
    if (key == GLFW_KEY_T)
    {
        white = 0;
    }

    if (key == GLFW_KEY_Y)
    {
        white = 1;
    }

    if (key == GLFW_KEY_U)
    {
        white = 2;
    }

}


void Tema2::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema2::OnWindowResize(int width, int height)
{
}
