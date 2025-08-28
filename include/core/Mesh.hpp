#pragma once
#include <vector>
#include <glad/glad.h>

class Mesh
{
public:
     Mesh(const std::vector<float> &vertices, const std::vector<unsigned int> &indices);
     ~Mesh();

     void Bind() const;
     void Unbind() const;

     unsigned int GetIndexCount() const; // Идексы по вершинам

private:
     unsigned int m_VAO;
     unsigned int m_VBO;
     unsigned int m_EBO;
     unsigned int m_IndexCount;

     void SetupMesh(const std::vector<float> &vertices, const std::vector<unsigned int> &indices); // Настройка: Атрибута вершин
};