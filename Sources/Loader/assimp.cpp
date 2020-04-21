/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/

#include <assimp/postprocess.h>
#include <iostream>
#include <Modeling/object.hpp>
#include "triangle.hpp"
#include "pointLight.hpp"
#include "Loader/assimp.hpp"

Loader::assimp::assimp()
: _scene(nullptr), _camera()
{}

bool Loader::assimp::loadFile(const std::string &filePath)
{
    _scene = _importer.ReadFile(filePath, aiProcess_Triangulate
        | aiProcess_GenSmoothNormals
        | aiProcess_FixInfacingNormals);
    if (!_scene) {
        std::cerr << "Error while importing scene: " << _importer.GetErrorString() << std::endl;
        return false;
    }
    this->loadNode(_scene->mRootNode, aiMatrix4x4());
    return true;
}

Tracing::camera Loader::assimp::getCameraFromScene() const
{
    return _camera;
}

std::vector<std::shared_ptr<Modeling::meshes>> Loader::assimp::getMeshesFromScene() const
{
    return _meshes;
}

std::vector<std::shared_ptr<Utils::light>> Loader::assimp::getLightsFromScene() const
{
    return _lights;
}

Modeling::material Loader::assimp::loadMaterialFromMesh(
    unsigned int materialIdx) const
{
    aiMaterial* aiMat = _scene->mMaterials[materialIdx];
    Modeling::material mat;
    aiColor3D color;
    float coef;
    if (aiMat->Get(AI_MATKEY_SHININESS, coef) == AI_SUCCESS) {
        mat.specularExponent = coef;
    }
    aiString name;
    if (aiMat->Get(AI_MATKEY_NAME, name) == AI_SUCCESS)
        mat.name = name.C_Str();
    if (aiMat->Get(AI_MATKEY_COLOR_AMBIENT, color) == AI_SUCCESS) {
        mat.ambiantColor = Utils::vector3<float>(color.r, color.g, color.b);
    }
    if (aiMat->Get(AI_MATKEY_COLOR_DIFFUSE, color) == AI_SUCCESS) {
        mat.diffuseColor = Utils::vector3<float>(color.r, color.g, color.b);
    }
    if (aiMat->Get(AI_MATKEY_COLOR_SPECULAR, color) == AI_SUCCESS) {
        mat.specularColor = Utils::vector3<float>(color.r, color.g, color.b);
    }
    if (aiMat->Get(AI_MATKEY_COLOR_EMISSIVE, color) == AI_SUCCESS) {
        mat.emissiveColor = Utils::vector3<float>(color.r, color.g, color.b);
    }
    if (aiMat->Get(AI_MATKEY_REFRACTI, coef) == AI_SUCCESS) {
        mat.refractionCoef = coef;
    }
    if (aiMat->Get(AI_MATKEY_OPACITY, coef) == AI_SUCCESS) {
        mat.opacity = coef;
    }
    if (aiMat->Get(AI_MATKEY_SHADING_MODEL, coef) == AI_SUCCESS) {
        mat.illumination = coef;
    }
    return mat;
}

