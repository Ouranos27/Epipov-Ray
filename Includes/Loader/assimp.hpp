/*
** EPITECH PROJECT, 2022
** Epipov_Ray
** File description:
** Created by philippe,
*/
#ifndef EPIPOV_RAY_ASSIMP_HPP
    # define EPIPOV_RAY_ASSIMP_HPP

    # include <assimp/Importer.hpp>
    # include <assimp/scene.h>
    # include <vector>
    # include <memory>
    # include "meshes.hpp"
    # include "light.hpp"
    # include "camera.hpp"

namespace Loader {
    class assimp {
        public:
            assimp();
            ~assimp() = default;

        public:
            assimp  &operator=(const assimp &loader) = default;

        public:
            bool    loadFile(const std::string &filePath);

        public:
            [[nodiscard]] Tracing::camera  getCameraFromScene() const;
            [[nodiscard]] std::vector<std::shared_ptr<Modeling::meshes>> getMeshesFromScene() const;
            [[nodiscard]] std::vector<std::shared_ptr<Utils::light>> getLightsFromScene() const;

        public:
            [[nodiscard]] Modeling::material  loadMaterialFromMesh(unsigned int materialIdx) const;
            void    loadNode(aiNode *node, aiMatrix4x4 const &parent);
            [[nodiscard]] Utils::vector3<float>   transform(aiMatrix4x4 const & matrix, Utils::vector3<float> const &point) const;

        private:
            const aiScene       *_scene;
            Assimp::Importer    _importer;
            Tracing::camera     _camera;
            std::vector<std::shared_ptr<Modeling::meshes>>  _meshes;
            std::vector<std::shared_ptr<Utils::light>>      _lights;
    };
}

#endif //EPIPOV_RAY_ASSIMP_HPP
