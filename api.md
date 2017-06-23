# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`STB_IMAGE_RESIZE_IMPLEMENTATION`](#_controller_manager_8cpp_1aa6a7b41350a14f718b619164bc2b8fdf)            | 
`define `[`STB_IMAGE_IMPLEMENTATION`](#_engine_8cpp_1a18372412ad2fc3ce1e3240b3cf0efe78)            | 
`enum `[`EntityType`](#_entity_8h_1ad79a57ed3105eb60d991a1aeb4a9dc44)            | 
`public int `[`main`](#main_8cpp_1ae66f6b31b5ad750f1fe042a706a4e3d4)`()`            | 
`class `[`ControllerManager`](#class_controller_manager) | 
`class `[`DebugDrawer`](#class_debug_drawer) | 
`class `[`Display`](#class_display) | 
`class `[`DisplayManager`](#class_display_manager) | 
`class `[`Engine`](#class_engine) | 
`class `[`Entity`](#class_entity) | 
`class `[`EntityController`](#class_entity_controller) | 
`class `[`EntityManager`](#class_entity_manager) | 
`class `[`FreeType`](#class_free_type) | 
`class `[`Mesh`](#class_mesh) | 
`class `[`Model`](#class_model) | 
`class `[`Pawn`](#class_pawn) | 
`class `[`Player`](#class_player) | 
`class `[`RenderManager`](#class_render_manager) | 
`class `[`ShaderManager`](#class_shader_manager) | 
`class `[`ShaderProgram`](#class_shader_program) | 
`class `[`Terrain`](#class_terrain) | 
`class `[`Time`](#class_time) | 
`class `[`Tree`](#class_tree) | 
`class `[`Utils`](#class_utils) | 
`struct `[`Character`](#struct_character) | 
`struct `[`DebugVertex`](#struct_debug_vertex) | 
`struct `[`Texture`](#struct_texture) | 
`struct `[`Vertex`](#struct_vertex) | 

## Members

#### `define `[`STB_IMAGE_RESIZE_IMPLEMENTATION`](#_controller_manager_8cpp_1aa6a7b41350a14f718b619164bc2b8fdf) 

#### `define `[`STB_IMAGE_IMPLEMENTATION`](#_engine_8cpp_1a18372412ad2fc3ce1e3240b3cf0efe78) 

#### `enum `[`EntityType`](#_entity_8h_1ad79a57ed3105eb60d991a1aeb4a9dc44) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
BASIC            | 
TREE            | 
TERRAIN            | 

#### `public int `[`main`](#main_8cpp_1ae66f6b31b5ad750f1fe042a706a4e3d4)`()` 

# class `ControllerManager` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`ControllerManager`](#class_controller_manager_1a9888279ea2d5aede348d39d5efe913cc)`()` | 

## Members

#### `public  `[`ControllerManager`](#class_controller_manager_1a9888279ea2d5aede348d39d5efe913cc)`()` 

# class `DebugDrawer` 

```
class DebugDrawer
  : public btIDebugDraw
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GLuint `[`VAO`](#class_debug_drawer_1ace1761417982e843e8ff71dcd4cc4b15) | 
`public GLuint `[`VBO`](#class_debug_drawer_1a11f02ebf80a319c4c90b6f03650ba100) | 
`public std::vector< `[`DebugVertex`](#struct_debug_vertex)` > `[`vertices`](#class_debug_drawer_1a057464de1a46cc2f7f37412eba20a177) | 
`public inline void `[`setup`](#class_debug_drawer_1a98fa4bcfd431c68928f535d710d19625)`()` | 
`public inline void `[`drawLine`](#class_debug_drawer_1a865bfa695e8d2760efe81dce2ad0b4c3)`(const btVector3 & from,const btVector3 & to,const btVector3 & color)` | 
`public inline void `[`draw3dText`](#class_debug_drawer_1a6794c0ab3a30cedb05ce88607f295016)`(const btVector3 & location,const char * text)` | 
`public inline void `[`setDebugMode`](#class_debug_drawer_1a33abd619b671544ef4fadb52d505cb67)`(int mode)` | 
`public inline int `[`getDebugMode`](#class_debug_drawer_1a382151a869699bc50504ae4949b07acd)`() const` | 
`public inline void `[`drawContactPoint`](#class_debug_drawer_1a045847b419c1d2953e7839ed35d0c290)`(const btVector3 & PointOnB,const btVector3 & normalOnB,btScalar distance,int lifeTime,const btVector3 & color)` | 
`public inline void `[`reportErrorWarning`](#class_debug_drawer_1a49a4d9c83d70e939d6de216667d9f61a)`(const char * warningString)` | 
`public inline void `[`Draw`](#class_debug_drawer_1ad486e92ae3cd7d6e83c4cfcffacb92ae)`()` | 

## Members

#### `public GLuint `[`VAO`](#class_debug_drawer_1ace1761417982e843e8ff71dcd4cc4b15) 

#### `public GLuint `[`VBO`](#class_debug_drawer_1a11f02ebf80a319c4c90b6f03650ba100) 

#### `public std::vector< `[`DebugVertex`](#struct_debug_vertex)` > `[`vertices`](#class_debug_drawer_1a057464de1a46cc2f7f37412eba20a177) 

#### `public inline void `[`setup`](#class_debug_drawer_1a98fa4bcfd431c68928f535d710d19625)`()` 

#### `public inline void `[`drawLine`](#class_debug_drawer_1a865bfa695e8d2760efe81dce2ad0b4c3)`(const btVector3 & from,const btVector3 & to,const btVector3 & color)` 

#### `public inline void `[`draw3dText`](#class_debug_drawer_1a6794c0ab3a30cedb05ce88607f295016)`(const btVector3 & location,const char * text)` 

#### `public inline void `[`setDebugMode`](#class_debug_drawer_1a33abd619b671544ef4fadb52d505cb67)`(int mode)` 

#### `public inline int `[`getDebugMode`](#class_debug_drawer_1a382151a869699bc50504ae4949b07acd)`() const` 

#### `public inline void `[`drawContactPoint`](#class_debug_drawer_1a045847b419c1d2953e7839ed35d0c290)`(const btVector3 & PointOnB,const btVector3 & normalOnB,btScalar distance,int lifeTime,const btVector3 & color)` 

#### `public inline void `[`reportErrorWarning`](#class_debug_drawer_1a49a4d9c83d70e939d6de216667d9f61a)`(const char * warningString)` 

#### `public inline void `[`Draw`](#class_debug_drawer_1ad486e92ae3cd7d6e83c4cfcffacb92ae)`()` 

# class `Display` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GLFWwindow * `[`window`](#class_display_1a068bb93c9ad5c54e8bc0c5640728bf10) | 
`public  `[`Display`](#class_display_1a5f731c6cf5e8a7efdbe15371ab238da7)`(int width,int height,const char * title)` | 
`public  `[`~Display`](#class_display_1ac2607a6bb236c55547a4223d40d85d1f)`()` | 

## Members

#### `public GLFWwindow * `[`window`](#class_display_1a068bb93c9ad5c54e8bc0c5640728bf10) 

#### `public  `[`Display`](#class_display_1a5f731c6cf5e8a7efdbe15371ab238da7)`(int width,int height,const char * title)` 

#### `public  `[`~Display`](#class_display_1ac2607a6bb236c55547a4223d40d85d1f)`()` 

# class `DisplayManager` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`width`](#class_display_manager_1af2b93028fa8698069a12648466b21630) | 
`public int `[`height`](#class_display_manager_1ab1d8c39436ceb290e342e5f439bc4382) | 
`public GLFWwindow * `[`window`](#class_display_manager_1ad61b5e4bc0d47253795550be32bcc490) | 
`public  `[`DisplayManager`](#class_display_manager_1a9cfcf307727008f2c5eae4769340e8ff)`(const char * title)` | 
`public  `[`~DisplayManager`](#class_display_manager_1ae4c9d79e08490e64602cf562a16d8834)`()` | 

## Members

#### `public int `[`width`](#class_display_manager_1af2b93028fa8698069a12648466b21630) 

#### `public int `[`height`](#class_display_manager_1ab1d8c39436ceb290e342e5f439bc4382) 

#### `public GLFWwindow * `[`window`](#class_display_manager_1ad61b5e4bc0d47253795550be32bcc490) 

#### `public  `[`DisplayManager`](#class_display_manager_1a9cfcf307727008f2c5eae4769340e8ff)`(const char * title)` 

#### `public  `[`~DisplayManager`](#class_display_manager_1ae4c9d79e08490e64602cf562a16d8834)`()` 

# class `Engine` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`Start`](#class_engine_1aaa183f6092a869ea570598f886f24175)`()` | 

## Members

#### `public int `[`Start`](#class_engine_1aaa183f6092a869ea570598f886f24175)`()` 

# class `Entity` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public btRigidBody * `[`rigidBody`](#class_entity_1a827468f332a2cb1c220e1cbc961b9274) | 
`public `[`EntityType`](#_entity_8h_1ad79a57ed3105eb60d991a1aeb4a9dc44)` `[`entityType`](#class_entity_1a47ff97f47f3b3f6a42b62f28f483f511) | 
`public `[`Model`](#class_model)` * `[`model`](#class_entity_1a6b682e00fc339ddafd1eed4bb3e61b66) | 
`public `[`Terrain`](#class_terrain)` * `[`terrain`](#class_entity_1a8c32c21aff0b89197f13079901091192) | 
`public bool `[`hasCollision`](#class_entity_1a3e5d3451aafb927d10155e742cc3ad96) | 
`public  `[`Entity`](#class_entity_1aba3db79d74d1f875b84a4bfa7ca930a5)`(GLchar * modelPath,bool generateCollision)` | 
`public  `[`Entity`](#class_entity_1a980f368aa07ce358583982821533a54a)`()` | 
`public void `[`Rotate`](#class_entity_1af243ee1a3d52eda72de9b3fdf31ca82d)`(float angle,glm::vec3 axis)` | 
`public void `[`Scale`](#class_entity_1a01762e16dd3086b5aa9736768e497eec)`(glm::vec3 axis)` | 
`public void `[`Translate`](#class_entity_1a43c69880415bfe44219ba19318094867)`(glm::vec3 axis)` | 
`public virtual void `[`ClickEvent`](#class_entity_1ab867cc8a4f8d46583e0dfde7a5e9d121)`()` | 

## Members

#### `public btRigidBody * `[`rigidBody`](#class_entity_1a827468f332a2cb1c220e1cbc961b9274) 

#### `public `[`EntityType`](#_entity_8h_1ad79a57ed3105eb60d991a1aeb4a9dc44)` `[`entityType`](#class_entity_1a47ff97f47f3b3f6a42b62f28f483f511) 

#### `public `[`Model`](#class_model)` * `[`model`](#class_entity_1a6b682e00fc339ddafd1eed4bb3e61b66) 

#### `public `[`Terrain`](#class_terrain)` * `[`terrain`](#class_entity_1a8c32c21aff0b89197f13079901091192) 

#### `public bool `[`hasCollision`](#class_entity_1a3e5d3451aafb927d10155e742cc3ad96) 

#### `public  `[`Entity`](#class_entity_1aba3db79d74d1f875b84a4bfa7ca930a5)`(GLchar * modelPath,bool generateCollision)` 

#### `public  `[`Entity`](#class_entity_1a980f368aa07ce358583982821533a54a)`()` 

#### `public void `[`Rotate`](#class_entity_1af243ee1a3d52eda72de9b3fdf31ca82d)`(float angle,glm::vec3 axis)` 

#### `public void `[`Scale`](#class_entity_1a01762e16dd3086b5aa9736768e497eec)`(glm::vec3 axis)` 

#### `public void `[`Translate`](#class_entity_1a43c69880415bfe44219ba19318094867)`(glm::vec3 axis)` 

#### `public virtual void `[`ClickEvent`](#class_entity_1ab867cc8a4f8d46583e0dfde7a5e9d121)`()` 

# class `EntityController` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`EntityController`](#class_entity_controller_1a8570420c07bffe6be96743727362f22f)`(`[`Model`](#class_model)` * attachedModel)` | 
`public  `[`EntityController`](#class_entity_controller_1a35bf74aebf061ca651717cd3368fe914)`(`[`Model`](#class_model)` * attachedModel,`[`Entity`](#class_entity)` * entity)` | 
`public void `[`MoveToCoord`](#class_entity_controller_1acbabd879cdc41bf527fcac71f747cae5)`(glm::vec3 worldCoord)` | 
`public float `[`getMovementSpeed`](#class_entity_controller_1a6d186157cfb29032ccf49966b7ead0b4)`() const` | 
`public void `[`setMovementSpeed`](#class_entity_controller_1afd14a3e7cf9b482cc8ba4f31f6925052)`(float movementSpeed)` | 
`public void `[`CheckPosition`](#class_entity_controller_1acab95a97d398f3d93a7cb3db12996fc3)`()` | 
`public void `[`SetMoveDirection`](#class_entity_controller_1aa31baf824c9f7dc7b0b5062617e75f9d)`(glm::vec3 moveDirection)` | 

## Members

#### `public  `[`EntityController`](#class_entity_controller_1a8570420c07bffe6be96743727362f22f)`(`[`Model`](#class_model)` * attachedModel)` 

#### `public  `[`EntityController`](#class_entity_controller_1a35bf74aebf061ca651717cd3368fe914)`(`[`Model`](#class_model)` * attachedModel,`[`Entity`](#class_entity)` * entity)` 

#### `public void `[`MoveToCoord`](#class_entity_controller_1acbabd879cdc41bf527fcac71f747cae5)`(glm::vec3 worldCoord)` 

#### `public float `[`getMovementSpeed`](#class_entity_controller_1a6d186157cfb29032ccf49966b7ead0b4)`() const` 

#### `public void `[`setMovementSpeed`](#class_entity_controller_1afd14a3e7cf9b482cc8ba4f31f6925052)`(float movementSpeed)` 

#### `public void `[`CheckPosition`](#class_entity_controller_1acab95a97d398f3d93a7cb3db12996fc3)`()` 

#### `public void `[`SetMoveDirection`](#class_entity_controller_1aa31baf824c9f7dc7b0b5062617e75f9d)`(glm::vec3 moveDirection)` 

# class `EntityManager` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `FreeType` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::map< FT_ULong, `[`Character`](#struct_character)` > `[`characters`](#class_free_type_1a47de2bc208aa67919e598f9d73aacfa4) | 
`public FT_Library `[`ft`](#class_free_type_1a7ff802706f8490f7accf09a389aa3cc8) | 
`public GLuint `[`VAO`](#class_free_type_1af3c3b792223aed6b9e75b2a3a9d461b1) | 
`public GLuint `[`VBO`](#class_free_type_1a2a976e1de98454616c66001c9a2656af) | 
`public void `[`Initalize`](#class_free_type_1ac11e81dc6b7c0702926ca09be92c3cd6)`()` | 
`public void `[`LoadCharacters`](#class_free_type_1aea1bb0479dba9c278c2feee9943481ec)`(GLchar * fontPath)` | 
`public void `[`SetupRendering`](#class_free_type_1afce8a3fe5c54d7d92da622a3a74fc9a4)`()` | 

## Members

#### `public std::map< FT_ULong, `[`Character`](#struct_character)` > `[`characters`](#class_free_type_1a47de2bc208aa67919e598f9d73aacfa4) 

#### `public FT_Library `[`ft`](#class_free_type_1a7ff802706f8490f7accf09a389aa3cc8) 

#### `public GLuint `[`VAO`](#class_free_type_1af3c3b792223aed6b9e75b2a3a9d461b1) 

#### `public GLuint `[`VBO`](#class_free_type_1a2a976e1de98454616c66001c9a2656af) 

#### `public void `[`Initalize`](#class_free_type_1ac11e81dc6b7c0702926ca09be92c3cd6)`()` 

#### `public void `[`LoadCharacters`](#class_free_type_1aea1bb0479dba9c278c2feee9943481ec)`(GLchar * fontPath)` 

#### `public void `[`SetupRendering`](#class_free_type_1afce8a3fe5c54d7d92da622a3a74fc9a4)`()` 

# class `Mesh` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::vector< `[`Vertex`](#struct_vertex)` > `[`vertices`](#class_mesh_1a6465a888c97232a39e12aad008c969c3) | 
`public std::vector< GLuint > `[`indices`](#class_mesh_1a5e55b84c6c967608bcf23ed7d68e4215) | 
`public std::vector< `[`Texture`](#struct_texture)` > `[`textures`](#class_mesh_1abf1e672703bf4f8e104f3b076faaf958) | 
`public GLuint `[`VAO`](#class_mesh_1a09b989b9d4df8ae595d7e80e091a4a5b) | 
`public GLuint `[`VBO`](#class_mesh_1a0d28b2c6fee628a13f43cae3f858569b) | 
`public GLuint `[`EBO`](#class_mesh_1a894c6723c0172f4e38b2509582abfa6c) | 
`public  `[`Mesh`](#class_mesh_1af1baf95f510199fd2b3631e9daae79ce)`(std::vector< `[`Vertex`](#struct_vertex)` > vertices,std::vector< GLuint > indices,std::vector< `[`Texture`](#struct_texture)` > textures)` | 
`public void `[`setupMesh`](#class_mesh_1aafa4e21067a9b0c4407daf5e3c9ea991)`()` | 
`public void `[`Draw`](#class_mesh_1afdd95c079fd0442afef8a6c421c8bfc9)`()` | 

## Members

#### `public std::vector< `[`Vertex`](#struct_vertex)` > `[`vertices`](#class_mesh_1a6465a888c97232a39e12aad008c969c3) 

#### `public std::vector< GLuint > `[`indices`](#class_mesh_1a5e55b84c6c967608bcf23ed7d68e4215) 

#### `public std::vector< `[`Texture`](#struct_texture)` > `[`textures`](#class_mesh_1abf1e672703bf4f8e104f3b076faaf958) 

#### `public GLuint `[`VAO`](#class_mesh_1a09b989b9d4df8ae595d7e80e091a4a5b) 

#### `public GLuint `[`VBO`](#class_mesh_1a0d28b2c6fee628a13f43cae3f858569b) 

#### `public GLuint `[`EBO`](#class_mesh_1a894c6723c0172f4e38b2509582abfa6c) 

#### `public  `[`Mesh`](#class_mesh_1af1baf95f510199fd2b3631e9daae79ce)`(std::vector< `[`Vertex`](#struct_vertex)` > vertices,std::vector< GLuint > indices,std::vector< `[`Texture`](#struct_texture)` > textures)` 

#### `public void `[`setupMesh`](#class_mesh_1aafa4e21067a9b0c4407daf5e3c9ea991)`()` 

#### `public void `[`Draw`](#class_mesh_1afdd95c079fd0442afef8a6c421c8bfc9)`()` 

# class `Model` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public bool `[`drawOutline`](#class_model_1a466fd5fc61b7d607eafca684f55a4172) | 
`public glm::mat4 `[`model`](#class_model_1ab700d3ab458a1846371c3ad19c276e13) | 
`public std::string `[`model_file`](#class_model_1a93176f36ca960d90b08319c9202ce114) | 
`public std::vector< `[`Mesh`](#class_mesh)` > `[`meshes`](#class_model_1a538e42901dcfba59471072a48a162163) | 
`public  `[`Model`](#class_model_1a418ff46b5c526311782c722883617d5a)`(std::string meshPath)` | 
`public  `[`Model`](#class_model_1ae3b375de5f6df4faf74a95d64748e048)`()` | 
`public void `[`createAssimpLog`](#class_model_1af2ecd3c192cbc28781d8f2628eea3f76)`()` | 
`public void `[`importFile`](#class_model_1a4daec5e3362a2b5a32bd7501272672aa)`()` | 
`public void `[`processNode`](#class_model_1a23b167ce0d33f7e6ab5693cd5e81a9a5)`(aiNode * node,const aiScene * scene)` | 
`public `[`Mesh`](#class_mesh)` `[`processMesh`](#class_model_1a95ae1a9980ded3d98b1c8785cb889d96)`(aiMesh * mesh,const aiScene * scene)` | 
`public std::vector< `[`Texture`](#struct_texture)` > `[`processMaterial`](#class_model_1a74d04b3ef3475dc1fac974e2f27a6fad)`(aiTextureType textureType,aiMaterial * material,std::string textureTypeString)` | 
`public void `[`Rotate`](#class_model_1a48f5701d28dcc0e0fb09f85e5d046fe0)`(GLfloat angle,glm::vec3 axis)` | 
`public void `[`Translate`](#class_model_1a9ace6430884984c7061829cecbf14794)`(glm::vec3 axis)` | 
`public void `[`Scale`](#class_model_1a171ba77c7e79d8c2dc619419fa9d78aa)`(glm::vec3 axis)` | 
`public void `[`Draw`](#class_model_1a0c668c13fc79a86326f75ea231f3886f)`()` | 

## Members

#### `public bool `[`drawOutline`](#class_model_1a466fd5fc61b7d607eafca684f55a4172) 

#### `public glm::mat4 `[`model`](#class_model_1ab700d3ab458a1846371c3ad19c276e13) 

#### `public std::string `[`model_file`](#class_model_1a93176f36ca960d90b08319c9202ce114) 

#### `public std::vector< `[`Mesh`](#class_mesh)` > `[`meshes`](#class_model_1a538e42901dcfba59471072a48a162163) 

#### `public  `[`Model`](#class_model_1a418ff46b5c526311782c722883617d5a)`(std::string meshPath)` 

#### `public  `[`Model`](#class_model_1ae3b375de5f6df4faf74a95d64748e048)`()` 

#### `public void `[`createAssimpLog`](#class_model_1af2ecd3c192cbc28781d8f2628eea3f76)`()` 

#### `public void `[`importFile`](#class_model_1a4daec5e3362a2b5a32bd7501272672aa)`()` 

#### `public void `[`processNode`](#class_model_1a23b167ce0d33f7e6ab5693cd5e81a9a5)`(aiNode * node,const aiScene * scene)` 

#### `public `[`Mesh`](#class_mesh)` `[`processMesh`](#class_model_1a95ae1a9980ded3d98b1c8785cb889d96)`(aiMesh * mesh,const aiScene * scene)` 

#### `public std::vector< `[`Texture`](#struct_texture)` > `[`processMaterial`](#class_model_1a74d04b3ef3475dc1fac974e2f27a6fad)`(aiTextureType textureType,aiMaterial * material,std::string textureTypeString)` 

#### `public void `[`Rotate`](#class_model_1a48f5701d28dcc0e0fb09f85e5d046fe0)`(GLfloat angle,glm::vec3 axis)` 

#### `public void `[`Translate`](#class_model_1a9ace6430884984c7061829cecbf14794)`(glm::vec3 axis)` 

#### `public void `[`Scale`](#class_model_1a171ba77c7e79d8c2dc619419fa9d78aa)`(glm::vec3 axis)` 

#### `public void `[`Draw`](#class_model_1a0c668c13fc79a86326f75ea231f3886f)`()` 

# class `Pawn` 

```
class Pawn
  : public Entity
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`EntityController`](#class_entity_controller)` * `[`entityController`](#class_pawn_1aafd04fb16b09e62f657c26317713d5fc) | 
`public  `[`Pawn`](#class_pawn_1a5678e56ca06578c4395ba6a2f10d018d)`(GLchar * modelPath,bool generateCollision)` | 

## Members

#### `public `[`EntityController`](#class_entity_controller)` * `[`entityController`](#class_pawn_1aafd04fb16b09e62f657c26317713d5fc) 

#### `public  `[`Pawn`](#class_pawn_1a5678e56ca06578c4395ba6a2f10d018d)`(GLchar * modelPath,bool generateCollision)` 

# class `Player` 

```
class Player
  : public Pawn
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Player`](#class_player_1a41137a19726ae513a4b53aa0310dfaa6)`(GLchar * modelPath,bool generateCollision)` | 

## Members

#### `public  `[`Player`](#class_player_1a41137a19726ae513a4b53aa0310dfaa6)`(GLchar * modelPath,bool generateCollision)` 

# class `RenderManager` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::vector< `[`Entity`](#class_entity)` * > `[`entities`](#class_render_manager_1ad61e05f61e351f7158d5c584f5abbbb6) | 
`public void `[`RenderModels`](#class_render_manager_1af9feae5fb58c0771f6c5d7988f83716b)`()` | 
`public void `[`RenderCelShader`](#class_render_manager_1a0a558d2f894335950b1152fdc6c9bd08)`(bool drawModels)` | 
`public void `[`RenderBaseShader`](#class_render_manager_1a1b373aa5c5a8f5e145b2ca256c92720d)`(bool drawModels)` | 
`public void `[`RenderCelShader`](#class_render_manager_1a575745ac9bb16e540a73a504d2f929c1)`()` | 
`public void `[`RenderBaseShader`](#class_render_manager_1a34830150c31d118e0d2c39e9e204ddf8)`()` | 
`public void `[`DrawModels`](#class_render_manager_1a4f9cebbacd3e442d0bfd38a2dfde3b08)`()` | 
`public void `[`RenderWaterShader`](#class_render_manager_1a5e140cf713aa5d3c35ea155103c3bb6d)`()` | 
`public void `[`RenderGuiShader`](#class_render_manager_1a841eac328655e7f908896549ab8314ed)`()` | 
`public void `[`RenderDebugShader`](#class_render_manager_1aac3dc62eb6c40ab92ae62babdd8890ac)`()` | 

## Members

#### `public std::vector< `[`Entity`](#class_entity)` * > `[`entities`](#class_render_manager_1ad61e05f61e351f7158d5c584f5abbbb6) 

#### `public void `[`RenderModels`](#class_render_manager_1af9feae5fb58c0771f6c5d7988f83716b)`()` 

#### `public void `[`RenderCelShader`](#class_render_manager_1a0a558d2f894335950b1152fdc6c9bd08)`(bool drawModels)` 

#### `public void `[`RenderBaseShader`](#class_render_manager_1a1b373aa5c5a8f5e145b2ca256c92720d)`(bool drawModels)` 

#### `public void `[`RenderCelShader`](#class_render_manager_1a575745ac9bb16e540a73a504d2f929c1)`()` 

#### `public void `[`RenderBaseShader`](#class_render_manager_1a34830150c31d118e0d2c39e9e204ddf8)`()` 

#### `public void `[`DrawModels`](#class_render_manager_1a4f9cebbacd3e442d0bfd38a2dfde3b08)`()` 

#### `public void `[`RenderWaterShader`](#class_render_manager_1a5e140cf713aa5d3c35ea155103c3bb6d)`()` 

#### `public void `[`RenderGuiShader`](#class_render_manager_1a841eac328655e7f908896549ab8314ed)`()` 

#### `public void `[`RenderDebugShader`](#class_render_manager_1aac3dc62eb6c40ab92ae62babdd8890ac)`()` 

# class `ShaderManager` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `ShaderProgram` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GLuint `[`vertexShader`](#class_shader_program_1a27dda70d14615be52b28206aad867103) | 
`public GLuint `[`fragmentShader`](#class_shader_program_1ad52a90b07eac47f4868ff0740cb53643) | 
`public GLint `[`success`](#class_shader_program_1a805459eabd5da5b60c4d864bdfa635ba) | 
`public GLchar `[`infoLog`](#class_shader_program_1ab52bfa4d1679013d1fe324014ea23a2f) | 
`public char * `[`VERTEX_SHADER_PATH`](#class_shader_program_1ae21faf4e41320eb603a4ce0079238ddf) | 
`public char * `[`FRAGMENT_SHADER_PATH`](#class_shader_program_1a6bcb11da4dfe939abe05092b7457983b) | 
`public GLuint `[`shaderProgramID`](#class_shader_program_1aa9866282a9cd51a43c958a28decece88) | 
`public `[`ShaderProgram`](#class_shader_program)` * `[`shaderProgram`](#class_shader_program_1a51ba98c2862f366aef1714eed08ced5d) | 
`public  `[`ShaderProgram`](#class_shader_program_1ac274cd017dbe6f5f109f7ad4ba601780)`(char * vertexShader,char * fragmentShader)` | 
`public  `[`ShaderProgram`](#class_shader_program_1add585b75cb78f4afa865ea7b27c9651e)`()` | 
`public GLuint `[`CreateShader`](#class_shader_program_1acbf31fcac8f3d1cc794d1ec3cfee9047)`(GLuint shaderType,GLchar * shaderPath)` | 
`public void `[`Start`](#class_shader_program_1a11c7f81e8c4fb089a2f7507c99116b4e)`()` | 
`public void `[`Stop`](#class_shader_program_1afc331f43c1e7d98f08ca0bed736e8a25)`()` | 
`public  `[`~ShaderProgram`](#class_shader_program_1a2d2eadcfc48cc2e2ddb82aba70553a9f)`()` | 

## Members

#### `public GLuint `[`vertexShader`](#class_shader_program_1a27dda70d14615be52b28206aad867103) 

#### `public GLuint `[`fragmentShader`](#class_shader_program_1ad52a90b07eac47f4868ff0740cb53643) 

#### `public GLint `[`success`](#class_shader_program_1a805459eabd5da5b60c4d864bdfa635ba) 

#### `public GLchar `[`infoLog`](#class_shader_program_1ab52bfa4d1679013d1fe324014ea23a2f) 

#### `public char * `[`VERTEX_SHADER_PATH`](#class_shader_program_1ae21faf4e41320eb603a4ce0079238ddf) 

#### `public char * `[`FRAGMENT_SHADER_PATH`](#class_shader_program_1a6bcb11da4dfe939abe05092b7457983b) 

#### `public GLuint `[`shaderProgramID`](#class_shader_program_1aa9866282a9cd51a43c958a28decece88) 

#### `public `[`ShaderProgram`](#class_shader_program)` * `[`shaderProgram`](#class_shader_program_1a51ba98c2862f366aef1714eed08ced5d) 

#### `public  `[`ShaderProgram`](#class_shader_program_1ac274cd017dbe6f5f109f7ad4ba601780)`(char * vertexShader,char * fragmentShader)` 

#### `public  `[`ShaderProgram`](#class_shader_program_1add585b75cb78f4afa865ea7b27c9651e)`()` 

#### `public GLuint `[`CreateShader`](#class_shader_program_1acbf31fcac8f3d1cc794d1ec3cfee9047)`(GLuint shaderType,GLchar * shaderPath)` 

#### `public void `[`Start`](#class_shader_program_1a11c7f81e8c4fb089a2f7507c99116b4e)`()` 

#### `public void `[`Stop`](#class_shader_program_1afc331f43c1e7d98f08ca0bed736e8a25)`()` 

#### `public  `[`~ShaderProgram`](#class_shader_program_1a2d2eadcfc48cc2e2ddb82aba70553a9f)`()` 

# class `Terrain` 

```
class Terrain
  : public Plane
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public btRigidBody * `[`rigidBody`](#class_terrain_1a93cfe15f6371a414a689d05f10d1543c) | 
`public std::map< int, int > `[`traversedVertices`](#class_terrain_1abff84d86bbe160ced149765f09d24ceb) | 
`public  `[`Terrain`](#class_terrain_1a141f5bdd205f5a2169ac77df93ddfc07)`(int sizeX,int sizeZ,int tileSize,bool generateHeightMap)` | 
`public void `[`generateCollision`](#class_terrain_1a7fc9bb9277f4446c203bc8723d7bd3f0)`()` | 
`public std::vector< int > `[`ChooseRiverStartIndices`](#class_terrain_1a584349fd1564f2abdb781e31b8cf5b51)`(std::vector< int > vector)` | 
`public std::vector< int > `[`GetPossibleRiverStartIndices`](#class_terrain_1ac1ecb42edf81460f1227750711c24ab1)`()` | 
`public void `[`GenerateRivers`](#class_terrain_1a6ed0396148340ae1522f66c12f49010e)`()` | 
`public void `[`CarvePath`](#class_terrain_1ad6f274e333e299960dd8a8f97163c373)`(int index)` | 

## Members

#### `public btRigidBody * `[`rigidBody`](#class_terrain_1a93cfe15f6371a414a689d05f10d1543c) 

#### `public std::map< int, int > `[`traversedVertices`](#class_terrain_1abff84d86bbe160ced149765f09d24ceb) 

#### `public  `[`Terrain`](#class_terrain_1a141f5bdd205f5a2169ac77df93ddfc07)`(int sizeX,int sizeZ,int tileSize,bool generateHeightMap)` 

#### `public void `[`generateCollision`](#class_terrain_1a7fc9bb9277f4446c203bc8723d7bd3f0)`()` 

#### `public std::vector< int > `[`ChooseRiverStartIndices`](#class_terrain_1a584349fd1564f2abdb781e31b8cf5b51)`(std::vector< int > vector)` 

#### `public std::vector< int > `[`GetPossibleRiverStartIndices`](#class_terrain_1ac1ecb42edf81460f1227750711c24ab1)`()` 

#### `public void `[`GenerateRivers`](#class_terrain_1a6ed0396148340ae1522f66c12f49010e)`()` 

#### `public void `[`CarvePath`](#class_terrain_1ad6f274e333e299960dd8a8f97163c373)`(int index)` 

# class `Time` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `Tree` 

```
class Tree
  : public Entity
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Tree`](#class_tree_1a3d8a92d7e57d19b7890dbd569846f5de)`(GLchar * modelPath,bool generateCollision)` | 
`public void `[`printShit`](#class_tree_1a2d220bdeb280770d61364418328845a1)`()` | 
`public virtual void `[`ClickEvent`](#class_tree_1a495a08471fe92145a24fff8ae575db5d)`()` | 

## Members

#### `public  `[`Tree`](#class_tree_1a3d8a92d7e57d19b7890dbd569846f5de)`(GLchar * modelPath,bool generateCollision)` 

#### `public void `[`printShit`](#class_tree_1a2d220bdeb280770d61364418328845a1)`()` 

#### `public virtual void `[`ClickEvent`](#class_tree_1a495a08471fe92145a24fff8ae575db5d)`()` 

# class `Utils` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# struct `Character` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GLuint `[`textureId`](#struct_character_1a08b0f2e46806e9596baf92726b5df269) | 
`public glm::ivec2 `[`size`](#struct_character_1a0a5d57d73f16437a0a9f324ffa5760be) | 
`public glm::ivec2 `[`bearing`](#struct_character_1ab0092bda8aab79cbc13f1b8cde4bc9ce) | 
`public FT_Pos `[`advance`](#struct_character_1a13ee79cc5e01ce0d0375a7ff80ccc294) | 

## Members

#### `public GLuint `[`textureId`](#struct_character_1a08b0f2e46806e9596baf92726b5df269) 

#### `public glm::ivec2 `[`size`](#struct_character_1a0a5d57d73f16437a0a9f324ffa5760be) 

#### `public glm::ivec2 `[`bearing`](#struct_character_1ab0092bda8aab79cbc13f1b8cde4bc9ce) 

#### `public FT_Pos `[`advance`](#struct_character_1a13ee79cc5e01ce0d0375a7ff80ccc294) 

# struct `DebugVertex` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public glm::vec3 `[`position`](#struct_debug_vertex_1a60f9799343e7d9f0ece90a12b4d419cb) | 
`public glm::vec3 `[`color`](#struct_debug_vertex_1a863ecb4f7b4c18702b04a2c9ed005f72) | 

## Members

#### `public glm::vec3 `[`position`](#struct_debug_vertex_1a60f9799343e7d9f0ece90a12b4d419cb) 

#### `public glm::vec3 `[`color`](#struct_debug_vertex_1a863ecb4f7b4c18702b04a2c9ed005f72) 

# struct `Texture` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GLuint `[`id`](#struct_texture_1af848138d72c1fc995ab414a71ab10d47) | 
`public std::string `[`type`](#struct_texture_1a916a835d009806f2a57546c7705942b1) | 

## Members

#### `public GLuint `[`id`](#struct_texture_1af848138d72c1fc995ab414a71ab10d47) 

#### `public std::string `[`type`](#struct_texture_1a916a835d009806f2a57546c7705942b1) 

# struct `Vertex` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public glm::vec3 `[`position`](#struct_vertex_1a030819fdc241743bbd3e180a6b132ed3) | 
`public glm::vec3 `[`normal`](#struct_vertex_1a3aa35fe84025ecf1acccb5f65f5577fd) | 
`public glm::vec2 `[`uv_coord`](#struct_vertex_1a6fcb87706bae4c5304cd3ec8ac2b8c56) | 

## Members

#### `public glm::vec3 `[`position`](#struct_vertex_1a030819fdc241743bbd3e180a6b132ed3) 

#### `public glm::vec3 `[`normal`](#struct_vertex_1a3aa35fe84025ecf1acccb5f65f5577fd) 

#### `public glm::vec2 `[`uv_coord`](#struct_vertex_1a6fcb87706bae4c5304cd3ec8ac2b8c56) 

Generated by [Moxygen](https://sourcey.com/moxygen)