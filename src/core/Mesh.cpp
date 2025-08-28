#include "../../include/core/Mesh.hpp"

Mesh::Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices) {
    m_IndexCount = indices.size();
    SetupMesh(vertices, indices);
}

Mesh::~Mesh() {
    // Освобождаем ресурсы при уничтожении объекта
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
}

void Mesh::SetupMesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices) {
    // 1. Создание и привязка VAO (Vertex Array Object)
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    // 2. Создание, привязка и передача данных в VBO (Vertex Buffer Object)
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // 3. Создание, привязка и передача данных в EBO (Element Buffer Object)
    glGenBuffers(1, &m_EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // 4. Настройка атрибутов вершин (Vertex Attributes)
    // Указываем OpenGL, как интерпретировать данные вершин.

    // Атрибут позиции (location = 0 в шейдере)
    // 3 компонента типа float, не нормализованные
    // Stride (шаг) - 3 * sizeof(float) - расстояние в байтах между началами атрибутов для двух последовательных вершин
    // Offset (смещение) - (void*)0 - смещение первого компонента в буфере
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void Mesh::Bind() const {
    glBindVertexArray(m_VAO);
}

void Mesh::Unbind() const {
    glBindVertexArray(0);
}

unsigned int Mesh::GetIndexCount() const {
    return m_IndexCount;
}