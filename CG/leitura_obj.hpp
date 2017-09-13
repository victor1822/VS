#ifndef LEITURA_OBJ_HPP_INCLUDED
#define LEITURA_OBJ_HPP_INCLUDED
#include <vector>
#include<stdio.h>
#include <iostream>
#include <fstream>
#include<string.h>
//#include <glm/vec2.hpp> // glm::vec3
//#include <glm/vec3.hpp>
//#include<glm/glm/detail/type_vec3.hpp>
//#include <glm/detail/type_vec2.hpp>
//#include <glm/detail/type_vec3.hpp>
#include<glm/glm.hpp>
using namespace std;

bool loadOBJ(
    const char * path,
    vector < glm::vec3 > & out_vertices,
    vector < glm::vec2 > & out_uvs,
    vector < glm::vec3 > & out_normals
)
{
vector< unsigned int > vertexIndices, uvIndices, normalIndices;
vector< glm::vec3 > temp_vertices;
vector< glm::vec2 > temp_uvs;
vector< glm::vec3 > temp_normals;

FILE * file = fopen(path, "r");
if( file == NULL ){
    //printf("Impossible to open the file !\n");
    return false;
}

while( true ){

    char lineHeader[128];

    int res = fscanf(file, "%s", lineHeader);

    if (res == EOF)

        break; // EOF = End Of File. Acabou a leitura
//else: continua

if ( strcmp( lineHeader, "v" ) == 0 ){
    glm::vec3 vertex;
    fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
    temp_vertices.push_back(vertex);
    }
    else if ( strcmp( lineHeader, "vt" ) == 0 ){
    glm::vec2 uv;
    fscanf(file, "%f %f\n", &uv.x, &uv.y );
    temp_uvs.push_back(uv);
    }
    else if ( strcmp( lineHeader, "vn" ) == 0 ){
    glm::vec3 normal;
    fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
    temp_normals.push_back(normal);
    }
    else if ( strcmp( lineHeader, "f" ) == 0 ){
    std::string vertex1, vertex2, vertex3;
    unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
    int matches = fscanf(file, "%d//%d %d//%d %d//%d\n",
                &vertexIndex[0], &normalIndex[0],
                &vertexIndex[1], &normalIndex[1],
                &vertexIndex[2], &normalIndex[2] );
    if (matches != 6){
        printf("File can't be read by our simple parser : ( Try exporting with other options\n");
        return false;
    }
    vertexIndices.push_back(vertexIndex[0]);
    vertexIndices.push_back(vertexIndex[1]);
    vertexIndices.push_back(vertexIndex[2]);
    //uvIndices.push_back(uvIndex[0]);
    //uvIndices.push_back(uvIndex[1]);
    //uvIndices.push_back(uvIndex[2]);
    normalIndices.push_back(normalIndex[0]);
    normalIndices.push_back(normalIndex[1]);
    normalIndices.push_back(normalIndex[2]);

   /*     // For each vertex of each triangle
    for( unsigned int i=0; i<vertexIndices.size(); i++ ){
            unsigned int vertexIndex = vertexIndices[i];
    glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
    out_vertices.push_back(vertex);
    }
        for( unsigned int i=0; i<uvIndices.size(); i++ ){
            unsigned int uvIndex = uvIndices[i];
    glm::vec2 uv = temp_uvs[ uvIndex-1 ];
    out_uvs.push_back(uv);
    }
        for( unsigned int i=0; i<normalIndices.size(); i++ ){
            unsigned int vertexIndex = normalIndices[i];
    glm::vec3 normal = temp_normals[ normalIndex-1 ];
    out_normals.push_back(normal);}*/

    }

    }
}

#endif // LEITURA_OBJ_HPP_INCLUDED
