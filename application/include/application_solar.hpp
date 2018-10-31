#ifndef APPLICATION_SOLAR_HPP
#define APPLICATION_SOLAR_HPP

#include "application.hpp"
#include "model.hpp"
#include "structs.hpp"
#include <string>
#include <list>

// gpu representation of model
class ApplicationSolar : public Application {
 public:
  // allocate and initialize objects
  ApplicationSolar(std::string const& resource_path);
  // free allocated objects
  ~ApplicationSolar();

  // react to key input
  void keyCallback(int key, int action, int mods);
  //handle delta mouse movement input
  void mouseCallback(double pos_x, double pos_y);
  //handle resizing
  void resizeCallback(unsigned width, unsigned height);

  // draw all objects
  void render() const;

 protected:
  void initializeShaderPrograms();
  void initializeGeometry();
  // update uniform values
  void uploadUniforms();
  // upload projection matrix
  void uploadProjection();
  // upload view matrix
  void uploadView();

  // cpu representation of model
  model_object planet_object;
  
  // camera transform matrix
  glm::fmat4 m_view_transform;
  // camera projection matrix
  glm::fmat4 m_view_projection;
};

class Node {
    Node* parent;
    std::list<Node> children;
    std::string name;
    std::string path;
    int depth;
    glm::fmat4 localTransform;
    glm::fmat4 worldTransform;
    
public:
    Node* getParent() {
        return this -> parent;
    }
    
    void setParent(Node* newParent) {
        this -> parent = newParent;
    }
    /*
    Node* getChildren(std::string search) {
        find_if(children.begin(), children.end(), ?iterator.match(serach)? );
    } 
    */
    std::list<Node> getChildrenList() {
        return this -> children;
    }
    
    std::string getName() {
        return this -> name;
    }
    
    std::string getPath() {
        return this -> path;
    }
    
    int getDepth() {
        return this -> depth;
    }
    
    void setLocalTransform( glm::fmat4 lt) {
        this -> localTransform = lt;
    }
    
    void setWorldTransform( glm::fmat4 wt) {
        this -> worldTransform = wt;
    }
    
    void addChildren( Node child) {
        children.push_back(child);
    }
    /*
    void removeChildren( std::string name) {
        children.remove_if(?getName() = name?);
    }
     */
};

class GeometryNode : public Node {
    model_object geometry;
    
public:
    model_object getGeometry(){
        return this -> geometry;
    }
    
    void setGeometry(model_object geometry) {
        this -> geometry = geometry;
    }
};

class SceneGraph {
    static SceneGraph *instance;
    std::string name;
    Node root;
    
    SceneGraph() {
        name = "Graph";
        Node* root = nullptr;
    }
public:
    static SceneGraph *getInstance(){
        if (!instance)
            instance = new SceneGraph;
            return instance;
    }
    
    std::string getName() {
        return this -> name;
    }
    
    Node getRoot(){
        return this -> root;
    }
    
private:
    void setName(std::string newName) {
        this -> name = newName;
    }
    
    void setRoot(Node newRoot) {
        this -> root = newRoot;
    }
};





#endif