void Loader::assimp::loadNode(aiNode *node, aiMatrix4x4 const &parent)
{
    aiMatrix4x4 matrix = parent * node->mTransformation;

    if (_scene->mNumCameras > 0 && node->mName == _scene->mCameras[0]->mName) {
        _camera.setMatrix(
            Utils::vector3<float>(matrix.a1, -matrix.c1, matrix.b1),
            Utils::vector3<float>(matrix.a2, -matrix.c2, matrix.b2),
            Utils::vector3<float>(matrix.a3, -matrix.c3, matrix.b3),
            Utils::vector3<float>(matrix.a4, -matrix.c4, matrix.b4)
        );
    }

    for (std::uint32_t lightIdx = 0; lightIdx < _scene->mNumLights; ++lightIdx) {
        aiLight* light = _scene->mLights[lightIdx];
        if (light->mName == node->mName) {
            if (light->mType == aiLightSource_POINT) {
                _lights.emplace_back(new Utils::pointLight(
                    transform(matrix, Utils::vector3<float>(light->mPosition.x, light->mPosition.y, light->mPosition.z)),
                    Utils::color(light->mColorDiffuse.r, light->mColorDiffuse.g, light->mColorDiffuse.b)
                ));
            }
        }
    }

    for (std::uint32_t meshIdx = 0u; meshIdx < node->mNumMeshes; ++meshIdx) {
        aiMesh* mesh = _scene->mMeshes[node->mMeshes[meshIdx]];
        if (!(mesh->mPrimitiveTypes & aiPrimitiveType_TRIANGLE) || mesh->mNumVertices <= 0) continue;
        std::vector<Modeling::triangle> triangles;
        for (std::uint32_t faceIdx = 0u; faceIdx < mesh->mNumFaces; ++faceIdx) {
            if (mesh->mFaces[faceIdx].mNumIndices == 3) {
                unsigned int v1Idx = mesh->mFaces[faceIdx].mIndices[0];
                unsigned int v2Idx = mesh->mFaces[faceIdx].mIndices[1];
                unsigned int v3Idx = mesh->mFaces[faceIdx].mIndices[2];
                Utils::vertex v1 = Utils::vertex(transform(matrix, Utils::vector3<float>(
                    mesh->mVertices[v1Idx].x,
                    mesh->mVertices[v1Idx].y,
                    mesh->mVertices[v1Idx].z
                )));
                Utils::vertex v2 = Utils::vertex(transform(matrix, Utils::vector3<float>(
                    mesh->mVertices[v2Idx].x,
                    mesh->mVertices[v2Idx].y,
                    mesh->mVertices[v2Idx].z
                )));
                Utils::vertex v3 = Utils::vertex(transform(matrix, Utils::vector3<float>(
                    mesh->mVertices[v3Idx].x,
                    mesh->mVertices[v3Idx].y,
                    mesh->mVertices[v3Idx].z
                )));
                if (mesh->mNormals) {
                    v1.setNormal(transform(matrix, Utils::vector3<float>(
                        mesh->mNormals[v1Idx].x,
                        mesh->mNormals[v1Idx].y,
                        mesh->mNormals[v1Idx].z
                    )));
                    v2.setNormal(transform(matrix, Utils::vector3<float>(
                        mesh->mNormals[v2Idx].x,
                        mesh->mNormals[v2Idx].y,
                        mesh->mNormals[v2Idx].z
                    )));
                    v2.setNormal(transform(matrix, Utils::vector3<float>(
                        mesh->mNormals[v3Idx].x,
                        mesh->mNormals[v3Idx].y,
                        mesh->mNormals[v3Idx].z
                    )));
                }
                triangles.emplace_back(v1, v2, v3);
            }
        }
        std::cout << "Creating KDTree for " << mesh->mName.C_Str() << " composed of " << triangles.size() << std::endl;
        _meshes.emplace_back(new Modeling::object(triangles, loadMaterialFromMesh(mesh->mMaterialIndex), mesh->mName.C_Str()));
        std::cout << "Done" << std::endl;
    }

    for (size_t i = 0; i < node->mNumChildren; ++i)
        loadNode(node->mChildren[i], matrix);
}

Utils::vector3<float> Loader::assimp::transform(aiMatrix4x4 const &matrix,
    Utils::vector3<float> const &point) const
{
    return Utils::vector3<float>(
        matrix.a1 * point.x + matrix.a2 * point.y + matrix.a3 * point.z + matrix.a4,
        -matrix.c1 * point.x - matrix.c2 * point.y - matrix.c3 * point.z - matrix.c4,
        matrix.b1 * point.x + matrix.b2 * point.y + matrix.b3 * point.z + matrix.b4);
};

