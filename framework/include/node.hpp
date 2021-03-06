#ifndef NODE_HPP
#define NODE_HPP

#include <glbinding/gl/types.h>
#include <list>
#include <glm/glm.hpp>
#include "model.hpp"

// gl definitions from glbindings
using namespace gl;

class Node {
    public:
            Node(std::string const& name);
            Node(Node* parent, std::string const& name, glm::mat4 const& local, glm::mat4 const& world);
            ~Node();
            Node* getParent() const;
            void setParent(Node* parent);
            Node* getChildren(std::string t_child) const;
            std::list<Node*> getChildrenList() const;
            std::string getName() const;
            std::string getPath() const;
            int getDepth() const;
            glm::mat4 getLocalTransform() const;
            void setLocalTransform(glm::mat4 t_local);
            glm::mat4 getWorldTransform() const;
            void setWorldTransform(glm::mat4 t_world);
            void addChildren(Node* t_child);
            Node* removeChildren(std::string t_child);

    private:
            Node* m_parent;
            std::list<Node*> m_children;
            std::string m_name;
            std::string m_path;
            int m_depth;
            glm::mat4 m_localTransform;
            glm::mat4 m_worldTransform;
};

#endif